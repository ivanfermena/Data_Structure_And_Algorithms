// Ivan Fernandez Mena
// E16

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>

#include "conjunto.h"

template <class T>
void read(set<T> & elemDatos, T end) {
	T elem;
	std::cin >> elem;
	while (elem != end) {
		if (!elemDatos.contains(elem)) {
			elemDatos.insert(elem);
		}
		std::cin >> elem;
	}
}

// función que resuelve el problema
template <class T>
void resolver(set<T> const & elementos, set<T> & sol, int k) {

	int i = elementos.size() - 1;
	while (i >= 0 && sol.size() < k) {
		if (!sol.contains(elementos.value(i)))
			sol.insert(elementos.value(i));
		i--;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	

	char selec;
	int numElem;
	std::cin >> selec;
	if (!std::cin)
		return false;

	std::cin >> numElem;

	if(selec == 'N') {
		set<int> setDatos;
		set<int> sol;

		read(setDatos, -1);

		resolver(setDatos, sol, numElem);

		sol.print(); 

	}else if(selec == 'P'){
		set<std::string> setDatos;
		set<std::string> sol;

		read(setDatos, std::string("FIN"));

		resolver(setDatos, sol, numElem);
		sol.print(); 
	}

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}