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
//this one works do not mess with it.. it is ugly but whatever
int padv4(char* message,char messageBlocks[][513]) {
    //takes binary string and fills and pads messageBlocks. NO overflow protection implemented
    int sizeNeeded = getStringLength(message) + 1;
    while (sizeNeeded % 512 != 448) {
        sizeNeeded++;
    }
    int blocksNeeded = 0;
    blocksNeeded = (sizeNeeded / 512) + 1;
    int iter = 0;
    for(int i = 0; i< getStringLength(message); i ++){
        messageBlocks[i/512][i%512] = message[iter];
        iter++;
    }
    messageBlocks[iter/512][iter%512] = '1';
    iter++;
    while(iter % 512 != 447){
        messageBlocks[iter/512][iter%512] = '0';
        iter++;
    }
    //appends size to end of last block
    char messageLengthInBinary2[65];
    numToBinary(getStringLength(message), messageLengthInBinary2, 64);
    // appending the length of the initial string in binary
    for (int kt = 0; kt < 64; kt++) {
        messageBlocks[blocksNeeded-1][448+kt] = messageLengthInBinary2[kt];
    }
    messageBlocks[blocksNeeded-1][512] = '\0';
    // print for testing
/*
    printf("\n");
    for(int f = 0; f < blocksNeeded; f++){
        printf("block: %d\n%s\n",f,messageBlocks[f]);
    }
*/
    return blocksNeeded;
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
    message[messageLength] = '\0';
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
    char messageBlocks[128][513];

    // padding the message and getting the message blocks
   // pad(message, messageLength, messageBlocks, numBlocksNeeded);
   int blocksUsed = 0;
    blocksUsed = padv4(message,messageBlocks);

    // creating int array for message schedule
    // adding 48 words to complete the message schedule
    for(int j =0; j< blocksUsed; j++) {
        unsigned int messageSchedule[64];
        createMessageSchedule(messageBlocks[j], messageSchedule);


        //* should print all words correctly - double check this vs a correct example


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
    }
    // hash from the first round
    printf("\n%X%X%X%X%X%X%X%X\n", hash[0], hash[1], hash[2], hash[3], hash[4], hash[5], hash[6], hash[7]);
}

int main() {
    //Test messages
    //cross check with this site. All constants are the same as our program: https://www.movable-type.co.uk/scripts/sha256.html
    char* message1 = "abc";
    char messagebinary[100000];
    //BA7816BF8F01CFEA414140DE5DAE2223B00361A396177A9CB410FF61F20015AD
    char* message2 = "it worked";
     //EA86226D3A82DBDD4FB2F1929193B8961B5548DA7368417A92EC1EF08D0D3695
    char* message3 = "hello world";
    //2 blocks 105 char
    char* message4 = "i am so stressed out from running my pet lizards instagram account i’m about to have a nervous breakdown";
    //c98b04d01b7f99c0c0f069fee7c7ca6dce15aa55e78a39241c34fbfb850e0006
    //6 blocks 327 char
    char* message5 = "We the People of the United States, in Order to form a more perfect Union, establish Justice, insure domestic Tranquility, provide for the common defense, promote the general Welfare, and secure the Blessings of Liberty to ourselves and our Posterity, do ordain and establish this Constitution for the United States of America.";
    //a15c9ccfe5690dfca6fa8af361ba76afefc8c968240586e6f3d4812c7c0925ca
    //28 blocks 865 char
    char* message6 = "Our services allow users to add content in a number of different ways, including via direct messages and in smaller and larger communities. Some of these spaces are public, and if you share content within them, that content may be accessed by people you do not know. For example, some servers are available in the Server Discovery section of the app and do not require an invite link to join. Other server owners may publish their server invite link on public websites. Anyone can access these spaces. You should be aware that these permissions are set by server owners or admins, and they may change over time. Please understand the difference between posting in public and private spaces on Discord, and choose the right space, features, and settings for you and your content. To understand how we treat your personal information, see our Privacy Policy.";
    prep(charToBinary(message5,messagebinary));

    return 0;
}