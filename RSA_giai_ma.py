import math
p = int(input("Nhap vao tham so p = "))
q = int(input("Nhap vao tham so q = "))
n=p*q;
phi_n=(p-1)*(q-1);
e = int(input("Nhap vao Khoa Cong Khai e ="))
d=int
for i in range(1,phi_n+1):
    if(i*e%phi_n)==1:
        d=i
Ban_Ma = int(input("Ban Ma = "))
print("===> Ban ro = ",int(pow(Ban_Ma,d))%n)
#Xét sơ đồ mã hoá RSA được cài đặt 
# các tham số p=13 và q=11. 
# Khoá công khai là e=7. Ta cần giải mã bản mã y=3.
# Ta giải mã được bản rõ x bằng