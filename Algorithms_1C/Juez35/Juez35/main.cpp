// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void compras(std::vector<std::vector<int> > const & m, int k, std::vector<int> & marcas, bool & exito, long int & sum, long int & sumMin) {
	for (int x = 0; x < m.size(); x++) {
		sum += m[x][k];
		marcas[x]++;
		if (marcas[x] <= 3) {
			if (k + 1 == m[0].size()) {
				if (sum < sumMin) {
					sumMin = sum;
					exito = true;
				}
			}
			else compras(m, k + 1, marcas, exito, sum, sumMin);
		}
		marcas[x]--;
		sum -= m[x][k];
	}
}

void resuelveCaso() {

	int numSup, numProd;
	std::cin >> numSup >> numProd;
	if (numProd == 0) std::cout << "Sin solucion factible\n";
	else {
		std::vector<std::vector<int> > m(numSup, std::vector<int>(numProd));
		for (int i = 0; i < numSup; i++)
			for (int j = 0; j < numProd; j++) 
				std::cin >> m[i][j];
	
		std::vector<int> marcas(numSup);
		for (int r = 0; r < numSup; r++) 
			marcas[r] = 0;

		bool exito = false;
		long int sumMin = 99999999, sum = 0;
		compras(m, 0, marcas, exito, sum, sumMin);

			// escribir sol
		if (!exito) std::cout << "Sin solucion factible\n";
		else std::cout << sumMin << "\n";
	}
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