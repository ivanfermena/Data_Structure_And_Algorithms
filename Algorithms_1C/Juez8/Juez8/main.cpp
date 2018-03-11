// Ivan Fernandez Mena
// E13

// Tiene un coste de O(n)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void resolver(std::vector<int> const &vc, int heigth, int &ini, int &posEnd) {

	int iniUltSeg = 0, maxLong = 0;
	ini = 0;

	for (int i = 0; i < vc.size(); i++) {
		if (vc[i] > heigth) {
			if (maxLong < i - iniUltSeg + 1) {
				ini = iniUltSeg;
				maxLong = i - iniUltSeg + 1;
			}
		}
		else { iniUltSeg = i + 1; }
	}
	posEnd = ini + maxLong - 1;
}

void resuelveCaso() {

	int numElem, height, numSelect, posIni, posEnd;

	std::cin >> numElem;
	std::cin >> height;

	std::vector<int> vc(numElem);

	for (int i = 0; i < numElem; i++) {
		std::cin >> numSelect;
		vc[i] = numSelect;
	}

	resolver(vc, height, posIni, posEnd);
	std::cout << posIni << " " << posEnd << "\n";
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