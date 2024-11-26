import numpy as np
def finnAntall(arr1):
    antall = 0
    for element in arr1:
        if element >= 0.4 and element <= 0.5:
            antall += 1
    return antall


arr1 = np.random.rand(100)
ant = finnAntall(arr1)
print("Det er", ant, "tall i intervallet [0.4, 0.5] i arr1")

def finnIndex(arr1):
    for index in range(len(arr1)-1):
        if arr1[index] > arr1[index + 1]:
            print(index)

        
def finnAntallElement(arr1):
    sum = 0
    index = 0
    while sum < 25:
        sum += arr1[index]
        index += 1
    return index

elem = finnAntallElement(arr1)
print(elem)

#%%

utfallsrom = 3*['F']+19*['L']
n = 100000
gunstige = 0

for i in range(n):
    svar = np.random.choice(utfallsrom, 3, False)
    """
    if((svar[0] =='L' and svar[1] == 'L') or
      (svar[0] == 'L' and svar[2] == 'L') or
      (svar[1] == 'L' and svar[2] == 'L'):
    """
    ant = 0
    for person in svar:
        if person == 'L':
            ant += 1 
    if ant >= 2:
        gunstige += 1
    
sannsynlighet = gunstige/n
print("Sannsynligheten for at 2 av 3 er lojale er", sannsynlighet)


