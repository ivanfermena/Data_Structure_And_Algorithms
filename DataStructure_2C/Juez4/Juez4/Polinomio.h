#ifndef Polinomio_h
#define Polinomio_h

#include <ostream>
#include <fstream>
#include <vector>
#include "Monomio.h" 

class Polinomio {
public:
	// constructores
	Polinomio() : vcMonomios(0) {};
	void addMonomio(Monomio mon);
	int calculatePolinomio(int valor);

	// destructor
	~Polinomio();

private:
	std::vector<Monomio> vcMonomios;
};

#endif // horas_h

