#include <stdio.h>
#include <math.h>
int kt(int a){
	if (a<2) return 0;
	int check=1;
	for (int i=2;i<=sqrt(a);i++){
		if (a%i==0) check ==0;
	}
	return check;
}
int kt2(int a,int b){
	if (a>b || a<1) return 0;
	while (a!=b){
		if (a>b){
			a=a-b;
		}
		else b=b-a;
	}
	if (b==1) return 1;
	else return 0;
}
int main(){
	int p,q,n,o,e,k,d;
	printf("Nhap p\n");
	scanf("%d",&p);
	while (kt(p)==0) {
		printf("p vua nhap khong phai so nguyen to, nhap lai: \n");
		scanf("%d",&p);
	}
	printf("Nhap q\n");
	scanf("%d",&q);
	while (kt(q)==0) {
		printf("q vua nhap khong phai so nguyen to, nhap lai: \n");
		scanf("%d",&q);
	}
	n=p*q;
	o=(p-1)*(q-1);
	printf("phi(n) la %d\n",o);
	printf("Nhap e (Dieu kien : Nguyen to cung nhau voi phi va nho hon phi) :\n");
	scanf("%d",&e);
	while (kt2(e,o)==0) {
		printf("e vua nhap khong thoa man, nhap lai: \n");
		scanf("%d",&e);
	}
	// tim d (1<d<o)
	for (k=1;k<=(o*e-1)/o;k++){
		if ((o*k+1)%e==0) {
			d=(o*k+1)/e;
			printf("k=%d => d=%d\nKhoa cong khai la [%d,%d]\nKhoa mat la [%d,%d]\n=====================\n", k,d,e,n,d,n);
		}
	}
}