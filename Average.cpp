#include <stdio.h>
float average(float a[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}
	
	
	int main(){
		float a[100];
		int  n ; 
		do{
			printf("So sinh vien trong lop :");
			scanf ("%d",&n);
		}while (n<1 || n > 100);
		for (int i=0; i< n; i ++){
			printf ("Diem ly cua sinh vien thu %d: ",i+1);
			scanf ("%f",&a[i]);
		}
		float ave = average(a,n);
		printf ("Diem Ly trung binh ca lop: %.2f\n",ave);
		return 0; 
	}
