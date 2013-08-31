#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <cmath>
using namespace std;

class Funciones{

	public:
		Funciones(){}
		Funciones(float x){alpha = x;} 

		// f corresponde al primer experimento para obtener sqrt(alpha) 
		float f(float x){return x*x - this->alpha;}
		float f_deriv(float x){return 2.0*x;}
		pair<float,float> semillas_biseccion_f();

		// e corresponde al segundo experimento para obtener 1/sqrt(alpha)
		float e(float x){return 1.0/(x*x) - this->alpha;}		
		float e_deriv(float x){ return (-2.0)/(x*x*x);}
		pair<float,float> semillas_biseccion_e();

		float cero_teorico(){return sqrt(alpha);}
		float cero_teorico_e(){return 1.0/sqrt(alpha);}
		float get_alpha(){return alpha;}

	private:
		float alpha;
};

#endif
