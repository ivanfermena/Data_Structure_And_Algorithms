// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

int resolver() {

	int raiz, suma = 0, sumaTotal = 0;
	std::cin >> raiz;

	if (raiz == 0) {
		return 1;
	}
	else {
		for (int i = 0; i < raiz; i++) {
			//suma = std::max(sumaTotal, resolver());
			suma = resolver() + 1;
			if (suma > sumaTotal) sumaTotal = suma;
		}
		
		return sumaTotal;
	}
	
}


void resuelveCaso() {

	int sumaTotal = 0;

	sumaTotal = resolver();

	std::cout << sumaTotal << "\n";

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