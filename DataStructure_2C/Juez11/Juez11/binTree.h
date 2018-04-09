#ifndef bintree_h
#define bintree_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "bintree_eda_h.h"

template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:
	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	size_t altura() const {
		return altura(this->raiz);
	}

	size_t numNodos() const {
		return numNodos(this->raiz);
	}

	size_t numHojas() const {
		return numHojas(this->raiz);
	}

private:
	static size_t altura(Link r) {
		if (r == nullptr) {
			return 0;
		}else {
			return 1 + std::max(altura(r->left), altura(r->right));
		}
	}

	static size_t numNodos(Link r) {
		if (r == nullptr) {
			return 0;
		}
		else {
			return 1 + numNodos(r->left) + numNodos(r->right);
		}
	}

	static size_t numHojas(Link r) {
		if (r == nullptr)
			return 0;
		else if (r->left == nullptr && r->right == nullptr)
			return 1;
		else
			return numHojas(r->left) + numHojas(r->right);
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