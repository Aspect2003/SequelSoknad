#1a
import numpy as np
def midtpunkt(a,b):
    return (a+b)/2

#b

def vektetPunkt(a,b,c):
    return a*(1-c)+b*c 

a = 4
b = 5
c = 0.54

verdi = vektetPunkt(a, b, c)

print("Lineærkombinasjoen av x og y ved c:", c, "er:", verdi)

#c 
c_v = np.linspace(0, 1, 101)
for c in c_v:
    print(vektetPunkt(a, b, c))

#%%
#2a
def finnAntall(arr):
    mini = 0.4
    maksi = 0.5
    antall = 0
    for n in arr:
        if n >= mini and n <= maksi:
            antall += 1
        return antall
    
    arr1 = np.random.rand(100)
    ant = finnAntall(arr1)
    print("Antall tall mellom [0.4, 0.5] i arr1 er:", ant)
    
    