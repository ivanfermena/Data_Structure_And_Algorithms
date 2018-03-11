// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
Coste es O(n)
*/

bool crecientePelos(std::vector<int> const & vc, int ini, int fin) {
	
	bool sol = false;
	
	if (ini + 2 == fin){
		if (vc[ini+1] - vc[ini] == 1 || vc[ini+1] - vc[ini] == 0){
			sol = true;
		}else{
			sol = false;
		}
	}
	else{
		int mitad = (ini + fin) / 2;
		bool tSolIzq = crecientePelos(vc, ini, mitad+1);
		bool tSolDer = crecientePelos(vc, mitad, fin);
		sol = tSolDer && tSolIzq;
		if ((vc.size()+1)/2 == mitad && vc[mitad] - vc[mitad - 1] != 1 && vc[mitad] - vc[mitad - 1] != 0) {
			sol = false;
		}
	}
	return sol;
}

void resuelveCaso() {

	int numElem;
	bool sol;

	std::cin >> numElem;

	if (numElem == 0) sol = false;	
	else{
		std::vector<int> vc(numElem);
		for (int & aux : vc) std::cin >> aux; // Llemando el vector

		sol = crecientePelos(vc, 0, vc.size());
	}

	if (sol) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}