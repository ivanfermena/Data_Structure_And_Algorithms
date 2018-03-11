// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector<int> const & vc, int ini, int fin) {
	
	int sol;

	if (ini + 1 == fin){
		sol = ini;
	}else {
		if (vc[ini] != vc[ini + 1]) sol = ini;
		else sol = resolver(vc, ini + 2, fin);
	}
	return sol;
}

void resuelveCaso() {

	int numElem;
	std::cin >> numElem;
	std::vector<int> vc(numElem);

	for (int &aux : vc)
		std::cin >> aux;

	int strSol = resolver(vc, 0, vc.size());
	std::cout << strSol << "\n";
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