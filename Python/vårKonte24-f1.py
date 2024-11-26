def prosentvisEndring(c,d):
    return 100*((d-c)/c)

c = 5
d = 8

print("Den prosentvise endringen ved c:", c, "og d:", d, "blir:", prosentvisEndring(c, d))

#b
def prosentvisEndring(c,d):
    if c == 0:
        print("Utregning ikke mulig")
    return 100*((d-c)/c)

#%%

def lagDatapunkt(x_stop):
    x1 = np.zeroes(x_stop)
    x2 = np.zeroes(x_stop)
    
    for i in range(x_stop):
        x1[i] = i + 1 
        x2[i] = (i/(i+1))
    return x1, x2

import matplotlib.pyplot as plt
x_stop = 20
x_vals, y_vals = lagDatapunkt(x1,x2)
plt.plot(x_vals, y_vals)

#%%
