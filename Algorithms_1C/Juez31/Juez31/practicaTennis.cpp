// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct players {
	bool clasificado = false;
	int ronda = 0;
	int numPartidos = 0;
};

players partido(std::vector<std::string> const & vc, int ini, int fin, int numMax) {

	players tSol;

	if (ini + 2 == fin) { // Tiene dos elementos

		tSol.ronda = 1;

		tSol.clasificado = vc[ini] != "NP" || vc[fin] != "NP";

		if (vc[ini] != "NP" && vc[fin] != "NP") tSol.numPartidos = 1;
		else tSol.numPartidos = 0;
	}
	else {
		int mitad = (ini + fin) / 2;
		players sIzq = partido(vc, ini, mitad, numMax);
		players sDer = partido(vc, mitad, fin, numMax);

		tSol.ronda = ++sDer.ronda;
		tSol.clasificado = sIzq.clasificado || sDer.clasificado;

		if (sDer.clasificado && sIzq.clasificado && tSol.ronda <= numMax) {
			tSol.numPartidos = sDer.numPartidos + sIzq.numPartidos + 1;
		}else {
			tSol.numPartidos = sDer.numPartidos + sIzq.numPartidos;
		}

	}


	return tSol;
}

bool resuelveCaso() {

	int numJugadores, numMax;

	std::cin >> numJugadores;

	if (!std::cin)
		return false;

	std::cin >> numMax;

	std::vector<std::string> vc(numJugadores);

	for (std::string aux : vc)
		std::cin >> aux;

	players sol = partido(vc, 0, vc.size(), numMax);

	std::cout << sol.numPartidos << "\n";

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