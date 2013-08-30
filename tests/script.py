import os 
import pylab
import graficador
import numpy

#Quiero que para un determinado metodos haga la prueba con todos los criterios
#para distintos ordenes de magnitud de epsilon

#def modificar_test_criterio(archivo,c):
	#filename = open(archivo,"r+")
	#entrada = filename.readline()
	#filename.seek(0)
	#entrada = entrada.split()
	#entrada = " ".join(entrada)
	#filename.write(entrada)
	#filename.close()

#def modificar_test_epsilon(archivo,e):
#	with open(archivo,"r+") as filename:
#		entrada = filename.readline()
#		filename.seek(0)
#		entrada = entrada.split()
#		entrada[2] = str(e)
#		entrada = " ".join(entrada)
#		filename.write(entrada)
#	filename.closed
#
#def modificar_test_alpha(archivo,alpha):
#	filename = open(archivo,"r+")
#	entrada = filename.readline()
#	filename.seek(0)
#	entrada = entrada.split()
#	entrada[0] = str(alpha)
#	entrada = " ".join(entrada)
#	filename.write(entrada)
#	filename.close()


os.system("mkdir -p experimentos/newton_f")
precision = [10**(-i) for i in range(4,9)]
max_iter = 20
#valores_alpha = numpy.arange(0.,10.,1)
valores_alpha = [0,1]

for alpha in valores_alpha:
	nombre_alpha = "alpha_"+str(alpha)	
	nombre_dir_alpha = "experimentos/newton_f/"+nombre_alpha+"/"
	os.system("mkdir "+nombre_dir_alpha)

	for e in precision:
		#modificar_test_epsilon("test.in",e)
		nombre_precision = "e_"+str(e)		
		nombre_dir_precision = nombre_dir_alpha+nombre_precision+"/"
		os.system("mkdir "+nombre_dir_precision)

		for i in range (1,7):

			info = str(alpha)+ " "+ str(max_iter)+ " " +str(e)+ " "+str(i)+"\n"+"#"
			with open("test.in","w") as filename:
				filename.write(info)
			filename.closed

			#Ejecuto el tester#
			os.system("../codigo/bin/tester < test.in > test.out")

			filename_1 = "test_"+str(i)+".in"
			filename_2 = "test_"+str(i)+".out"
			
			#Llamo al graficador
			graficador.graficador("test.out",nombre_dir_precision,i)

			#Renombro los archivos#
			os.system("cp test.in "+ filename_1)
			os.system("mv test.out "+ filename_2)
			os.system("mv "+ filename_1+ " "+nombre_dir_precision)	
			os.system("mv "+ filename_2+ " "+nombre_dir_precision)
		
			os.system("rm test.in")

os.system("echo terminado para alpha = "+str(alpha))



