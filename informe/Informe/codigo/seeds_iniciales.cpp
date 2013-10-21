pair<double,double> Funciones::semillas_biseccion_f(int cantItDeseadas){
	pair<double,double> res;
	if (abs(this->alpha) < 1){
		res.first = 1.0;
		res.second = alpha;
	}
	else { 
		res.first = alpha;
		res.second = 1.0;
	} (*)

	int i = 0;
	double positivo = res.first;
	double negativo = res.second;
	double medio;

	while (i < cantItDeseadas){
		medio = (positivo+negativo)/2;
		if (f(medio) < 0 ){
			negativo = medio;
			res.second = medio;
		}
		else{
			positivo = medio;
			res.first = medio;
		}
		i++;
	}
	return res;
}


pair<double,double> Funciones::semillas_biseccion_e(int cantItDeseadas){
	pair<double,double> res;
	if (abs(this->alpha) > 1){
		res.first = 1.0/alpha;
		res.second = alpha;
	}
	else{
		res.first = alpha;
		res.second = 1.0/alpha;
	} (**)

	int i = 0;
	double positivo = res.first;
	double negativo = res.second;
	double medio;

	while (i < cantItDeseadas){
		medio = (positivo+negativo)/2;
		
		if(e(medio) < 0 ){
			negativo = medio;
			res.second = medio;
		}
		else{
			positivo = medio;
			res.first = medio;
		}
		i++;
	}
	return res;
}
