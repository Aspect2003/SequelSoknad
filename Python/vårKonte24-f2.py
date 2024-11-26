#a
def prosentvisEndring(c,d):
    return 100*((d-c)/c)

c = 0
d = 7
svar = prosentvisEndring(c, d)

print("Den prosentvise endringen ved c", c, "og d", d, "er", svar)
#%% b
def prosentvisEndring(c,d):
    if c == 0:
        print("0 er ikke en gyldig verdi")
    return 100*((d-c)/c)

c = 0
d = 3
svar2 = prosentvisEndring(c, d)
print("Den prosentvise endringen ved c", c, "og d", d, "er", svar)

#%%
#2a
import numpy as np

def lagDatapunkt(x_stop):
    x1 = np.zeros(x_stop)
    x2 = np.zeros(x_stop)
    for i in range(1, x_stop):
        x1[i] = i
        x2[i] = (i-1)/i
    return x1, x2        
    
        
#%%
import numpy as np
def finnAntall(arr1):
    antall = 0
    for n in arr1:
        if n < 0:
            antall += 1
        return antall
    
arr1 = np.random.uniform(-1,1,150)
svar = finnAntall(arr1)
            
print("Antall tall som er mindre enn 0 er", svar)

def finnIndex(arr1):
    antall = 0
    index = 0
    while antall < 10:
        if arr1[index] < 0:
            antall += 1 
        index += 1
    return index
svar2 = finnIndex(arr1)
print("Det tiende negative tallet på index er", svar2,)

                                                                                           
def finnPositivSum(arr1):
    sum = 0
    antall_elementer = 0
    for tall in arr1:
        if tall > 0:
            sum += tall
            antall_elementer += 1
        if sum >= 15:
            return antall_elementer
        return "Summen av alle positive elementer er under 15"
    
print("man må summere de", finnPositivSum(arr1), "første positive elementene for at sumen skal bli over 15.")

#%%
#4
import numpy as np


x_v = np.linspace(0, np.sqrt(10), 1000)
max_v = 0

for x in x_v:
    y = 10-x**2
    if x + y > max_v:
        max_v = x + y
        
print(max_v)
