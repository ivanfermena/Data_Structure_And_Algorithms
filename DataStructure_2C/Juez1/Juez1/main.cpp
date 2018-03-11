// Ivan Fernandez Mena
// E13

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "Horas.h"

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

//Sobrecarga de operando hor < that.hor
bool Horas::operator<(Horas const& that) const {
	if (that.hor < hor)
		return false;
	else if (that.hor == hor && that.min < min)
		return false;
	else if (that.hor == hor && that.min == min && that.seg < seg)
		return false;
	else if (that.hor == hor && that.min == min && that.seg == seg)
		return false;

	return true;
}

// Metodos resulve caso que gestiona lectura
bool resuelveCaso() {

	int numTrenes, numHoras, hor, min, seg;

	std::cin >> numTrenes >> numHoras;

	//Control de fin de fichero
	if (numTrenes == 0 && numHoras == 0)
		return false;

	std::vector<Horas> vc(numTrenes);
	Horas vcHoras;

	// Llenamos el array de vc
	for (unsigned int i = 0; i < vc.size(); i++)
		std::cin >> vc[i];
		
	// Ordenamos el array de horas
	std::sort(vc.begin(), vc.begin());

	bool encontrado;
	int j;

	// Obtenemos el valor que buscamos
	for (int i = 0; i < numHoras; i++){
		try {
			std::cin >> vcHoras;

			if (vc[vc.size() - 1] < vcHoras) {
				throw std::domain_error("NO");
			}else{
				j = 0;
				encontrado = false;
				while (!encontrado && j < vc.size()) {
					if (!(vc[j]< vcHoras)) {
						std::cout << vc[j];
						encontrado = true;
					}
					j = j + 1;
				}
			}
		}
		catch (std::domain_error const& de) {
			std::cout << de.what() << '\n';
		}
	}

	std::cout << "---\n";

	// Comprobar que sea menor 
	//vc[i].print(std::cout); CUando sea solucion

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto.
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}