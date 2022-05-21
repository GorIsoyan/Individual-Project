#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char* base64Encoder(char *input_string, int len_string) // the base64 function, includes itself the input string from the user and the string size 
{
	char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; // the Base64 encoding table
	
	char *result_string = (char *) malloc(len_string * sizeof(char)); //the result string, which also uses malloc,  len_string is the size, which takes the size from the user, creates 
	
   	 int index; 
	 int no_of_bits = 0;
	 int padding = 0; 
	 int value = 0; 
	 int count = 0;
	 int temp;
   	 int i = 0; 
	 int j = 0;
	 int k = 0;
	
	for (i = 0; i < len_string; i += 3) //the loop take 3 characters at a time from input string and stores in value
		{
			value = 0, count = 0, no_of_bits = 0;

			for (j = i; j < len_string && j < i + 3; j++)
			{
				value = value << 8; // binary data of input string is stored in value, makes empty
				
				value = value | input_string[j]; // stores the characters in value 
				
				count = count + 1; // as we will have less than 3 characters, and every time, it will be added by three,  we need to count how many times our j + 3 was done 
			
			}

			no_of_bits = count * 8; // counts the number of bits

			padding = no_of_bits % 3; // calculates how many "=" to append after result_string, for 3 characters, takes reminder

			while (no_of_bits != 0)	{    // extracts all bits from value (6 at a time) and find the value of each block
				if (no_of_bits >= 6) // retrieve the value of each block
				{
					temp = no_of_bits - 6;
					
					index = (value >> temp) & 63; // binary of 63 is (111111) f
					no_of_bits -= 6;		
				}
				else
				{
					temp = 6 - no_of_bits;
					index = (value << temp) & 63;// append zeros to right if bits are less than 6
					no_of_bits = 0;
				}
				result_string[k++] = char_set[index];
			}
	}

	for (i = 1; i <= padding; i++){ // padding is done here
		result_string[k++] = '=';
	}

	result_string[k] = '\0';

	return result_string;

}


int main()
{
	char *input_string;
	int string_size;

	printf("\nPlease enter the size of string greater than 0: ");
	scanf("%d", &string_size);						//Take the size value from the user, 
										//I tried to take only integer, but it is a big code, and we did not pass during the class, also I have tried to take only bigger than 0, but something went wrong and I left this code like this
	printf("\nThe size is %d\n", string_size);
	input_string = (char *)malloc(string_size * sizeof(char));		// Takes size multyplies by 1 byte

	printf("\nPlease enter someting: ");
	scanf("%s", input_string); 					// Take the string from the user for encoding
	
	printf("\nInput string is: %s\n", input_string);

	printf("\nEncoded string is: %s\n", base64Encoder(input_string, string_size));
	return 0;
}

