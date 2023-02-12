#pragma once
#include "Prenda.h"

class Tienda {
	double cantidadMangaCorta_CuelloMao_Standard;
	double cantidadMangaCorta_CuelloMao_Premium;
	double cantidadMangaCorta_CuelloCom�n_Standard;
	double cantidadMangaCorta_CuelloCom�n_Premium;

	double cantidadMangaLarga_CuelloMao_Standard;
	double cantidadMangaLarga_CuelloMao_Premium;
	double cantidadMangaLarga_CuelloCom�n_Standard;
	double cantidadMangaLarga_CuelloCom�n_Premium;

	double cantidadPantalon_Chup�n_Standard;
	double cantidadPantalon_Chup�n_Premium;
	double cantidadPantalon_Com�n_Standard;
	double cantidadPantalon_Com�n_Premium;

	string nombre;
	string direccion;
public:
	Tienda(string nombre, string direccion) {
		cantidadMangaCorta_CuelloMao_Standard = 100;
		cantidadMangaCorta_CuelloMao_Premium = 100;
		cantidadMangaCorta_CuelloCom�n_Standard = 150;
		cantidadMangaCorta_CuelloCom�n_Premium = 150;

		cantidadMangaLarga_CuelloMao_Standard = 75;
		cantidadMangaLarga_CuelloMao_Premium = 75;
		cantidadMangaLarga_CuelloCom�n_Standard = 175;
		cantidadMangaLarga_CuelloCom�n_Premium = 175;

		cantidadPantalon_Chup�n_Standard = 750;
		cantidadPantalon_Chup�n_Premium = 750;
		cantidadPantalon_Com�n_Standard = 250;
		cantidadPantalon_Com�n_Premium = 250;

		this->nombre = nombre;
		this->direccion = direccion;
	}

	void contabilizar(Prenda* prenda) {
		if (prenda->getType()[0] == "Camisa") {
			if (prenda->getType().size() > 2) {
				if (prenda->getType()[1] == "Manga corta" && prenda->getType()[2] == "Cuello Mao" && prenda->getCalidad() == "Standard") {
					cantidadMangaCorta_CuelloMao_Standard -= prenda->getUnidades();
				}
				else {
					if (prenda->getType()[1] == "Manga corta" && prenda->getType()[2] == "Cuello Mao" && prenda->getCalidad() == "Premium") {
						cantidadMangaCorta_CuelloMao_Premium -= prenda->getUnidades();
					}
					else {
						if (prenda->getType()[1] == "Manga larga" && prenda->getType()[2] == "Cuello Mao" && prenda->getCalidad() == "Standard") {
							cantidadMangaLarga_CuelloMao_Standard -= prenda->getUnidades();
						}
						else {
							if (prenda->getType()[1] == "Manga larga" && prenda->getType()[2] == "Cuello Mao" && prenda->getCalidad() == "Premium") {
								cantidadMangaLarga_CuelloMao_Premium -= prenda->getUnidades();
							}
						}
					}
				}
			}
			else {
				if (prenda->getType()[1] == "Manga corta" && prenda->getCalidad() == "Standard") {
					cantidadMangaCorta_CuelloCom�n_Standard -= prenda->getUnidades();
				}
				else {
					if (prenda->getType()[1] == "Manga corta" && prenda->getCalidad() == "Premium") {
						cantidadMangaCorta_CuelloCom�n_Premium -= prenda->getUnidades();
					}
					else {
						if (prenda->getType()[1] == "Manga larga" && prenda->getCalidad() == "Standard") {
							cantidadMangaLarga_CuelloCom�n_Standard -= prenda->getUnidades();
						}
						else {
							if (prenda->getType()[1] == "Manga larga" && prenda->getCalidad() == "Premium") {
								cantidadMangaLarga_CuelloCom�n_Premium -= prenda->getUnidades();
							}
						}
					}
				}
			}
		}
		else {
			if (prenda->getType()[0] == "Pantal�n") {
				if (prenda->getType().size() > 1) {
					if (prenda->getType()[1] == "Chup�n" && prenda->getCalidad() == "Standard") {
						cantidadPantalon_Chup�n_Standard -= prenda->getUnidades();
					}
					else {
						if (prenda->getType()[1] == "Chup�n" && prenda->getCalidad() == "Premium") {
							cantidadPantalon_Chup�n_Premium -= prenda->getUnidades();
						}
					}
				}
				else {
					if (prenda->getCalidad() == "Standard") {
						cantidadPantalon_Com�n_Standard -= prenda->getUnidades();
					}
					else {
						if (prenda->getCalidad() == "Premium") {
							cantidadPantalon_Com�n_Premium -= prenda->getUnidades();
						}
					}
				}
			}
		}
	}

	double getCantidadMangaCorta_CuelloMao_Standard() { return cantidadMangaCorta_CuelloMao_Standard; }
	double getCantidadMangaCorta_CuelloMao_Premium() { return cantidadMangaCorta_CuelloMao_Premium; }
	double getCantidadMangaCorta_CuelloCom�n_Standard() { return cantidadMangaCorta_CuelloCom�n_Standard; }
	double getCantidadMangaCorta_CuelloCom�n_Premium() { return cantidadMangaCorta_CuelloCom�n_Premium; }
	double getCantidadMangaLarga_CuelloMao_Standard() { return cantidadMangaLarga_CuelloMao_Standard; }
	double getCantidadMangaLarga_CuelloMao_Premium() { return cantidadMangaLarga_CuelloMao_Premium; }
	double getCantidadMangaLarga_CuelloCom�n_Standard() { return cantidadMangaLarga_CuelloCom�n_Standard; }
	double getCantidadMangaLarga_CuelloCom�n_Premium() { return cantidadMangaLarga_CuelloCom�n_Premium; }
	double getCantidadPantalon_Chup�n_Standard() { return cantidadPantalon_Chup�n_Standard; }
	double getCantidadPantalon_Chup�n_Premium() { return cantidadPantalon_Chup�n_Premium; }
	double getCantidadPantalon_Com�n_Standard() { return cantidadPantalon_Com�n_Standard; }
	double getCantidadPantalon_Com�n_Premium() { return cantidadPantalon_Com�n_Premium; }

	double totalCamisas() {
		return cantidadMangaCorta_CuelloMao_Standard + cantidadMangaCorta_CuelloMao_Premium + cantidadMangaCorta_CuelloCom�n_Standard + cantidadMangaCorta_CuelloCom�n_Premium + cantidadMangaLarga_CuelloMao_Standard + cantidadMangaLarga_CuelloMao_Premium + cantidadMangaLarga_CuelloCom�n_Standard + cantidadMangaLarga_CuelloCom�n_Premium;
	}

	double totalPantalon() {
		return cantidadPantalon_Chup�n_Standard + cantidadPantalon_Chup�n_Premium + cantidadPantalon_Com�n_Standard + cantidadPantalon_Com�n_Premium;
	}

	string getNombre() { return nombre; }
	string getDireccion() { return direccion; }
};