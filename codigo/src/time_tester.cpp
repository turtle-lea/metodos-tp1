#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>
#include "../include/metodos.h"
#include "../include/funciones.h"
#include "../include/criterios.h"
#include "../include/tiempo.h"

using namespace std;

int main(){
	ofstream out;
	//Formato del time_test.in: Metodo Funcion Alfa cantItBis Criterio Precision MaxIter
	double alfa, prec;
	int met, func, cantItBis, maxIter, criterio;
	unsigned long long int start, end, result;
	bool esFuncionValida,esMetodoValido,esCriterioValido;
	cin >> met;
	esMetodoValido = (1 <= met && met <=4);
	assert(esMetodoValido);
	cin >> func;
	esFuncionValida = (func == 1 || func == 2);
	assert(esFuncionValida);
	cin >> alfa;
	cin >> cantItBis;
	cin >> criterio;
	esCriterioValido = (1 <= criterio && criterio <= 6);
	assert(esCriterioValido);
	cin >> prec;
	cin >> maxIter;
	Funciones fs(alfa);
	Criterios cs(maxIter,prec);
	Metodos ms(fs,cs);
	int cantRepeticiones = 200;
	result = 0;
	switch(func){
		case 1:
			switch(met){
				case 1:
					out.open("../timetests/bis_f.txt");
					for(int i = 0; i < cantRepeticiones; i++){
						start=0; end=0;
						MEDIR_TIEMPO_START(start);
						ms.Biseccion_f(criterio,cout);
						MEDIR_TIEMPO_STOP(end);
						result += end-start;
						out << end-start << endl;
					}
					break;
				case 2:
					out.open("../timetests/newt_f.txt");
					for(int i = 0; i < cantRepeticiones; i++){
						start=0; end=0;
						MEDIR_TIEMPO_START(start);
						ms.Newton_f(criterio,cout,cantItBis);
						MEDIR_TIEMPO_STOP(end);
						result += end-start;
					}
					break;
				case 3:
					out.open("../timetests/sec_f.txt");
					for(int i = 0; i < cantRepeticiones; i++){
						start=0; end=0;
						MEDIR_TIEMPO_START(start);
						ms.Secante_f(criterio,cout,cantItBis);
						MEDIR_TIEMPO_STOP(end);
						result += end-start;
					}
					break;
				case 4:
					out.open("../timetests/reg_f.txt");
					for(int i = 0; i < cantRepeticiones; i++){
						start=0; end=0;
						MEDIR_TIEMPO_START(start);
						ms.Regula_falsi_f(criterio,cout,cantItBis);
						MEDIR_TIEMPO_STOP(end);
						result += end-start;
					}
					break;
			}
			break;
		case 2:
			switch(met){
				case 1:
					out.open("../timetests/bis_e.txt");
					for(int i = 0; i < cantRepeticiones; i++){
						start=0; end=0;
						MEDIR_TIEMPO_START(start);
						ms.Biseccion_e(criterio,cout);
						MEDIR_TIEMPO_STOP(end);
						result += end-start;
					}
					break;
				case 2:
					out.open("../timetests/newt_e.txt");
					for(int i = 0; i < cantRepeticiones; i++){
						start=0; end=0;
						MEDIR_TIEMPO_START(start);
						ms.Newton_e(criterio,cout,cantItBis);
						MEDIR_TIEMPO_STOP(end);
						result += end-start;
					}
					break;
				case 3:
					out.open("../timetests/sec_e.txt");
					for(int i = 0; i < cantRepeticiones; i++){
						start=0; end=0;
						MEDIR_TIEMPO_START(start);
						ms.Secante_e(criterio,cout,cantItBis);
						MEDIR_TIEMPO_STOP(end);
						result += end-start;
					}
					break;
				case 4:
					out.open("../timetests/reg_e.txt");
					for(int i = 0; i < cantRepeticiones; i++){
						start=0; end=0;
						MEDIR_TIEMPO_START(start);
						ms.Regula_falsi_e(criterio,cout,cantItBis);
						MEDIR_TIEMPO_STOP(end);
						result += end-start;
					}
					break;
			}
			break;
	}
	result = result/cantRepeticiones; //Calculo el promedio
	out << result;
	out.close();
	cout << "Tiempos en ../timetests/" << endl;
	return 0;
}


