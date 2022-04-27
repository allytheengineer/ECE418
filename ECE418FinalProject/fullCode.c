#include "fullCode.h"
// function for getting the length of a string
int getStringLength(char* str) {
	// initializing string length
	int strLength = 0;
	// variable for checking each char in string
	char temp = str[0];
	// iterator variable
	int i = 1;
	while(temp != '\0') {
		temp = str[i];
		// incrementing string length
		strLength++;
		i++;
	}
	return strLength;
}

// converts a given long to a binary string
char* numToBinary(unsigned long num, char* binaryBuffer, int buffer_size) {
	binaryBuffer += (buffer_size-1); // shifting the buffer pointer
	// looping over the buffer and adding binary chars
	for (int i = buffer_size; i >= 0; i--) {
		
		// checking to see what the least significant bit is
		if ( (num & 1) == 0 ) {
			// setting the char value at buffer pointer
			*binaryBuffer = '0';
		} else {
			// setting the char value at buffer pointer
			*binaryBuffer = '1';
		}
		binaryBuffer--; // shifting buffer pointer
		// right shifting num - erase least significant bit
		num >>= 1;
	}
	// return the buffer with binary string
	return binaryBuffer;
}


//input char array.. output is 8*length of input
char* charToBinary(char* input, char* output){

     int placeholder = 0;
    output[(getStringLength(input)*8)] = '\0';
    for(int i = 0; i<getStringLength(input); i++){
        char temp[9];
           temp[8] = '\0';
        numToBinary(input[i], temp, 8);
        for(int j = 0; j < 8; j++){
            output[placeholder] = temp[j];
            placeholder++;
        }

    }



    return output;
}


/*
 * The padding function that pads a given message until it's a multiple of 512
 * and splits the padded message into message blocks of 512 bits
 */
void pad(char* binaryMessage, int sizeBits, char messageBlocks[][blockSize+1], int numBlocks){

	//+1 is added to avoid issues involving edge cases before padding is added and after the
	//'1' separator is added
	int newSizeBits = sizeBits+1; 
	int i = 0;
	// makes newSizeBits the size needed to have exactly 64 remaining spots for the size 
	while(newSizeBits % 512 != 448){
	    newSizeBits++;
	}
	
	// creating a buffer for the message and padding
	// including the length of the message in bits
	char paddedBuff[newSizeBits+64]; 

    // copies the message into the padded buffer 
	for(i = 0; i<sizeBits; i++){
	    paddedBuff[i] = binaryMessage[i];
	}	

	printf("\n\n");
	printf("copied message: %s\n", paddedBuff);
	printf("\n\n");

	// adds a trailing '1' after the message and before the padding of 0's
	paddedBuff[sizeBits] = '1'; 
	//pads the buffer up until there are only 64 spots left for the length 
	for(i = sizeBits + 1; i < newSizeBits; i++){
	    paddedBuff[i] = '0';
	}

	// getting the size of the initial message in 64 bits
	const int BUFFER_SIZE = 65;
	char messageLengthInBinary[BUFFER_SIZE];
	// string ends with null char
	messageLengthInBinary[BUFFER_SIZE-1] = '\0';
	numToBinary(sizeBits, messageLengthInBinary, BUFFER_SIZE-1);

	// appending the length of the initial string in binary
	for (i = 0; i < 64; i++) {
		paddedBuff[newSizeBits+i] = messageLengthInBinary[i];
	}

	printf("\n\n");
	printf("everything padded: %s\n", paddedBuff);
	printf("\n\n");

	// splitting the string into blocks of 512 bits and null char
	printf("\n\n");
	for (int k = 0; k < numBlocks; k++) {
		for (int j = 0; j < blockSize; j++) {
			messageBlocks[k][j] = paddedBuff[ (k * blockSize) + j];
		}	
		// appending null char to each block
		messageBlocks[k][blockSize] = '\0';
	}
}

unsigned int binaryToInt(char* binaryString) {

    // pointer at start of binary string
    char* temp = &binaryString[0];
	// int value to return
    unsigned int val = 0;
	// while there are still characters in string
    while (*temp != '\0')
    {
		// left shift int value
        val <<= 1;
		// if the string has a one...
        if (*temp == '1') {
			// add one to the value
            val += 1;
        }
		// shift pointer forward
        temp++;
    }
	// return integer value
    return val;
}

//Rotate right function
unsigned int rotateRightint(unsigned int x, unsigned int n) {
    return (x >> n % 32) | (x << (32-n) % 32);
}

/*
 * function for taking a message block and turning it into words
 */
void createMessageSchedule(char messageBlock[blockSize+1], unsigned int messageSchedule[]) {

	int j = 0;
	int i = 0;
	// block will be split into 16 words with 32 bits and a null char
	char splitBlock[wordSize+1];
	// filling temporary buffers for 32 bit strings
	for (i = 0; i < numWords; i++) {
		for (j = 0; j < wordSize; j++) {
			splitBlock[j] = messageBlock[wordSize * i + j];
		}
		// appending null char to end of each 32 bit string
		splitBlock[wordSize] = '\0';
		printf("\nsplit block %d %s\n", i, splitBlock);
		// converting each 32 bit string into int
		messageSchedule[i] = binaryToInt(splitBlock);
	}

		// initializing the last 48 words to all zeros
		for (i = 16; i < 64; i++) {
			messageSchedule[i] = 0;
		}

		// continue the rest of computation for the message schedule
		unsigned int s0 = 0;
		unsigned int s1 = 0;
		for (i = 16; i < 64; i++) {
			s0 = rotateRightint(messageSchedule[i-15], 7) ^ rotateRightint(messageSchedule[i-15], 18) ^ (messageSchedule[i-15] >> 3);
			s1 = rotateRightint(messageSchedule[i-2], 17) ^ rotateRightint(messageSchedule[i-2], 19) ^ (messageSchedule[i-2] >> 10);
			// generating the message schedule with modulus 2^32 to keep all words into 32 bits
			messageSchedule[i] = (messageSchedule[i-16] + s0 + messageSchedule[i-7] + s1) % 4294967296;
		}

		printf("\n");
		for (i = 0; i < 64; i++) {
			printf("WORD %d %d\n", i, messageSchedule[i]);

			const int BUFFER_SIZE = 33;
			char wordInBinary[BUFFER_SIZE];
			// string ends with null char
			wordInBinary[BUFFER_SIZE-1] = '\0';
			numToBinary(messageSchedule[i], wordInBinary, BUFFER_SIZE-1);	
			printf("%s\n", wordInBinary);
		}
}

unsigned int choice(unsigned int x, unsigned int y, unsigned int z) {
	return (x & y) ^ ((~ x) & z);
}

unsigned int majority(unsigned int x, unsigned int y, unsigned int z) {
	return (x & y) ^ (x & z) ^ (y & z);
}

void compression(unsigned int messageSchedule[]) {


	// initializing hash values
	a = hash[0];
	b = hash[1];
	c = hash[2];
	d = hash[3];
	e = hash[4];
	f = hash[5];
	g = hash[6];
	h = hash[7];

	// variables needed for the loop
	unsigned int i = 0;
	unsigned int S0 = 0;
	unsigned int S1 = 0;
	unsigned int temp1 = 0;
	unsigned int temp2 = 0;
	unsigned int ch = 0;
	unsigned int maj = 0;

	// loop for the compression algorithm

        for (i = 0; i < 64; i++) {
            S1 = rotateRightint(e, 6) ^ rotateRightint(e, 11) ^ rotateRightint(e, 25);
            ch = choice(e, f, g);
            temp1 = h + S1 + ch + constants[i] + messageSchedule[i];
            S0 = rotateRightint(a, 2) ^ rotateRightint(a, 13) ^ rotateRightint(a, 22);
            maj = majority(a, b, c);
            temp2 = S0 + maj;
            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

}

//was in main and looked messy so moved to own function... also can help for testing not having to call main
void prep(char* message){
    int i = 0;
    // getting the length of the binary string
    int messageLength = getStringLength(message);

    // finding out how many 512-bit message blocks will be needed
    int numBlocksNeeded = 0;
    // least length of a message after padding a 1 and the message length
    int leastPaddedMessageLength = messageLength + 65;

    // last block is 447 bits - will pad to 512 exactly
    if (leastPaddedMessageLength % 512 == 0) {
        numBlocksNeeded = leastPaddedMessageLength / 512;
    } else {
        // adding one for integer division
        numBlocksNeeded = leastPaddedMessageLength / 512 + 1;
    }

    // creating the array of strings for the message blocks
    char messageBlocks[numBlocksNeeded][blockSize+1];

    // padding the message and getting the message blocks
    pad(message, messageLength, messageBlocks, numBlocksNeeded);

    // printing all of the message blocks
    printf("\n\n");
    for (i = 0; i < numBlocksNeeded; i++) {
        printf("\n\n");
        printf ("block %d: %s\n", i, messageBlocks[i]);
    }
    printf("\n\n");

    // creating int array for message schedule
    // adding 48 words to complete the message schedule
    for(int j =0; j< numBlocksNeeded; j++) {
        unsigned int messageSchedule[numWords + 48];
        createMessageSchedule(messageBlocks[j], messageSchedule);


        //* should print all words correctly - double check this vs a corect example

        for (i = 0; i < numWords + 48; i++) {
            const int BUFFER_SIZE = 33;
            char wordInBinary[BUFFER_SIZE];
            // string ends with null char
            wordInBinary[BUFFER_SIZE-1] = '\0';
            numToBinary(messageSchedule[i], wordInBinary, BUFFER_SIZE-1);
            // prints correct words here... do we need to fix this in main()?
            printf("%s\n", wordInBinary);
        }


        // running the compression for the function
        compression(messageSchedule);

        hash[0] += a;
        hash[1] += b;
        hash[2] += c;
        hash[3] += d;
        hash[4] += e;
        hash[5] += f;
        hash[6] += g;
        hash[7] += h;
    printf("Hash %d: %X%X%X%X%X%X%X%X\n",j, hash[0], hash[1], hash[2], hash[3], hash[4], hash[5], hash[6], hash[7]);
    }
    // hash from the first round
    //printf("\n%X%X%X%X%X%X%X%X\n", hash[0], hash[1], hash[2], hash[3], hash[4], hash[5], hash[6], hash[7]);




}

int main() {
    //Test messages
    //cross check with this site. All constants are the same as our program: https://www.movable-type.co.uk/scripts/sha256.html
    //char* message = "011000010110001001100011";     //abc
    //
    char* message = "011010010111010000100000011101110110111101110010011010110110010101100100";       //it worked
    //char* message = "0110100001100101011011000110110001101111001000000111011101101111011100100110110001100100";     //hello world
    //char* message = "0110100001101001"; //hi
    //pushes message to prep aka the function
	prep(message);
    return 0;
}


