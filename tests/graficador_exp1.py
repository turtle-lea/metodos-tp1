#! usr/bin/python
from matplotlib.pyplot import *
from numpy import *
from pylab import *

def graficador_exp1(fuente,destino,i):
	with open(fuente) as filename:
		s = filename.read()
	filename.closed	
	s.strip('\n')
	s = s.split()
	s = [float(x) for x in s]
	
	alpha = float(s[0])
	cero_teorico = float(s[1])
	iteraciones = [s[x] for x in range(2,len(s),2)]
	valores = [s[x] for x in range(3,len(s),2)]
	
	#Start plotting
	t = np.linspace(0.,alpha, 1024, endpoint = True)
	plot(t,t**2 - alpha, color="blue", linewidth = 2.0, linestyle="-", label= r'$x^{2}-\alpha$')
	plot(t,t-(t**2-alpha)/2*t, color="black", linewidth = 2.0, linestyle="--", label= r'$f(x) = x - frac{f(x)}{f\_derivada(x)}$')
	plot(t,t, color="green", linewidth = 2.0, linestyle="--", label= r'$f(x)=x$')
	plot(iteraciones,valores, color="red", linewidth = 2.0 , linestyle = "None", marker = "o", label = r'$Iteraciones \ del \ metodo$')

	#Adding legend
	legend(loc='lower right')

	#Setting limits
	xlim(0., alpha*1.1)
	ylim(-alpha*1.1, alpha*1.1)

	#Moving spines
	ax = gca()
	ax.spines['right'].set_color('none')
	ax.spines['top'].set_color('none')
	ax.xaxis.set_ticks_position('bottom')
	ax.spines['bottom'].set_position(('data',0))
	ax.yaxis.set_ticks_position('left')
	ax.spines['left'].set_position(('data',0))

	#Anoto para que se muestre el cero_teorico
	plot([cero_teorico,cero_teorico],[-(alpha*1.25),alpha**2], color ='red', linewidth=2.5, linestyle="--")
	annotate(r'$x='+str(s[1])+'$',
        xy=(cero_teorico, 0), xycoords='data',
        xytext=(+10, -30), textcoords='offset points', fontsize=16,
        arrowprops=dict(arrowstyle="->", connectionstyle="arc3,rad=.2"))

	savefig(destino+"imagen_"+str(i)+".jpg")
	close()





