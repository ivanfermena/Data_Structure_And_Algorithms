// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

enum piedrasPreciosas { diamante, rubi, esmeralda, zafiro, jade };

std::istream& operator >> (std::istream& entrada, piedrasPreciosas& p) { 
	char num; 
	std::cin >> num; 
	
	switch (num) { 
		case 'd': p = diamante; break; 
		case 'r': p = rubi; break; 
		case 'e': p = esmeralda; break; 
		case 'z': p = zafiro; break; 
		case 'j': p = jade; break; 
	} 
	return entrada; 
}

int resolver(std::vector<piedrasPreciosas> const &v, int max, piedrasPreciosas tipo1, int numtipo1, piedrasPreciosas tipo2, int numtipo2) {

	int countTipo1 = 0, countTipo2 = 0, result = 0;
	for (int i = 0; i < max; i++) {
		if (v[i] == tipo1) {
			countTipo1++;
		}
		else if (v[i] == tipo2) {
			countTipo2++;
		}
	}

	if (countTipo1 >= numtipo1 && countTipo2 >= numtipo2) {
		result++;
	}

	for (int j = 0; j < v.size() - max; j++) {
		
		if (v[j] == tipo1) {
			countTipo1--;
		}
		else if (v[j] == tipo2) {
			countTipo2--;
		}

		if (v[j + max] == tipo1) {
			countTipo1++;
		}
		else if(v[j + max] == tipo2)
		{
			countTipo2++;
		}

		if (countTipo1 >= numtipo1 && countTipo2 >= numtipo2) {
			result++;
		}
	}
	return result;
}

void resuelveCaso() {

	int countPiedras, numPiedras, numElem; 
	int numtipo1, numtipo2; 
	piedrasPreciosas tipo1, tipo2; 

	std::cin >> numElem;
	std::cin >> numPiedras >> tipo1 >> numtipo1 >> tipo2 >> numtipo2;
	
	std::vector<piedrasPreciosas> v(numElem); 
	for (piedrasPreciosas& i : v) std::cin >> i;

	countPiedras = resolver(v, numPiedras, tipo1, numtipo1, tipo2, numtipo2);

	std::cout << countPiedras << "\n";
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