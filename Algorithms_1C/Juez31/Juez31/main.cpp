// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct tSolucion
{
	int numPartidos = 0;
	bool clasificado = false;
	int ronda = 0;
};

tSolucion resolver(std::vector <std::string> vc, int maxRondas, int ini, int fin) {

	tSolucion tSol;

	if (ini + 2 == fin){
		tSol.ronda = 1;
		tSol.clasificado = vc[ini] != "NP" || vc[fin - 1] != "NP"; // Se ha presentado alguno
		
		if (vc[ini] != "NP" && vc[fin - 1] != "NP") tSol.numPartidos = 1;
		else tSol.numPartidos = 0;

		// SI no se ha presentado ninguno no se hace nada 
	}
	else{
		int mitad = (ini + fin) / 2;
		tSolucion tIzq = resolver(vc, maxRondas , ini ,mitad);
		tSolucion tDer = resolver(vc, maxRondas, mitad, fin);

		tSol.ronda = ++tIzq.ronda; // Da igual por la izquierda que por la derecha
		tSol.clasificado = tDer.clasificado || tIzq.clasificado;
		if (tDer.clasificado && tIzq.clasificado && tSol.ronda <= maxRondas){
			tSol.numPartidos = tIzq.numPartidos + tDer.numPartidos + 1; // Se juega el partido
		}else{
			tSol.numPartidos = tIzq.numPartidos + tDer.numPartidos; // No se juega
		}
	}

	return tSol;
}

bool resuelveCaso() {

	int numElem, maxRondas, numRondas = 0;

	std::cin >> numElem;

	if (!std::cin)
		return false;

	std::cin >> maxRondas;

	std::vector <std::string> vc(numElem);

	for (std::string &aux : vc)
		std::cin >> aux;

	tSolucion sol = resolver(vc, maxRondas, 0, vc.size());

	std::cout << sol.numPartidos << "\n";

	return true;
}

int main2() {

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