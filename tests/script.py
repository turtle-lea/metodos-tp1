import sys
import os 
import pylab
import graficador
import numpy

#Quiero que para un determinado metodos haga la prueba con todos los criterios
#para distintos ordenes de magnitud de epsilon


nombre_exp = sys.argv[1]
nombre_metodo = sys.argv[2]

#Cosas que pueden ser cambiadas segun el experimento
precision = [10**(-i) for i in range(4,9)]
max_iter = 20
valores_alpha = numpy.arange(1.,21.,10)
#valores_alpha = [5.25]

nombre_dir = "experimentos/"+nombre_exp+"/"+nombre_metodo+"/"
os.system("mkdir -p "+nombre_dir)

for alpha in valores_alpha:
	nombre_alpha = "alpha_"+str(alpha)	
	nombre_dir_alpha = nombre_dir+nombre_alpha+"/"
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
			
			#os.system("cat test.out && echo \n")
			#Llamo al graficador
			graficador.graficador_exp1("test.out",nombre_dir_precision,i)

			#Renombro los archivos#
			os.system("cp test.in "+ filename_1)
			os.system("mv test.out "+ filename_2)
			os.system("mv "+ filename_1+ " "+nombre_dir_precision)	
			os.system("mv "+ filename_2+ " "+nombre_dir_precision)
		
			os.system("rm test.in")

	os.system("echo terminado para alpha = "+str(alpha))



