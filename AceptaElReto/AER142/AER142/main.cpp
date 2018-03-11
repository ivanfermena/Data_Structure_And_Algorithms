// Ivan Fernendez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

#include <queue>

// función que resuelve el problema
long int resolver(std::queue<long int> ninos, int numSaltos) {
	int saltos = 0;
	while (ninos.size() != 1) {
		if (saltos == numSaltos) {
			ninos.pop();
			saltos = 0;
		}
		else {
			long int elem = ninos.front();
			ninos.pop();
			ninos.push(elem);
			saltos++;
		}
	}
	return ninos.front();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	long int numNinos;
	int numSaltos;
	std::cin >> numNinos >> numSaltos;
	if (numNinos == 0 && numSaltos == 0)
		return false;
	std::queue<long int> ninos;
	for (int i = 0; i < numNinos; i++)
		ninos.push(i + 1);
	std::cout << resolver(ninos, numSaltos) << "\n";
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
