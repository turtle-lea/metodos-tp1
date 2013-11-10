#include <iostream>
#include <cmath>
#include "../include/metodos.h"
#include "../include/funciones.h"
#include "../include/criterios.h"

using namespace std;

int main(){
	Funciones fs(1.5);
	Criterios cs(60,0.000001);
	Metodos ms(fs,cs);

	cout << "Biseccion f: " << endl;
	ms.Biseccion_f(3,cout);
	cout << endl;

	cout << "Biseccion e: " << endl << endl;
	double aux = ms.Biseccion_e(3,cout);
	cout << endl;

	cout << "Newton f: " << endl << endl;
	ms.Newton_f(3,cout);
	cout << endl;

	cout << "Newton e: " << endl << endl;
	ms.Newton_e(3,cout);
	cout << endl;

	cout << "Secante f: " << endl << endl;
	ms.Secante_f(5,cout);
	cout << endl;

	cout << "Secante e: " << endl << endl;
	ms.Secante_e(5,cout);
	cout << endl;

	return 0;
}


