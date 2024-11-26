#%%
# Oppgave 3.12
import numpy as np
navn = ["Eli", "Ola", "Ali", "Ela"]
tlf = [9423234, 9223001, 4756001, 9592676]

input_navn = input("Skriv inn et navn: ")

try: #denne linjen prøver å se om navnet vi gir i inputen over ligger i navne listen
    indeks = navn.index(input_navn)
    print(f"{input_navn} sitt tlf nr er {tlf[indeks]}")
except ValueError: #denne linjen kommer om vi oppgir et navn som ikke er i listen
    print(f"Fant ikke {input_navn} i listen.")

#%%
# Oppgave 3.18

import numpy as np

L = [-2.2, -1, 0, 1.1, 2]
A = np.array(L)
print("L har datatypen: ", type(L))
print("A har datatypen: ", type(A))

print("L =", L)
print("A =", A)
#%%
# Oppgave 3.19

A = (-2.2, -1, 0, 1.1, 2)
L = list(A)
print(L)
print("L er datatypen: ", type(L))

#%%
# Oppgave 3.20
import numpy as np
A1 = np.zeros(5)
A2 = np.ones(5)
A3 = np.zeros(5) + 8.3
A4 = A3 + 1.1

A5 = np.linspace(0, 1, 5)

A6 = np.arange(0, 1, 0.2)
print(A1)
print(A2)
print(A3)
print(A4)
print(A5)
print(A6)

#%%
#Oppgave 3.21
import numpy as np
B = np.zeros(5)
Lengde = len(B)
Shape = B.shape
Size = B.size

print("Lengden på B =", Lengde)
print("Dimensjonen til B =", Shape)
print("Størrelsen til B =", Size)

#%%
# Oppgave 3.22
import numpy as np
C = (0, 10, 20, 30)
x = C[0]
y = C[-1]
z = C[1]
ny_verdi = C[3] + 20
ny_verdi2 = C[0] + 1, C[1] - 9
print(C)
print(x)
print(y)
print(z)
print(ny_verdi)
print(ny_verdi2)

#%%
# Oppgave 3.23
import numpy as np
D = (0, 10, 20, 30)
E = (40, 50)

DE = D + E
print(DE)

#%% 
# Oppgave 3.24
E = (0, 2, 4, 5, 3, 1)
maks = E.index(max(E))
maks_verdi = max(E)

print("Array E = ", E)
print("Index for maks verdi =", maks)
print("Max verdi =", maks_verdi)

#%%
# Oppgave 3.25
import numpy as np
A = np.array([2, 1, 3, 8, 5, 4, 0])

x = 7

best_match = np.argmin(np.abs(x - A))

best_verdi = A[best_match]

print("Array A = ", A)
print("Indeks med best match med ", x ,"er ", best_match)
print("Elementverdi som matcher best = ", best_verdi)

#%%
# Oppgave 3.26
F = np.array([0, 1, 2, 2])
print("F gammel =", F)
F = F + 10
print("F ny =", F)

#%% 
# Oppgave 3.27
import numpy as np
r = (1, 2, 3)
volum0 = (4 / 3) * np.pi * r[0]**3
volum1 = (4 / 3) * np.pi * r[1]**3
volum2 = (4 / 3) * np.pi * r[2]**3

print(round(volum0, 1), "m^3.", "radius =", r[0])
print(round(volum1, 1), "m^3.", "radius =", r[1])
print(round(volum2), "m^3.", "radius =", r[2])