// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSolucion
{
	int suma = 0;
	bool ok = true;
};

tSolucion degradado(std::vector<int> const & v, int ini, int fin) {
	
	tSolucion sol;

	if (ini + 1 == fin){
		sol.suma = v[ini];
		sol.ok = true;
	}else{
		int mitad = (ini + fin + 1) / 2;
		tSolucion solIz = degradado(v, ini, mitad);
		tSolucion solDe = degradado(v, mitad, fin);
		sol.suma = solIz.suma + solDe.suma;
		sol.ok = solIz.ok && solDe.ok && (solIz.suma < solDe.suma);
	}
	return sol;
}

bool resuelveCaso() {

	int numRows, numElem, numSelect;
	tSolucion sol;
	bool solReturn = true;

	std::cin >> numRows;

	if (!std::cin)
		return false;

	std::cin >> numElem;
	std::vector<int>vc;

	for (int i = 0; i < numRows; i++) {

		for (int i = 0; i < numElem; i++) {
			std::cin >> numSelect;
			vc.push_back(numSelect);
		}

		sol = degradado(vc, 0, vc.size());

		if (!sol.ok)
			solReturn = false;

		vc.clear();
	}

	if (solReturn)
		std::cout << "SI" << "\n";
	else
		std::cout << "NO" << "\n";

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