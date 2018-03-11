// Ivan Fernandez Mena
// E13

// O(n^2)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector< std::vector<int> > const & m) {

	int count = 0;

	for (int i = 0; i < m.size(); i++)
		for (int j = 0; j < m[0].size(); j++)
			if (m[i][j] == i) count++;
				
	return count;
}

bool resuelveCaso() {

	int numRows, numColumns;

	std::cin >> numRows;

	if (!std::cin)
		return false;

	std::cin >> numColumns;

	std::vector< std::vector<int> > m(numRows, std::vector<int>(numColumns));

	for (int i = 0; i < numRows; i++)
		for (int j = 0; j < numColumns; j++)
			std::cin >> m[i][j];

	int sol = resolver(m);

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