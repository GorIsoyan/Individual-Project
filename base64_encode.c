#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int *size;
	printf( "Please write the size of array: ");
	scanf("%d",&n);
	size = (int*)malloc (n * sizeof(int));
	printf("\nPlease write the values of array: ");
	for(i = 0; i<size; i++){
		scanf("%d", &size[i]);
	}
	printf("\nThe value of array are: ");

	return 0:
}
