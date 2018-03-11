// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "queue_eda.h"

template <class T>
inline std::istream & operator >> (std::istream & in, queue<T> & rhs) {

	int numberAux;
	in >> numberAux;

	while (numberAux != 0 && std::cin) {
		rhs.push(numberAux);
		in >> numberAux;
	}

	return in;
}

bool resuelveCaso() {

	queue<int> colaDinamica;
	queue<int> copiaColaDinamica;

	std::cin >> colaDinamica;

	if (!std::cin)
		return false;

	copiaColaDinamica.copiaAlReves(colaDinamica);

	copiaColaDinamica.printQueue();

	std::cout << "\n";

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