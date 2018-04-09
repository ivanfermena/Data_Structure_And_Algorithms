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

	std::vector<int> numHojas() const {
		std::vector<int> sol;
		int valor = numHojas(this->raiz, sol);
		if (valor != -1) {
			sol.push_back(valor);
			return sol;
		} 
		else return sol;
	}

private:

	static size_t numHojas(Link r, std::vector<int> & sol) {
		
		if (r == nullptr)
			return -1;
		else if (r->left == nullptr && r->right == nullptr) {
			return r->elem;
		}else {
			int numLeft = numHojas(r->left, sol);
			if (numLeft != -1) sol.push_back(numLeft);
			int numRight = numHojas(r->right, sol);
			if (numRight != -1) sol.push_back(numRight);
			
			return -1;
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
