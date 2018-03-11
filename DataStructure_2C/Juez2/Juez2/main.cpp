// Ivan Fernandez Mena
// E13

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>

#include "Horas.h"
#include "Pelicula.h"

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

bool Horas::operator==(Horas const& that) const {
	return that.hor == hor && that.min == min && that.seg == seg;
}

bool Pelicula::operator<(Pelicula const& that) const {
	if (that.horaFin < horaFin) {
		return false;
	}
	else if (that.horaFin == horaFin) {
		if (that.nombre < nombre) {
			return false;
		}
	}

	return true;
}

// Sobrecarga de operandos >> y <<
inline std::ostream & operator<<(std::ostream & out, Horas const& rhs) {
	rhs.print(out);
	return out;
}

// Metodos resulve caso que gestiona lectura
bool resuelveCaso() {

	int numPelis;

	std::cin >> numPelis;

	//Control de fin de fichero
	if (numPelis == 0)
		return false;

	std::vector<Pelicula> vc(numPelis);

	// Llenamos el array de vc
	for (int i = 0; i < numPelis; i++) {
		Horas auxIni, auxDuracion;
		std::string auxName = " ";

		std::cin >> auxIni >> auxDuracion;
		std::getline(std::cin, auxName);

		vc[i] = Pelicula(auxIni, auxDuracion, auxName);
	}
	
	// Ordenamos el array de horas
	std::sort(vc.begin(), vc.end());
	
	for (Pelicula aux: vc) {
		std::cout << aux.get_horaFin() << aux.get_nombre() << "\n";
	}

	std::cout << "---\n";

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