double Metodos::Newton_f_aux(int criterio,ostream& os,
		bool hacerBiseccion, int cantItBis,double x_0){
	
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
	
	while(!criterios.criterios(criterio,i,actual,anterior,
			functions.f(actual),functions.f(anterior))){ 

		anterior = actual;
		actual = anterior - (functions.f(anterior)/functions.f_deriv(anterior)); (*)
		++i;
		os << actual << " " << functions.f(actual) << endl;
	}
	return actual;
}