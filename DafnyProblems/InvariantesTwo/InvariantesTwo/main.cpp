void main() {

	int Fib(int n){
		if (n < 2) return n
		else return Fib(n - 2) + Fib(n - 1)
	}

	int Fibonacci(int n){
		//requires n >= 0
		//ensures f == Fib(n)
	
		int aux = 0;
		if (n<2) { f = n; }
		else {
			var i = 0;
			f: = 1;
			while (i <= n - 2){
				//invariant 0 <= i <= n - 1
				//invariant f == Fib(i + 1)
				//invariant aux == Fib(i)
			
				f = f + aux;
				aux = f - aux;
				i = i + 1;
			}
		}
		return f;
	}
}

// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>



// función que resuelve el problema
TipoSolucion resolver(TipoDatos datos) {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	if (!std::cin)
		return false;

	TipoSolucion sol = resolver(datos);

	// escribir sol


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