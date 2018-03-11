// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector <int> vc, int ini, int fin) {

	int min = vc[ini];

	if(ini + 1 != fin){
		int mitad = (ini + fin + 1) / 2;
		int solIz = resolver(vc, ini, mitad);
		int solDe = resolver(vc, mitad, fin);
		if (solDe < min) min = solDe;
		else if (solIz < min) min = solIz;
	}
	return min;
}

bool resuelveCaso() {

	int numElem;

	std::cin >> numElem;

	if (!std::cin)
		return false;

	std::vector <int> vc(numElem);

	for (int &aux : vc)
		std::cin >> aux;

	int sol = resolver(vc, 0, vc.size());

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