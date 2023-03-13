/*
Bài 1: Sơ đồ mã hoá OTP có thể dễ dàng tổng quát trên bộ chữ bất kỳ thay vì chỉ có hai ký
tự .
1. Mô tả bộ mã hoá trên bảng chữ a, b, ..., z biểu diễn bởi số . Hàm
mã hoá và giải mã ở đây là gì?
2. Giải mã bản mã
bsaspp kkuosp
biết rằng nó được mã hoá bằng khoá
rsidpy dkawoa
3. Người đàn ông trẻ đã bị giết như thế nào?
===>> bị đâm

Hexa :6c73d5240a948c86981bc294
gui duc 111d

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LENGTH_OTP 50 
#define LENGTH_HEX 12

void OTP(){
    int choose;
    char Ban_ma1[LENGTH_OTP],Khoa[LENGTH_OTP],Ban_ma2[LENGTH_OTP],Hex[LENGTH_HEX],Hex_out[LENGTH_HEX];
    printf("====================================================\n");
    printf("Enter Ban ro 1: ");fflush(stdin); gets(Ban_ma1);
    printf("Enter Hex from Ban Ma 1: ");
    for (int i = 0; i < strlen(Ban_ma1); i++)
    {
        scanf("%2x",&Hex[i]);
    }
    
    printf("|---------------------------------------------------|\n");
    printf("|Enter Ban Ro 2: ");fflush(stdin); gets(Ban_ma2);
    printf("|---------------------------------------------------|\n");
    printf("|====> Hex from Ban Ma 2: ");
    for(int i = 0; i<strlen(Ban_ma1) ; i++ ){
        Khoa[i] =Ban_ma1[i]^Hex[i];
        //printf("%x",[i]+97);
        Hex_out[i] =Ban_ma2[i]^Khoa[i];
        if(Hex_out[i]>9&& Hex_out[i]<16)printf("0");
        printf("%x",Hex_out[i]&0xff);
    }
    printf("\n|                   <cai nay la dap an, hay copy no>|\n");
    printf("|---------------------------------------------------|\n");
    getch();
     
}
