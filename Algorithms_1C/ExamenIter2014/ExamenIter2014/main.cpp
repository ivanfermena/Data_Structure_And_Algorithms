// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector <int> vc, int m) {

	int i = 0, sumParcial = 0, sumMax = 0, j = 0;

	while (i < m) {
		sumParcial += vc[i];
		i++;
	}

	sumMax = sumParcial;

	while (j < vc.size() - m) {
		sumParcial += vc[j + m] - vc[j];
		if (sumMax < sumParcial) sumMax = sumParcial;
		j++;
	}

	return sumMax;
}

bool resuelveCaso() {

	int numElem, numVentana;

	std::cin >> numElem;

	if (!std::cin)
		return false;

	std::cin >> numVentana;

	std::vector <int> vc(numElem);

	for (int &aux : vc)
		std::cin >> aux;

	int sol = resolver(vc, numVentana);

	std::cout << sol << "\n";

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