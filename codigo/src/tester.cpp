#include "../include/metodos.h"
#include "../include/funciones.h"
#include "../include/criterios.h"

using namespace std;

int main()
{
	double alfa;
	double prec;
	int maxIter;
	int criterio;
	char c;
	cin >> c;
	while(c != '#'){
		cin.putback(c);
		cin >> alfa;
		Funciones fs(alfa);
		cin >> maxIter;
		cin >> prec;
		Criterios cs(maxIter,prec);
		Metodos ms(fs,cs);
		cin >> criterio;
		cout << alfa << " " << ms.cero_teorico_e() << endl;;
		ms.Biseccion_e(criterio,cout);
		cin >> c;
	}
	return 0;
}
