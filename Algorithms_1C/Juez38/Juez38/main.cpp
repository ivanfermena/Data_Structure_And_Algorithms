// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/* 
	Coste es lineal O(n), falta invariantes
*/

bool resolver(std::vector<int> vc, int dDivertido){

	int countDiver = 1;

	for (int i = 0; i < vc.size() - 1; i++){
		// Que [i] sea siempre mayor que [i+1] y que [i+1]-1 sea menor o igual restandole uno (que sea igual o un valor mas)
		if (vc[i] > vc[i + 1] || vc[i + 1] - 1 > vc[i])
			return false;
		else if (vc[i] == vc[i + 1]) {
			countDiver++;
			if (countDiver > dDivertido){
				return false;
			}
		}
		else countDiver = 1;
	}
	return true;
}

void resuelveCaso() {

	int dDivertido, numElem;

	std::cin >> dDivertido >> numElem;

	std::vector<int> vc(numElem);

	for (int & aux : vc) std::cin >> aux;

	bool sol = resolver(vc, dDivertido);

	if (sol) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";

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