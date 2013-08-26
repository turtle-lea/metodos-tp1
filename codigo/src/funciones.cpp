#include "../include/funciones.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
   Debemos encontrar valores iniciales para bisección de la función f(x) = x^2 - alpha
   En el primer elemento de la tupla f será positiva y en el segundo negativa ( f(first) > 0 y f(second) < 0 ).
   Si alpha es menor que uno, entonces f(1) > 0 y f(alpha) < 0
   Si alpha es exactamente uno, entonces es raiz de la funcion y devolvemos una tupla<alpha,alpha> (Puede que
   la comparación por == no esté del todo bien).
   Si alpha es mayor que uno, entonces f(alpha) > 0 y f(1) < 0
 */


pair<float,float> Funciones::semillas_biseccion_f(){
	pair<float,float> res;
	if (abs(this->alpha) < 1){
		res.first = 1.0;
		res.second = alpha;
	}
	else { 
		if(alpha == 1.0) { res.first = alpha ; res.second = alpha ;}
		else{
			res.first = alpha;
			res.second = 1.0;
		}
	}
	return res;
}


pair<float,float> Funciones::semillas_biseccion_e(){
	pair<float,float> res;
	if (abs(this->alpha) < 1){
		res.first = 1.0/alpha;
		res.second = alpha;
	}
	else {
		if (alpha == 1.0) { res.first = alpha ; res.second = alpha ; }
		else{
			res.first = alpha;
			res.second = 1.0/alpha;
		}
	}
	return res;
}

