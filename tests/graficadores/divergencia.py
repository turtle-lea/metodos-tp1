#! usr/bin/python
from matplotlib.pyplot import *
from numpy import *
from pylab import *

def e_derivada(x):
	return -2./x**3

def graficador_derivada():
	alpha = 0.01
	raiz = 1./sqrt(alpha)

	valor_1 = 23.
	e_valor_1 = 1/valor_1**2 - alpha

	valor_2 = -26.335
	e_valor_2 = 1/valor_2**2 - alpha
	
	valor_3 = 51.8184 
	e_valor_3 = 1/valor_3**2 - alpha

	#Start plotting

	#Dominio para e
	t = np.linspace(-100.,100., 2**12, endpoint = True)

	#Recta tangente nro. 1: 
	b = 1./(valor_1**2) - 0.01 + 2./valor_1**2
	m = -2./valor_1**3
	plot(t,m*t+b, color="red", linewidth = 1.0, linestyle="-", label= r'Recta tangente a e que pasa por (x_0,e(x_0))')
	plot([valor_1,valor_1],[e_valor_1,0.02], color="blue", linewidth = 1.0, linestyle="--")
	
	annotate(r'$x_0 = 23$',
        xy=(valor_1, 0), xycoords='data',
        xytext=(+5, -20), textcoords='offset points', fontsize=8,
        arrowprops=dict(arrowstyle="->", connectionstyle="arc3,rad=.2"))
	scatter([valor_1],[e_valor_1], color="red")

	#Recta tangente nro. 2:
	b = 1./(valor_2**2) - 0.01 + 2./valor_2**2
	m = -2./valor_2**3
	plot(t,m*t+b, color="red", linewidth = 1.0, linestyle="-.", label= r'Recta tangente a e que pasa por (x_1,e(x_1))')
	plot([valor_2,valor_2],[e_valor_2,0.02], color="blue", linewidth = 1.0, linestyle="--")
	
	annotate(r'$x_1 = -26.335$',
        xy=(valor_2, 0), xycoords='data',
        xytext=(-50, -20), textcoords='offset points', fontsize=8,
        arrowprops=dict(arrowstyle="->", connectionstyle="arc3,rad=.2"))
	scatter([valor_2],[e_valor_2], color="red")

	#Recta tangente nro. 3:
	b = 1./(valor_3**2) - 0.01 + 2./valor_3**2
	m = -2./valor_3**3
	plot(t,m*t+b, color="black", linewidth = 2.0, linestyle="-", label= r'Recta tangente a e que pasa por (x_2,e(x_2))')
	plot([valor_3,valor_3],[e_valor_3,0.02], color="blue", linewidth = 1.0, linestyle="--")
	
	annotate(r'$x_2 = 51.8184$',
        xy=(valor_3, 0), xycoords='data',
        xytext=(+5, -20), textcoords='offset points', fontsize=8,
        arrowprops=dict(arrowstyle="->", connectionstyle="arc3,rad=.2"))
	scatter([valor_3],[e_valor_3], color="black")

	#Grafico las 4 curvas
	plot(t,1/t**2 - alpha, color="blue", linewidth = 2.0, linestyle="-", label= r'$e$')

	#plot([raiz,raiz],[-0.02,0.02], color="blue", linewidth = 1.0, linestyle="--", label= r'$\alpha_1$')	
	#annotate(r'$\frac{1}{\sqrt{\alpha}} = 10$',
        #xy=(raiz, 0), xycoords='data',
        #xytext=(0,0), textcoords='offset points', fontsize=8,
        #arrowprops=dict(arrowstyle="->", connectionstyle="arc3,rad=.2"))

	
	#scatter([10.125],[10.125/2 - 5.0625], color="red")
	#scatter([sqrt(alpha)],[0], color="blue")

	#Adding legend
	legend(loc='upper left', prop={'size':4})

	#Setting limits f
	#xlim(0., 10.5)
	ylim(-0.02, 0.02)
	xlim(-100., 100.)

	#Moving spines
	ax = gca()
	ax.spines['right'].set_color('none')
	ax.spines['top'].set_color('none')
	ax.xaxis.set_ticks_position('bottom')
	ax.spines['bottom'].set_position(('data',0))
	ax.yaxis.set_ticks_position('left')
	ax.spines['left'].set_position(('data',0))

	#Adapto el tam de la fuente para que quede prolija
	font = {'size': 6}
	matplotlib.rc('font', **font)

	#Cambio el tam del grafico, para que quede bien en el .tex
	fig = matplotlib.pyplot.gcf()
	fig.set_size_inches(6.0,4.0)

	#Escribo el nombre de los ejes
	xlabel("x")
	ylabel("y")
	ax.xaxis.set_label_coords(1.05, 0.500)
	ax.yaxis.set_label_coords(0.5, 1.05)

	#savefig(destino+"imagen_"+str(i)+".pdf")
	savefig("corrimiento.pdf")
	close()

graficador_derivada()




