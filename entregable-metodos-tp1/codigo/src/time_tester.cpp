#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>
#include "../include/metodos.h"
#include "../include/funciones.h"
#include "../include/criterios.h"
#include "../include/tiempo.h"

using namespace std;

enum funcion {f=1,e=2};
enum metodo {biseccion=1,newton=2,secante=3};

int main(){
	ofstream out;
	//Formato del time_test.in: Metodo Funcion Alfa Criterio
	double alfa, precisionActual;
	int met, func, maxIter, criterio;
	unsigned long long int start, end, result;
	bool esFuncionValida,esMetodoValido,esCriterioValido;
	cin >> met;
	esMetodoValido = (1 <= met && met <=3);
	assert(esMetodoValido);
	cin >> func;
	esFuncionValida = (func == 1 || func == 2);
	assert(esFuncionValida);
	cin >> alfa;
	cin >> criterio;
	esCriterioValido = (1 <= criterio && criterio <= 6);
	assert(esCriterioValido);
	Funciones fs(alfa);
	int cantRepeticiones = 1000;
	result = 0;
	int iteracion = 1;
	switch(func){
		case f:
			switch(met){
				case biseccion:
					out.open("../timetests/bis_f.txt");
					break;
				case newton:
					out.open("../timetests/newt_f.txt");
					break;
				case secante:
					out.open("../timetests/sec_f.txt");
					break;
			}
			break;
		case e:
			switch(met){
				case biseccion:
					out.open("../timetests/bis_e.txt");
					break;
				case newton:
					out.open("../timetests/newt_e.txt");
					break;
				case secante:
					out.open("../timetests/sec_e.txt");
					break;
			}
			break;
	}
	maxIter = 20;
	while(iteracion < 17){
		precisionActual = pow(10,(-iteracion));
		Criterios cs(maxIter,precisionActual);
		Metodos ms(fs,cs);
		switch(func){
			case f:
				switch(met){
					case biseccion:
						for(int i = 0; i < cantRepeticiones; i++){
							start=0; end=0;
							MEDIR_TIEMPO_START(start);
							ms.Biseccion_f(criterio,cout);
							MEDIR_TIEMPO_STOP(end);
							result += end-start;
							//out << end-start << endl;
						}
						break;
					case newton:
						for(int i = 0; i < cantRepeticiones; i++){
							start=0; end=0;
							MEDIR_TIEMPO_START(start);
							ms.Newton_f(criterio,cout);
							MEDIR_TIEMPO_STOP(end);
							result += end-start;
						}
						break;
					case secante:
						for(int i = 0; i < cantRepeticiones; i++){
							start=0; end=0;
							MEDIR_TIEMPO_START(start);
							ms.Secante_f(criterio,cout);
							MEDIR_TIEMPO_STOP(end);
							result += end-start;
						}
						break;
				}
				break;
			case e:
				switch(met){
					case biseccion:
						for(int i = 0; i < cantRepeticiones; i++){
							start=0; end=0;
							MEDIR_TIEMPO_START(start);
							ms.Biseccion_e(criterio,cout);
							MEDIR_TIEMPO_STOP(end);
							result += end-start;
						}
						break;
					case newton:
						for(int i = 0; i < cantRepeticiones; i++){
							start=0; end=0;
							MEDIR_TIEMPO_START(start);
							ms.Newton_e(criterio,cout);
							MEDIR_TIEMPO_STOP(end);
							result += end-start;
						}
						break;
					case secante:
						for(int i = 0; i < cantRepeticiones; i++){
							start=0; end=0;
							MEDIR_TIEMPO_START(start);
							ms.Secante_e(criterio,cout);
							MEDIR_TIEMPO_STOP(end);
							result += end-start;
						}
						break;
				}
				break;
		}
		result = result/cantRepeticiones; //Calculo el promedio
		result = floor(result/10000); //Escala para valores más representativos
		out << iteracion << " " << result << endl;
		iteracion++;
	}
	out.close();
	cout << "Tiempos en ../timetests/" << endl;
	return 0;
}


