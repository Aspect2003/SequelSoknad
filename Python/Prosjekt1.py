#%%
#Oppgave 1
import numpy as np

alder = int(input('Hvilket år er du født? '))

nåværende_år = 2024
alder_i_2024 = nåværende_år - alder

print(f'Du blir {alder_i_2024} år i løpet av {nåværende_år}.')

#%%
#Oppgave 2

antall_elever = int(input('Skriv inn antall elever: '))

pizza_per_elev = 1 / 4
totalt_pizzaer = antall_elever * pizza_per_elev

pizzaer_å_kjøpe = round(np.ceil(totalt_pizzaer))

print(f'Du må kjøpe {pizzaer_å_kjøpe} pizzaer til klassefesten.')

#%%
#Oppgave 3

def grad2rad(v_g):
    v_r = v_g*np.pi/180
    return v_r

v_g = float(input('Skriv inn gradtallet:'))

v_r = grad2rad(v_g)

print(f'{v_g:.0f} grader er lik {v_r:.3f} i radianer.')

#%%
#Oppgave 4
def areal_omkrets(a, b):
    areal_trekant = (a*b) / 2
    radius_halvsirkel = a / 2
    areal_halvsirkel = (np.pi *radius_halvsirkel**2) / 2
    total_areal = areal_trekant + areal_halvsirkel
    
    hypotenus = np.sqrt(a**2 + b**2)
    omkrets_halvsirkel = np.pi * radius_halvsirkel
    ytre_omkrets = a + b + hypotenus + omkrets_halvsirkel
    
    return total_areal, ytre_omkrets

a = float(input("Skriv inn lengden til a: "))
b = float(input("Skriv inn lengden til b: "))

areal, omkrets = areal_omkrets(a, b)

print(f"Arealet av figuren er: {areal:.2f}")
print(f"Den ytre omkretsen av figuren er: {omkrets:.2f}")

#%%
#Oppgave 5

def reiselengde_og_luftlinje(punkter):
    total_lengde = 0
    for i in range(len(punkter) - 1):
        avstand = np.linalg.norm(np.array(punkter[i+1]) - np.array(punkter[i]))
        total_lengde += avstand

    luftlinje_avstand = np.linalg.norm(np.array(punkter[-1]) - np.array(punkter[0]))

    return total_lengde, luftlinje_avstand

punkter = [(0, 0), (2, 0), (2, 3), (0, 3)]

total_lengde, luftlinje_avstand = reiselengde_og_luftlinje(punkter)

print(f"Reisens totale lengde er: {total_lengde:.2f}")
print(f"Luftlinjeavstanden mellom start- og sluttpunktet er: {luftlinje_avstand:.2f}")
