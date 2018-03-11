// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Complejo.h"

inline std::istream & operator >> (std::istream & in, Complejo & rhs) {
	float auxReal, auxImg;
	int auxIter;
	in >> auxReal >> auxImg >> auxIter;
	rhs = Complejo(auxReal, auxImg, auxIter);
	return in;
}

void resuelveCaso() {
	
	Complejo comp;

	std::cin >> comp;

	int i = 0;
	bool control = true;
	Complejo conjunto = comp;

	while (i < comp.get_numeroIter() && control) {

		if ((conjunto%conjunto) > 2) {
			control = false;
		}

		conjunto = (conjunto * conjunto) + comp;

		i++;
	}

	if (control) {
		std::cout << "SI\n";
	} else std::cout << "NO\n";
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