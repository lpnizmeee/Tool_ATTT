#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a;
int p;

typedef struct coordinates
{
    int x;
    int y;
} coor;

coor *list;

// Euclid mo rong
int Euclid(int a0, int b0)
{
    int a[100], b[100], c[100], d, x[100], y[100];
    int check = -1;
    int i = 0, j;

    a[0] = a0;
    b[0] = b0;

    if (a[0] < b[0])
    {
        i++;
        a[1] = b[0];
        b[1] = a[0];
        c[0] = 0;
    }

    // check a mod b
    while (check != 0)
    {
        c[i] = (a[i] - a[i] % b[i]) / b[i];
        a[i + 1] = b[i];
        b[i + 1] = a[i] - c[i] * b[i];
        i++;
        check = b[i];
    }

    j = i;
    d = a[i];
    x[i] = 1;
    y[i] = 0;

    while (i != 0)
    {
        x[i - 1] = y[i];
        y[i - 1] = x[i] - c[i - 1] * y[i];
        i--;
    }

    while (x[0] < 0)
    {
        x[0] += b[0];
    }

    return x[0];
}

// cong hai point
coor Cal_Key(coor point_p, coor point_q)
{
    int x1 = point_p.x,
        y1 = point_p.y,
        x2 = point_q.x,
        y2 = point_q.y,
        x3, y3;
    coor point_pq;
    int s;

    // tinh s
    if (x1 == x2 && y1 == y2)
    {
        s = (3 * x1 * x1 + a) % p;
        s = (s * Euclid(2 * y1, p)) % p;
    }
    else
    {
        s = (y2 - y1) % p;
        int tmp = x2 - x1;
        if (x2 < x1)
        {
            s = s * (-1);
            tmp = tmp * (-1);
        }
        s = s * Euclid(tmp, p) % p;
    }
    while (s < 0)
    {
        s += p;
    }

    // tinh toan x3 va y3
    x3 = (s * s - x1 - x2) % p;
    while (x3 < 0)
    {
        x3 += p;
    }
    y3 = (s * (x1 - x3) - y1) % p;
    while (y3 < 0)
    {
        y3 += p;
    }

    // return
    point_pq.x = x3;
    point_pq.y = y3;
    return point_pq;
}

// tinh theo kieu ban nhi phan
coor Cal_modul(int k, coor point)
{
    if (k == 1)
        return point;
    if (k % 2 == 0)
    {
        coor temp = Cal_modul(k / 2, point);
        return Cal_Key(temp, temp);
    }
    else
    {
        coor temp = Cal_modul(k - 1, point);
        return Cal_Key(temp, point);
    }
}

// ham check he so k
int Create_list(coor point_p)
{
    int i;

    list = (coor *)malloc(sizeof(coor) * 100);
    list[0] = point_p;
    list[1] = Cal_Key(point_p, point_p);
    for (i = 2;; i++)
    {
        if (list[i - 1].x == point_p.x)
            break;
        else
            list[i] = Cal_Key(list[i - 1], point_p);
    }

    return i + 1;
}

int Check(coor point_temp, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (point_temp.x == list[i].x && point_temp.y == list[i].y)
            return i + 1;
    }
}

void Core_default()
{
    coor point_f, point_p, point_pq;
    int b, k, hs;

    // phuong trinh duong cong
    printf("E: y^2 = x^3 + ax + b (mod p)\n");
    printf("a = ");
    scanf("%d", &a);

    printf("b = ");
    scanf("%d", &b);

    printf("p = ");
    scanf("%d", &p);

    // nhap toa do cua phan tu dau tien
    printf("Phan Tu Sinh = (xf, yf)\n");
    printf("\txf = ");
    scanf("%d", &point_f.x);
    printf("\tyf = ");
    scanf("%d", &point_f.y);

    // tao bang
    k = Create_list(point_f);

    // nhap toa do cua P
    printf("P = (xp, yp)\n");
    printf("\txp = ");
    scanf("%d", &point_p.x);
    printf("\typ = ");
    scanf("%d", &point_p.y);

    // nhap he so k
    printf("Nhap he so k\n");
    printf("k = ");
    scanf("%d", &hs);
    int hso = hs;

    // check he so cua aP trong bang
    int coe_P = Check(point_p, k);
    hs = hs * coe_P % k;

    // ghi ra man hinh
    printf("%dP = (%d,%d)\n", hso, list[hs - 1].x, list[hs - 1].y);
}

void Core_abP()
{
    coor point_bP, point_aP, point_p, point_abP, point_f;
    int b, abP, k;

    // phuong trinh duong cong
    printf("E: y^2 = x^3 + ax + b (mod p)\n");
    printf("a = ");
    scanf("%d", &a);

    printf("b = ");
    scanf("%d", &b);

    printf("p = ");
    scanf("%d", &p);

    // nhap toa do cua phan tu dau tien
    printf("Phan Tu Sinh = (xf, yf)\n");
    printf("\txf = ");
    scanf("%d", &point_f.x);
    printf("\tyf = ");
    scanf("%d", &point_f.y);

    k = Create_list(point_f);

    // nhap toa do cua P
    printf("P = (xp, yp)\n");
    printf("\txp = ");
    scanf("%d", &point_p.x);
    printf("\typ = ");
    scanf("%d", &point_p.y);

    // nhap toa do cua aP
    printf("aP = (xaP, yaP)\n");
    printf("\txaP = ");
    scanf("%d", &point_aP.x);
    printf("\tyaP = ");
    scanf("%d", &point_aP.y);

    // nhap toa do bP
    printf("bP = (xbP, ybP)\n");
    printf("\txbP = ");
    scanf("%d", &point_bP.x);
    printf("\tybP = ");
    scanf("%d", &point_bP.y);

    int coe_a, coe_b;
    // check he so cua aP trong bang
    int coe_aP = Check(point_aP, k);
    // check he so cua P trong bang
    int coe_P = Check(point_p, k);
    // tim coefficient a trong aP
    for (coe_a = 1;; coe_a++)
    {
        if (coe_P * coe_a % k == coe_aP)
            break;
    }

    // check he so cua bP trong bang
    int coe_bP = Check(point_bP, k);
    // tim coefficient b trong bP
    for (coe_b = 1;; coe_b++)
    {
        if (coe_P * coe_b % k == coe_bP)
            break;
    }

    // tinh toan abP
    abP = coe_b % k;
    abP = abP * coe_a % k;
    abP = abP * coe_P % k;

    // ghi ra man hinh
    printf("abP  = (%d,%d)\n", list[abP - 1].x, list[abP - 1].y);
}

void Plus_twoPoint()
{
    coor point_q, point_p, point_pq;
    int b, abP;

    // phuong trinh duong cong
    printf("E: y^2 = x^3 + ax + b (mod p)\n");
    printf("a = ");
    scanf("%d", &a);

    printf("b = ");
    scanf("%d", &b);

    printf("p = ");
    scanf("%d", &p);

    // nhap toa do cua P
    printf("P = (xp, yp)\n");
    printf("\txp = ");
    scanf("%d", &point_p.x);
    printf("\typ = ");
    scanf("%d", &point_p.y);

    // nhap toa do cua q
    printf("aQ = (xQ, yQ)\n");
    printf("\txaQ = ");
    scanf("%d", &point_q.x);
    printf("\tyaQ = ");
    scanf("%d", &point_q.y);

    if (point_p.x != point_q.x)
    {
        point_pq = Cal_Key(point_p, point_q);
        printf("P + Q  = (%d,%d)\n", point_pq.x, point_pq.y);
    }
    else
        printf("P + Q = 0\n");
}

void EllipticCurve()
{
    int choose_EC = -1;

    while (choose_EC != 0)
    {
        printf("\n--------------------------------------------------\n");
        printf("1. Tim diem Q = k . P \n");
        printf("2. Tinh abP\n");
        printf("3. Tinh P + Q\n");
        printf("0. Exit\n");
        printf("--------------------------------------------------\n");
    back_EC:
        printf("your choose: ");
        scanf("%d", &choose_EC);
        switch (choose_EC)
        {
        case 1:
            Core_default();
            break;
        case 2:
            Core_abP();
            break;
        case 3:
            Plus_twoPoint();
            break;
        case 0:
            printf("Exit!\n");
            break;
        default:
            printf("Lua chon khong ton tai\n");
            goto back_EC;
            break;
        }
    }
}
