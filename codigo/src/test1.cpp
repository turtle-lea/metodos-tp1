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
		for(maxIter = 20; maxIter < 1000;maxIter = maxIter*2){
			cout << "Max. Iter: " << maxIter << endl;
			for(int i = 1; i <= 7; i++){
				prec = 1*pow(10,-i);
				cout << "\tEpsilon: " << prec << endl;
			}
		}
		
	}
	return 0;
}
