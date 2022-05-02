// include statement for printing to the console
//#include "fullCode.h"
#include <stdio.h>
// main for testing


int main() {
    //Test message
    char* message = "011000010110001001100011";   // abc

    printf("\n");
    printf("\n");

    int messageLength = 0;
	printf("testing getStringLength: \n");
    printf("initialized message for getStringLength: %s\n", message);
    printf("initialized length for getStringLength: %d\n", messageLength);
	printf("running getStringLength: \n");
	messageLength = getStringLength(message); // should return 24
	printf("message length of %s computed: %d\n\n", message, messageLength);

	printf("\n");
    printf("\n");

	printf("testing numBinary: \n");
	const int BUFFER_SIZE = 5;
	char numInBinary[BUFFER_SIZE];
	// string ends with null char
	numInBinary[BUFFER_SIZE-1] = '\0';
	int testNum = 15;
	printf("initial number for numToBinary: %d\n", testNum);
	printf("running numBinary: \n");
	numToBinary(testNum, numInBinary, BUFFER_SIZE-1);
	printf("resulting binary string of %d: %s\n\n", testNum, numInBinary);

    printf("\n");
    printf("\n");


	printf("testing stringToBinary: \n");
	char* testString = "Thomas";
	char testOutput[ (8 * 6) + 1 ];
	printf("initialized character for charToBinary: %s\n", testString);
	printf("running stringToBinary: \n");
	stringToBinary(testString, testOutput);
	printf("resulting binary string of %s: %s\n\n", testString, testOutput);

    printf("\n");
    printf("\n");


	printf("testing binaryToInt: \n");
	char* testBinaryStr = "0000000000001100"; // 12 in binary
	int testBinaryToInt = 0;
	printf("initialized binary string for binaryToInt: %s\n", testBinaryStr);
	printf("initialized output integer: %d\n", testBinaryToInt);
	printf("running binaryToInt: \n");
	testBinaryToInt = binaryToInt(testBinaryStr);
	printf("resulting integer from binary %s: %d\n\n", testBinaryStr, testBinaryToInt);

    printf("\n");
    printf("\n");


	printf("testing rotateRightint: \n");
	testNum = 60;
	int numShifts = 3;
	int testNumOutput = 0;
	printf("initialized number for rotateRightint: %d\n", testNum);
	printf("initialized number of shifts for rotateRightint: %d\n", numShifts);
	printf("initialized test output: %d\n", testNumOutput);
	printf("running rotateRightint: \n");
	testNumOutput = rotateRightint(testNum, numShifts);
	printf("output - rotate right %d %d times: %d\n\n", testNum, numShifts, testNumOutput);

    printf("\n");
    printf("\n");


	printf("testing choice: \n");
	int num0 = 65535;
	int num1 = 16711935;
	int num2 = 4294901760;
	testNumOutput = 0;
	printf("initialized first number for choice function: %d\n", num0);
	printf("initialized second number for choice function: %d\n", num1);
	printf("initialized third number for choice function: %d\n", num2);
	printf("initialized test output: %d\n", testNumOutput);
	printf("running choice: \n");
	testNumOutput = choice(num0, num1, num2);
	printf("choice of %d, %d, and %d: %d\n\n", num0, num1, num2, testNumOutput);

    printf("\n");
    printf("\n");


	printf("testing majority: \n");
	num0 = 65535;
	num1 = 16711935;
	num2 = 4294901760;
	testNumOutput = 0;
	printf("initialized first number for majority function: %d\n", num0);
	printf("initialized second number for majority function: %d\n", num1);
	printf("initialized third number for majority function: %d\n", num2);
	printf("initialized test output: %d\n", testNumOutput);
	printf("running majority: \n");
	testNumOutput = majority(num0, num1, num2);
	printf("majority of %d, %d, and %d: %d\n\n", num0, num1, num2, testNumOutput);

    printf("\n");
    printf("\n");


	printf("testing padv4: \n");
	char* message0 = "0101010001101000011010010111001100100000011010010111001100100000011000010010000001110010011000010110111001100100011011110110110100100000011100110111010001110010011010010110111001100111001000000100100100100000011000010110110100100000011101010111001101101001011011100110011100100000011101000110111100100000011101000110010101110011011101000010000001110100011010000110010100100000011101100110000101101100011010010110010001101001011101000111100100100000011011110110011000100000011011110111010101110010001000000101001101001000010000010011001000110101001101100010000001100110011101010110111001100011011101000110100101101111011011100010000001110100011010000110000101110100001000000110100101110011001000000111001101110100011100100110000101101001011001110110100001110100001000000111010101110000001000000111011101101111011100100110101101101001011011100110011100100000011011110110111000100000011011010110000101100111011010010110001100100000011000010111010000100000011101000110100001101001011100110010000001110000011011110110100101101110011101000010000100100000010010000110110101101101001000000111011101101000011000010111010000100000011101000110100001100101001000000110100001100101011000110110101100100000011010010111001100100000011100100110010101100001011011000110110001111001001000000110100001100001011100000111000001100101011011100110100101101110011001110010000001110111011010010111010001101000001000000111010001101000011010010111001100111111";
	char messageBlocks0[128][513];
	printf("initialized message in binary: %s\n", message0);
	printf("running padv4: \n");
	int numBlocksUsed0 = padv4(message0, messageBlocks0);
	printf("number of blocks used to pad: %d\n", numBlocksUsed0);
	for (int i = 0; i < numBlocksUsed0; i++) {
		printf("\nblock %d \n %s", i, messageBlocks0[i]);
	}

    printf("\n");
    printf("\n");


	printf("testing createMessageSchdule: \n");
	char messageBlocks[10][513];
	unsigned int messageSchedule[64];
	printf("initialized message in binary: %s\n", message); // abc in binary
	printf("running createMessageSchdule: \n");
	int numBlocksUsed = padv4(message, messageBlocks);
	createMessageSchedule(messageBlocks[0], messageSchedule); // will only have one block for "abc"
	printf("Here is the message schedule as integers for %s:\n", message);
	for (int k = 0; k < 64; k++) {
		printf("%u\n", messageSchedule[k]);
	}

    printf("\n");
    printf("\n");


	printf("testing prep function: \n");
    char messagebinary[100000];
    char* message5 = "We the People of the United States, in Order to form a more perfect Union, establish Justice, insure domestic Tranquility, provide for the common defense, promote the general Welfare, and secure the Blessings of Liberty to ourselves and our Posterity, do ordain and establish this Constitution for the United States of America.";
    printf("Here is the message to hash: %s\n", message5);
    printf("running prep: \n");
    prep(stringToBinary(message5,messagebinary));


    return 0;
}


