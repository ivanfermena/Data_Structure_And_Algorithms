// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector <int> const & vc, int ini, int fin) {

	if (ini + 1 == fin) {
		return 1;
	}
	else if (vc[ini] == vc[fin-1]) return 1;
	else {
		int mitad = (ini + fin) / 2;
		int tIzq = resolver(vc, ini, mitad);
		int tDer = resolver(vc, mitad, fin);
		if (vc[mitad] == vc[mitad-1]) return tIzq + tDer - 1;
		else if (vc[mitad] != vc[mitad-1]) return tIzq + tDer;
	}
	return 0;
}

bool resuelveCaso() {

	int numElem;
	int sol;

	std::cin >> numElem;

	if (!std::cin)
		return false;

	std::vector <int> vc(numElem);

	for (int &aux : vc) std::cin >> aux;

	sol = resolver(vc, 0, vc.size());

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