#include <stdio.h>
#include <algorithm>

	void linearseach (int a[], int n, int x){

		for (int i =0; i <n; i++){
			if( a[i]== x ){
				printf ("Found");
				return;
		}
	}
}
	void binarysearch(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) {
            printf("Found at index %d", m);
            return;
        } else if (a[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    printf("Not found");
}
	int main(){
		int a[1000], n,x ; 
			scanf ("%d",&n);
		scanf ("%d",&x);
		for (int i =0; i < n; i ++){
			scanf ("%d",&a[i]);
		}
		//linearseach (a , n , x);
		binarysearch (a, n , x);
		return 0;
	}
