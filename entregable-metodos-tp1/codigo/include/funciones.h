#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <cmath>
using namespace std;

class Funciones{

	public:
		Funciones(){}
		Funciones(double x){alpha = x;} 

		// f corresponde al primer experimento para obtener sqrt(alpha) 
		double f(double x){return x*x - this->alpha;}
		double f_deriv(double x){return 2.0*x;}
		pair<double,double> semillas_biseccion_f(int);

		// e corresponde al segundo experimento para obtener 1/sqrt(alpha)
		double e(double x){return 1.0/(x*x) - this->alpha;}		
		double e_deriv(double x){ return (-2.0)/(x*x*x);}
		pair<double,double> semillas_biseccion_e(int);

		double cero_teorico(){return sqrt(alpha);}
		double cero_teorico_e(){return 1.0/sqrt(alpha);}
		double get_alpha(){return alpha;}

	private:
		double alpha;
};

#endif
