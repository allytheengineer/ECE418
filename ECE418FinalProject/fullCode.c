#include <stdio.h>
#
// block size for SHA-256
const int blockSize = 512;

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
void pad(char* binaryMessage, int sizeBits, char messageBlocks[][blockSize+1], int numBlocks) {
	//printf("sizeBits:%d\n", sizeBits);
	//printf("original message:%s\n", binaryMessage);
	//printf("num blocks:%d\n", numBlocks);


	// filling in all complete 512-bit blocks - PROBLEM HERE
	printf("\n\n");
	for (int k = 0; k < numBlocks-1; k++) {
		for (int j = 0; j < blockSize; j++) {
			messageBlocks[k][j] = binaryMessage[ (k * blockSize) + j];
			printf("%c", messageBlocks[k][j]); 
		}	
		messageBlocks[k][blockSize] = '\0';
	}
	printf("\n\n");

	// filling in the last incomplete block with message bits
	int i = 0;
	while (binaryMessage[ ( (numBlocks - 1) * blockSize) + i] != '\0') {
		messageBlocks[numBlocks - 1][i] = binaryMessage[ ( (numBlocks - 1) * blockSize) + i];
		i++;
	}

	// appending 1 to separate message and padding
	messageBlocks[numBlocks - 1][i] = '1';
	i++;

	// padding with zeros until 64 bits less than 512
	int j = i;
	while (j % (blockSize - 64) != 0) {
		messageBlocks[numBlocks - 1][j] = '0';
		j++;
	}
 
	// getting the size of the initial message in 64 bits
	const int BUFFER_SIZE = 65;
	char messageLengthInBinary[BUFFER_SIZE];
	// string ends with null char
	messageLengthInBinary[BUFFER_SIZE-1] = '\0';
	longToBinary(sizeBits, messageLengthInBinary, BUFFER_SIZE-1);
	//printf("messageLengthInBinary=%s\n", messageLengthInBinary);

	for (int k = 0; k < BUFFER_SIZE-1; k++) {
		messageBlocks[numBlocks - 1][j + k] = messageLengthInBinary[k];
	}

	// appending null character to end of last block
	messageBlocks[numBlocks - 1][blockSize] = '\0';

	for (int i = 0; i < numBlocks; i++) {
		printf("\n");
		printf("block %d: %s\n", i, messageBlocks[i]);
		printf("\n");
	}
}


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
//Addison Added this here This works btw 
/*
char* pad(char* binaryMessage){
	// find size of binaryMessage
	int sizeBits = getStringLength(binaryMessage);
	//+1 is added to avoid issues involving edge cases before padding is added and after the
	//'1' separator is added 
	int newSizeBits = sizeBits+1; 
//makes newSizeBits the size needed to have exactly 64 remaining spots for the size 
	while(newSizeBits % blockSize != 448){
	    newSizeBits++;
	}
	//ignore this this is from my IDE
   char* paddedBuff; 
    //copies the message into the padded buffer 
	for(int i = 0; i<sizeBits; i++){
	    paddedBuff[i] = binaryMessage[i];
	}	
	//adds a trailing '1' after the message and before the padding 
	paddedBuff[sizeBits] = '1'; 
	//pads the buffer up until there are only 64 spots left so 448
	for(int i = sizeBits+1; i<newSizeBits; i++){
	    paddedBuff[i] = '0';
	}
	//converts the size of the initial message into binary and concats it to the end of the message in the last 
	//64 bits 
	for(int i = 63; i>-1; i--){
	    if((pow(2,i) >= 0) && (pow(2,i) <= sizeBits)){
	        sizeBits = sizeBits - pow(2,i);
	        paddedBuff[newSizeBits+63-i] = '1';
	    }
	    else{
	      paddedBuff[newSizeBits+63-i] = '0';  
	    }
	    
	}
	return paddedBuff;
	// split binaryMessage every 512 bits
	//for(int i = 0; i < sizeBits; i++){
		//if(i%512==0){
			//split
		//}
	//}
	//
}

int main() {
	char* buffer = "0000011";
	char* PaddedBuffer; //Uncomment to use in normal IDE // = malloc(sizeof(char)* getStringLength(buffer)*2);
	PaddedBuffer = pad(buffer);
   printf ("%s\n", PaddedBuffer);
    return 0;

}
*/


int main() {
	// test input message
	//char* message = "10010100100101";
	char* message = "10101010101010101101001111000100101000110011010101001100110011001100110011001100110101010101001010101010100100101001001010010101010010100101000101010010101010101010101010001000110111110101101110010101010101010100101010101010010101001010101011111111111100000000000000111111111111111100000000000000111111111111010100000000000000011111111111110000000000000001111111111111000000000000001111111111111100000000000000111111111111111111111111111010101010101010101010101010101000000000000000001111111111111111000000000000000111111111111111110000000000000000111111111111111110000000000000011111111111111100000000000000011111111111111000000000000101010101010101010101010010101010111111111111111000000000000000001111111111111110000000000000011111111111111110010100000000000000000000111111111111111100000000000000001111111111111100000000000000001010101000000000000001111111111111110000000000000001111111111111000000000000010101000000000000000000111111111111111111000000000000000000111111111010101010100101010101010101010";
	// getting the length of the binary string
	int messageLength = getStringLength(message);
	
	// finding out how many 512-bit message blocks will be needed
	int numBlocksNeeded = 0;
	// least length of a message after padding a 1 and the message length
	int leastPaddedMessageLength = messageLength + 65;

	//printf("\n leastPaddedMessageLength %d\n", leastPaddedMessageLength);

	// last block is 447 bits - will pad to 512 exactly
	if (leastPaddedMessageLength % 512 == 0) {
		numBlocksNeeded = leastPaddedMessageLength / 512;
	} else {
 		// adding one for integer division
		numBlocksNeeded = leastPaddedMessageLength / 512 + 1;
	}
	
	// array of strings for 512-bit message blocks
	char messageBlocks[numBlocksNeeded][blockSize+1]; // added 1 for the null character
	pad(message, messageLength, messageBlocks, numBlocksNeeded);
    return 0;
}
