// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
void funcionarios(std::vector<std::vector<long int> > const & m, int k, std::vector<bool> & marcas, long int & sumMin, long int & sum) {
	for (int t = 0; t < m[0].size(); t++) {
		sum += m[k][t];
		if (!marcas[t]) {
			if (k + 1 == marcas.size()) {
				if (sum < sumMin) sumMin = sum;
			}
			else {
				//Marcas y desmarcar siempre en el mismo bucle.
				marcas[t] = true;
				funcionarios(m, k + 1, marcas, sumMin, sum);
				marcas[t] = false;
			}
		}
		sum -= m[k][t];
	}
}

bool resuelveCaso() {
	int numElem;
	std::cin >> numElem;
	if (numElem == 0)
		return false;
	std::vector<std::vector<long int> > m(numElem, (std::vector<long int>(numElem)));
	long int sumMin = 10000 * numElem, sum = 0;
	for (int u = 0; u < numElem; u++) sumMin += m[u][u]; // Inicializacion de sumMin con la primera diagonal, la primera posible combinacion
	for (int x = 0; x < numElem; x++) // Entrada en la matriz
		for (int y = 0; y < numElem; y++)
			std::cin >> m[x][y];
	std::vector<bool> marcas(numElem); // Vector para controlar el marcaje de los trabajadores
	for (int i = 0; i < numElem; i++) // Inicializacion del vector de marcas a falsos
		marcas[i] = false;
	funcionarios(m, 0, marcas, sumMin, sum);
	std::cout << sumMin << "\n";
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