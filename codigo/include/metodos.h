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
		double Biseccion_f(int,ostream&);
		double Biseccion_e(int,ostream&);
		
		//Newton_f
		double Newton_f(int,ostream&);
		double Newton_f(int,ostream&,int cantItBis);
		double Newton_f(int,ostream&,double seed);
		double Newton_f_aux(int,ostream&,bool,int,double);
		
		//Newton_e
		double Newton_e(int,ostream&);
		double Newton_e(int,ostream&,int cantItBis);
		double Newton_e(int,ostream&,double seed);
		double Newton_e_aux(int,ostream&,bool,int,double);
		
		//Secante_f
		double Secante_f(int,ostream&);
		double Secante_f(int,ostream&,int cantItBis);
		double Secante_f(int,ostream&,double seed1,double seed2);
		double Secante_f_aux(int,ostream&,bool,int,double,double);
		
		//Secante_e
		double Secante_e(int,ostream&);
		double Secante_e(int,ostream&,int cantItBis);
		double Secante_e(int,ostream&,double seed1,double seed2);
		double Secante_e_aux(int,ostream&,bool,int,double,double);
		
		//Regula_falsi_f
		double Regula_falsi_f(int,ostream&);
		double Regula_falsi_f(int,ostream&,int cantItBis);
		double Regula_falsi_f(int,ostream&,double seed1,double seed2);
		double Regula_falsi_f_aux(int,ostream&,bool,int,double,double);
		
		//Regula_falsi_e
		double Regula_falsi_e(int,ostream&);
		double Regula_falsi_e(int,ostream&,int cantItBis);
		double Regula_falsi_e(int,ostream&,double seed1, double seed2);
		double Regula_falsi_e_aux(int,ostream&,bool,int,double,double);
		
		double cero_teorico(){return functions.cero_teorico();}
		double cero_teorico_e(){return functions.cero_teorico_e();}
	private:
		Funciones functions;
		Criterios criterios;
};

#endif

