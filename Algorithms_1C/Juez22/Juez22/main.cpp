// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>	

struct tSolucion{
	int max = 0;
	int min = 0;
	bool ok = false;
};

tSolucion resolver(std::vector <int> const & vc, int ini, int fin){
	 
	 tSolucion sol;

	 if (ini + 1 == fin) {
			 sol.min = vc[ini];
			 sol.max = vc[ini];
			 sol.ok = true;
	 }
	 else {
		 int mitad = (ini + fin) / 2;
		 tSolucion solIz = resolver(vc, ini, mitad);
		 tSolucion solDe = resolver(vc, mitad, fin);
		 //sol.ok = solIz.ok && solDe.ok && (solIz.max <= solDe.max) && (solIz.min <= solDe.min);
		 if (solIz.min <= solDe.min){
			 sol.min = solIz.min;
		 }else sol.min = solDe.min;
		 if (solIz.max >= solDe.max) {
			 sol.max = solIz.max;
		 }else sol.max = solDe.max;

		 sol.ok = solIz.ok && solDe.ok && (solIz.max <= solDe.max) && (solIz.min <= solDe.min);
	 }
	 return sol;

}

bool resuelveCaso() {
	int numSelect;

	std::vector <int> vc;

	std::cin >> numSelect;

	if (numSelect == 0)
		return false;

	while (numSelect != 0){
		vc.push_back(numSelect);
		std::cin >> numSelect;
	}

	tSolucion sol = resolver(vc, 0, vc.size());

	if (sol.ok)
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