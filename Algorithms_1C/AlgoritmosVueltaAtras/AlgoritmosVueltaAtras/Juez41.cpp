// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// No haya dos colores juntos
// Un color no sobrepase la suma de las demas
// Las tiras de colores no pueden superar un coste maximo

struct tColores {
	int consumoUsado = 0;
	int solucion = 0;
	int sumaTotal = 0;
};

bool esValida(std::vector <int> & const vc, int k, std::vector <int> & const vcMarcas, int sumaTotal) {
	
	if (vc[k] == vc[k + 1]) return false;
	else if (sumaTotal - vcMarcas[k] < vcMarcas[k] + 1) return false;

}

tColores resolver(std::vector <int> & vc, int k, int numColores, int consumoMaximo, std::vector <int> & const vcConsumo, std::vector <int> & vcMarcas) {

	tColores tSol;

	for (int i = 0; i < numColores; i++){
		// Ponemos el primer elemento y marcamos el consumo
		vc[k] = i;
		vcMarcas[k]++;

		if (esValida(vc, k, vcMarcas)){
			tSol.consumoUsado += vcConsumo[k]; // Marcamos

			if (k + 1 == vc.size() || tSol.consumoUsado <= consumoMaximo) { // esSolucion
				tSol.solucion++;
			}
			else resolver(vc, k + 1, numColores, consumoMaximo, vcConsumo);
			
			tSol.consumoUsado += vcConsumo[k]; //Desmarcamos
		}

		vcMarcas[k]--;
	}

	return tSol;
}

bool resuelveCaso() {

	int numTira, numColores, consumoMaximo;

	std::cin >> numTira;

	if (!std::cin)
		return false;

	std::cin >> numColores >> consumoMaximo;

	std::vector <int> vc(numTira); // Vector solucion con el numero de tiras a poner
	std::vector <int> vcConsumo(numColores);
	std::vector <int> vcMarcas(numColores);

	// Los colores son de manera creciente hasta llegar al numero de colores

	for (int &aux : vcConsumo)
		std::cin >> aux;

	tColores sol = resolver(vc, 0, numColores, consumoMaximo, vcConsumo, vcMarcas);

	std::cout << sol.solucion << "\n";

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