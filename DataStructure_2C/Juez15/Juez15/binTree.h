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


	void navegables(int & sol) const {
		int nivel = -1;
		rescate(this->raiz, sol, nivel);
	}

private:

	static int rescate(Link r, int & sol, int nivel) {

		nivel++;

		if (r == nullptr) 
			return 0;
		// Vemos si es hoja para sumar uno
		if (r->left == nullptr && r->right == nullptr) return 1;
		else {
			int valor = rescate(r->left, sol, nivel) + rescate(r->right, sol, nivel) - r->elem;
			if (valor >= 3 && nivel != 0) sol++;
			return (valor <= 0) ? 0 : valor;
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
		auto dr = leerArbol_ext(vacio);
		auto iz = leerArbol_ext(vacio);
		return{ iz, raiz, dr };
	}
}

#endif 
