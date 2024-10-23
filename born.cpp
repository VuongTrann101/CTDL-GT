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

//-------------------------------------------------------------------------------------------------------------------------


// Ham dem so lan xuat hien phan tu x trong mang a
int CountBS(int a[], int n, int x) {
    int l = 0, r = n - 1, count = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        
        if (a[m] == x) {
            
            count++;
            
        //tim phia ben trai xem co su xuat hien cua x nua khong
            int left = m - 1;
            while (left >= 0 && a[left] == x) {
                count++;
                left--;
            }
            
            //tim phia ben phai xem co su xuat hien cua x nua khong
            int right = m + 1;
            while (right < n && a[right] == x) {
                count++;
                right++;
            }
            
          break;
        }
        else if (a[m] < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return count;
}

//-------------------------------------------------------------------------------------------------------------------------

int FoundMax(int a[], int n)
 {
 	for (int i = 0; i<n; i++) {
 		if(a)
	 }
 }
//-------------------------------------------------------------------------------------------------------------------------

//kieu struct chua nam sinh va so luong nguoi sinh trong nam
typedef struct  {
	int date, number;
} Born;

//-------------------------------------------------------------------------------------------------------------------------

int main() {

     Born People[52] = {{1920, 19}, {1921, 77}, {1922, 40}, {1923, 90}, {1924, 2}, { 1925, 25}, {1926, 54},
	{1927, 17}, {1928, 79}, {1929, 6}, {1930, 44}, {1931,24}, {1932, 14}, {1933, 4}, {1934, 95}, {1935, 47}, {1936, 66}, 
	{1937, 48}, {1938, 23}, {1939, 98}, {1940, 15}, {1941, 86}, {1942, 25}, {1943, 50}, {1944, 9}, {1945, 29}, {1946, 64}, {1947, 3},
	{1948, 67}, {1949, 4}, {1950, 90}, {1951, 81}, {1952, 74}, {1953, 34}, {1954, 98}, {1955, 13}, {1956, 87}, {1957, 96}, {1958, 56},
	 {1959, 90}, {1960, 49}, {1961, 85}, {1962, 94}, {1963, 66}, {1964, 19}, {1965, 95}, {1966, 47}, {1967, 42}, {1968, 65}, 
	{1969, 87 }, {1970, 11}
	};
	
	//-------------------------------------------------------------------------------------------------------------------------
	
	int dem[52]={0};//mang dem co chi so tuong ung voi chi so cua mang dang xet
	
   for (int i = 0; i < 51;i++) {
   	
   	 for (int j = i+1; j < 52; j++) {
   	 	
   	 	if (People[i].number==People[j].number) {
		     dem[i]++;//xuat hien phan tu number giong nhau thi tang gia tri bien dem tai phan tu i
			                               }
		}
   }
   
   //-------------------------------------------------------------------------------------------------------------------------
   //in ra nhung nam co cung so luong nguoi sinh trong list
   int i;
   printf("So nam sinh co so luong nguoi sinh giong nhau la: \n"); 
   for (int i = 0; i < 52; i++) {
	   int j = i+1;
   	    if (dem[i]!=0) { 
		   printf("So nam sinh co so luong nguoi sinh %d la: %d ", People[i].number, People[i].date); 
   	    while(j<52) {
		   
   	if (People[i].number==People[j].number) {
   		printf("%d ", People[j].date ); }
   		j++;
	   }  
	   printf("\n");
	   
	   } }
	   
	// ---------------------------------------------------------------------------------------------------------------------------- 

	//tim trong mang nhung nam co so luong nguoi sinh theo yeu cau
	
	int x, dem[52] = 0; //reset bien dem 
	printf("Nhap so can tim: "); scanf("%d", &x); // nhap so number can tim
    	if(binary_search(People,52,x)) {
    	printf("Found\n"); 
    	
   	//liet ke so nam co cung x can tim
   	 for (int i = 0; i < 51;i++) {
   	 	if (People[i].number==x) 
   	 	
		     dem[i]++;//xuat hien phan tu number giong nhau thi tang gia tri bien dem tai phan tu i
		     
			  if(dem[i]!=0) printf("%d ",People[i].date); }                        
}        else printf("Not found/n");
	
	
	//---------------------------------------------------------------------------------------------------------------------------
   
   // tim max, min 
   int 
   
   return 0;
}
