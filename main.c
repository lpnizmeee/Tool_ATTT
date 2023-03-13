#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "OTP.h"
#include "LuyThuaSoDu.h"
#include "RSA_giai_ma.h"
#include "Euclid.h"
#include "Elliptic.h"

int main()
{
    int menu, temp;
    int sigma6, n6, e6, m6;

    char cmd[100];
    do
    {
        printf("\n====================================================\n");
        printf("                    THI GK ATTT                   \n");
        printf("----------------------------------------------------\n");
        printf("1. Ma Hoa OTP\n");
        printf("2. Logarit roi rac Dlog(g) (x)\n");
        printf("3. Logarit roi rac DH g (ga,gb)\n");
        printf("4. tinh so du luy thua (a ^ b) mod m\n");
        printf("5. Kiem tra phan tu sinh cua Module Z\n");
        printf("6. RSA Kiem tra so do chu ky (cho n va e)\n");
        printf("7. RSA Giai ma ban ro (cho p,q,e,y  => tim x)\n");
        printf("8. ElGamal tim chu ky \n");
        printf("9. Euclid de tinh a^-1\n");
        printf("10.Duong cong Elliptic <co menu ben trong>\n");
        printf("0. Exit \n");
        printf("----------------------------------------------------\n");
        printf("Your choose: ");
        scanf("%d", &menu);
        printf("====================================================\n");
        printf("\n");
        switch (menu)
        {
        case 1:
            OTP();
            break;
        case 2:
            printf("====================================================\n");
            strcpy(cmd, "py Logaritroirac_1bien.py");
            system(cmd);
            printf("----------------------------------------------------\n");
            printf("Press Enter...\n");
            printf("====================================================\n");
            getch();
            break;
        case 3:
            printf("====================================================\n");
            strcpy(cmd, "py Logarit_roi_rac_2bien.py");
            system(cmd);
            printf("----------------------------------------------------\n");
            printf("Press Enter...\n");
            printf("====================================================\n");
            getch();
            break;
        case 4:
            LuyThuaSoDu();
            printf("Press Enter...\n");
            getch();
            break;
        case 5:
            printf("====================================================\n");
            strcpy(cmd, "py PhanTuSinh.py");
            system(cmd);
            printf("----------------------------------------------------\n");
            printf("Press Enter...\n");
            printf("====================================================\n");
            getch();
            break;
        case 6:
            printf("====================================================\n");
            printf("Enter n: ");
            scanf("%d", &n6);
            printf("Enter e: ");
            scanf("%d", &e6);
            printf("----------------------------------------------------\n");
            do
            {
                printf("Enter Sigma: ");
                scanf("%d", &sigma6);
                printf("----------------------------------------------------\n");
                printf("   ( n=%5d, e=%2d)   =>  ( m=%5d, sigma=%5d)\n", n6, e6, modpow(sigma6, e6, n6), sigma6);
                printf("----------------------------------------------------\n");
                do
                {
                    printf("Press 1 to continue, press 0 to exit...\n");
                    scanf("%d", &temp);
                } while (temp != 1 && temp != 0);
                printf("----------------------------------------------------\n");

            } while (temp != 0);
            printf("====================================================\n");
            break;
        case 7:
            printf("====================================================\n");
            strcpy(cmd, "py RSA_giai_ma.py");
            system(cmd);
            printf("----------------------------------------------------\n");
            printf("Press Enter...\n");
            printf("====================================================\n");
            getch();
            break;
        case 8:
            do
            {

                printf("====================================================\n");
                strcpy(cmd, "py ElGamal.py");
                system(cmd);
                printf("----------------------------------------------------\n");
                do
                {
                    printf("Press 1 to continue, press 0 to exit...\n");
                    scanf("%d", &temp);
                } while (temp != 1 && temp != 0);
                printf("----------------------------------------------------\n");
            } while (temp != 0);
            break;
        case 9:
            Euclid_tinhtoan();
            break;
        case 10:
            printf("====================================================\n");
            EllipticCurve();
            printf("====================================================\n");
            break;
        case 0:
            break;
        default:
            printf("Chon lai!!!\n");
            break;
        }
    } while (menu != 0);
}