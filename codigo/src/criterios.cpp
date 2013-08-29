#include "../include/criterios.h"
#include <iostream>
#include <cmath>
using namespace std;

bool Criterios::criterio2_parar(float x, float x_anterior){
	return abs(x - x_anterior) < (this->epsilon);
}

bool Criterios::criterio2_bis_parar(float x, float x_anterior){
	return abs(x - x_anterior)/abs(x_anterior) < (this->epsilon);
}

bool Criterios::criterio3_parar(float y){
	return abs(y) < (this->epsilon);
}

bool Criterios::criterio4_parar(float y, float y_anterior){
	return abs(y-y_anterior);
}

bool Criterios::criterio4_bis_parar(float y, float y_anterior){
	return abs(y - y_anterior) / abs(y_anterior) < (this->epsilon);
}

bool Criterios::criterios(int selector, int numIter,float x,float x_anterior,float f_x,float f_anterior)
{
	bool esPrimeraIteracion = numIter == 0; //Si fuese la primera iteracion, no desearia que se detenga
	if(!esPrimeraIteracion){
		if(!criterio1_parar(numIter)){
			switch(selector){
				case 1:
					return false;//Ya lo evalue en la guarda
					break;//Por si las dudas
				case 2:
					return criterio2_parar(x,x_anterior);
					break;
				case 3:
					return criterio2_bis_parar(x,x_anterior);
					break;
				case 4:
					return criterio3_parar(f_x);
					break;
				case 5:
					return criterio4_parar(f_x,f_anterior);
					break;
				case 6:
					return criterio4_bis_parar(f_x,f_anterior);
					break;
				default:
					return false;
			}
		}
		else return true;//Se excedio en iteraciones
	}
	else return false;
}

