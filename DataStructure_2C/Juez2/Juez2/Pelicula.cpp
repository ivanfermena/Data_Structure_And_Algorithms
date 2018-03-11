#include "Pelicula.h"

#include <string>
#include <stdexcept>

Pelicula::Pelicula(Horas auxInicio, Horas duracion, std::string auxNombre) {
	horaInicio = auxInicio;
	duracion = duracion;
	horaFin = auxInicio + duracion;
	nombre = auxNombre;
}

Pelicula::~Pelicula() {}

Horas Pelicula::get_horaFin() const {
	return horaFin;
}

std::string Pelicula::get_nombre() const {
	return nombre;
}