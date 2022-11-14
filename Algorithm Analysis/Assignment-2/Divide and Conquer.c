
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
					
typedef struct	alt_dizi{
	int top;
	int start_idx;
	int end_idx;
}ALTDIZI;

ALTDIZI *max_alt(ALTDIZI *a, ALTDIZI *b, int m);
ALTDIZI *max_alt1(ALTDIZI *a, ALTDIZI *b,	ALTDIZI *c);
ALTDIZI *d_max(int arr[], int l, int m, int r,ALTDIZI *alt);
ALTDIZI *max_Alt_Dizi(int arr[], int l, int r,ALTDIZI *alt );	
void brute_force(int arr[], int n);

int main(){
	
	setlocale(LC_ALL, "Turkish");
	ALTDIZI *alt=(ALTDIZI*) malloc(sizeof(ALTDIZI));
	int n;
	
	printf("\n\n\t\tFaruk Veli ÖZDEMÝR\n\t\t    18011052\n\n");
	
	printf("Dizinin Eleman Sayýsýný Giriniz: ");
	scanf("%d", &n);
	
	int arr[n];
	
	
	printf("Elemanlarý giriniz:\n");
	int i=0;
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	printf("\n--------------Brute Force----------------\n");
	brute_force(arr, n);
	printf("\n--------------Brute Force----------------\n\n\n");
	
	alt->end_idx=n-1;
	alt->start_idx=0;
	alt->top=INT_MIN;
	
	printf("\n--------------Divide and Conquer----------------\n");
	alt=max_Alt_Dizi(arr,alt->start_idx,alt->end_idx,alt);
	printf("Maksimum Toplam :%d\nÝndisler: %d, %d",alt->top,alt->start_idx,alt->end_idx);
	printf("\n--------------Divide and Conquer----------------\n");
	free(alt);
    return 0;
}

ALTDIZI *max_alt(ALTDIZI *a, ALTDIZI *b, int m) {
	
	if(a->top + b->top - m > a->top){
		if(a->top + b->top - m > b->top){
			a->end_idx=b->end_idx;
			a->top=a->top + b->top - m;
			return a;
		}else{
			return b;
		}
	}else{
		if(a->top > b->top){
			return a;
		}else{
			return b;
		}
	}
}

ALTDIZI *max_alt1(ALTDIZI *a, ALTDIZI *b,	ALTDIZI *c) {
	
	if(a->top > b->top){
		if(a->top > c->top){
			return a;
		}else{
			return c;
		}
	}else{
		if(b->top > c->top){
			return b;
		}else{
			return c;
		}
	}
	
}
 
ALTDIZI *d_max(int arr[], int l, int m, int r,ALTDIZI *alt){

	ALTDIZI *alt_l=(ALTDIZI*)malloc(sizeof(ALTDIZI));
	ALTDIZI *alt_r=(ALTDIZI*)malloc(sizeof(ALTDIZI));
	
    int sum = 0,i;
    alt_l->top = INT_MIN;
	alt_l->end_idx=m;
    for ( i = m; i >= l; i--) {
		
        sum = sum + arr[i];

        if (sum > alt_l->top){
        	alt_l->top = sum;
			alt_l->start_idx=i;
		}
			
    }
    sum = 0;
    alt_r->top = INT_MIN;
	alt_r->start_idx=m;
    for (i = m; i <= r; i++) {

        sum = sum + arr[i];

        if (sum > alt_r->top){
        	
            alt_r->top = sum;
            alt_r->end_idx=i;
		}
    }
    return max_alt(alt_l , alt_r , arr[m]);
}
 
ALTDIZI *max_Alt_Dizi(int arr[], int l, int r,ALTDIZI *alt ){

    if (l > r){
      	alt->top=INT_MIN;
    	return alt;
	}
	
	if (l == r){
	    alt->top= arr[l];
	    return alt;
	}
		
    int m = (l + r) / 2;
    return max_alt1(max_Alt_Dizi(arr, l, m - 1,alt),max_Alt_Dizi(arr, m + 1, r,alt),d_max(arr, l, m, r,alt));
    
}
 
 
void brute_force(int arr[], int n){
	int left_i=0;
	int right_i=0;
	int max=INT_MIN;
	int curr=0;
	int i,j;
	for(i=0;i<n-1;i++){
		curr=0;
		for(j=i;j<n;j++){
			curr=curr+arr[j];
			if(curr>max){
				left_i=i;
				right_i=j;
				max=curr;
			}
		}
	}
	printf("Maksimum Toplam: %d\nÝndisler= %d, %d",max,left_i,right_i);
}

