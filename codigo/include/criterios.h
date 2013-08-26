#ifndef CRITERIOS_H
#define CRITERIOS_H

class Criterios{
	public:
		Criterios(){}
		Criterios(int x, float e):max_iter(x),epsilon(e){}

		//N = max_iter 
		bool criterio1_parar(int x){return x >= max_iter;}

		// |x - x_anterior| < epsilon
		bool criterio2_parar(float x, float x_anterior);

		// ( |x - x_anterior| / |x_anterior| ) < epsilon
		bool criterio2_bis_parar(float x, float x_anterior);

		// |f(x)| < epsilon
		bool criterio3_parar(float y);

		// |f(x) - f(x_anterior)| < epsilon
		bool criterio4_parar(float y, float y_anterior);

		// ( |f(x) - f(x_anterior)| / |f(x_anterior)| ) < epsilon
		bool criterio4_bis_parar(float y, float y_anterior);

	private:
		int max_iter;
		float epsilon;
};

#endif
