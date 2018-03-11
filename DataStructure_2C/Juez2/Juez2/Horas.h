#ifndef Horas_h
#define Horas_h

#include <ostream>
#include <exception>
#include <fstream>

class Horas {
public:
	// constructores
	Horas() : hor(0), min(0), seg(0) {};
	Horas(int horas, int minutos, int segundos);

	// Metodos
	void print(std::ostream & out) const;
	bool operator<(Horas const& that) const;
	bool operator==(Horas const& that) const;
	Horas operator+(Horas const& that) const;
	int getHoras();
	int getMin();
	int getSeg();

	// destructor
	~Horas();

private:
	int hor, min, seg; // Variables
};

#endif // horas_h