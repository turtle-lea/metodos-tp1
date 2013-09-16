#! usr/bin/python
from matplotlib.pyplot import *
from numpy import *
from pylab import *

def graficador_exp2(fuente,destino,i):
	with open(fuente) as filename:
		s = filename.read()
	filename.closed	
	s.strip('\n')
	s = s.split()
	s = [float(x) for x in s]
	
	alpha = float(s[0])
	cero_teorico = float(s[1])
		
	iteraciones = [s[x] for x in range(2,len(s),2)]
	num_iteracion = [(x-1)/2 for x in range(3,len(s),2)]
	cantidad = len(iteraciones)	

	constantes = [cero_teorico for x in num_iteracion]

	#Start plotting
	#Dominio para f
	t = np.linspace(0.,cantidad, cantidad+1, endpoint = True)

	#Grafico las 4 curvas
	#plot(iteraciones,valores, color="red", linewidth = 2.0 , linestyle = "None", marker = "o", label = r'$Iteraciones \ biseccion \ f$')
	plot(num_iteracion,constantes, color="red", linewidth = 2.0 , linestyle = "--", label = r'Raiz teorica')
	plot(num_iteracion,iteraciones, color="blue", linewidth = 1.0 , linestyle = "-", label = r'$metodo(i)=x_i$')
	
	#Ejemplo
	#plot(t,t-(t**2-alpha)/2*t, color="black", linewidth = 2.0, linestyle="--", label= r'$y = x -\frac{f(x)}{f\_derivada(x)}$')

	#Adding legend
	legend(loc='lower right', prop={'size':6})

	#Setting limits f
	#xlim(0., 4.)
	#ylim(9.95, 10.05)

	#Moving spines
	#ax = gca()
	#ax.spines['right'].set_color('none')
	#ax.spines['top'].set_color('none')
	#ax.xaxis.set_ticks_position('bottom')
	#ax.spines['bottom'].set_position(('data',0))
	#ax.yaxis.set_ticks_position('left')
	#ax.spines['left'].set_position(('data',0))

	#Adapto el tam de la fuente para que quede prolija
	font = {'size': 6}
	matplotlib.rc('font', **font)

	#Cambio el tam del grafico, para que quede bien en el .tex
	fig = matplotlib.pyplot.gcf()
	fig.set_size_inches(6.0,4.0)

	#Escribo el nombre de los ejes
	xlabel("Numero de iteracion")
	ylabel("Valores de x_n")
	#ax.xaxis.set_label_coords(1.05, 0.500)
	#ax.yaxis.set_label_coords(0.0, 1.05)

	#Anoto para que se muestre el cero_teorico
	#plot([cero_teorico,cero_teorico],[-(alpha*1.25),alpha**2], color ='red', linewidth=2.5, linestyle="--")
	#annotate(r'$x='+str(s[1])+'$',
        #xy=(cero_teorico, 0), xycoords='data',
        #xytext=(+10, -30), textcoords='offset points', fontsize=8,
        #arrowprops=dict(arrowstyle="->", connectionstyle="arc3,rad=.2"))

	savefig(destino+"imagen_"+str(i)+".pdf")
	close()
