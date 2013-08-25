#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
using namespace std;
// Vamos a trabajar con precision double o float ??

class Funciones{

	public:
		Funciones(){}
		Funciones(float x){alpha = x;} 

		// f corresponde al primer experimento para obtener 1/sqrt(alpha) 
		int f(int x){return x*x - this->alpha;}
		int f_deriv(int x){return 2.0*x;}
		pair<float,float> semillas_biseccion_f();

		// e corresponde al segundo experimento para obtener 1/sqrt(alpha)
		int e(int x){return 1/x*x - 1.0/this->alpha;}		
		int e_deriv(int x){ (-2.0)/x*x*x;}
		pair<float,float> semillas_biseccion_e();

	private:
		//Parece loco, pero es el único atributo que necesitamos.
		//lo demás está harcodeado.
		float alpha;
};

#endif
