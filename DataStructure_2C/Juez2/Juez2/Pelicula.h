#ifndef Pelicula_h
#define Pelicula_h

#include <ostream>
#include <exception>
#include <fstream>
#include "Horas.h"

class Pelicula {
public:
	// constructores
	Pelicula(Horas horaInicio, Horas duracion, std::string nombre);
	Pelicula() : horaInicio(Horas()), duracion(Horas()), nombre("") {};
	bool operator<(Pelicula const& that) const;
	// destructor
	~Pelicula();

	Horas get_horaFin() const;
	std::string get_nombre() const;

private:
	Horas horaInicio;
	Horas horaFin;
	Horas duracion;
	std::string nombre;
};

#endif // horas_h
