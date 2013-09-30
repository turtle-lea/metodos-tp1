#include <iostream>
#include <cmath>
#include "../include/metodos.h"
#include "../include/funciones.h"
#include "../include/criterios.h"

using namespace std;

int main(){
	//Formato del test.in: Alfa Funcion Metodo Criterio Precision MaxIter
	double alfa, prec;
	int func,met, maxIter, criterio;
	char c;
	bool esFuncionValida,esMetodoValido,esCriterioValido;
	cin >> c;
	while(c!= '#'){
		cin.putback(c);
		cin >> alfa;
		cin >> func;
		esFuncionValida = (func == 1 || func == 2);
		if(!esFuncionValida){
			cout << "No es una funcion valida.\n";
			break;
		}
		cin >> met;
		esMetodoValido = (1 <= met && met <=3);
		if(!esMetodoValido){
			cout << "No es un metodo valido.\n";
			break;
		}
		cin >> criterio;
		esCriterioValido = (1 <= criterio && criterio <= 6);
		if(!esCriterioValido){
			cout << "No es un criterio valido.\n";
			break;
		}
		cin >> prec;
		cin >> maxIter;
		Funciones fs(alfa);
		Criterios cs(maxIter,prec);
		Metodos ms(fs,cs);
		switch(func){
			case 1:
				switch(met){
					case 1:
						ms.Biseccion_f(criterio,cout);
						break;
					case 2:
						ms.Newton_f(criterio,cout);
						break;
					case 3:
						ms.Secante_f(criterio,cout);
						break;
				}		
				break;
			case 2:
				switch(met){
					case 1:
						ms.Biseccion_e(criterio,cout);
						break;
					case 2:
						ms.Newton_e(criterio,cout);
						break;
					case 3:
						ms.Secante_e(criterio,cout);
						break;
				}
				break;
		}
	break;
	}
	return 0;
}


