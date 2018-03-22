// Ivan Fernandez Mena
// E13

#include <iostream>
#include <fstream>
using namespace std;

#include "queue_eda.h"

template <class T>
class InsertaElementos : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	// imprime la lista enlazada
	void print(std::ostream & o = std::cout) const {
		Nodo * aux = this->prim;
		while (aux != nullptr) {
			std::cout << aux->elem << " ";
			aux = aux->sig;
		}
	}

	// inserta los elementos de elems (que se vacía) a partir de la posición P
	// 0 <= P <= nelems
	void inserta(size_t P, InsertaElementos<T> & elems) {

		// Te devulva la misma cola si esta vacia la nueva
		if(!elems.empty()){
			// Aislamos el caso en el que P = 0 como particular
			if (P == 0) {
				elems.ult->sig = this->prim;
				this->prim = elems.prim;

				// Resto de casos
			}else {
				//Creamos dos nodos auxiliares para el primero y ultimo
				Nodo * aux = this->prim;
				Nodo * auxfin = elems.ult;
				int i = 1;

				// Iteramos hasta hasta el elemento a tratar
				while (i < P && aux != nullptr) {
					aux = aux->sig;
					i++;
				}

				//Introducimos la lista nueva a partir de la posicion dictada
				auxfin->sig = aux->sig;
				aux->sig = elems.prim;
			}
			
		}
	}

	// Metodo que limpia la lista auxiliar
	void vaciar() {
		this->prim = nullptr;
		this->ult = nullptr;
		this->nelems = 0;
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, InsertaElementos<T> const& lista) {
	lista.print(o);
	return o;
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin)
		return false;

	InsertaElementos<int> lista;
	for (size_t i = 0; i < N; ++i) {
		int num;
		cin >> num;
		lista.push(num);
	}

	int M, P;
	cin >> M >> P;

	InsertaElementos<int> nuevos;
	for (size_t i = 0; i < M; ++i) {
		int num;
		cin >> num;
		nuevos.push(num);
	}

	lista.inserta(P, nuevos);

	cout << lista << '\n';

	nuevos.vaciar();
	
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}