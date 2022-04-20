#include <stdio.h>

// initialzing global block size
const int blockSize = 512;

// 16 words per message block
const int numWords = 16;
// 32 bits in each word
const int wordSize = 32;

// initializing all global hash values
int h0 = 0x6a09e667;
int h1 = 0xbb67ae85;
int h2 = 0x3c6ef372;
int h3 = 0xa54ff53a;
int h4 = 0x510e527f;
int h5 = 0x9b05688c;
int h6 = 0x1f83d9ab;
int h7 = 0x5be0cd19;

// initializing round constants
int constants[] = {
0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

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
	printf("\n\n");	

}

int binaryToInt(char* binaryString) {

    // pointer at start of binary string
    char* temp = &binaryString[0];
	// int value to return
    int val = 0;
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
int rotateRightint(int x, int n) {
    return (x >> n % 32) | (x << (32-n) % 32);
}

/*
 * function for taking a message block and turning it into words
 */
void createMessageSchedule(char messageBlock[blockSize+1], int messageSchedule[]) {

	// block will be split into 16 words with 32 bits and a null char
	char splitBlock[wordSize+1];
	// filling temporary buffers for 32 bit strings
	for (int i = 0; i < numWords; i++) {
		for (int j = 0; j < wordSize; j++) {
			splitBlock[j] = messageBlock[wordSize * i + j];
		}
		// appending null char to end of each 32 bit string
		splitBlock[wordSize] = '\0';
		printf("\nsplit block %s\n", splitBlock);
		// converting each 32 bit string into int
		messageSchedule[i] = binaryToInt(splitBlock);
		printf("word %d %d\n", i, messageSchedule[i]);

		// initializing the last 48 words to all zeros
		for (i = 16; i < 64; i++) {
			messageSchedule[i] = 0;
		}


		// continue the rest of computation for the message schedule
		int s0 = 0;
		int s1 = 0;
		for (i = 16; i < 64; i++) {
			s0 = rotateRightint(messageSchedule[i-15], 7) ^ rotateRightint(messageSchedule[i-15], 18) ^ (messageSchedule[i-15] >> 3);
			s1 = rotateRightint(messageSchedule[i-2], 17) ^ rotateRightint(messageSchedule[i-2], 19) ^ (messageSchedule[i-2] >> 10);
			messageSchedule[i] = messageSchedule[i-16] + s0 + messageSchedule[i-7] + s1;
		}
	}
}

int main() {
	// test input message
	// char* message = "1101010101010101011010011110001001010001100110101010011001100110011001100110011001101010101010010101010101001001010010010100101010100101001010001010100101010101010101010100010001101111101011011100101010101010101001010101010100101010010101010111111111111101010101010101011010011110001001010001100110101010011001100110011001100110011001101010101010010101010101001001010010010100101010100101001010001010100101010101010101010100010001101111101011011100101010101010101001010101010100101010010101010111111111111010101010101010110100111100010010100011001101010100110011001100110011001100110011010101010100101010101010010010100100101001010101001010010100010101001010101010101010101000100011011111010110111001010101010101010010101010101001010100101010101111111111110000000000000011111111111111110000000000000011111111111101010000000000000001111111111111000000000000000111111111111100000000000000111111111111110000000000000011111111111111111111111111101010101010101010101010101010100000000000000000111111111111111100000000000000011111111111111111000000000000000011111111111111111000000000000001111111111111110000000000000001111111111111100000000000010101010101010101010101001010101011111111111111100000000000000000111111111111111000000000000001111111111111111001010000000000000000000011111111111111110000000000000000111111111111110000000000000000101010100000000000000111111111111111000000000000000111111111111100000000000001010100000000000000000011111111111111111100000000000000000011111111101010101010010101010101010101111";
	//char* message = "110101010100010010100011001101010100110011001100110011001100110011010101010100101010101010010010100100101001010101001010010100010101001010101010101010101000100011011111010110111001010101010101010010101010101001010100101010101111111111111010101010101010110100111100010010100011001101010100110011001100110011001100110011010101010100101010101010010010100100101001010101001010010100010101001010101010101010101000100011011111010110111001010101010101010010101010101001010100101010101111111111110101010101010101101001111000100101000110011010101001100110011001100110011001100110101010101001010101010100100101001001010010101010010100101000101010010101010101010101010001000110111110101101110010101010101010100101010101010010101001010101011111111111100000000000000111111111111111100000000000000111111111111010100000000000000011111111111110000000000000001111111111111000000000000001111111111111100000000000000111111111111111111111111111010101010101010101010101010101000000000000000001111111111111111000000000000000111111111111111110000000000000000111111111111111110000000000000011111111111111100000000000000011111111111111000000000000101010101010101010101010010101010111111111111111000000000000000001111111111111110000000000000011111111111111110010100000000000000000000111111111111111100000000000000001111111111111100000000000000001010101000000000000001111111111111110000000000000001111111111111000000000000010101000000000000000000111111111111111111000000000000000000111111111010101010100101010101010101011111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010111101001";
	char* message = "01101000 01100101 01101100 01101100 01101111 00100000 01110111 01101111 01110010 01101100 01100100";
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
	for (int i = 0; i < numBlocksNeeded; i++) {
		printf("\n\n");
 		printf ("block %d: %s\n", i, messageBlocks[i]);
	}	
	printf("\n\n");

	// creating int array for message schedule
	// adding 48 words to complete the message schedule
    int messageSchedule[numWords + 48];
	createMessageSchedule(messageBlocks[0], messageSchedule);




	printf("\nMESSAGE SCHEDULE\n");

	// getting the size of the initial message in 64 bits
	const int BUFFER_SIZE0 = 33;
	char messageLengthInBinary0[BUFFER_SIZE0];
	// string ends with null char
	messageLengthInBinary0[BUFFER_SIZE0-1] = '\0';
	for (i = 0; i < 64; i++) {
		numToBinary(messageSchedule[i], messageLengthInBinary0, BUFFER_SIZE0-1);
		printf("%s\n", messageLengthInBinary0);
	}

    return 0;
}

