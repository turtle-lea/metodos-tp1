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
		float Biseccion_f(int,ostream&);
		float Biseccion_e(int,ostream&);
		float Newton_f(int,ostream&);
		//void test_f_Newton(ostream&,int);
		float Newton_e(int,ostream&);
		float Regula_falsi_f(int,ostream&);
		float Regula_falsi_e(int,ostream&);
		float Secante_f(int,ostream&);
		float Secante_e(int,ostream&);

		float cero_teorico(){return functions.cero_teorico();}
		float cero_teorico_e(){return functions.cero_teorico_e();}
	private:
		Funciones functions;
		Criterios criterios;
};

#endif

