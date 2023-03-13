print(" ")
print("(a0 x a1 x a2 x ... x an-1) mod p = ???")
p=int(input("Enter p="))
print(" ")
n=int(input("Enter n= "))

print(" ")
z=[]
for i in range(n):
    z.append(int(input("Enter a"+str(i)+" = ")))
multi=1
for i in range(n):
    multi=multi*z[i]
print(" ")
print("a(n) mod p = "+str(multi%p))
print(" ")