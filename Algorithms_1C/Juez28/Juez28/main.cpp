// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct stSolution
{
	bool ok = false;
	int suma = 0;
	int min = 0;
	int max = 0;
	int media = 0;
};

stSolution resolver(std::vector<int> const & vc, int ini, int fin) {

	stSolution sol;

	if (ini + 1 == fin) {
		sol.max = sol.min = vc[ini];
		sol.suma = vc[ini];
		sol.ok = true;
	}
	else {
		int mitad = (ini + fin + 1) / 2;
		stSolution solIz = resolver(vc, ini, mitad);
		stSolution solDr = resolver(vc, mitad, fin);

		// Seleccionamos minimos y maximos a la solucion
		if (solIz.max >= solDr.max) sol.max = solIz.max;
		else sol.max = solDr.max;
		if (solIz.min <= solDr.min) sol.min = solIz.min;
		else sol.min = solDr.min;

		sol.suma = solIz.suma + solDr.suma;
		sol.media = sol.suma / (fin - ini);
		// Comprobamos por encima y por debajo!
		sol.ok = solDr.ok && solIz.ok && (sol.min >= sol.media - (sol.media / 2)) && (sol.max <= sol.media + (sol.media / 2));
	}
	return sol;
}

bool resuelveCaso() {

	int numElem;
	stSolution sol;

	std::cin >> numElem;

	if (!std::cin)
		return false;

	std::vector<int> vc(numElem);

	for (int &aux : vc) {
		std::cin >> aux;
	}
		
	sol = resolver(vc, 0, vc.size());
	
	if (sol.ok) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";

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