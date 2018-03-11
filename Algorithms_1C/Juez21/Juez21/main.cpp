// Ivan Fernandez Mena
// E46

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
	int sum = 0;
	int ind = -1;
	int len = 0;
};

tSol resolver(std::vector<int> const & v) {
	tSol sol;
	int auxSum = 0, auxLen = 0, auxInd = 0;

	for (int x = 0; x < v.size(); x++) {
		auxSum += v[x];
		if (auxSum <= 0) {
			auxInd = x + 1;
			auxSum = 0;
		}else {
			auxLen = x - auxInd + 1;
			if (auxSum > sol.sum) {
				sol.sum = auxSum;
				sol.ind = auxInd;
				sol.len = auxLen;
			}else if (auxSum == sol.sum && auxLen < sol.len) {
				sol.sum = auxSum;
				sol.ind = auxInd;
				sol.len = auxLen;
			}
		}
	}
	return sol;
}

bool resuelveCaso() {

	int numElem;
	std::cin >> numElem;

	if (!std::cin)
		return false;

	std::vector<int> v(numElem);

	for (int i = 0; i < numElem; i++) {
		std::cin >> v[i];
	}

	tSol sol = resolver(v);

	// escribir sol
	std::cout << sol.sum << " " << sol.ind << " " << sol.len << "\n";

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