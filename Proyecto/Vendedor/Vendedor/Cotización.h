#pragma once
#include "Prenda.h"
#include <time.h>
#include <ctime>
#include <stdio.h>

class Cotizacion {
private:
	int numeroIdentificacion;
	string fechaHora;
	string calidad;
	Prenda* prenda;
	double descuentoPorcentaje;
	double unidades;
	double precioFinal;
	int codigoVendedor;

public:
	Cotizacion(int númeroIdentificación, string fechaHora, int codigoVendedor, Prenda* prenda) {
		this->numeroIdentificacion = númeroIdentificación;
		this->fechaHora = fechaHora;
		this->prenda = prenda;
		unidades = prenda->getUnidades();
		this->codigoVendedor = codigoVendedor;
		calidad = prenda->getCalidad();
		precioFinal = 0;
		descuentoPorcentaje = 0;
	}

	void precioFinalCotizacion() {
		if (prenda->getRN() == 1) {
			precioFinal = (unidades * prenda->getPrecioUnitario()) + prenda->calcularDescuentoTipo();
		}
		else {
			if (prenda->getRN() == 2) {
				precioFinal = (unidades * prenda->getPrecioUnitario()) + prenda->calcularDescuentoTipo();
			}
			else {
				if (prenda->getRN() == 3) {
					precioFinal = (unidades * prenda->getPrecioUnitario()) - ((unidades * prenda->getPrecioUnitario())*0.10);
					precioFinal = precioFinal + (precioFinal * 0.03);
				}
				else {
					if (prenda->getRN() == 4) {
						precioFinal = (unidades * prenda->getPrecioUnitario()) + prenda->calcularDescuentoTipo();
					}
				}
			}
		}

		if (prenda->getCalidad() == "Premium") {
			if (precioFinal != 0) {
				precioFinal = precioFinal + (precioFinal * 0.3);
			}
			else {
				precioFinal = (unidades * prenda->getPrecioUnitario()) + (unidades * prenda->getPrecioUnitario()*0.3);
			}
		}


		if (prenda->getRN() == 0 && prenda->getCalidad() == "Standard") {
			precioFinal = unidades * prenda->getPrecioUnitario();
		}
	}

	void showCotizacion() {

		cout << "Número de identificacion: " << numeroIdentificacion << "\n";
		cout << "Fecha y Hora de la cotización: " << fechaHora << "\n";
		cout << "Código del Vendedor: " << codigoVendedor << "\n";
		cout << "Prenda cotizada: ";
		for (int i = 0; i < prenda->getType().size(); i++) {
				cout << prenda->getType()[i] << " - ";
		}
		cout << prenda->getCalidad() << "\n";
		cout << "Precio unitario: " << prenda->getPrecioUnitario() << "\n";;
		cout << "Cantidad de unidades cotizadas: " << unidades << "\n";
		precioFinalCotizacion();
		cout << "Precio Final: " << precioFinal << "\n\n";
	}


};