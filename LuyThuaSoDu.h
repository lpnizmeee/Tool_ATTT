/*#include <iostream>
#include <cstdint>*/
#include <stdio.h>
// Calculate (a * b) mod m
int modmul(int a, int b, int m)
{
    return (a * b) % m;
}

// Calculate (a ^ e) mod m
int modpow(int a, int e, int m)
{
    int ret = e % 2 ? a : 1;
    while (e >>= 1)
    {
        a = modmul(a, a, m);
        if (e % 2) ret = modmul(ret, a, m);
    }
    return ret;
}

void LuyThuaSoDu(){
    int a,e,m;
    printf("====================================================\n");
    printf("Calculate (a ^ e) mod m...\n");
    printf("Enter a = ");scanf("%d",&a);
    printf("Enter e = ");scanf("%d",&e);
    printf("Enter m = ");scanf("%d",&m);
    printf("----------------------------------------------------\n");
    printf("(%d ^ %d) mod %d = %d\n",a,e,m,modpow(a, e, m));
    printf("====================================================\n");
}
