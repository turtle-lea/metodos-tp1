#include "../include/metodos.h"
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

float Metodos::Biseccion_f(int criterio,ostream& os){
	int i = 0;
	float res;
	pair<float, float> seed = functions.semillas_biseccion_f(0);
	float positivo = seed.first;
	float negativo = seed.second;
	float medio = positivo;//X_1
	float anterior = negativo;//X_0

	while (!criterios.criterios(criterio,i,medio,anterior,functions.f(medio),functions.f(anterior))){
		anterior = medio;
		medio = (positivo+negativo)/2;
		
		if ( (this->functions).f(medio) < 0 ){negativo = medio; }
		else { positivo = medio; }
		
		res = medio;
		i++;
		os << res << " " << functions.f(res) << endl;
	}
	/*
	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << res << endl; 
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).f(res)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	*/
	return res;	
}

float Metodos::Biseccion_e(int criterio,ostream& os){
	int i = 0;
	float res;
	pair<float, float> seed = functions.semillas_biseccion_e(0);
	float positivo = seed.first;
	float negativo = seed.second;
	float medio = positivo;//X_1
	float anterior = negativo;//X_0
	while (!criterios.criterios(criterio,i,medio,anterior,functions.e(medio),functions.e(anterior))){
		anterior = medio;
		medio = (positivo+negativo)/2;
		
		if (functions.e(medio) < 0 ) { negativo = medio; }
		else { positivo = medio; }
		
		res = medio;
		i++;
		os << res << " " << functions.e(res) << endl;
	}
	/*
	cout << "Cero teórico: " << 1.0/(this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << res << endl;
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).e(res)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	*/
	return res;	
}

float Metodos::Newton_f(int criterio,ostream&os)
{
	return Newton_f_aux(criterio,os,true,0,0.0);
}

float Metodos::Newton_f(int criterio,ostream &os,int cantItBis)
{
	return Newton_f_aux(criterio,os,true,cantItBis,0.0);
}

float Metodos::Newton_f(int criterio,ostream &os,float seed)
{
	return Newton_f_aux(criterio,os,false,-1,seed);
}

float Metodos::Newton_f_aux(int criterio,ostream& os,bool hacerBiseccion, int cantItBis,float x_0){
	float actual, anterior;
	if(hacerBiseccion){
		pair<float,float> seed =  functions.semillas_biseccion_f(cantItBis);
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
		actual = anterior - functions.f(anterior)/functions.f_deriv(anterior);
		anterior = actual;
		++i;
		os << actual << " " << functions.f(actual) << endl;
	}
	/*
	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << actual << endl;
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).f(actual)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	*/
	return actual;
}

float Metodos::Newton_e(int criterio,ostream&os)
{
	return Newton_e_aux(criterio,os,true,0,0.0);
}

float Metodos::Newton_e(int criterio,ostream &os,int cantItBis)
{
	return Newton_e_aux(criterio,os,true,cantItBis,0.0);
}

float Metodos::Newton_e(int criterio,ostream &os,float seed)
{
	return Newton_e_aux(criterio,os,false,-1,seed);
}

float Metodos::Newton_e_aux(int criterio,ostream& os,bool hacerBiseccion, int cantItBis, float x_0){
	float actual, anterior;
	if(hacerBiseccion){
		pair<float,float> seed =  functions.semillas_biseccion_e(cantItBis);
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
		actual = anterior - functions.e(anterior)/functions.e_deriv(anterior);
		anterior = actual;
		++i;
		os << actual << " " << functions.e(actual) << endl;
	}
	/*
	cout << "Cero teórico: " << 1.0/(this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << actual << endl;
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).e(actual)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	*/
	return actual;
}

float Metodos::Secante_f(int criterio,ostream&os)
{
	return Secante_f_aux(criterio,os,true,0,0.0,0.0);
}

float Metodos::Secante_f(int criterio,ostream &os,int cantItBis)
{
	return Secante_f_aux(criterio,os,true,cantItBis,0.0,0.0);
}

float Metodos::Secante_f(int criterio,ostream &os,float seed1,float seed2)
{
	return Secante_f_aux(criterio,os,false,-1,seed1,seed2);
}


float Metodos::Secante_f_aux(int criterio,ostream& os,bool hacerBiseccion, int cantItBis,float seed1, float seed2){
	float actual, anterior;
	if(hacerBiseccion){
		pair<float,float> seed =  functions.semillas_biseccion_f(cantItBis);
		anterior = seed.first;
		actual = seed.second;
	}
	else{
		actual = seed1;
		anterior = seed2;
	}
	float prox;	//X_2
	int i = 0;

	while(!criterios.criterios(criterio,i,actual,anterior,functions.f(actual),functions.f(anterior))){
		prox = actual - (functions.f(actual)*(actual-anterior)/(functions.f(actual)-functions.f(anterior)));
		anterior = actual;
		actual = prox;
		++i;
		os << prox << " " << functions.f(prox) << endl;
	}
	/*
	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << actual << endl;
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).f(actual)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	*/
	return actual;
}

float Metodos::Secante_e(int criterio,ostream&os)
{
	return Secante_e_aux(criterio,os,true,0,0.0,0.0);
}

float Metodos::Secante_e(int criterio,ostream &os,int cantItBis)
{
	return Secante_e_aux(criterio,os,true,cantItBis,0.0,0.0);
}

float Metodos::Secante_e(int criterio,ostream &os,float seed1,float seed2)
{
	return Secante_e_aux(criterio,os,false,-1,seed1,seed2);
}

float Metodos::Secante_e_aux(int criterio,ostream& os,bool hacerBiseccion,int cantItBis,float seed1,float seed2){
	float actual, anterior;
	if(hacerBiseccion){
		pair<float,float> seed =  functions.semillas_biseccion_e(cantItBis);
		anterior = seed.first;
		actual = seed.second;
	}
	else{
		actual = seed1;
		anterior = seed2;
	}
	float prox;
	int i = 0;

	while(!criterios.criterios(criterio,i,actual,anterior,functions.e(actual),functions.e(anterior))){
		prox = actual - ((functions.e(actual)*(actual-anterior))/(functions.e(actual)-functions.e(anterior)));
		anterior = actual;
		actual = prox;
		++i;
		os << prox << " " << functions.e(prox) << endl;
	}
	/*
	cout << "Cero teórico: " << 1.0/(this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << actual << endl;
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).e(actual)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	*/
	return actual;
}

float Metodos::Regula_falsi_f(int criterio,ostream&os)
{
	return Regula_falsi_f_aux(criterio,os,true,0,0.0,0.0);
}

float Metodos::Regula_falsi_f(int criterio,ostream &os,int cantItBis)
{
	return Regula_falsi_f_aux(criterio,os,true,cantItBis,0.0,0.0);
}

float Metodos::Regula_falsi_f(int criterio,ostream &os,float seed1,float seed2)
{
	return Regula_falsi_f_aux(criterio,os,false,-1,seed1,seed2);
}

float Metodos::Regula_falsi_f_aux(int criterio,ostream& os,bool hacerBiseccion,int cantItBis,float seed1,float seed2){
	float positivo, negativo;
	if(hacerBiseccion){
		pair<float,float> seed =  functions.semillas_biseccion_f(cantItBis);
		positivo = seed.first;
		negativo = seed.second;
	}
	else{
		assert(functions.f(seed1)*functions.f(seed2) < 0);
		positivo = seed1;
		negativo = seed2;
	}
	float prox;
	int i = 0;

	while(!criterios.criterios(criterio,i,negativo,positivo,functions.f(negativo),functions.f(positivo))){
		prox = negativo - (functions.f(negativo)*(negativo-positivo)/(functions.f(negativo)-functions.f(positivo)));
		
		if(prox > 0) positivo = prox;
		else negativo = prox;
		++i;
		os << prox << " " << functions.f(prox) << endl;
	}
	/*
	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << prox << endl;
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).f(prox)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	*/
	return prox;
}

float Metodos::Regula_falsi_e(int criterio,ostream&os)
{
	return Regula_falsi_e_aux(criterio,os,true,0,0.0,0.0);
}

float Metodos::Regula_falsi_e(int criterio,ostream &os,int cantItBis)
{
	return Regula_falsi_e_aux(criterio,os,true,cantItBis,0.0,0.0);
}

float Metodos::Regula_falsi_e(int criterio,ostream &os,float seed1,float seed2)
{
	return Regula_falsi_e_aux(criterio,os,false,-1,seed1,seed2);
}

float Metodos::Regula_falsi_e_aux(int criterio,ostream& os,bool hacerBiseccion,int cantItBis,float seed1,float seed2){
	float positivo, negativo;
	if(hacerBiseccion){
		pair<float,float> seed =  functions.semillas_biseccion_e(cantItBis);
		positivo = seed.first;
		negativo = seed.second;
	}
	else{
		assert(functions.e(seed1)*functions.e(seed2) < 0);
		positivo = seed1;
		negativo = seed2;
	}
	float prox;
	int i = 0;

	while(!criterios.criterios(criterio,i,negativo,positivo,functions.e(negativo),functions.e(positivo))){
		prox = negativo - ((functions.e(negativo)*(negativo-positivo))/(functions.e(negativo)-functions.e(positivo)));
		
		if(prox > 0) positivo = prox;
		else negativo = prox;
		++i;
		os << prox << " " << functions.e(prox) << endl;
	}
	/*
	cout << "Cero teórico: " << 1.0/(this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << prox << endl;
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).e(prox)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	*/
	return prox;
}
