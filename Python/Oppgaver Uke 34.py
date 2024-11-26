#%%
# Oppgave 3.1
beløp = 10000
rente = 1.85
verdi = beløp*(1 + 1.85/100)**5
print(f'{verdi:.2f}')

#%%
# Oppgave 3.2
"""
numpy.floor eller np.floor er en funksjon som runder et tall ned til det nærmeste heltallet 
og det største heltallet.

np.ceil er en lik funksjon som runder et tall ned til det nærmeste heltallet
men denne gangen til det laveste heltallet.
"""

import numpy as np

a = np.array([1.5, 6.8, 2.3, 1.49])
result = np.floor(a)
print(result)

result2 = np.ceil(a)
print(result2)

#%%
import numpy as np
# Oppgave 3.3


xA, xB = 2.3, 7.4
yA, YB = 8.1, -13.5

avstand = np.sqrt((xB - xA)**2 + (yB - yA)**2)
print(f'{avstand:.3e}') 

#%%

# Oppgave 3.4
import numpy as np

xA = float(input("Skriv inn x-koordinatet for punkt A: "))
yA = float(input("Skriv inn y-koordinatet for punkt A: "))
xB = float(input("Skriv inn x-koordinatet for punkt B: "))
yB = float(input("Skriv inn y-koordinatet for punkt B: "))

avstand = np.sqrt((xB - xA)**2 + (yB - yA)**2)
print(f'{avstand:.3e}') 
#%%

# Oppgave 3.5
import numpy as np

radius = float(input("Skriv inn radiuesen til kulen: "))
volum = (4/3)*np.pi*radius**3
overflate = 4*np.pi*radius**2

print("Volumet til kulen er", f'{volum:.1f}')
print("Overflaten til kulen er", f'{overflate:.1f}')

#%%

#Oppgave 3.6

import numpy as np


a, c = 7, 6

b = np.sqrt(a**2 - c**2)

print("Den store kateten av trekanten er", round(b, 2))

A = (1/2)*a*b
O = a + b + c

print("Arealet av trekanten er", round(A, 2), "og overflaten til trekanten er", round(O, 2))

#%%
# oppgve 3.7
import numpy as np

c = float(input('Lengden av c ='))
a = float(input('Lengden av a ='))

b = np.sqrt(a**2 - c**2)

v1 = np.arctan(c/a)
v2 = np.arctan(a/c)
v3 = np.pi/2 
print("Test av vinkler som skal være 180 grader =", round(np.degrees(v1 + v2 + v3)))

print("Vinklene i rad er: ",
      f'{v1:.4f},',
      f'{v2:.4f},',
      f'{v3:.4f},')

print('Vinklene i grader er:',
      f'{np.degrees(v1):.1f},',
      f'{np.degrees(v2):.1f},',
      f'{np.degrees(v3):.1f}')

#%%
import numpy as np

#oppgave 3.8

odd = (1, 3, 5, 7, 9, 11, 13)
primes = (2, 3, 5, 7, 11, 13)

mix = odd + primes

print('11 kommer', mix.count(11), 'ganger i mix')
print('14 i mix er', 14 in mix)

#%%
import numpy as np
# oppgave 3.9
pannekaker = {'hvetemel' : '3 dl',
              'salt' : '0.5 ts',
              'egg' : '4',
              'melk' : '6 dl',
              'smør' : '2ss'
              }
print(pannekaker.values())
print(pannekaker.keys())

#%%
#oppgave 3.14
import numpy as np

xstart = 0.0
ystart = 0.0

xend = float(input('Skriv inn x-koordinatene for neste destinasjon'))
yend = float(input('Skriv inn y-koordinatene for neste destinasjon'))

avstand1 = np.sqrt((xend-xstart)**2 + (yend - ystart)**2)
print('Avstand1 =', avstand1)

xstart = xend
ystart = yend

xend = float(input('x.koord for neste destinasjon'))
yend = float(input('y-koord for neste destinasjon'))

avstand2 = np.sqrt((xend-xstart)**2 + (yend - ystart)**2)
print('Avstand2 =', avstand2)
    

print('Total avstand er', 
      avstand1 + avstand2)

#%%
















