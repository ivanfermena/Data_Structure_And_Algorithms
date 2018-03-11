// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct MyStruct
{
	int position = 0;
	int ok = false;
};

MyStruct resolver(std::vector<int> const & vc, int ini, int fin, int valor) {

	MyStruct sol;

	if (ini + 1 == fin) {
		sol.position = ini;
		if (vc[sol.position] == sol.position + valor)
			sol.ok = true;
	}
	else {
		int mitad = (ini + fin + 1) / 2;
		MyStruct solIz = resolver(vc, ini, mitad, valor);
		MyStruct solDe = resolver(vc, mitad, fin, valor);
		sol.ok = solIz.ok || solDe.ok;
		if (solIz.ok) sol.position = solIz.position;
		else if (solDe.ok) sol.position = solDe.position;
	}
	return sol;

}

void resuelveCaso() {

	int numElem, numSay;

	std::cin >> numElem;
	std::cin >> numSay;
	std::vector<int> vc(numElem);

	for (int &aux : vc)
		std::cin >> aux;

	MyStruct sol = resolver(vc, 0, vc.size(), numSay);

	if (!sol.ok)
		std::cout << "NO" << "\n";
	else std::cout << vc[sol.position] << "\n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}