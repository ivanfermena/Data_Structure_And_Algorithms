// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stack>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int elemStack, auxTam;
	std::stack<int> stackTortitas;
	std::stack<int> stackAuxiliar; 
	std::stack<int> stackIntermedia;

	std::cin >> elemStack;

	if (elemStack == 0)
		return false;

	if (elemStack == -1) {
		return true;
	}

	stackTortitas.push(elemStack);
	std::cin >> elemStack;
	while (elemStack != -1) {
		stackTortitas.push(elemStack);
		std::cin >> elemStack;
	}
	
	std::cin >> auxTam;

	int tortitasMover = 0;

	for (int i = 0; i < auxTam; i++) {
		
		std::cin >> tortitasMover;

		// Cogemos y movemos a la intermedia
		for(int j = 0; j < tortitasMover; j++){
			stackIntermedia.push(stackTortitas.top());
			stackTortitas.pop();
		}

		//Lanzamos de la intermedia a la auxiliar
		for (int j = 0; j < tortitasMover; j++) {
			stackAuxiliar.push(stackIntermedia.top());
			stackIntermedia.pop();
		}

		//Devolvemos a stack tortitas
		for (int j = 0; j < tortitasMover; j++) {
			stackTortitas.push(stackAuxiliar.top());
			stackAuxiliar.pop();
		}

	}

	std::cout << stackTortitas.top() << "\n";

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