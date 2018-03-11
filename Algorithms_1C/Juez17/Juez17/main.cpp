// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSolucion
{
	int peso = 0;
	bool ok = true;
};

tSolucion estaBalanceado() {

	int pI, dI, pD, dD;
	tSolucion sol;

	std::cin >> pI >> dI >> pD >> dD;

	if (pI!=0 && pD!=0)
	{
		sol.peso = pI + pD;
		sol.ok = (pI * dI == pD * dD);
	}
	else{
		if (pI==0 && pD == 0){
			tSolucion solIz = estaBalanceado();
			tSolucion solDe = estaBalanceado();
			sol.peso = solIz.peso + solDe.peso;
			sol.ok = solIz.ok && solDe.ok && (solIz.peso * dI == solDe.peso * dD);
		}
		else if (pI==0) {
			tSolucion solIz = estaBalanceado();
			sol.peso = solIz.peso + pD;
			sol.ok = solIz.ok && (solIz.peso*dI == pD*dD);
		}
		else{
			tSolucion solDr = estaBalanceado();
			sol.peso = solDr.peso + pI;
			sol.ok = solDr.ok && (solDr.peso*dD == pI*dI);
		}
	}
	return sol;
}

void resuelveCaso() {

	tSolucion sol = estaBalanceado();

	if (sol.ok)
		std::cout << "SI" << "\n";
	else
		std::cout << "NO" << "\n";
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;

	std::cin >> numCasos;

	for (int i = 0; i < numCasos; i++)
		resuelveCaso();

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}