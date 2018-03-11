// Ivan Fernandez Mena
// E13

// Poblema tiene coste O(n)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector <int> const &vc) {

	int pos=-1, countZeros = 0, countOne = 0;

	for (int i = 0; i < vc.size(); i++){

		if (vc[i]==0) countZeros++;
		else if (vc[i]==1)countOne++;
		
		if (countOne == countZeros)pos = i;
	}
	return pos;
}

void resuelveCaso() {

	int numElem, numSelect;

	std::cin >> numElem;
	std::vector<int> vc(numElem);

	for (int i = 0; i < numElem; i++){
		std::cin >> numSelect;
		vc[i] = numSelect;
	}

	 int sol = resolver(vc);
	 std::cout << sol << "\n";
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