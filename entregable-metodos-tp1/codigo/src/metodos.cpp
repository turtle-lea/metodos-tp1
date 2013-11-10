#include "../include/metodos.h"
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

double Metodos::Biseccion_f(int criterio,ostream& os){
	pair<double, double> seed = functions.semillas_biseccion_f(0);
	double positivo = seed.first;
	double negativo = seed.second;
	return Biseccion_f_aux(criterio,os,positivo,negativo);
}

double Metodos::Biseccion_f(int criterio,ostream& os,double seed1,double seed2){
	assert(functions.f(seed1)*functions.f(seed2) < 0);
	return Biseccion_f_aux(criterio, os, seed1, seed2);
}

double Metodos::Biseccion_f_aux(int criterio,ostream& os,double seed1,double seed2){
	int i = 0;
	double res;
	double positivo = seed1;
	double negativo = seed2;
	double medio = positivo;//X_1
	double anterior = negativo;//X_0

	while (!criterios.criterios(criterio,i,medio,anterior,functions.f(medio),functions.f(anterior))){
		anterior = medio;
		medio = (positivo+negativo)/2;
		
		if ( (this->functions).f(medio) < 0 ){negativo = medio; }
		else { positivo = medio; }
		
		res = medio;
		i++;
		os << res << " " << functions.f(res) << endl;
	}
	return res;
}

double Metodos::Biseccion_e(int criterio,ostream& os){
	pair<double, double> seed = functions.semillas_biseccion_e(0);
	double positivo = seed.first;
	double negativo = seed.second;
	return Biseccion_e_aux(criterio, os, positivo, negativo);
}

double Metodos::Biseccion_e(int criterio,ostream& os,double seed1,double seed2){
	assert(functions.e(seed1)*functions.e(seed2) < 0);
	return Biseccion_e_aux(criterio,os,seed1,seed2);	
}

double Metodos::Biseccion_e_aux(int criterio,ostream& os,double seed1, double seed2){
	int i = 0;
	double res;
	double positivo = seed1;
	double negativo = seed2;
	double medio = positivo;//X_1
	double anterior = negativo;//X_0
	while (!criterios.criterios(criterio,i,medio,anterior,functions.e(medio),functions.e(anterior))){
		anterior = medio;
		medio = (positivo+negativo)/2;
		
		if (functions.e(medio) < 0 ) { negativo = medio; }
		else { positivo = medio; }
		
		res = medio;
		i++;
		os << res << " " << functions.e(res) << endl;
	}
	return res;	
}

double Metodos::Newton_f(int criterio,ostream&os)
{
	return Newton_f_aux(criterio,os,true,0,0.0);
}

double Metodos::Newton_f(int criterio,ostream &os,int cantItBis)
{
	return Newton_f_aux(criterio,os,true,cantItBis,0.0);
}

double Metodos::Newton_f(int criterio,ostream &os,double seed)
{
	return Newton_f_aux(criterio,os,false,-1,seed);
}

double Metodos::Newton_f_aux(int criterio,ostream& os,bool hacerBiseccion, int cantItBis,double x_0){
	double actual, anterior;
	if(hacerBiseccion){
		pair<double,double> seed =  functions.semillas_biseccion_f(cantItBis);
		actual = seed.first;
		anterior = seed.first;
	}
	else{
		actual = x_0;
		anterior = x_0;
	}
	int i = 0;
	os << actual << " " <<  functions.f(actual) << endl;
	while(!criterios.criterios(criterio,i,actual,anterior,functions.f(actual),functions.f(anterior))){ 
		anterior = actual;
		actual = anterior - (functions.f(anterior)/functions.f_deriv(anterior));
		++i;
		os << actual << " " << functions.f(actual) << endl;
	}
	return actual;
}

double Metodos::Newton_e(int criterio,ostream&os)
{
	return Newton_e_aux(criterio,os,true,0,0.0);
}

double Metodos::Newton_e(int criterio,ostream &os,int cantItBis)
{
	return Newton_e_aux(criterio,os,true,cantItBis,0.0);
}

double Metodos::Newton_e(int criterio,ostream &os,double seed)
{
	return Newton_e_aux(criterio,os,false,-1,seed);
}

double Metodos::Newton_e_aux(int criterio,ostream& os,bool hacerBiseccion, int cantItBis, double x_0){
	double actual, anterior;
	if(hacerBiseccion){
		pair<double,double> seed =  functions.semillas_biseccion_e(cantItBis);
		actual = seed.first;
		anterior = seed.first;
	}
	else{
		actual = x_0;
		anterior = x_0;
	}
	int i = 0;
	os << actual << " " << functions.e(actual) << endl;
	while(!criterios.criterios(criterio,i,actual,anterior,functions.e(actual),functions.e(anterior))){
		anterior = actual;
		actual = anterior - functions.e(anterior)/functions.e_deriv(anterior);
		++i;
		os << actual << " " << functions.e(actual) << endl;
	}
	return actual;
}

double Metodos::Secante_f(int criterio,ostream&os)
{
	return Secante_f_aux(criterio,os,true,0,0.0,0.0);
}

double Metodos::Secante_f(int criterio,ostream &os,int cantItBis)
{
	return Secante_f_aux(criterio,os,true,cantItBis,0.0,0.0);
}

double Metodos::Secante_f(int criterio,ostream &os,double seed1,double seed2)
{
	return Secante_f_aux(criterio,os,false,-1,seed1,seed2);
}


double Metodos::Secante_f_aux(int criterio,ostream& os,bool hacerBiseccion, int cantItBis,double seed1, double seed2){
	double actual, anterior;
	if(hacerBiseccion){
		pair<double,double> seed =  functions.semillas_biseccion_f(cantItBis);
		anterior = seed.first;
		actual = seed.second;
	}
	else{
		actual = seed1;
		anterior = seed2;
	}
	double prox;	//X_2
	int i = 0;

	while(!criterios.criterios(criterio,i,actual,anterior,functions.f(actual),functions.f(anterior))){
		prox = actual - (functions.f(actual)*(actual-anterior)/(functions.f(actual)-functions.f(anterior)));
		anterior = actual;
		actual = prox;
		++i;
		os << prox << " " << functions.f(prox) << endl;
	}
	return actual;
}

double Metodos::Secante_e(int criterio,ostream&os)
{
	return Secante_e_aux(criterio,os,true,0,0.0,0.0);
}

double Metodos::Secante_e(int criterio,ostream &os,int cantItBis)
{
	return Secante_e_aux(criterio,os,true,cantItBis,0.0,0.0);
}

double Metodos::Secante_e(int criterio,ostream &os,double seed1,double seed2)
{
	return Secante_e_aux(criterio,os,false,-1,seed1,seed2);
}

double Metodos::Secante_e_aux(int criterio,ostream& os,bool hacerBiseccion,int cantItBis,double seed1,double seed2){
	double actual, anterior;
	if(hacerBiseccion){
		pair<double,double> seed =  functions.semillas_biseccion_e(cantItBis);
		anterior = seed.first;
		actual = seed.second;
	}
	else{
		actual = seed1;
		anterior = seed2;
	}
	double prox;
	int i = 0;
	while(!criterios.criterios(criterio,i,actual,anterior,functions.e(actual),functions.e(anterior))){
		prox = actual - ((functions.e(actual)*(actual-anterior))/(functions.e(actual)-functions.e(anterior)));
		anterior = actual;
		actual = prox;
		++i;
		os << prox << " " << functions.e(prox) << endl;
	}
	return actual;
}