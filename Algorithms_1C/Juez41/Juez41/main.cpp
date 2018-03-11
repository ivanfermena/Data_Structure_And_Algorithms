// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool esValida(std::vector <int> const & vc, int i, int k,int consumoMaximo, int consumoUsado, std::vector <int> const & vecesUsados, int auxUsados) {

	if (consumoUsado > consumoMaximo) return false;
	else if (vc[i] == vc[i + 1] == vc[i + 2]) return false;
	else return true;
}

void resolver(std::vector <int> & vc, int k, std::vector <int> const & consumo, int consumoMaximo, std::vector <int> & vecesUsados,
	int & consumoUsado, int & numeroSol, int & auxUsados) {

	// Tirase en orden creciente segun existan [ 0 , 1 , 2 ... ]

	for (int i = 0; i < vecesUsados.size(); i++) {
		vc[k] = i;
		consumoUsado += consumo[i];
		vecesUsados[i]++;
		auxUsados++;

		if (esValida(vc, i, k, consumoMaximo, consumoUsado, vecesUsados, auxUsados)) {
			if (k + 1 == vc.size()) { // Es solucion
				numeroSol++;
			}
			else resolver(vc, k + 1, consumo, consumoMaximo, vecesUsados, consumoUsado, numeroSol, auxUsados);
		}
		consumoUsado -= consumo[i];
		vecesUsados[i]--;
		auxUsados--;
	}
}

bool resuelveCaso() {

	int numTiras, numColores, consumoMaximo, consumoUsado = 0, numeroSol = 0, auxUsados = 0;

	std::cin >> numTiras;

	if (!std::cin)
		return false;

	std::cin >> numColores >> consumoMaximo;

	std::vector <int> vc(numTiras, -1);
	std::vector <int> consumo(numColores);
	std::vector <int> vecesUsados(numColores, 0);

	for (int &aux : consumo)
		std::cin >> aux;

	resolver(vc, 0, consumo, consumoMaximo, vecesUsados, consumoUsado, numeroSol, auxUsados);

	std::cout << numeroSol << "\n";

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