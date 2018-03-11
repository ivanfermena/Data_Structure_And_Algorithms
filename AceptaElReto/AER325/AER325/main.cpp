// Ivan Fernandez Mena
// ivanfermena

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void escribir(std::vector<int> const & vc, bool & printSpace) {
	if (!printSpace) printSpace = true;
	else std::cout << " ";
	for (int x = 0; x < vc.size(); x++) {
		if (vc[x] == 0) std::cout << 'C';
		else std::cout << 'V';
	}
}

void cucurucho(std::vector<int> & sol, int k, int numChoco, int numVan, int & usadosChoco, int & usadosVan, bool & pintarEspacio) {
	for (int i = 0; i < 2; i++) { 
		sol[k] = i;
		if (i == 0) usadosChoco++;
		else usadosVan++;
		if (usadosChoco <= numChoco && usadosVan <= numVan) {
			if (k + 1 == sol.size()) escribir(sol, pintarEspacio);
			else cucurucho(sol, k + 1, numChoco, numVan, usadosChoco, usadosVan, pintarEspacio);
		}
		if (i == 0) usadosChoco--;
		else usadosVan--;
	}
}

void resuelveCaso() {
	// leer los datos de la entrada
	int numChoco, numVan, usadosChoco = 0, usadosVan = 0;
	std::cin >> numChoco >> numVan;
	std::vector<int> sol(numChoco + numVan);
	bool pintarEspacio = false;
	cucurucho(sol, 0, numChoco, numVan, usadosChoco, usadosVan, pintarEspacio);
	std::cout << "\n";
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