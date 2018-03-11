// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>

int siguiente(int n) { // n > 0
	int suma = 0;
	while (n > 0) {
		int digito = n % 10;
		suma += digito * digito * digito; // Es al cubo
		n /= 10; // avanzo de dígito
	}
	return suma;
}

bool cuboinfinito(int n) {
	std::set<int> cjto; // vacío inicialmente
	bool controlCount = false;
	while (n != 1 && ((controlCount = cjto.count(n)) == 0)) {
		cjto.insert(n);
		std::cout << n << " - ";
		n = siguiente(n); // paso al siguiente
	}
	if(controlCount) std::cout << n	;
	return n == 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int numTotal;

	std::cin >> numTotal;

	if (numTotal == 0)
		return false;

	if (cuboinfinito(numTotal) == 1) std::cout << "1 -> cubifinito.";
	else std::cout << " -> no cubifinito.";

	std::cout << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso())
		;

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}