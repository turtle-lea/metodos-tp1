#include "../include/metodos.h"
#include "../include/funciones.h"
#include "../include/criterios.h"

using namespace std;

int main()
{
	float alfa;
	float prec;
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
		cout << alfa << endl;
		ms.test_f_Newton(cout,criterio);
		cin >> c;
	}
	return 0;
}
