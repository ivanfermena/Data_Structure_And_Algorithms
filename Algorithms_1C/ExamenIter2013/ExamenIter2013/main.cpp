// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool resolver(std::vector <int> const & vc) {

	if (vc.size() == 0) return false;

	bool isExito = true, isZero = false;
	int i = 0;

	while (i < vc.size() && isExito){
		if (vc[i]==0 && !isZero) isZero = true;
		if (isZero && vc[i] == 1) isExito = false;
		i++;
	}
	return isExito;
}

bool resuelveCaso() {

	int numElem;

	std::cin >> numElem;

	if (!std::cin)
		return false;

	std::vector <int> vc(numElem);

	for (int &aux : vc)
		std::cin >> aux;

	bool sol = resolver(vc);

	if (sol) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";

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