#include <iostream>
#include <cmath>
#include "../include/metodos.h"
#include "../include/funciones.h"
#include "../include/criterios.h"

using namespace std;

int main(){
	Funciones fs(5.25);
	Criterios cs(60,0.000001);
	Metodos ms(fs,cs);


	cout << "Biseccion f: " << endl;
	ms.Biseccion_f(6,cout);
	cout << endl;

	cout << "Biseccion e: " << endl << endl;
	float aux = ms.Biseccion_e(1,cout);
	cout << endl;

	cout << "Newton f: " << endl << endl;
	ms.Newton_f(1,cout);
	cout << endl;

	cout << "Newton e: " << endl << endl;
	ms.Newton_e(1,cout);
	cout << endl;

	cout << "Regula_falsi f: " << endl << endl;
	ms.Regula_falsi_f(1,cout);
	cout << endl;

	cout << "Regula_falsi e: " << endl << endl;
	ms.Regula_falsi_e(1,cout);
	cout << endl;

	cout << "Secante f: " << endl << endl;
	ms.Secante_f(1,cout);
	cout << endl;

	cout << "Secante e: " << endl << endl;
	ms.Secante_e(1,cout);
	cout << endl;

	return 0;
}


