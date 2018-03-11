#ifndef conjunto_h
#define conjunto_h

#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <iostream>
#include <string>
#include <fstream>

template <class T>
class set {
public:
	set(size_t tam = TAM_INICIAL); // constructor
	set(set<T> const& other); // constructor por copia
	set<T> & operator=(set<T> const& other); // operador de asignación
	~set(); // destructor
	void insert(T e);
	bool contains(T e) const;
	void erase(T e);
	bool empty() const;
	T value(int pos) const;
	size_t size() const;
	T min() const;
	void eraseMin();
	void print() const;
	void printInverse() const;
private:
	const static size_t TAM_INICIAL = 8;
	size_t contador;
	size_t capacidad;
	T * datos;
	void amplia();
	void libera();
	void copia(set<T> const& other);
	int search(int ini, int fin, T x) const;
};

template <class T>
set<T>::set(size_t tam) : contador(0), capacidad(tam), datos(new T[capacidad]) {}

template <class T>
set<T>::~set() {
	libera();
}

template <class T> void set<T>::libera() {
	delete[] datos;
}

/** Constructor por copia */
template <class T>
set<T>::set(set<T> const& other) {
	copia(other);
}

/** Operador de asignación */
template <class T>
set<T> & set<T>::operator=(set<T> const& other) {
	if (this != &other) {
		libera();
		copia(other);
	}
	return *this;
}

template <class T>
void set<T>::copia(set<T> const& other) {
	capacidad = other.capacidad;
	contador = other.contador;
	datos = new T[capacidad];
	for (size_t i = 0; i < contador; ++i)
		datos[i] = other.datos[i];
}

template <class T>
void set<T>::insert(T e) {
	if (!contains(e)) {
		if (contador == capacidad)
			amplia();

		int pos = 0;
		while (pos < size() && datos[pos] < e)
			pos++;

		for (int i = size(); i > pos; i--)
			datos[i] = datos[i - 1];
		datos[pos] = e;
		++contador;
	}
}

template <class T>
bool set<T>::contains(T e) const {
	size_t i = 0;
	while (i < size() && datos[i] != e)
		++i;
	return i < contador;
}

template <class T>
void set<T>::amplia() {
	T * nuevos = new T[2 * capacidad];
	for (size_t i = 0; i < capacidad; ++i)
		nuevos[i] = std::move(datos[i]);
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}

template <class T>
void set<T>::erase(T e) {
	size_t i = 0;
	while (i < contador && datos[i] != e)
		++i;
	if (i < contador) {
		for (int x = i; x < size() - 1; x++)
			datos[x] = datos[x + 1];
		--contador;
	}
	else
		throw std::domain_error("El elemento no esta");
}


template <class T>
bool set<T>::empty() const {
	return contador == 0;
}

template <class T>
size_t set<T>::size() const {
	return contador;
}

template <class T>
int set<T>::search(int ini, int fin, T x) const {
	if (ini == fin)
		return ini; // vector vacio
	else if (ini + 1 == fin) {// vector de 1 elemento
		if (datos[ini] > x)
			return ini;
		else
			return fin;
	}
	else {
		int m = (ini + fin) / 2;
		if (datos[m] > x)
			return search(ini, m, x);
		else			return search(m, fin, x);	}
}

template <class T>
T set<T>::min() const {
	return datos[0];
}

template<class T>
void set<T>::eraseMin() {
	erase(min());
}


template <class T>
T set<T>::value(int pos) const {
	if (0 <= pos && pos <= contador)
		return datos[pos];
	else
		throw std::domain_error("Posicion fuera del rango del array de datos del conjunto\n");
}

template <class T>
void set<T>::printInverse() const {
	std::cout << datos[contador - 1];
	for (int i = contador - 2; i >= 0; i--)
		std::cout << " " << datos[i];
	std::cout << "\n";
}

template <class T>
void set<T>::print() const {
	std::cout << datos[0];
	for (int i = 1; i < size(); i++)
		std::cout << " " << datos[i];
	std::cout << "\n";
}


#endif