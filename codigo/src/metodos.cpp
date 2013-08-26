#include "../include/metodos.h"
#include <iostream>
#include <cmath>

using namespace std;

float Metodos::Biseccion_f(){
	int i = 0;
	float res;
	float positivo = (this->functions).semillas_biseccion_f().first;
	float negativo = (this->functions).semillas_biseccion_f().second;

	while (!(this->criterios).criterio1_parar(i)){
		float medio = (positivo+negativo)/2;
		
		if ( (this->functions).f(medio) < 0 ) { negativo = medio; }
		else { positivo = medio; }
		
		res = medio;
		i++;
	}
	
	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << res << endl;
	cout << "Me dio un buen cero ? El error es de: " << (this->functions).f(res) << endl;

	return res;	
}

float Metodos::Biseccion_e(){
	int i = 0;
	float res;
	float positivo = (this->functions).semillas_biseccion_e().first;
	float negativo = (this->functions).semillas_biseccion_e().second;

	while (!(this->criterios).criterio1_parar(i)){
		float medio = (positivo+negativo)/2;
		
		if ( (this->functions).e(medio) < 0 ) { negativo = medio; }
		else { positivo = medio; }
		
		res = medio;
		i++;
	}
	
	cout << "Cero teórico: " << 1.0/(this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << res << endl;
	cout << "Me dio un buen cero ? El error es de: " << (this->functions).e(res) << endl;

	return res;	
}

float Metodos::Newton_f(){
	//float anterior = Biseccion_f();
	float anterior = 3.0;
	float actual;
	int i = 0;

	while(!(this->criterios).criterio1_parar(i)){
		actual = anterior - functions.f(anterior)/functions.f_deriv(anterior);
		anterior = actual;
		++i;
	}
	
	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << actual << endl;
	return actual;
}

float Metodos::Newton_e(){
	//float anterior = Biseccion_e();
	float anterior = 0.5;
	float actual;
	int i = 0;

	while(!(this->criterios).criterio1_parar(i)){
		actual = anterior - functions.e(anterior)/functions.e_deriv(anterior);
		anterior = actual;
		++i;
	}
	
	cout << "Cero teórico: " << 1.0/(this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << actual << endl;
	return actual;
}
///FALTA VER CRITERIOS PARA TODOS! ---------------------------------------------------------------------------------------------------------------------

float Metodos::Secante_f(){
	pair<float,float> xceros = (this->functions).semillas_biseccion_f();
	float anterior = xceros.first;	/// = xn-1
	float actual = xceros.second;	/// = xn
	float prox;	/// = xn+1
	int i = 0;

	while(!(this->criterios).criterio1_parar(i) && !(this->criterios).criterio3_parar(functions.f(actual))){
		prox = actual - (functions.f(actual)*(actual-anterior)/(functions.f(actual)-functions.f(anterior)));
		anterior = actual;
		actual = prox;
		++i;
	}

	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << actual << endl;
	cout << "Iteraciones: " << i << endl;
	return actual;
}

float Metodos::Secante_e(){
	pair<float,float> xceros = (this->functions).semillas_biseccion_e();
	float anterior = xceros.first;	/// = xn-1
	float actual = xceros.second;	/// = xn
	float prox;	/// = xn+1
	int i = 0;

//	while(!(this->criterios).criterio1_parar(i) && !(this->criterios).criterio3_parar(functions.e(actual))){
		prox = actual - (functions.e(actual)*(actual-anterior)/(functions.e(actual)-functions.e(anterior)));
		anterior = actual;
		actual = prox;
		++i;
//	}
		prox = actual - (functions.e(actual)*(actual-anterior)/(functions.e(actual)-functions.e(anterior)));
		anterior = actual;
		actual = prox;
		++i;
			prox = actual - (functions.e(actual)*(actual-anterior)/(functions.e(actual)-functions.e(anterior)));
		anterior = actual;
		actual = prox;
		++i;
	
	
	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << actual << endl;
	cout << "Iteraciones: " << i << endl;
	return actual;
}

float Metodos::Regula_falsi_f(){
	pair<float,float> xceros = (this->functions).semillas_biseccion_f();
	float positivo = xceros.first;	/// = xn-1
	float negativo = xceros.second;	/// = xn
	float prox;	/// = xn+1
	int i = 0;

	while(!(this->criterios).criterio1_parar(i)){
		prox = negativo - (functions.f(negativo)*(negativo-positivo)/(functions.f(negativo)-functions.f(positivo)));
		
		if(prox > 0) positivo = prox;
		else negativo = prox;
		++i;
	}
	
	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << prox << endl;
	return prox;
}

float Metodos::Regula_falsi_e(){
	pair<float,float> xceros = (this->functions).semillas_biseccion_e();
	float positivo = xceros.first;	/// = xn-1
	float negativo = xceros.second;	/// = xn
	float prox;	/// = xn+1
	int i = 0;

	while(!(this->criterios).criterio1_parar(i)){
		prox = negativo - (functions.e(negativo)*(negativo-positivo)/(functions.e(negativo)-functions.e(positivo)));
		
		if(prox > 0) positivo = prox;
		else negativo = prox;
		++i;
	}
	
	cout << "Cero teórico: " << (this->functions).cero_teorico() << endl;
	cout << "Raiz obtenida: " << prox << endl;
	return prox;
}



