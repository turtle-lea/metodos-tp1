#include "../include/metodos.h"
#include <iostream>
#include <cmath>

using namespace std;

float Metodos::Biseccion_f(int criterio){
	int i = 0;
	float res;
	pair<float, float> seed = (this->functions).semillas_biseccion_f();
	float positivo = seed.first;
	float negativo = seed.second;
	float medio = positivo;
	float anterior = negativo;

	while (!(this->criterios).criterios(criterio,i,medio,anterior,functions.f(medio),functions.f(anterior))){
		anterior = medio;
		medio = (positivo+negativo)/2;
		
		if ( (this->functions).f(medio) < 0 ){negativo = medio; }
		else { positivo = medio; }
		
		res = medio;
		i++;
	}
	
	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << res << endl; 
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).f(res)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;

	return res;	
}

float Metodos::Biseccion_e(int criterio){
	int i = 0;
	float res;
	pair<float, float> seed = (this->functions).semillas_biseccion_e();
	float positivo = seed.first;
	float negativo = seed.second;
	float medio = positivo;
	float anterior = negativo;
	while (!(this->criterios).criterios(criterio,i,medio,anterior,functions.e(medio),functions.e(anterior))){
		anterior = medio;
		medio = (positivo+negativo)/2;
		
		if ( (this->functions).e(medio) < 0 ) { negativo = medio; }
		else { positivo = medio; }
		
		res = medio;
		i++;
	}
	
	cout << "Cero teórico: " << 1.0/(this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << res << endl;
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).e(res)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	return res;	
}

float Metodos::Newton_f(int criterio){
	//float anterior = Biseccion_f();
	float anterior = 3.0;
	float actual;
	int i = 0;

	while(!(this->criterios).criterios(criterio,i,actual,anterior,functions.f(actual),functions.f(anterior))){
		actual = anterior - functions.f(anterior)/functions.f_deriv(anterior);
		anterior = actual;
		++i;
	}
	
	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << actual << endl;
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).f(actual)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	return actual;
}

void Metodos::test_f_Newton(ostream& os,int criterio){
	//float anterior = Biseccion_f();
	float anterior = 3.0;
	float actual = 3.0;
	int i = 0;
	os << actual << " " << this->functions.f(actual) << endl;
	while(!(this->criterios).criterios(criterio,i,actual,anterior,functions.f(actual),functions.f(anterior))){
		actual = anterior - functions.f(anterior)/functions.f_deriv(anterior);
		anterior = actual;
		++i;
		os << actual << " " << this->functions.f(actual) << endl;
	}
}

float Metodos::Newton_e(int criterio){
	//float anterior = Biseccion_e();
	float anterior = 0.5;
	float actual;
	int i = 0;

	while(!(this->criterios).criterios(criterio,i,actual,anterior,functions.e(actual),functions.e(anterior))){
		actual = anterior - functions.e(anterior)/functions.e_deriv(anterior);
		anterior = actual;
		++i;
	}
	
	cout << "Cero teórico: " << 1.0/(this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << actual << endl;
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).e(actual)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	return actual;
}
///FALTA VER CRITERIOS PARA TODOS! ---------------------------------------------------------------------------------------------------------------------

float Metodos::Secante_f(int criterio){
	pair<float,float> xceros = (this->functions).semillas_biseccion_f();
	float anterior = xceros.first;	/// = xn-1
	float actual = xceros.second;	/// = xn
	float prox;	/// = xn+1
	int i = 0;

	while(!(this->criterios).criterios(criterio,i,actual,anterior,functions.f(actual),functions.f(anterior))){
		prox = actual - (functions.f(actual)*(actual-anterior)/(functions.f(actual)-functions.f(anterior)));
		anterior = actual;
		actual = prox;
		++i;
	}

	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << actual << endl;
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).f(actual)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	return actual;
}

float Metodos::Secante_e(int criterio){
	pair<float,float> xceros = (this->functions).semillas_biseccion_e();
	//float anterior = xceros.first;	/// = xn-1
	//float actual = xceros.second;	/// = xn
	float anterior = 0.9;
	float actual = 0.6;
	float prox;	/// = xn+1
	int i = 0;

	while(!(this->criterios).criterios(criterio,i,actual,anterior,functions.e(actual),functions.e(anterior))){
		prox = actual - ((functions.e(actual)*(actual-anterior))/(functions.e(actual)-functions.e(anterior)));
		anterior = actual;
		actual = prox;
		++i;
	}
	
	cout << "Cero teórico: " << 1.0/(this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << actual << endl;
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).e(actual)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	return actual;
}

float Metodos::Regula_falsi_f(int criterio){
	pair<float,float> xceros = (this->functions).semillas_biseccion_f();
	float positivo = xceros.first;	/// = xn-1
	float negativo = xceros.second;	/// = xn
	float prox;	/// = xn+1
	int i = 0;

	while(!(this->criterios).criterios(criterio,i,negativo,positivo,functions.f(negativo),functions.f(positivo))){
		prox = negativo - (functions.f(negativo)*(negativo-positivo)/(functions.f(negativo)-functions.f(positivo)));
		
		if(prox > 0) positivo = prox;
		else negativo = prox;
		++i;
	}
	
	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << prox << endl;
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).f(prox)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	return prox;
}

float Metodos::Regula_falsi_e(int criterio){
	pair<float,float> xceros = (this->functions).semillas_biseccion_e();
	//float positivo = xceros.first;	/// = xn-1
	//float negativo = xceros.second;	/// = xn
	float positivo = 0.9;
	float negativo = 0.6;
	float prox;	/// = xn+1
	int i = 0;

	while(!(this->criterios).criterios(criterio,i,negativo,positivo,functions.e(negativo),functions.e(positivo))){
		prox = negativo - ((functions.e(negativo)*(negativo-positivo))/(functions.e(negativo)-functions.e(positivo)));
		
		if(prox > 0) positivo = prox;
		else negativo = prox;
		++i;
	}
	
	cout << "Cero teórico: " << 1.0/(this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << prox << endl;
	cout << "Me dio un buen cero ? El error es de: " << abs((this->functions).e(prox)) << endl;
	cout << "Cant. iter. realizadas: " << i << endl;
	return prox;
}