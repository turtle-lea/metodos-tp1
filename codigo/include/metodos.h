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
		float Newton_f();
		float Newton_e();
		float Regula_falsi_f();
		float Regula_falsi_e();
		float Secante_f();
		float Secante_e();

	private:
		Funciones functions;
		Criterios criterios;
};

#endif

