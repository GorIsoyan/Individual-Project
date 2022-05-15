#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char* base64Encoder(char *input_string, int len_string)
{
	char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; // the Base64 encoding table
	
	// Resultant string
	char *res_string = (char *) malloc(len_string * sizeof(char)); // len_string is the size, which gives the user
	
	int index;
	int no_of_bits = 0; 
	int padding = 0; 
	int val = 0; 
	int count = -1; 
	int temp;
	int i = 0; 
	int j = 0; 
	int k = 0;
	
	// Loop takes 3 characters at a time from
	// input_str and stores it in val
	for (i = 0; i < len_string; i += 3)
		{
			val = 0, count = 0, no_of_bits = 0;

			for (j = i; j < len_string && j <= i + 2; j++)
			{
				// binary data of input_str is stored in val
				val = val << 8;
				
				// (A + 0 = A) stores character in val
				val = val | input_string[j];
				
				// calculates how many time loop
				// ran if "MEN" -> 3 otherwise "ON" -> 2
				count++;
			
			}

			no_of_bits = count * 8;

			// calculates how many "=" to append after res_str.
			padding = no_of_bits % 3;

			// extracts all bits from val (6 at a time)
			// and find the value of each block
			while (no_of_bits != 0)	{
				// retrieve the value of each block
				if (no_of_bits >= 6)
				{
					temp = no_of_bits - 6;
					
					// binary of 63 is (111111) f
					index = (val >> temp) & 63;
					no_of_bits -= 6;		
				}
				else
				{
					temp = 6 - no_of_bits;
					
					// append zeros to right if bits are less than 6
					index = (val << temp) & 63;
					no_of_bits = 0;
				}
				res_string[k++] = char_set[index];
			}
	}

	// padding is done here
	for (i = 1; i <= padding; i++){
		res_string[k++] = '=';
	}

	res_string[k] = '\0';

	return res_string;

}


int main()
{
	char *input_string;
	int size;

	printf("\nPlease enter the size of string greater than 1: ");
	scanf("%d", &size);						//Take the size value from the user

	printf("%d\n", size);
	input_str = (char *)malloc((size+1) * sizeof(char));		// Takes size * 1 byte

	printf("\nPlease enter someting: ");
	scanf("%s", input_string); 					// Take the string from the user for encoding
	
	printf("Input string is : %s\n", input_string);
	printf("Encoded string is : %s\n", base64Encoder(input_string, size));
	return 0;
}

