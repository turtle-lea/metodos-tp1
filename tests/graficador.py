#! usr/bin/python
from matplotlib.pyplot import *
from numpy import *
from pylab import *

def graficador(fuente,destino,i):
	file = open(fuente)
	s = file.read()
	s.strip('\n')
	s = s.split()
	s = [float(x) for x in s]
	
	alpha = float(s[0])
	iteraciones = [s[x] for x in range(1,len(s),2)]
	valores = [s[x] for x in range(2,len(s),2)]
	#print iteraciones, '\n' 
	#print valores, '\n' 

	t = np.linspace(0.,alpha, 1024, endpoint = True)
	plot(t,t**2 - alpha, "blue")
	plot(iteraciones,valores, "ro")
	savefig(destino+"imagen_"+str(i)+".jpg")





