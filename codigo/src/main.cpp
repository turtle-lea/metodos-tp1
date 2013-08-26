#include <iostream>
#include <cmath>
#include "../include/metodos.h"
#include "../include/funciones.h"

using namespace std;

int main(){
	Funciones fs(5.25);
	Metodos ms(fs);
	ms.Biseccion(); 
	return 0;
}


