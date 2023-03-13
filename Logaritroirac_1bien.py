import math
print("   Module Z*(p)")
print("   D_log(g) (x) = dap an")
p=int(input("Nhap vao Module p: "))
g=int(input("Nhap vao co so g: "))
x=int(input("Nhap vao x: "))
for i in range(0,1000):
    if(g**i%p==x):
        print("===> D_log(",g,") (",x,") = ",i)
        break