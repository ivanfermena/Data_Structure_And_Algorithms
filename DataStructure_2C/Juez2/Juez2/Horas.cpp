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
	out << strHoras << ':' << strMin << ':' << strSeg;
}

//Sobrecarga de operando hor + that.hor
Horas Horas::operator + (Horas const& that) const {
	Horas horas;
	horas.hor = that.hor + hor;
	horas.min = that.min + min;
	horas.seg = that.seg + seg;
	if (horas.seg > 59) {
		horas.min++; horas.seg -= 60;
	}
	
	if (horas.min > 59) {
		horas.hor++; horas.min -= 60;
	}
	
	return horas;
}

int Horas::getHoras() { return hor; }
int Horas::getMin() { return min; }
int Horas::getSeg() { return seg; }