// include statement for printing to the console
//#include "fullCode.h"
#include <stdio.h>
// main for testing
int main() {
    //Test message
    char* message = "011000010110001001100011";   // abc

    int messageLength = 0;
    printf("initialized message for getStringLength: %s\n", message);
    printf("initialized length for getStringLength: %d\n", messageLength);
	printf("testing getStringLength: \n");
	messageLength = getStringLength(message); // should return 24
	printf("message length of %s computed: %d\n\n", message, messageLength);


	const int BUFFER_SIZE = 5;
	char numInBinary[BUFFER_SIZE];
	// string ends with null char
	numInBinary[BUFFER_SIZE-1] = '\0';
	int testNum = 15;
	printf("initial number for numToBinary: %d\n", testNum);
	printf("testing numBinary: \n");
	numToBinary(testNum, numInBinary, BUFFER_SIZE-1);
	printf("resulting binary string of %d: %s\n\n", testNum, numInBinary);

	char* testString = "Thomas";
	char testOutput[ (8 * 6) + 1 ];
	printf("initialized character for charToBinary: %s\n", testString);
	printf("testing charToBinary: \n");
	charToBinary(testString, testOutput);
	printf("resulting binary string of %s: %s\n\n", testString, testOutput);

	char* testBinaryStr = "0000000000001100"; // 12 in binary
	int testBinaryToInt = 0;
	printf("initialized binary string for binaryToInt: %s\n", testBinaryStr);
	printf("initialized output integer: %d\n", testBinaryToInt);
	printf("testing binaryToInt: \n");
	testBinaryToInt = binaryToInt(testBinaryStr);
	printf("resulting integer from binary %s: %d\n\n", testBinaryStr, testBinaryToInt);


	testNum = 60;
	int numShifts = 3;
	int testNumOutput = 0;
	printf("initialized number for rotateRightint: %d\n", testNum);
	printf("initialized number of shifts for rotateRightint: %d\n", numShifts);
	printf("initialized test output: %d\n", testNumOutput);
	printf("testing rotateRightint: \n");
	testNumOutput = rotateRightint(testNum, numShifts);
	printf("output - rotate right %d %d times: %d\n\n", testNum, numShifts, testNumOutput);


	int num0 = 65535;
	int num1 = 16711935;
	int num2 = 4294901760;
	testNumOutput = 0;
	printf("initialized first number for choice function: %d\n", num0);
	printf("initialized second number for choice function: %d\n", num1);
	printf("initialized third number for choice function: %d\n", num2);
	printf("initialized test output: %d\n", testNumOutput);
	printf("testing choice: \n");
	testNumOutput = choice(num0, num1, num2);
	printf("choice of %d, %d, and %d: %d\n\n", num0, num1, num2, testNumOutput);


	num0 = 65535;
	num1 = 16711935;
	num2 = 4294901760;
	testNumOutput = 0;
	printf("initialized first number for majority function: %d\n", num0);
	printf("initialized second number for majority function: %d\n", num1);
	printf("initialized third number for majority function: %d\n", num2);
	printf("initialized test output: %d\n", testNumOutput);
	printf("testing majority: \n");
	testNumOutput = majority(num0, num1, num2);
	printf("majority of %d, %d, and %d: %d\n\n", num0, num1, num2, testNumOutput);



    return 0;
}
