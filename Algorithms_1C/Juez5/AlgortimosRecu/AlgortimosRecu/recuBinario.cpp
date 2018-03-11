#include <vector>

//O(log n)

// Tratamos que esta ordenado y que biscamos o vamos viendo en que lado viendo el vamor de m y con el que buscamos

bool busquedaBinaria(std::vector<int> const & vc, int ini, int fin, int x) { // x es el valor que se esta buscando
	
	if (ini == fin) return false;
	else if (ini + 1 == fin) return vc[ini] == x;
	else {
		int mitad = (ini + fin) / 2;
		if (vc[mitad] == x) return true; // Si esta en la mitad justo retornamos encontrado
		else if (vc[mitad] > x) return busquedaBinaria(vc, ini, mitad, x);  //Si es mayor que el que buscamos tenemos que ir a la izquierda
		else return busquedaBinaria(vc, mitad, fin, x);
	}
}