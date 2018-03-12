// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

#include <stack>

struct carta {
	int valor;
	int palo; // 0 = oros , 1 = copas , 2 = espadas , 3 = bastos
};
// función que resuelve el problema
bool gana_solitario(std::stack<carta> & mazo, std::stack<carta> & mano) {
	std::vector<int> ultima_carta_palo(4, 0); // 0 = oros , 1 = copas , 2 = espadas , 3 = bastos
	bool derrota = false;
	while (!mazo.empty() && !derrota) {
		int tam_inicial_mazo = mazo.size();
		while (!mazo.empty() && !derrota) {
			if (mazo.size() != 1) {
				mano.push(mazo.top());
				mazo.pop();
				mano.push(mazo.top());
				mazo.pop();
			}
			else {
				mano.push(mazo.top());
				mazo.pop();
			}

			while (!mano.empty() && ((ultima_carta_palo[mano.top().palo] + 1 == mano.top().valor) || (ultima_carta_palo[mano.top().palo] == 7 && mano.top().valor == 10))) {
				ultima_carta_palo[mano.top().palo] = mano.top().valor;
				mano.pop();
			}
		}
		if (tam_inicial_mazo == mano.size())
			derrota = true;
		while (!mano.empty() && !derrota) {
			mazo.push(mano.top());
			mano.pop();
		}
	}
	return !derrota;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	std::cin >> numElem;
	if (numElem == 0)
		return false;
	std::stack<carta> mazo, mano;
	for (int i = 0; i < numElem * 10; i++) {
		carta elem;
		char auxPalo;
		std::cin >> elem.valor >> auxPalo;
		switch (auxPalo)
		{
		case 'O': {
			elem.palo = 0;
		} break;
		case 'C': {
			elem.palo = 1;
		} break;
		case 'E': {
			elem.palo = 2;
		} break;
		case 'B': {
			elem.palo = 3;
		}break;
		}
		mano.push(elem);
	}
	while (!mano.empty()) {
		mazo.push(mano.top());
		mano.pop();
	}
	std::cout << (gana_solitario(mazo, mano) ? "GANA\n" : "PIERDE\n");
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}