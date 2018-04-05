// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

int resolver(int minBecario, int nivel) {

	int raiz, sumaTotal = 0;
	std::cin >> raiz;

	if (raiz == 0) {
		if(nivel >= minBecario) return 1;
		else return 0;
	}
	else {
		for (int i = 0; i < raiz; i++) {
			sumaTotal += resolver(minBecario, nivel + 1);
		}

		return sumaTotal;
	}
}


bool resuelveCaso() {

	int sumaTotal = 0, minBecario = 0, nivel = 0;

	std::cin >> minBecario;

	if (!std::cin)
		return false;

	sumaTotal = resolver(minBecario, nivel);

	std::cout << sumaTotal << "\n";

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