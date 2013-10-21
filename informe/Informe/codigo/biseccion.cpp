double Metodos::Biseccion_f_aux(int criterio,ostream& os,double seed1,double seed2){
	int i = 0;
	double res;
	double positivo = seed1;
	double negativo = seed2;
	double medio = positivo;//X_1
	double anterior = negativo;//X_0

	// La guarda del ciclo evalua el criterio de parada correspondiente (determinado por el parametro criterio),
	// con los parametros necesarios: numero de iteracion, valores de x_n, x_(n-1), f(x_n), etc .

	while (!criterios.criterios(criterio,i,medio,anterior,
			functions.f(medio),functions.f(anterior))){
		
		anterior = medio;
		medio = (positivo+negativo)/2;
		
		if ( (this->functions).f(medio) < 0 ){negativo = medio; }
		else { positivo = medio; }
		
		res = medio;
		i++;
		//Muestro si el metodo converge o no a la raiz
		os << res << " " << functions.f(res) << endl;
	}
	return res;
}