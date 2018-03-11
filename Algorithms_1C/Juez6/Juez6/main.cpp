// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void resolver(std::vector<int> const &v, int max, int &benefit, int &wagonSelect) {

	int sumSec = 0; 
	for (int i = 0; i < max; i++) {
		sumSec = sumSec + v[i]; 
	}
	benefit = sumSec; 
		
	for (int j = 0; j < v.size() - max; j++){
		sumSec += v[j + max] - v[j];
		if (sumSec >= benefit) { 
			benefit = sumSec; 
			wagonSelect = j + 1; 
		} 
	}
}

void resuelveCaso() {

	int numElem, numSelect, maxWagons, wagonSelect = 0, benefit = 0;
	std::cin >> numElem;
	std::cin >> maxWagons;
	std::vector<int> vc(numElem);

	for (int i = 0; i < numElem; ++i) {
		std::cin >> numSelect;
		vc[i] = numSelect;
	}

	resolver(vc, maxWagons, benefit, wagonSelect);

	std::cout << wagonSelect << " " << benefit << "\n";

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}