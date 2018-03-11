// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void resolver(std::vector<int>& a, std::vector<int>& v)
/*	Especificacion:

requires a!= null && a.Length > 0
ensures v != null && v.Length > 0 && a.Length == v.Length
ensures forall n :: 0 <= n < v.Length ==> v[n] == Sum(a[n..])
*/
{
	int x = 0;

	for (int long i = a.size(); i > 0; --i)
		/*	invariant 0 <= i <= v.Length
			invariant forall n :: i <= n < v.Length ==> v[n] == Sum(a[n..])
			invariant x == Sum(a[i..])
			invariant a.Length == v.Length
			decreases i
		*/
	{
		x += a[i - 1];
		v[i - 1] = x;
	}

}

bool resuelveCaso() {

	std::vector <int> vc;
	int numSelect;

	do {
		std::cin >> numSelect;

		vc.push_back(numSelect);

	} while (numSelect != 0);

	if (vc.size() == 1 && vc[0] == 0)
		return false;

	std::vector <int> sol(vc.size());

	resolver(vc, sol);

	for (int i = 0; i < sol.size() - 1; ++i) {
		std::cout << sol[i] << " ";
	}
	std::cout << "\n";

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