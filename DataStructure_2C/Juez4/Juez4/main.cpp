// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "Monomio.h"
#include "Polinomio.h"

inline std::istream & operator >> (std::istream & in, Monomio & rhs) {
	int auxCoeficiente, auxExponencial;

	in >> auxCoeficiente >> auxExponencial;
	rhs = Monomio(auxCoeficiente, auxExponencial);
	return in;
}

bool resuelveCaso() {

	Monomio mono;
	Polinomio poli;
	int numTests, sol;

	std::cin >> mono;

	if (!std::cin)
		return false;

	while (!mono.isEndLine()) {
		poli.addMonomio(mono);
		std::cin >> mono;
	}

	std::cin >> numTests;
	std::vector<int> vcValores(numTests);

	for (int i = 0; i < vcValores.size(); i++)
		std::cin >> vcValores[i];



	for (int i = 0; i < vcValores.size(); i++) {
		sol = poli.calculatePolinomio(vcValores[i]);
		std::cout << sol << " ";
	}

	std::cout << "\n";

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}