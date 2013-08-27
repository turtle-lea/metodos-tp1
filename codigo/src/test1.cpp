#include "../include/metodos.h"
#include "../include/funciones.h"
#include "../include/criterios.h"

using namespace std;

int main()
{
	float alfa;
	float prec;
	int maxIter;
	char c;
	cin >> c;
	while(c != '#'){
		cin.putback(c);
		cin >> alfa;
		Funciones fs(alfa);
		for(maxIter = 20; maxIter <= 40;maxIter = maxIter*2){
			for(int i = 1; i <= 2; i++){
				for(int c = 1; c <=6; c++){ 
					prec = 1*pow(10,-i);
					cout << "Max. Iter: " << maxIter << " ";
					cout << "Epsilon: " << prec << endl;
					Criterios cs(maxIter,prec);
					Metodos ms(fs,cs);
					
					cout << "Biseccion f: " << endl;
					ms.Biseccion_f(c);
					cout << endl;

					cout << "Biseccion e: " << endl << endl;
					float aux = ms.Biseccion_e(c);
					cout << endl;

					cout << "Newton f: " << endl << endl;
					ms.Newton_f(c);
					cout << endl;

					cout << "Newton e: " << endl << endl;
					ms.Newton_e(c);
					cout << endl;

					cout << "Regula_falsi f: " << endl << endl;
					ms.Regula_falsi_f(c);
					cout << endl;

					cout << "Regula_falsi e: " << endl << endl;
					ms.Regula_falsi_e(c);
					cout << endl;

					cout << "Secante f: " << endl << endl;
					ms.Secante_f(c);
					cout << endl;

					cout << "Secante e: " << endl << endl;
					ms.Secante_e(c);
					cout << endl;
				}
			}
		}
		cin >> c;
	}
	return 0;
}
