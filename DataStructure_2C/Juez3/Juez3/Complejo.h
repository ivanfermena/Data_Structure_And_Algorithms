#ifndef Complejo_h
#define Complejo_h

#include <ostream>
#include <fstream>

class Complejo {
public:
	// constructores
	Complejo(float numeroReal, float numeroImag, int numeroIter);
	Complejo() : numeroReal(0.0f), numeroImag(0.0f), numeroIter(0) {};

	// destructor
	~Complejo();

	Complejo operator+(Complejo const& that) const;
	Complejo operator*(Complejo const& that) const;
	int operator%(Complejo const& that) const;
	//Complejo operator^(int const& that) const;
	int get_numeroIter();

private:
	float numeroReal;
	float numeroImag;
	int numeroIter;
};

#endif // horas_h
