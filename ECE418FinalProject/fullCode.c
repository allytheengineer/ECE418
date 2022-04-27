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

    //one block or less messages
    //char* message = "011000010110001001100011";     //abc
    //char* message = "011010010111010000100000011101110110111101110010011010110110010101100100";       //it worked
    //char* message = "0110100001100101011011000110110001101111001000000111011101101111011100100110110001100100";     //hello world
    //char* message = "0110100001101001"; //hi

    //multiblock messages
    //2 blocks 105 char
        //"i am so stressed out from running my pet lizards instagram account i’m about to have a nervous breakdown"
        //char* message2Blocks = "01101001001000000110000101101101001000000111001101101111001000000111001101110100011100100110010101110011011100110110010101100100001000000110111101110101011101000010000001100110011100100110111101101101001000000111001001110101011011100110111001101001011011100110011100100000011011010111100100100000011100000110010101110100001000000110110001101001011110100110000101110010011001000111001100100000011010010110111001110011011101000110000101100111011100100110000101101101001000000110000101100011011000110110111101110101011011100111010000100000011010011110001010000000100110010110110100100000011000010110001001101111011101010111010000100000011101000110111100100000011010000110000101110110011001010010000001100001001000000110111001100101011100100111011001101111011101010111001100100000011000100111001001100101011000010110101101100100011011110111011101101110";


    //6 block 327 char
        //"We the People of the United States, in Order to form a more perfect Union, establish Justice, insure domestic Tranquility, provide for the common defense, promote the general Welfare, and secure the Blessings of Liberty to ourselves and our Posterity, do ordain and establish this Constitution for the United States of America."
        char* message6Blocks = "010101110110010100100000011101000110100001100101001000000101000001100101011011110111000001101100011001010010000001101111011001100010000001110100011010000110010100100000010101010110111001101001011101000110010101100100001000000101001101110100011000010111010001100101011100110010110000100000011010010110111000100000010011110111001001100100011001010111001000100000011101000110111100100000011001100110111101110010011011010010000001100001001000000110110101101111011100100110010100100000011100000110010101110010011001100110010101100011011101000010000001010101011011100110100101101111011011100010110000100000011001010111001101110100011000010110001001101100011010010111001101101000001000000100101001110101011100110111010001101001011000110110010100101100001000000110100101101110011100110111010101110010011001010010000001100100011011110110110101100101011100110111010001101001011000110010000001010100011100100110000101101110011100010111010101101001011011000110100101110100011110010010110000100000011100000111001001101111011101100110100101100100011001010010000001100110011011110111001000100000011101000110100001100101001000000110001101101111011011010110110101101111011011100010000001100100011001010110011001100101011011100111001101100101001011000010000001110000011100100110111101101101011011110111010001100101001000000111010001101000011001010010000001100111011001010110111001100101011100100110000101101100001000000101011101100101011011000110011001100001011100100110010100101100001000000110000101101110011001000010000001110011011001010110001101110101011100100110010100100000011101000110100001100101001000000100001001101100011001010111001101110011011010010110111001100111011100110010000001101111011001100010000001001100011010010110001001100101011100100111010001111001001000000111010001101111001000000110111101110101011100100111001101100101011011000111011001100101011100110010000001100001011011100110010000100000011011110111010101110010001000000101000001101111011100110111010001100101011100100110100101110100011110010010110000100000011001000110111100100000011011110111001001100100011000010110100101101110001000000110000101101110011001000010000001100101011100110111010001100001011000100110110001101001011100110110100000100000011101000110100001101001011100110010000001000011011011110110111001110011011101000110100101110100011101010111010001101001011011110110111000100000011001100110111101110010001000000111010001101000011001010010000001010101011011100110100101110100011001010110010000100000010100110111010001100001011101000110010101110011001000000110111101100110001000000100000101101101011001010111001001101001011000110110000100101110";

        //pushes message to prep aka the function
	prep(message6Blocks);
    return 0;
}


