// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct stPlayer
{
	std::string name = "";
	int canicas = 0;
};

stPlayer degradado(std::vector<stPlayer> const & v, int ini, int fin) {

	stPlayer sol;

	if (ini + 1 == fin) {
		sol.canicas = v[ini].canicas;
		sol.name = v[ini].name;
	}
	else {
		int mitad = (ini + fin + 1) / 2;
		stPlayer solIz = degradado(v, ini, mitad);
		stPlayer solDe = degradado(v, mitad, fin);
		if (solIz.canicas >= solDe.canicas) { 
			sol.canicas = solIz.canicas + (solDe.canicas/2);
			sol.name = solIz.name;
		}else if (solIz.canicas < solDe.canicas) {
			sol.canicas = solDe.canicas + (solIz.canicas/2);
			sol.name = solDe.name;
		}
	}
	return sol;
}

bool resuelveCaso() {

	int numPlayers, canSelect;
	std::string nameSelect;
	stPlayer sol;

	std::cin >> numPlayers;

	if (!std::cin)
		return false;

	std::vector<stPlayer>vc(numPlayers);

	for (int i = 0; i < numPlayers; i++) {
		std::cin >> sol.name;
		std::cin >> sol.canicas;
		vc[i] = sol;
	}

	sol = degradado(vc, 0, vc.size());
	std::cout << sol.name << " " << sol.canicas << "\n";

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