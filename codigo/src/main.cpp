#include <iostream>
#include <cmath>
#include "../include/metodos.h"
#include "../include/funciones.h"
#include "../include/criterios.h"

using namespace std;

int main(){
	Funciones fs(5.25);
	Criterios cs(200,0.000001);
	Metodos ms(fs,cs);
	ms.Biseccion(); 
	return 0;
}


