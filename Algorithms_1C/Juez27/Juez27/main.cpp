// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

int battle(std::vector<int> &vc, int ini, int fin) {

	if (ini + 1 >= fin)
		return 0;
	else{
		int mitad = (ini + fin + 1) / 2; 
		int invIz = battle(vc, ini, mitad);
		int invDr = battle(vc, mitad, fin);
		int inv = 0, i = ini, j = mitad;

		while (i < mitad && j < fin){
			if (vc[i] > vc[j]){
				inv += mitad - i;
				++j;
			}
			else ++i;
		}

		std::vector<int> aux(fin - ini);
		std::merge(vc.begin() + ini, vc.begin() + mitad, vc.begin() + mitad, vc.begin() + fin, aux.begin());

		for (int k = 0; k < aux.size(); k++)
			vc[ini + k] = aux[k];

		return inv + invIz + invDr;
	}
}

bool resuelveCaso() {

	int numElem;

	std::cin >> numElem;

	if (!std::cin)
		return false;

	std::vector<int> vc(numElem);

	for (int &i : vc)
		std::cin >> i;

	int sol = battle(vc, 0, vc.size());

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