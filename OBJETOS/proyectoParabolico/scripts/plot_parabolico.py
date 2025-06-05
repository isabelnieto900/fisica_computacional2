import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt('results/datos.dat', skiprows=1)
plt.plot(data[:,1], data[:,2])
plt.title("Trayectoria del proyectil")
plt.xlabel("x (m)")
plt.ylabel("y (m)")
plt.grid(True)
plt.show()
