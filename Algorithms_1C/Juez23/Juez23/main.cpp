// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

char resolver(std::vector<char> const & v, int ini, int fin) {

	if (ini + 2 == fin)
		return v[ini] + 1;
	else {
		int mitad = (ini + fin) / 2;
		if(v[mitad] - v[0] == mitad) return resolver(v, mitad, fin);
		else return resolver(v, ini, mitad + 1);
	}
}

void resuelveCaso() {

	char firstElem, endElem, charSelect;
	std::vector<char> vc;

	std::cin >> firstElem;
	std::cin >> endElem;

	int numElem = endElem - firstElem;

	for (int i = 0; i < numElem; i++) {
		std::cin >> charSelect;
		vc.push_back(charSelect);
	}

	if (vc[0] != firstElem)
		std::cout << firstElem << "\n";
	else if(vc[vc.size()-1]!=endElem)
		std::cout << endElem << "\n";
	else
	{
		char sol = resolver(vc, 0, vc.size());
		std::cout << sol << "\n";
	}
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