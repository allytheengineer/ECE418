#include <stdio.h>

/**
 *
 */
int pad(char* binaryMessage){
	//find size of binaryMessage
	int sizeBytes = strlen(binaryMessage);
	int sizeBits = sizeBytes*8;
	//split binaryMessage every 512 bits


		while(sizeBits % 512 != 0){
		strcat(binaryMessage, '0');
		}


	for(int i = 0; i < sizeBits; i++){
		if(i%512==0){
			//split
		}
	}
	//
}
