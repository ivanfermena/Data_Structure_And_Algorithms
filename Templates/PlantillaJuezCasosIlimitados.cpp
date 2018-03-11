// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector <int> vc) {
    

    
}

bool resuelveCaso() {
    
	int numElem;

	std::cin >> numElem;

    if (! std::cin)
        return false;

	std::vector <int> vc(numElem);

	for (int &aux : vc)
		std::cin >> aux;

    int sol = resolver(vc, 0, vc.size());
 
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