// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct MyStruct
{
	int maxWin = 0;
	int countMaxWin = 0;
	int matchEnd = 0;
};

MyStruct resolver(std::vector<int> const & vc) {

	MyStruct myStr;
	int auxMaxWin = 0, auxPos = 0;

	for (int i = 0; i < vc.size(); i++)
	{
		if (vc[i] > 0){

			auxMaxWin++;
			
			if (auxMaxWin > myStr.maxWin)
			{
				myStr.maxWin = auxMaxWin;
				myStr.countMaxWin = 1;
				auxPos = i + 1;
			}
			else if (auxMaxWin == myStr.maxWin)
			{
				myStr.countMaxWin++;
				auxPos = i + 1;
			}
		}
		else
		{
			auxMaxWin = 0;
		}
	}

	myStr.matchEnd = vc.size() - auxPos;

	return myStr;
}

bool resuelveCaso() {

	int sizeVector;

	std::cin >> sizeVector;

	if (!std::cin)
		return false;

	std::vector<int> vc(sizeVector);

	for (int &aux : vc) 
		std::cin >> aux;

	MyStruct sol = resolver(vc);

	std::cout << sol.maxWin << " " << sol.countMaxWin << " " << sol.matchEnd << "\n";

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