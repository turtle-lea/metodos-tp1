#! usr/bin/python
from matplotlib.pyplot import *
from numpy import *
from pylab import *

with open(sys.argv[1]) as filename:
	leer = filename.read()	
filename.closed

leer = leer.split()
alpha = float(leer[0])
cero_teorico = float(leer[1])

leer = leer[2:]

valores_1 = leer[0:leer.index('H')] #Newton_f

leer = leer[leer.index('H')+1:]

valores_2 = leer[0:leer.index('H')] #Secante_f

leer = leer[leer.index('H')+1:]

#valores_3 = leer[0:leer.index('H')] #Regula_falsi_f

#leer = leer[leer.index('H')+1:]

valores_4 = leer[0:leer.index('H')] #Newton_e

leer = leer[leer.index('H')+1:]

valores_5 = leer[0:leer.index('H')] #Secante_e

#valores_5 = leer[0:leer.index('H')] #Secante_e

#leer = leer[leer.index('H')+1:]

#valores_6 = leer #Regula_falsi_e


valores_1_x = [float(valores_1[i]) for i in range(0,len(valores_1),2)]
valores_1_y = [float(valores_1[i]) for i in range(1,len(valores_1),2)]

valores_2_x = [float(valores_2[i]) for i in range(0,len(valores_2),2)]
valores_2_y = [float(valores_2[i]) for i in range(1,len(valores_2),2)]

#valores_3_x = [float(valores_3[i]) for i in range(0,len(valores_3),2)]
#valores_3_y = [float(valores_3[i]) for i in range(1,len(valores_3),2)]


valores_4_x = [float(valores_4[i]) for i in range(0,len(valores_4),2)]
valores_4_y = [float(valores_4[i]) for i in range(1,len(valores_4),2)]

valores_5_x = [float(valores_5[i]) for i in range(0,len(valores_5),2)]
valores_5_y = [float(valores_5[i]) for i in range(1,len(valores_5),2)]

#valores_6_x = [float(valores_6[i]) for i in range(0,len(valores_6),2)]
#valores_6_y = [float(valores_6[i]) for i in range(1,len(valores_6),2)]


plot(valores_1_x, valores_1_y, "r", linewidth = 2.0, label= r'$Newton\_f$')
plot(valores_2_x, valores_2_y, "b", linewidth = 2.0, label= r'$Secante\_f$')
#plot(valores_3_x, valores_3_y, "g", linewidth = 2.0, label= r'$Regula\_falsi\_f$')
plot(valores_4_x, valores_4_y, "m", linewidth = 2.0, label= r'$Newton\_e$')
plot(valores_5_x, valores_5_y, "c", linewidth = 2.0, label= r'$Secante\_e$')
#plot(valores_6_x, valores_6_y, "y", linewidth = 2.0, label= r'$Regula\_falsi\_e$')

legend(loc='upper center')

xlabel('Cant iteraciones de biseccion')
ylabel('Cant iteraciones del metodo')

savefig("experimento_biseccion.jpg")
close()
