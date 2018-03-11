// Ivan Fernandez Mena
// E13

// O(n^3)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector< std::vector<int> > const & m, int zone) {

	int count = 0, maxZone = 0, auxCount = 0;

	for (int i = 0; i < zone; i++)
		for (int j = 0; j < zone; j++)
			count += m[i][j];

	auxCount = count;
	maxZone = count;
	
	for (int i = 0; i < m.size() - zone; i++){
		for (int j = 0; j < m.size() - zone; j++) {
			for (int k = 0; k < zone; k++)
				count = count - m[k + i][j] + m[k + i][j + zone];

			if (count > maxZone) maxZone = count;
		}

		count = auxCount;
		for (int w = 0; w < zone; w++) 
			count = count - m[i][w] + m[i + zone][w];
		auxCount = count;

		if (count > maxZone) maxZone = count;
	}

	for (int j = 0; j < m.size() - zone; j++) {
		for (int k = 0; k < zone; k++)
			count = count - m[k + m.size() - zone][j] + m[k + m.size() - zone][j + zone];

		if (count > maxZone) maxZone = count;
	}

	return maxZone;
}

bool resuelveCaso() {

	int numRows, zone;

	std::cin >> numRows;

	if (!std::cin)
		return false;

	std::cin >> zone;

	std::vector< std::vector<int> > m(numRows, std::vector<int>(numRows));

	for (int i = 0; i < numRows; i++)
		for (int j = 0; j < numRows; j++)
			std::cin >> m[i][j];

	int sol = resolver(m, zone);

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