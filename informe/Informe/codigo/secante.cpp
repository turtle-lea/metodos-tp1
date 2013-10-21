double Metodos::Secante_f_aux(int criterio,ostream& os,bool hacerBiseccion, 
                              int cantItBis,double seed1, double seed2){

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

	while(!criterios.criterios(criterio,i,actual,anterior,
		functions.f(actual),functions.f(anterior))){

		prox = actual - (functions.f(actual)*(actual-anterior)/
						(functions.f(actual)-functions.f(anterior))); (**)

		anterior = actual;
		actual = prox;
		++i;
		os << prox << " " << functions.f(prox) << endl;
	}
	return actual;
}