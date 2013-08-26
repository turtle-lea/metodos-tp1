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

