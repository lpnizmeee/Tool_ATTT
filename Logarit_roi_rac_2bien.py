p=int(input("Nhap vao Module: "))
g=int(input("Nhap vao phan tu sinh: "))
g_bandau=g
z=[]
for i in range(p-1):
    z.append(g**i%p)
print (z)
ga=int(input("Nhap vao g^a: "))
gb=int(input("Nhap vao g^b: "))
key=1
isDlogB = False 
for i in range(p-1):
    if(z[i]==ga):        
        key*=i
        break
    if(z[i]==gb):
        key*=i
        isDlogB = True 
        break
if isDlogB: 
    print("DH",g_bandau,"(",ga,",",gb,") = ",ga**key%p)
else:
    print("DH",g_bandau,"(",ga,",",gb,") = ",gb**key%p)
