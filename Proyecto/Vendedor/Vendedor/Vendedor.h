#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Cotizaci�n.h"

using namespace std;

class Vendedor {
private:
	string nombre;
	string apellido;
	int codigoVendedor;
	vector<Cotizacion> cotizaciones;
	int n�meroIdentificaci�n;
public:
	Vendedor(string nombre, string apellido, int codigoVendedor) {
		this->nombre = nombre;
		this->apellido = apellido;
		this->codigoVendedor = codigoVendedor;
		n�meroIdentificaci�n = 0;
	}

	void realizarCotizacion(Prenda* prenda) {
		struct tm nuevoTiempo;
		time_t tiempoAhora = time(0);
		time(&tiempoAhora);
		localtime_s(&nuevoTiempo, &tiempoAhora);
		string mes = to_string(nuevoTiempo.tm_mon+1);
		string dia = to_string(nuevoTiempo.tm_mday);
		string a�o = to_string(nuevoTiempo.tm_year + 1900);
		string hora = to_string(nuevoTiempo.tm_hour);
		string minutos = to_string(nuevoTiempo.tm_min);

		string fecha = dia + "/" + mes + "/" + a�o + " " + hora + ":" + minutos;

		

		cotizaciones.push_back(Cotizacion(n�meroIdentificaci�n++, fecha, codigoVendedor, prenda));
	}

	void mostrarUltimaCotizaci�n() {
		cotizaciones[cotizaciones.size() - 1].showCotizacion();
	}

	int getCodigoVendedor() { return codigoVendedor; }
	vector<Cotizacion> getCotizaciones() { return cotizaciones; }
	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
};