#include <stdio.h>
	void swap (int a[],int i , int j){
		int temp =  a[i] ;
		 a[i] = a[j];
		 a[j] = temp;
	}
	void swap2 ( int a[], int j , int j1){
		int temp = a[j];
		a[j] = a[j+1];
		a[j+1] = temp;
	}
	void selectionsort ( int a[], int n){
		for (int i=0; i < n-1;i++){
			int min = i; 
			for (int j =i +1; j<n;j++){
				if (a[j]<a[min]){
					min = j; 
				}
			}
			swap(a,i , min );
		}
	}
	void bubblesort (int a[], int n ){
		for (int i = 0; i < n; i ++){
			for (int j = 0; j < n - i -1; j ++){
				if (a[j]>a[j + 1]){
					swap2 (a,j,j+1);
				}
			}
		}
	}
	int main(){
		int a[1000], n;
		scanf ("%d",&n);
		for (int i=0;i <n;i++){
			scanf ("%d",&a[i]);
		}
		//selectionsort(a, n ); 
		bubblesort (a, n );
		for (int i =0; i <n; i++){
			printf ("%d ",a[i]);
		}
		return 0;
	}
