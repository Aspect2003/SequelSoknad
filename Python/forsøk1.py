#1a
def midtpunkt(a, b): 
    return (a + b) / 2.0

a = float(input("Oppgi målet til a: "))
b = float(input("Oppgi målet til b: "))

resultat = midtpunkt(a, b)

print("Midtpunktet mellom", round(a), "og", round(b), "er:", round(resultat)
      
#%%
#1b
def vektetPunkt(a, b, c):
    return a * (1 - c) + b * c

a = float(input("Verdien til a: "))
b = float(input("Verdien til b: "))
c = float(input("Verdien til c: "))

resultat = vektetPunkt(a, b, c)

print("Lineærkombinasjonen av", a, "og", b, "med vekting", c, "er", resultat)

#%%
#1c
a = 4
b = 6

c_vals = np.linspace(0, 1, 101)

for c in c_vals:
    print(vektetPunkt(a, b, c))    
#%%
#2a
def finn_antall(arr):
    minimum = 0.4
    maksimum = 0.5
    antall = 0
    for n in arr:
        if n >= minimum and n <= maksimum:
            antall += 1
        return antall
arr1 = np.random.rand(100)
ant = finn_antall(arr1)
print("Det er", ant, "tall i arrayet som er på intervallet [0.4, 0.5]")

#%%
#2b
def finnIndex(arr):
    indeksliste = []
    for i in range(len(arr) - 1):
        if arr[i] > arr[i + 1]:
            indeksliste.append(i)
    return indeksliste

arr1 = [1, 3, 2, 4, 3, 5]
indekser = finnIndex(arr1)
print(f"Indekser hvor arr1[i] > arr1[i + 1]: {indekser}")
#%%
#3
import numpy as np

num_simulations = 10000

deltakere = 19 * ["L"] + 3 * ["F"]

def simuler_trekning():
    valg = np.random.choice(deltakere, 3, False)
    antall_lojale = sum(1 for person in valg if person == "L")
    return antall_lojale >= 2

suksesser = sum(simuler_trekning() for _ in range(num_simulations))

sannsynlighet = suksesser / num_simulations

print(f"Sannsynligheten for at minst 2 av de 3 valgte er lojale: {sannsynlighet:.4f}")

#%%

def korde(R, h):
    return np.sqrt(4*(2*h*R-h**2))

R = 123.9
K = 135
h = 0

while(K > korde(R, h)):
    h += 0.1

print("Høyden som gir korden K=", K, "er h=", h)