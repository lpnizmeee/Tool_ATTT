import math
p=int(input("Enter Module Zp= "))
temp=1
while(temp==1):
    g=int(input("Enter phan tu sinh <g>= "))
    z=[]
    for i in range(p-1):
        z.append(pow(g,i)%p)
    print(z)
    temp=int(input("""    An 1 de tiep tuc kiem tra
    An 0 de thoat
    ==>  Enter: """))
    if(temp==0):
        break