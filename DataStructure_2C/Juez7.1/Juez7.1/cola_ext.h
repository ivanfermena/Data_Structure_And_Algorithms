#ifndef cola_ext_h
#define cola_ext_h

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "queue_eda.h"

template <class T>
class colaExt : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:

	// constructor: cola vacía
	colaExt() {}

	// Metodo que copia insertando en el vector copia el doble de elementos
	void removePair() {
		if (this->empty()) {
			this->prim = this->ult = nullptr;
			this->nelems = 0;
		}
		else {
			Nodo * actual = this->prim; // recorre la cola original

			while (actual->sig != nullptr && actual->sig->sig != nullptr) {
				actual->sig = actual->sig->sig;
				actual = actual->sig;
			}

			if (this->nelems % 2 == 0) {
				actual->sig = nullptr;
				this->nelems = this->nelems / 2;
			}
			else
				this->nelems = (this->nelems / 2) + 1;

			this->ult = actual;
		}
	}

	// this está sin inicializar
	void printQueue() {
		Nodo * aux = this->prim;
		while (aux != nullptr) {
			std::cout << aux->elem << " ";
			aux = aux->sig;
		}
		this->ult = nullptr;
	}
};

#endif 
