import math

x=int(input("Khoa bi mat : "))
p=int(input("Module p = "))
g=int(input("Phan tu sinh g = "))
k=int(input("Khoa tam thoi k = "))
r=g**k%p
inverse_k=pow(k,-1,p-1)
m=int(input("Thong diep m = "))
print(" ")
print(f"===> (r,s) = ({r},{(inverse_k*(m-r*x))%(p-1)})  <copy luon>")
print(" ")