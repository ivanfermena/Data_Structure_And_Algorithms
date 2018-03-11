// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void resolver(std::vector <int> & vc) {

	int j = 0;
	bool isZero = false;

	while (j < vc.size() && !isZero) {
		if (vc[j] == 0) {
			isZero = true;
			std::swap(vc[0], vc[j]);
		}
		j++;
	}

	int k = 1, i = 1;

	if (isZero && vc.size() > 1) {
		while (i < vc.size()) {
			if (vc[k - 1] % 2 == vc[i] % 2) ++i;
			else {
				std::swap(vc[i], vc[k]);
				k++;
			}
		}

		if (k % 2 == 1) vc.resize(k - 1);
		else vc.resize(k);

	}
	else vc.resize(0);
}

bool resuelveCaso() {

	int numElem;

	std::cin >> numElem;

	if (!std::cin)
		return false;

	std::vector <int> vc(numElem);

	for (int &aux : vc)
		std::cin >> aux;

	resolver(vc);

	for (int &aux : vc)
		std::cout << aux << " ";

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