#include "../include/metodos.h"
#include <iostream>
#include <cmath>

using namespace std;

float Metodos::Biseccion(){
	int max_iter = 200; int i=0;
	float epsilon = 0.000001;
	float res;
	float positivo = (this->functions).semillas_biseccion_f().first;
	float negativo = (this->functions).semillas_biseccion_f().second;

	while (i<max_iter && (this->functions).f(positivo) > 0 && (this->functions).f(negativo) < 0){
		float medio = (positivo+negativo)/2;
		if (abs((this->functions).f(medio)) < epsilon) {
			break;
		}
		else {
			if ( (this->functions).f(medio) < 0 ) { negativo = medio; }
			else { positivo = medio; }
		}

		res = medio;
		i++;
	}
	
	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << res << endl;
	cout << "Me dio un buen cero ? El error es de: " << (this->functions).f(res) << endl;

	return res;	
}


