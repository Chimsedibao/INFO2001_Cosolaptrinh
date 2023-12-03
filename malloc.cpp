#include <stdio.h>
#include <stdlib.h>

	int main(){
		int *ptr = (int*)malloc(1000  *  sizeof(int) );
		int n = 5; 
		for (int i = 0; i < 5; i ++){
			scanf ("%d",ptr);
		}
		free(ptr);
	return 0;
	}
