// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>

long long int resolver(long long int n) 
/* Especificacion:
	requires n>=0
	ensures f == Fib(n)
*/
{
	long long int f, anterior = 0;
	if (n < 2) {
		f = n;
	}else {
		f = 1;
		for (long long int i = 0; i <= n - 2; i++) 
		/*	invariant f == Fib(i+1)
			invariant anterior == Fib(i)
			invariant 0 <= i <= n-1
			invariant n-2-i
		*/
		{
			f += anterior;
			anterior = f - anterior;
		}
	}
	return f;
}

bool resuelveCaso() {
	long long int numFibo;

	std::cin >> numFibo;
	if (numFibo == -1)
		return false;

	long long int sol = resolver(numFibo);

	std::cout << sol << "\n";

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