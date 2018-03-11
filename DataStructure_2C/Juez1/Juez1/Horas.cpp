#include "Horas.h"

#include <string>
#include <stdexcept>

Horas::Horas(int horas, int minutos, int segundos) {
	if ((0 <= horas) && (horas <= 23) && (0 <= minutos) && (minutos <= 59) && (0 <= segundos) && (segundos <= 59)) {
		hor = horas;
		min = minutos;
		seg = segundos;
	}
	else {
		throw std::domain_error("ERROR");
	}
}

Horas::~Horas() {}

void Horas::print(std::ostream & out) const {
	std::string strHoras = (hor / 10 == 0) ? "0" + std::to_string(hor) : std::to_string(hor);
	std::string strMin = (min / 10 == 0) ? "0" + std::to_string(min) : std::to_string(min);
	std::string strSeg = (seg / 10 == 0) ? "0" + std::to_string(seg) : std::to_string(seg);
	out << strHoras << ':' << strMin << ':' << strSeg << "\n";
}

int Horas::getHoras() { return hor; }
int Horas::getMin() { return min; }
int Horas::getSeg() { return seg; }