#include "../include/funciones.h"
#include "../include/metodos.h"
#include "../include/criterios.h"

using namespace std;

int main()
{
	int itbis;
	double alfa;
	double prec = 0.00000001;
	int maxIter = 30;
	int criterio = 3;
	char c;
	cin >> c;
	while(c != '#'){
		cin.putback(c);
		cin >> alfa;
		Funciones fs(alfa);
		//cin >> maxIter;
		//cin >> prec;
		Criterios cs(maxIter,prec);
		Metodos ms(fs,cs);
		//cin >> criterio;
		cout << alfa << " " << ms.cero_teorico() << endl;
		for(itbis = 0; itbis < 31; itbis++)
			{cout << itbis << " "; ms.Newton_f(criterio,cout,itbis);}
		cout << "H" << endl;
		for(itbis = 0; itbis < 31; itbis++)
			{cout << itbis << " "; ms.Secante_f(criterio,cout,itbis);}
		cout << "H" << endl;
/*		for(itbis = 0; itbis < 31; itbis++)
			{cout << itbis << " "; ms.Regula_falsi_f(criterio,cout,itbis);}
		cout << "H" << endl;*/
		for(itbis = 0; itbis < 31; itbis++)
			{cout << itbis << " "; ms.Newton_e(criterio,cout,itbis);}
		cout << "H" << endl;
		for(itbis = 0; itbis < 31; itbis++)
			{cout << itbis << " "; ms.Secante_e(criterio,cout,itbis);}
		cout << "H" << endl;
/*		for(itbis = 0; itbis < 31; itbis++)
			{cout << itbis << " "; ms.Regula_falsi_e(criterio,cout,itbis);}*/
		cin >> c;
	}
	return 0;
}
