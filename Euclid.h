#include<stdio.h>
#include<stdlib.h>
void Euclid_tinhtoan(){
    // tinh a^-1 trong module p
    int a,p;
    printf("====================================================\n");
    printf("tinh a^-1 trong module p\n");
    printf("----------------------------------------------------\n");
    printf("Enter a = ");scanf("%d",&a);
    printf("Enter p = ");scanf("%d",&p);
    for(int i=0;i<p;i++){
        if(a*i%p==1)printf("%d^-1 = %d\n",a,i);
    }
    printf("----------------------------------------------------\n");
    printf("Press Enter...\n");
    printf("====================================================\n");
    getch();
    
    
}