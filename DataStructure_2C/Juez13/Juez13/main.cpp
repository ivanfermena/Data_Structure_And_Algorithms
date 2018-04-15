// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

#include "binTree.h"

bool resuelveCaso() {

	char selec;
	std::cin >> selec;

	if (!std::cin)
		return false;

	if (selec == 'N') {
		int vacio = -1;
		bintree_ext<int> myBinTree = leerArbol_ext(vacio);
		std::cout << myBinTree.minimo() << "\n";
	}
	else if (selec == 'P') {
		std::string vacio = "#";
		bintree_ext<std::string> myBinTree = leerArbol_ext(vacio);
		std::cout << myBinTree.minimo() << "\n";
	}

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