// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "horas.h"
#include "cola_ext.h"
#include "queue_eda.h"

// Sobrecarga de operandos >> y <<
inline std::ostream & operator<<(std::ostream & out, Horas const& rhs) {
	rhs.print(out);
	return out;
}

inline std::istream & operator >> (std::istream & in, Horas & rhs) {
	int horas, minutos, segundos;
	char auxChar = ' ';
	in >> horas >> auxChar >> minutos >> auxChar >> segundos;
	rhs = Horas(horas, minutos, segundos);
	return in;
}

bool resuelveCaso() {

	colaExt<Horas> cola;
	int numElem;

	std::cin >> numElem;

	if (numElem == 0)
		return false;

	for (int i = 0; i < numElem; i++) {
		Horas aux;
		std::cin >> aux;
		cola.push(aux);
	}

	cola.removePair();

	cola.printQueue();

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