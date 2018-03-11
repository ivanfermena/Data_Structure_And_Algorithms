// Ivan Fernandez
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

 void resolver(std::vector<std::string> const &vc,int &ini, int &posEnd ) {

	 int iniUltSeg = 0, maxLong = 0;
	 ini = 0; 

	 for (int i = 0; i < vc.size(); i++) {
		 if (vc[i] == "FFFFFF") {
			 if (maxLong < i - iniUltSeg + 1) {
				 ini = iniUltSeg; 
				 maxLong = i - iniUltSeg + 1;
			 }
		 }
		 else { iniUltSeg = i + 1; } 
	 }
	posEnd = ini + maxLong - 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int numLines, elemForLine, posIni, posEnd;
	std::string elemSelect;

	std::cin >> numLines;

	if (!std::cin)
		return false;

	std::cin >> elemForLine;

	std::vector<std::string> vc;
	
	int j = 0;

	for (int i = 0; i < numLines;)
	{
		std::cin >> elemSelect;
		vc.push_back(elemSelect);
		j++;
		if (j == elemForLine) {
			resolver(vc, posIni, posEnd);
			std::cout << posIni << " " << posEnd << std::endl;
			vc.clear();
			i++; 
			j = 0;
		}
	}

	std::cout << std::endl;
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