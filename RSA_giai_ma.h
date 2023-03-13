#include <stdio.h>
#include <math.h>
void RSA_giai_ma(){
    int p,q,n,e,BanMa,phi_n,d,BanRo,temp;
    printf("Nhap vao tham so p = ");scanf("%d",&p);
    printf("Nhap vao tham so q = ");scanf("%d",&q);
    n=p*q;
    phi_n=(p-1)*(q-1);
    printf("n=%d,phi(n)=%d\n",n,phi_n);
    printf("Nhap vao Khoa cong khai e = ");scanf("%d",&e);
    //tim d sao cho d*e %phi(n) == 1
    for(int i=1;i<n;i++){
        if(((i*e)%phi_n)==1){
            d=i;
            break;
        }
    }
    printf("e^-1 trong phi(n) =%d\n",d);
    printf("Ban ma = ");scanf("%d",&BanMa);
    printf("====> Ban Ro = %d\n",(int)pow(BanMa,d)%n);
    do
    {
        printf("Press 1 to continue, press 0 to exit...\n");
        scanf("%d",&temp);
    } while (temp!=1&&temp!=0);
    printf("----------------------------------------------------\n");
    
    printf("====================================================\n"); 
    
}