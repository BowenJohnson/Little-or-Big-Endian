#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static char *studentName = "Bowen Johnson";

// report whether machine is big or small endian
void bigOrSmallEndian()
{
	int x = 1;
	
	if (*(char *)&x == 1)
	{
		printf("byte order: little-endian\n");
	}
	else
	{
		printf("byte order: big-endian\n");
	}
}

// get next float using scanf()
// returns true (success) or false (failure)
// if call succeeded, return float value via fPtr
bool getNextFloat(float *fPtr)
{
    // replace this code with the call to scanf()
    *fPtr = 0.0;

	scanf("%f", fPtr);

	if (!fPtr)
	{
		return false;
	}
	else
	{
    	return true;
	}
}

// print requested data for the given number
void printNumberData(float f)
{
	int f2i = f;

	//int to hex
	printf("%10i", f2i);
	printf(" ");
	printf("0x%08X\n", f2i);

	//float to hex
	printf("%10.02f", f);
	printf(" ");
	printf("0x%08X\n", *(int*)&f);
}

int main(int argc, char **argv)
{
	float	f;								// number currently being analyzed
	bool	validInput;						// was user input valid?

	printf("CS201 - A01 - %s\n\n", studentName);
	bigOrSmallEndian();
	for (;;) {
		if (argc == 1)						// allow grading script to control ...
			printf("> ");					// ... whether prompt character is printed
		validInput = getNextFloat(&f);
		if (! validInput) {					// encountered bad input
			printf("bad input\n");
			while (getchar() != '\n') ;		// flush bad line from input buffer
			continue;
			}
		printNumberData(f);
		if (f == 0.0) {
			printf("bye...\n");
			break;
			}
		}
	printf("\n");
	return 0;
}
