#ifndef bintree_h
#define bintree_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

#include "bintree_eda_h.h"

template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:
	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}


	void recate(int & numHelp, int & ruteMax) const {
		rescate(this->raiz, numHelp, ruteMax);
	}

private:

	// numHelp y ruteMax son argumnetos de retorno
	static void rescate(Link r, int & numHelp, int & ruteMax) {
		if (r != nullptr) {

			// Genero variables auxiliares para controlar mejor los valores de retorno
			int numHelpLeft = numHelp, numHelpRight = numHelp;
			int ruteMaxLeft = ruteMax, ruteMaxRight = ruteMax;
			rescate(r->left, numHelpLeft, ruteMaxLeft);
			rescate(r->right, numHelpRight, ruteMaxRight);

			// Comprobamos cual es el mejor
			ruteMax = std::max(ruteMaxLeft, ruteMaxRight);

			//Comprobamos que haya alguien atrapado 
			if (r->elem != 0) {
				ruteMax += r->elem;
				if (numHelpLeft == 0 && numHelpRight == 0) numHelp++;
			}
			
			numHelp += numHelpLeft + numHelpRight;
		}
	}

};

// lee un árbol binario de la entrada estándar
template <typename T>
bintree_ext<T> leerArbol_ext(T vacio) {

	T raiz;
	std::cin >> raiz;

	if (raiz == vacio) { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol_ext(vacio);
		auto dr = leerArbol_ext(vacio);
		return{ iz, raiz, dr };
	}
}

#endif 
