#include <stdio.h>
#include <string.h>


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
		num>>=1; 
	}
	// return the buffer with binary string
	return binaryBuffer;
}

/**
 * Creating all of the initial padding for SHA-256
 */
void pad(char* binaryMessage){
	// find size of binaryMessage
	int sizeBits = strlen(binaryMessage);
	int newSizeBits = sizeBits +1; 
	while(newSizeBits%512 != 448){
	    newSizeBits++;
	}
    char* paddedBuff = malloc(sizeof(char)*1024); 
	//strcat(paddedBuff,binaryMessage);
	for(int i = 0; i<sizeBits; i++){
	paddedBuff[i] = binaryMessage[i];
	}	
	paddedBuff[sizeBits] = '1'; 
	for(int i = sizeBits+1; i<newSizeBits; i++){
	    paddedBuff[i] = '0';
	}	
	printf("padded=%s", paddedBuff);
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
	// adding a single '1' to separate message and padding
	//strcat(binaryMessage, "1");
	//sizeBits++;

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
}

int main() {
	char* buffer = "00000011";
	pad(buffer);
 //   printf ("%s\n", buffer);
    return 0;

}