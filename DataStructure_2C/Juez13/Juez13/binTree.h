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


	T minimo() const {
		return minimo(this->raiz);
	}

private:

	static T minimo(Link r) {
		if (r->left == nullptr && r->right == nullptr)
			return r->elem;
		else if (r->left == nullptr && r->right != nullptr)
			return std::min(r->elem, minimo(r->right));
		else if (r->left != nullptr && r->right == nullptr) 
			return std::min(r->elem, minimo(r->left));
		else return std::min(r->elem, std::min(minimo(r->left), minimo(r->right)));
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
