// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Estimacion -> Cuando estamos en la etapa "k" cogemos el minimo de todas las tareas que mejor sabe hacer, es decir uq eel caso mejor es que le den la mejor 
// tarea. Para ello lo que hacemos es el acomulado y s elo pasamos como argumento

void funcionarios(std::vector<std::vector<long int> > const & m, std::vector<int> const & vAcum, int k, std::vector<bool> & marcas, long int & sumMin, long int & sum) {
	for (int t = 0; t < m.size(); t++) {
		sum += m[k][t];
		if (!marcas[t]) {
			if (k + 1 == marcas.size()) { //Es solucion
				if (sum < sumMin) sumMin = sum;
			}
			else {
				//Marcas y desmarcar siempre en el mismo bucle.
				if(sum + vAcum[k+1] < sumMin){ // Comprobamos que el siguiente es mas costoso y si es asi no realizamos la recursion k + 1
					marcas[t] = true;
					funcionarios(m, vAcum, k + 1, marcas, sumMin, sum);
					marcas[t] = false;
				}
			}
		}
		sum -= m[k][t];
	}
}

std::vector<int> acumula(std::vector<std::vector<long int> > const & m) {

	std::vector<int> minimos(m.size());

	// Primero seleccionamos la acumulacion de minimos 
	for (int x = 0; x < m.size(); x++) { 
		int min = m[x][0];
		for (int y = 1; y < m.size(); y++) {
			if (m[x][y] < min) min = m[x][y];
		}
		minimos[x] = min;
	}

	// Realizamos la acumulacion de los valores
	for (int i = minimos.size() - 1; i > 0; --i)
		minimos[i - 1] += minimos[i];

	return minimos;
}

bool resuelveCaso() {
	int numElem;
	std::cin >> numElem;
	if (numElem == 0)
		return false;
	std::vector<std::vector<long int> > m(numElem, (std::vector<long int>(numElem)));

	long int sumMin = 10000 * numElem, sum = 0;

	for (int u = 0; u < numElem; u++) sumMin += m[u][u]; // Inicializacion de sumMin con la primera diagonal, la primera posible combinacion

	for (int x = 0; x < numElem; x++) // Entrada en la matriz
		for (int y = 0; y < numElem; y++)
			std::cin >> m[x][y];

	std::vector<int> vAcum = acumula(m);// Vector de acumulados

	std::vector<bool> marcas(numElem); // Vector para controlar el marcaje de los trabajadores
	for (int i = 0; i < numElem; i++) // Inicializacion del vector de marcas a falsos
		marcas[i] = false;
	funcionarios(m, vAcum, 0, marcas, sumMin, sum);
	std::cout << sumMin << "\n";
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