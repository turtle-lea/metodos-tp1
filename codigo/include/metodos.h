#ifndef METODOS_H
#define METODOS_H

#include <iostream>
#include "funciones.h"
#include "criterios.h"

/*Esta clase simplemente encuentra los ceros de las funciones 
pasadas como parámetro. No está mal que se independice de
aspectos como las funciones y el alpha */

class Metodos{
	public:
		Metodos(){}
		Metodos(const Funciones& fs, const Criterios& cs): criterios(cs),functions(fs){}
		float Biseccion_f(int,ostream&);
		float Biseccion_e(int,ostream&);
		
		//Newton_f
		float Newton_f(int,ostream&);
		float Newton_f(int,ostream&,int cantItBis);
		float Newton_f(int,ostream&,float seed);
		float Newton_f_aux(int,ostream&,bool,int,float);
		
		//Newton_e
		float Newton_e(int,ostream&);
		float Newton_e(int,ostream&,int cantItBis);
		float Newton_e(int,ostream&,float seed);
		float Newton_e_aux(int,ostream&,bool,int,float);
		
		//Secante_f
		float Secante_f(int,ostream&);
		float Secante_f(int,ostream&,int cantItBis);
		float Secante_f(int,ostream&,float seed1,float seed2);
		float Secante_f_aux(int,ostream&,bool,int,float,float);
		
		//Secante_e
		float Secante_e(int,ostream&);
		float Secante_e(int,ostream&,int cantItBis);
		float Secante_e(int,ostream&,float seed1,float seed2);
		float Secante_e_aux(int,ostream&,bool,int,float,float);
		
		//Regula_falsi_f
		float Regula_falsi_f(int,ostream&);
		float Regula_falsi_f(int,ostream&,int cantItBis);
		float Regula_falsi_f(int,ostream&,float seed1,float seed2);
		float Regula_falsi_f_aux(int,ostream&,bool,int,float,float);
		
		//Regula_falsi_e
		float Regula_falsi_e(int,ostream&);
		float Regula_falsi_e(int,ostream&,int cantItBis);
		float Regula_falsi_e(int,ostream&,float seed1, float seed2);
		float Regula_falsi_e_aux(int,ostream&,bool,int,float,float);
		
		float cero_teorico(){return functions.cero_teorico();}
		float cero_teorico_e(){return functions.cero_teorico_e();}
	private:
		Funciones functions;
		Criterios criterios;
};

#endif

