//
//  queue_eda.h
//
//  Implementaci�n del TAD cola con nodos enlazados
//  y punteros al primero y al �ltimo nodo
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Inform�tica
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2016-2018 Alberto Verdejo
//

#ifndef queue_eda_h
#define queue_eda_h

#include <iostream>
#include <fstream>
#include <stdexcept>  // std::domain_error

template <class T>
class queue {
protected:

	/*
	Nodo que almacena internamente el elemento (de tipo T),
	y un puntero al nodo siguiente, que puede ser nullptr si
	el nodo es el �ltimo de la lista enlazada.
	*/
	struct Nodo {
		Nodo() : sig(nullptr) {}
		Nodo(T const& elem, Nodo * si = nullptr) : elem(elem), sig(si) {}
		T elem;
		Nodo * sig;
	};

	// punteros al primer y �ltimo elemento
	Nodo * prim;
	Nodo * ult;

	// n�mero de elementos en la cola
	size_t nelems;

public:

	// constructor: cola vac�a
	queue() : prim(nullptr), ult(nullptr), nelems(0) {}

	// destructor
	~queue() {
		libera();
	}

	// constructor por copia
	queue(queue<T> const& other) {
		copia(other);
	}

	// operador de asignaci�n
	queue<T> & operator=(queue<T> const& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	// a�adir un elemento al final de la cola
	void push(T const& elem) {
		Nodo * nuevo = new Nodo(elem);

		if (ult != nullptr)
			ult->sig = nuevo;
		ult = nuevo;
		if (prim == nullptr) // la cola estaba vac�a
			prim = nuevo;
		++nelems;
	}

	// consultar el primero de la cola
	T const& front() const {
		if (empty())
			throw std::domain_error("la cola vacia no tiene primero");
		return prim->elem;
	}

	// eliminar el primero de la cola
	void pop() {
		if (empty())
			throw std::domain_error("eliminando de una cola vacia");
		Nodo * a_borrar = prim;
		prim = prim->sig;
		if (prim == nullptr) // la cola se ha quedado vac�a
			ult = nullptr;
		delete a_borrar;
		--nelems;
	}

	// consultar si la cola est� vac�a
	bool empty() const {
		return nelems == 0;
	}

	// consultar el tama�o de la cola
	size_t size() const {
		return nelems;
	}

	// Metodo que copia insertando en el vector copia el doble de elementos
	void copiaConDoble() {
		if (empty()) {
			prim = ult = nullptr;
			nelems = 0;
		}
		else {
			if (nelems == 2) {
				Nodo * actual = prim;
				actual->sig->sig = actual;
				actual = ult;
				actual->sig = prim;
			}
			else if(nelems > 2) {
				Nodo * izq = prim;
				ult = izq;
				Nodo * actual = izq->sig;
				Nodo * der = actual->sig;

				while (der->sig != nullptr) {
					actual->sig = izq;
					izq = actual;
					actual = der;
					der = der->sig;
				}
				// lo hacemos para el ultimo caso

				actual->sig = izq;
				der->sig = actual;
				prim = der;

			}
		}
	}

	// Metodo que copia insertando en el vector copia el doble de elementos
	void copiaAlReves(queue const& other) {
		if (other.empty()) {
			prim = ult = nullptr;
			nelems = 0;
		}
		else {
			Nodo * act = other.prim; // recorre la cola original
			Nodo * ant = new Nodo(act->elem); // �ltimo nodo copiado
			ult = ant;

			while (act->sig != nullptr) {
				act = act->sig;
				prim = ant = new Nodo(act->elem); // El nuevo se convierte en primero
				ant->sig = ult;
				ult = prim;
			}
			
			prim = ant;
			nelems = other.nelems;
		}
	}

	void printQueue() {
		Nodo * aux = prim;
		while (aux != nullptr) {
			std::cout << aux->elem << " ";
			aux = aux->sig;
		}
		ult = nullptr;
	}

protected:

	void libera() {
		while (prim != nullptr) {
			Nodo * a_borrar = prim;
			prim = prim->sig;
			delete a_borrar;
		}
		ult = nullptr;
	}

	// this est� sin inicializar
	void copia(queue const& other) {
		if (other.empty()) {
			prim = ult = nullptr;
			nelems = 0;
		}
		else {
			Nodo * act = other.prim; // recorre la cola original
			Nodo * ant = new Nodo(act->elem); // �ltimo nodo copiado
			prim = ant;
			while (act->sig != nullptr) {
				act = act->sig;
				ant->sig = new Nodo(act->elem);
				ant = ant->sig;
			}
			ult = ant;
			nelems = other.nelems;
		}
	}
};

#endif // queue_eda_h

