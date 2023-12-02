#include <stdio.h>
		void swap ( int a[], int j , int j1){
		int temp = a[j];
		a[j] = a[j+1];
		a[j+1] = temp;
	}
	
	void sort( int a[] ){
		for (int i = 0 ; i < 10-1; i ++){
			for ( int j = 0 ; j <10 - i - 1;j++ ){
				if ( a[j]> a[j+1] ){
					swap ( a,j, j +1);
				}
			}
		}
	}
	void binarysearch(int a[], int x) {
    int l = 0, r = 10 - 1; 
    int m;

    while (l <= r) {
        m = (l + r) / 2;

        if (a[m] == x) {
            printf("found\n");
            return;
        } else if (a[m] < x) {
            l = m + 1; 
        } else {
            r = m - 1;
        }
    }

    printf("not found\n");
}
	
	int main (){
		int a[10], x ; 
		int *ptr = a;
		for ( int i = 0; i < 10; i ++){
			scanf ( "%d",ptr ); 
			ptr++;
		}
		ptr = a;
		for ( int i = 0; i < 10 ; i ++){
			printf ("%d ",*ptr);
			ptr ++;
		}
		printf ("choose the number need search : ");
		scanf ("%d",&x);
		sort (a);
		binarysearch (a, x);
		return 0;
	}
