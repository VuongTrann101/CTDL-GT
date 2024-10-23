#include <stdio.h>


//Ham xem co xuat hien phan tu x trong mang a khong
int binary_search(int a[], int n, int x){
     int l = 0, r = n - 1;
    while(l<=r) {
       
        int m = (l + r) / 2;
        if(a[m] == x){
            return 1; } 
        else if(a[m] < x){
            
            l = m + 1;
        }
        else{
          
            r = m - 1;
        }
    } 
    return 0;
}
// Ham dem so lan xuat hien phan tu x trong mang a
int CountBS (int a[], int n, int x) {
	int l = 0, r=n-1, count = 0;
	while (l<=r) {
		int m=(r+l)/2;
		if (a[m]==x)  count++;
		
		else if (a[m] < x) {
			l = m+1;
		}
		else {
		 r = m - 1;
		}
	}
	return count;
}

