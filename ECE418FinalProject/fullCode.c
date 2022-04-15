#include <stdio.h>

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
char* longToBinary(unsigned long num, char* binaryBuffer, int buffer_size) {
	binaryBuffer += (buffer_size-1); // shifting the buffer pointer

	// looping over the buffer and adding binary chars
	for (int i = 64; i >= 0; i--) {
		
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

/**
 * Creating all of the initial padding for SHA-256
 * returns an array of binary strings - each 512 characters
 */
//void pad(char* binaryMessage, char* messageBlocks[], int sizeBits) {
	// find size of binaryMessage
//	printf("size:%d", sizeBits);

//	int newSizeBits = sizeBits;


	//while(newSizeBits % 512 != 448) {
//	    newSizeBits++;
//	}

 //   char* paddedBuff = malloc(sizeof(char)*1024);
//	//strcat(paddedBuff,binaryMessage);
//	for(int i = 0; i < sizeBits; i++) {
//		paddedBuff[i] = binaryMessage[i];
//	}

	// adding a single '1' to separate message and padding
	//paddedBuff[sizeBits] = '1';
//	sizeBits++;

//	for(int i = sizeBits; i < newSizeBits; i++){
//	    paddedBuff[i] = '0';
//	}
//	printf("padded=%s", paddedBuff);
	/*
	const int BUFFER_SIZE = 65;
	char stringLength[BUFFER_SIZE];
	stringLength[BUFFER_SIZE-1] = '\0';
	longToBinary(sizeBits, stringLength, BUFFER_SIZE-1);
	printf("binary=%s", stringLength);

	char paddedBinary[512];
	strcpy(paddedBinary, binaryMessage);
	printf("padded=%s", paddedBinary);
    */


	// padding message up until 512 - 64 bits
	// message length is stored in the last 64 bits
	//while(sizeBits % 448 != 0){
	//	strcat(binaryMessage, "0");
	//	sizeBits++;
	//}

	//strcat(binaryMessage, stringLength);
	//printf("message=%s", binaryMessage);

	// split binaryMessage every 512 bits
	//for(int i = 0; i < sizeBits; i++){
		//if(i%512==0){
			//split
		//}
	//}
	//
//}

int main() {
	char* message = "00000011";
	int messageLength = getStringLength(message);

	int numBlocks = 0;
	if (messageLength % 512 == 0) {
		numBlocks = messageLength / 512;
	}
	char* messageBlocks[numBlocks];
	pad(message, messageBlocks, messageLength);
    return 0;
}
