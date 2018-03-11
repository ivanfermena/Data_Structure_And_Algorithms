// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void adorno(std::vector<int> const & costesObj, std::vector<int> const & espacioObj, int dineroMax, int & superficieMaxima, int k, 
	std::vector<bool> & marcasObjetos , int & dineroActual, int & mejorSol,int & auxSol) {

	// Primero marcamos el elemento (Usamos el objeto)
	marcasObjetos[k] = true;
	dineroActual += costesObj[k]; // Le metemos el peso y el coste
	auxSol += espacioObj[k];

	if (dineroActual <= dineroMax){ // Es valida
		if (k + 1 == costesObj.size()){
			if (auxSol > mejorSol) mejorSol = auxSol; // Actualizamos la mejor solucion
		}
		else adorno(costesObj, espacioObj, dineroMax, superficieMaxima, k + 1, marcasObjetos, dineroActual, mejorSol, auxSol);
	}

	// No usamos ese objeto
	marcasObjetos[k] = false;
	dineroActual -= costesObj[k]; // Le metemos el peso y el coste
	auxSol -= espacioObj[k];

	if (k + 1 == costesObj.size()) {
			if (auxSol > mejorSol) mejorSol = auxSol; // Actualizamos la mejor solucion
		}
	else adorno(costesObj, espacioObj, dineroMax, superficieMaxima, k + 1, marcasObjetos, dineroActual, mejorSol, auxSol);
}

bool resuelveCaso() {

	int numObjetos, dineroMax, superficieMaxima = 0, dineroActual = 0, mejorSol = 0, auxMejor = 0;

	std::cin >> numObjetos;

	// Control de entrada y final de programa
	if (!std::cin)
		return false;

	std::cin >> dineroMax;

	std::vector<int> costesObj(numObjetos);
	std::vector<int> espacioObj(numObjetos);
	std::vector<bool> marcasObjetos(numObjetos, false);

	for (int & aux : costesObj) std::cin >> aux;
	for (int & aux : espacioObj) std::cin >> aux;

	adorno(costesObj, espacioObj, dineroMax, superficieMaxima, 0, marcasObjetos, dineroActual, mejorSol, auxMejor);

	std::cout << mejorSol << "\n";

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}