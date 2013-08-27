#include <iostream>
#include <cmath>
#include "../include/metodos.h"
#include "../include/funciones.h"
#include "../include/criterios.h"

using namespace std;

int main(){
	Funciones fs(5.25);
	Criterios cs(20,0.000001);
	Metodos ms(fs,cs);


	cout << "Biseccion f: " << endl;
	ms.Biseccion_f();
	cout << endl;

	cout << "Biseccion e: " << endl << endl;
	float aux = ms.Biseccion_e();
	cout << endl;

	cout << "Newton f: " << endl << endl;
	ms.Newton_f();
	cout << endl;

	cout << "Newton e: " << endl << endl;
	ms.Newton_e();
	cout << endl;

	cout << "Regula_falsi f: " << endl << endl;
	ms.Regula_falsi_f();
	cout << endl;

	cout << "Regula_falsi e: " << endl << endl;
	ms.Regula_falsi_e();
	cout << endl;

	cout << "Secante f: " << endl << endl;
	ms.Secante_f();
	cout << endl;

	cout << "Secante e: " << endl << endl;
	ms.Secante_e();
	cout << endl;

	return 0;
}


