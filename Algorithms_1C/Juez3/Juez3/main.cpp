// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
bool resolver(std::vector<int> const & vc, int p) {

	bool result = true;
	int max = vc[0];

	for (int i = 1; i <= p; ++i) {
		if (vc[i]>max) max = vc[i];
	}
	int j = p + 1;
	while (result && j < vc.size()) {
		if (vc[j] <= max){
			result = false;
		}
		j++;
	}

	return result;
}

void resuelveCaso() {
	int countNumbers, p;
	std::cin >> countNumbers;
	std::cin >> p;

	std::vector<int> vc(countNumbers);

	for (int& c : vc)
		std::cin >> c;

	bool sol = resolver(vc, p);

	if (sol)
		std::cout << "SI" << std::endl;
	else
		std::cout << "NO" << std::endl;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
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