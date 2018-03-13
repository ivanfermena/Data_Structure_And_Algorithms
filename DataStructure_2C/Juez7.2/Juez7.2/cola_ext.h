#ifndef cola_ext_h
#define cola_ext_h

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "queue_eda.h"
#include "horas.h"

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
			Nodo * anterior = this->prim;
			Nodo * a_borrar = actual;
			int countDelete = 0;

			while (actual->sig != nullptr) {
				if (actual->sig->elem < actual->elem && actual->sig->sig != nullptr) {
					actual->sig = actual->sig->sig;
					delete a_borrar;
					a_borrar = actual->sig;
					countDelete++;
				}
				else {
					anterior = actual;
					actual = actual->sig;
					a_borrar = actual->sig;
				}
			}

			if (actual->elem < anterior->elem) {
				anterior->sig = nullptr;
				delete actual;
				this->ult = anterior;
			}
			else {
				this->ult = actual;
			}

			this->nelems = this->nelems - countDelete;
			
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

