// Alberto Pastor Moreno
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

#include <queue>

struct strPalabra
{
	int indice;
	std::string nombres;
};

bool compareByLength(const strPalabra &a, const strPalabra &b)
{
	return a.indice < b.indice;
}

void sortQueue(std::queue<strPalabra> & nombres, std::vector<strPalabra> & vc) {

	int i = 0;
	while (!nombres.empty()) {
		vc[i] = nombres.front();
		nombres.pop();
		i++;
	}

	std::sort(vc.begin(), vc.end(), compareByLength);
}

void print(std::queue<strPalabra>  & queue, int tamInicial) {
	if (queue.size() > 0) {
		if (queue.size() == tamInicial)
			std::cout << "TODOS TIENEN CAMA";
		else {
			std::vector<strPalabra> vc(queue.size());
			sortQueue(queue, vc);

			std::cout << vc[0].nombres;
			for (int i = 1; i < vc.size(); i++) std::cout << " " << vc[i].nombres;
		}
	}
	else
		std::cout << "NADIE TIENE CAMA";
	std::cout << "\n";
}



// función que resuelve el problema
void resolver(std::queue<strPalabra> & nombres, int numCamas, int numPalabras) {
	int contPalabras = 0;
	while (nombres.size() > numCamas) {
		if (contPalabras == numPalabras - 1) {
			nombres.pop();
			contPalabras = 0;
		}
		else {
			strPalabra elem = nombres.front();
			nombres.pop();
			nombres.push(elem);
			contPalabras++;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	strPalabra palabra;

	std::queue<strPalabra> nombres;
	std::cin >> palabra.nombres;
	palabra.indice = 0;

	while (palabra.nombres != "F") {
		nombres.push(palabra);
		std::cin >> palabra.nombres;
		palabra.indice++;
	}

	int numCamas, numPalabras, numPeregrinos = nombres.size();
	std::cin >> numCamas >> numPalabras;
	resolver(nombres, numCamas, numPalabras);
	// escribir sol

	print(nombres, numPeregrinos);
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
