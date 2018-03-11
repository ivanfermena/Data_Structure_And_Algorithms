// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void calculadora(std::vector<std::vector<int>> teclas, int k, int numCal, int numUltimo) {

	while()
	{

	}

}

void resuelveCaso() {

	int numCal, numUltimo;

	std::cin >> numCal >> numUltimo;

	std::vector<std::vector<int>> teclas(3, std::vector<int>(3));
	int numeroAux = 1;

	for (int i = teclas.size(); i > 0; --i) {
		for (int j = 0; j < teclas.size(); j++) {
			teclas[i][j] = numeroAux;
			numeroAux++;
		}
	}

	calculadora(teclas, 0, numCal, numUltimo);
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