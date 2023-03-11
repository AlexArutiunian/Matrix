import numpy as np



v = []
n = 100
with open('gen_m.txt') as file:
    с = 0
   
    
    for i in range(0, n * n):
        
        v.append(int(file.readline()))



print(v)

a = np.eye(n)



for i in range(0, n):
    for j in range(0, n):
        a[i, j] = v[i * n + j]

print(a)    

det = np.linalg.det(a)
print(det)


       

