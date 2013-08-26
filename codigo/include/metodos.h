#ifndef METODOS_H
#define METODOS_H

#include <iostream>
#include "funciones.h"
#include "criterios.h"

/*Esta clase simplemente encuentra los ceros de las funciones 
pasadas como parámetro. No está mal que se independice de
aspectos como las funciones y el alpha */

//Falta el tema de los criterios. Commiteo esto por ahora

class Metodos{
	public:
		Metodos(){}
		Metodos(const Funciones& fs, const Criterios& cs): criterios(cs),functions(fs){}
		float Biseccion();
		//float Newton();
		//float Regula_falsi();
		//float Secante();

	private:
		Funciones functions;
		Criterios criterios;
};

#endif

