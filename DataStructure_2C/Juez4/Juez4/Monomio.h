#ifndef Monomio_h
#define Monomio_h

#include <ostream>
#include <fstream>

class Monomio {
public:
	// constructores
	Monomio(int coeficiente, int exponencial);
	Monomio() : coeficiente(0), exponencial(0) {};
	bool isEndLine();
	int calculateMonomio(int valor);

	// destructor
	~Monomio();

private:
	int coeficiente;
	int exponencial;
};

#endif // horas_h

