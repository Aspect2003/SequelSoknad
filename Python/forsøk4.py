import numpy as np

#1a
def midtpunkt(a,b):
    return (a+b)/2
a = 2
b = 10
print("Midtpunkt mellom", a, "og", b, "er", midtpunkt(a, b))

#%% b
def vektetPunkt(a,b,c):
    return a*(1-c)+b*c

a = 2
b = 7
c = 0.6

verdi = vektetPunkt(a, b, c)

print("Lineærkombinasjonen av x når a er", a, "og b er", b, "og c er", c, "blir", verdi)

#%% c
import numpy as np

a = 4
b = 9

c_verdi = np.linspace(0,1,101)

for c in c_verdi:
    print(vektetPunkt(a, b, c))

#%%
#2a
import numpy as np

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

print("Det ligger", ant, "tall på intervallet [0.4, 0.5]")

#
#2b

def finnIndex(arr):
    for i in range(arr.size-1):
        if(arr[i] > arr[i+1]):
            print(i)
            
finnIndex(arr1)

# c

def finnAntallElement(arr):
    antall = 0
    index = 0
    while antall < 25:
        antall += arr[index]
        index += 1
    return index 

print("Det måtte", finnAntallElement(arr1), "elementer for å nå 25 som sum")

#%%
import numpy as np

#3

deltakere = 3*[0]+19*[1]

n = 10000
gunstige = 0

for i in range(n):
    svar = np.random.choice(deltakere, 3, False)
    if sum(svar) >= 2:
        gunstige += 1 

print("Sannsnyligheten for 2 av 3 er lojale er", gunstige/n)    
    

#%%
#4
import numpy as np

def korde(h,r):
    return np.sqrt(4*(2*h*r-h**2))

h = 0
k = 135
r = 123.9

while(k > korde(h,r)):
    h += 0.1
    
print(h)
