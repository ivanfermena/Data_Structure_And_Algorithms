// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

#include "binTree.h"

void resuelveCaso() {

	bintree_ext<char> myBinTree = leerArbol_ext('.');

	int nodos = myBinTree.numNodos();
	int hojas = myBinTree.numHojas();
	int altura = myBinTree.altura();

	std::cout << nodos << " " << hojas << " " << altura << "\n";

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