// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int> const &vc) {
	
	int resultSum, maxNumber, countMax = 1;
	resultSum = maxNumber = vc[0];

	for (int i = 1; i < vc.size(); i++){
		resultSum += vc[i];
		if (maxNumber < vc[i]) {
			maxNumber = vc[i];
			countMax = 1;
		}
		else if (maxNumber == vc[i]) countMax++;
	}

	return resultSum - (countMax * maxNumber);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	
	int countNum, numSelect;

	std::cin >> countNum;
	std::vector<int> vc(countNum);

	for (int i = 0; i < countNum; i++){
		std::cin >> numSelect;
		vc[i] = numSelect;
	}

	int sol = resolver(vc);
	std::cout << sol << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
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