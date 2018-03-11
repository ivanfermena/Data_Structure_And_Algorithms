// Ivan Fernandez Mena
// E13

// Coste de resolver es: O(n^2) ya que acunque hay mas bucles for, son sumados y se coje el que mas coste tenga que es el cuadratico.
// El resto hace iteraciones de n

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector< std::vector<int> > const & m, int anchoFranja,int maxColumnas, int numCeros) {

	int countCeros = 0, result = 0, sumaCorrectos = 0;
	std::vector<int> vc;

	for (int i = 0; i < m[0].size(); i++) { // Columnas
		for (int j = 0; j < m.size(); j++) // Filas
			if (m[j][i] == 0) countCeros++;
		if (countCeros >= numCeros) vc.push_back(1);
		else vc.push_back(0);
		countCeros = 0;
	}

	for (int i = 0; i < anchoFranja; i++) {
		sumaCorrectos = sumaCorrectos + vc[i];
	}

	if (sumaCorrectos >= maxColumnas) result++;

	for (int j = 0; j < vc.size() - anchoFranja; j++) {
		sumaCorrectos += vc[j + anchoFranja] - vc[j];
		if (sumaCorrectos >= maxColumnas) result++;
	}
	return result;
}

bool resuelveCaso() {

	int numRows, numColumns, anchoFranja, maxColumnas, numCeros;

	std::cin >> numRows;

	if (!std::cin)
		return false;

	std::cin >> numColumns;
	std::cin >> anchoFranja;
	std::cin >> maxColumnas;
	std::cin >> numCeros;

	std::vector< std::vector<int> > m(numRows, std::vector<int>(numColumns));

	for (int i = 0; i < numRows; i++)
		for (int j = 0; j < numColumns; j++)
			std::cin >> m[i][j];

	int sol = resolver(m, anchoFranja, maxColumnas, numCeros);

	std::cout << sol << "\n";

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