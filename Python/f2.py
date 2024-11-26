#1a
def midtpunkt(a,b):
    return (a+b)/2

#b
def vektetPunkt(a,b,c):
    return a*(1-c)+b*c

a = 7
b = 11
c = 0.67

verdi = vektetPunkt(a, b, c)

print("Lineærkombinasjon av x og y når c er", c, "gir verdien", verdi)

#c
c_v = np.linspace(0, 1, 101)

for c in c_v:
    print(vektetPunkt(a, b, c))
#%%
#2a

def finnAntall(arr):
    mini = 0.4
    maks = 0.5
    antall = 0
    for n in arr:
        if n >= mini and n <= maks:
            antall += 1
        return antall

arr1 = np.random.rand(100)
ant = finnAntall(arr1)
print("Det er", ant, "tall i arrayet mellom [0.4, 0.5]")

#b

def finn_index(arr):
    for i in range(arr.size-1):
        if(arr[i] > arr[i+1]):
            print(i)

finn_index(arr1)

#c
def finnAntallElementer(arr):
    sum = 0
    index = 0
    while sum < 25:
        sum += arr[index]
        index += 1
    return index
print("Det måtte", finnAntallElementer(arr1), "elementer for å nå 25 som sum")
#%%
#3

deltakere = 3*[0]+19*[1]

n = 10000
gunstige = 0

for i in range(n):
    utvalgte = np.random.choice(deltakere, 3, False)
    if sum(utvalgte) >= 2:
        gunstige += 1

print("Sannsynligheten for at 2 av 3 kuler er lojale er", gunstige/n)

#%%
#4
def korde(h,r ):
    return np.sqrt(4*(2*h*r-h**2))

r = 123.9
k = 135
h = 0

while(k > korde(h, r)):
    h += 0.1
    
print("Høyden som gir korden:", k, "er h:", h)


        
    