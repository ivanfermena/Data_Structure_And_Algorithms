// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void arbol(std::vector<int> const & superficieObjs, std::vector<int> const& costesObjs, std::vector<bool>& sol, int k, int n, int maximoDinero, int coste, 
	int & beneficio, int & valorMejor)
{ 
	// hijo izquierdo [cogemos el objeto] 
	sol[k] = true; 
	coste = coste + costesObjs[k]; 
	beneficio = beneficio + superficieObjs[k]; 
	
	if(coste <= maximoDinero) { //es valida
		if(k == n - 1) { // Es solucion
			if(valorMejor < beneficio){ // Obtenemos el mejor valor del arbol
				valorMejor = beneficio; 
			}
		} else {
			arbol(superficieObjs, costesObjs, sol, k+1, n, maximoDinero, coste, beneficio, valorMejor); 
		} 
	}
	
	//desmarcamos peso y beneficio
	coste = coste - costesObjs[k];
	beneficio = beneficio - superficieObjs[k];

	// hijo derecho [no cogemos el objeto] 
	sol[k] = false; 
	if(k == n-1){ 
		if(valorMejor < beneficio){ 
			valorMejor = beneficio; 
		} 
	} else{
		arbol(superficieObjs, costesObjs, sol, k + 1, n, maximoDinero, coste, beneficio, valorMejor);
	}
}


bool resuelveCaso2() {

	int numElem, maxDinero, beneficio = 0, coste = 0, valorMejor = 0;

	std::cin >> numElem;

	// Control de entrada y final de programa
	if (!std::cin)
		return false;

	std::cin >> maxDinero;

	std::vector <int> costesObj(numElem);
	std::vector <int> superficieObj(numElem);
	std::vector<bool> sol(numElem);
	std::vector<int> solMejor(numElem);

	// Introducimos los datos en los vectores determinados
	for (int &auxA : costesObj)
		std::cin >> auxA;

	for (int &auxB : superficieObj)
		std::cin >> auxB;

	arbol(superficieObj, costesObj, sol, 0, numElem, maxDinero, coste, beneficio, valorMejor);

	//Imprimimos la mejor solucion fuera y asi nos quedamos con la mejor
	std::cout << valorMejor << "\n";

	return true;
}

int main2() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso2());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}