#include <stdio.h>


//kieu struct chua nam sinh va so luong nguoi sinh trong nam
typedef struct  {
	int date, number;
} Born;

//Ham xem co xuat hien phan tu x trong mang a khong, tra ve chi so
int binary_search(Born a[], int n, int x){
     int l = 0, r = n - 1;
    while(l<=r) {
       
        int m = (l + r) / 2;
        if(a[m].number == x){
            return m; } 
        else if(a[m].number < x){
            
            l = m + 1;
        }
        else{
          
            r = m - 1;
        }
    } 
    return -1;
}


//-------------------------------------------------------------------------------------------------------------------------


// count[] chi so dem tuong ung vi tri cua moi nam sinh, neu nam sinh co so luong nguoi can tim thi tang bien dem

// Ham tim tat ca vi tri xuat hien phan tu x trong mang a
void CountBS(Born a[], int n, int x, int count[]) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m= (l + r) / 2;
        
        if (a[m].number == x) {
            count[m]++;
            ;
            
        //tim phia ben trai xem co su xuat hien cua x nua khong
            int left = m - 1;
            while (left >= 0 && a[left].number == x) {
                count[left]++;
                left--;
            }
            
            //tim phia ben phai xem co su xuat hien cua x nua khong
            int right = m + 1;
            while (right < n && a[right].number == x) {
                count[right]++;
                right++;
            }
            
          break;
        }
        else if (a[m].number < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
   
}

//-------------------------------------------------------------------------------------------------------------------------


int FoundMax(Born a[], int n)
 { int index = 0;
 	for (int i = 1; i<n; i++) {
 		if(a[i].number>a[index].number) index=i;
	 }
	 return index;
 }
 
int FoundMin(Born a[], int n)
 { int index = 0;
 	for (int i = 1; i<n; i++) {
 		if(a[i].number < a[index].number) index = i;
	 }
	 return index;
 }
 

//-------------------------------------------------------------------------------------------------------------------------


int main() {

     Born People[51] = {{1920, 19}, {1921, 77}, {1922, 40}, {1923, 90}, {1924, 2}, { 1925, 25}, {1926, 54},
	{1927, 17}, {1928, 79}, {1929, 6}, {1930, 44}, {1931,24}, {1932, 14}, {1933, 4}, {1934, 95}, {1935, 47}, {1936, 66}, 
	{1937, 48}, {1938, 23}, {1939, 98}, {1940, 15}, {1941, 86}, {1942, 25}, {1943, 50}, {1944, 9}, {1945, 29}, {1946, 64}, {1947, 3},
	{1948, 67}, {1949, 4}, {1950, 90}, {1951, 81}, {1952, 74}, {1953, 34}, {1954, 98}, {1955, 13}, {1956, 87}, {1957, 96}, {1958, 56},
	 {1959, 90}, {1960, 49}, {1961, 85}, {1962, 94}, {1963, 66}, {1964, 19}, {1965, 95}, {1966, 47}, {1967, 42}, {1968, 65}, 
	{1969, 87 }, {1970, 11}
	};
	
	//-------------------------------------------------------------------------------------------------------------------------
	
	
	int count[51]={0};
    int x; 
	printf("Nhap so can tim x la: "); scanf("%d", &x);
	
    CountBS(People,51,x,count);
    //tim k thay x thi in ra not found
    int i = 0;
    while (i<51) { 
	if(count[i]!=0) {
    printf("So nam co cung so luong %d la: ",x); 
    break; }
    i++;
    if(i==51) printf("Not Found");
	 }
    
    for (int i = 0; i<51;i++) {
    	if (count[i]!=0) printf("%d ", People[i].date);
}

	
	//--------------------------------------------------------------------------------------------------------------------------
  
	
	// tim max, min
   
   printf("\nNam nguoi sinh nhieu nhat va it nhat la: %d va %d \n", People[FoundMax(People,51)].date, People[FoundMin(People,51)].date);
   

   return 0;
}



	
   
