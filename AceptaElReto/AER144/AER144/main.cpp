// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>

bool resuelveCaso() {

	std::string palabra;
	std::list<char> list;

	getline(std::cin, palabra);

	if (!std::cin)
		return false;

	auto it = list.begin();

	for (char c : palabra) {

		switch (c) {
			case '-': {
				it = list.begin();
				}break;
			case '+': {
				it = list.end();
				}break;
			case '*': {
				if (it != list.end())
					it++;
				}break;
			case '3': {
				if (it != list.end())
					it = list.erase(it);
			}break;
			default: {
				it = list.insert(it, c);
				++it;
			}break;
		}
	}

	for (char c: list) {
		std::cout << c;
	}

	std::cout << "\n";

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