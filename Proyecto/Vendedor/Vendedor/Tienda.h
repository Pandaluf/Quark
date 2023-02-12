#pragma once
#include "Prenda.h"

class Tienda {
	double cantidadMangaCorta_CuelloMao_Standard;
	double cantidadMangaCorta_CuelloMao_Premium;
	double cantidadMangaCorta_CuelloComún_Standard;
	double cantidadMangaCorta_CuelloComún_Premium;

	double cantidadMangaLarga_CuelloMao_Standard;
	double cantidadMangaLarga_CuelloMao_Premium;
	double cantidadMangaLarga_CuelloComún_Standard;
	double cantidadMangaLarga_CuelloComún_Premium;

	double cantidadPantalon_Chupín_Standard;
	double cantidadPantalon_Chupín_Premium;
	double cantidadPantalon_Común_Standard;
	double cantidadPantalon_Común_Premium;

	string nombre;
	string direccion;
public:
	Tienda(string nombre, string direccion) {
		cantidadMangaCorta_CuelloMao_Standard = 100;
		cantidadMangaCorta_CuelloMao_Premium = 100;
		cantidadMangaCorta_CuelloComún_Standard = 150;
		cantidadMangaCorta_CuelloComún_Premium = 150;

		cantidadMangaLarga_CuelloMao_Standard = 75;
		cantidadMangaLarga_CuelloMao_Premium = 75;
		cantidadMangaLarga_CuelloComún_Standard = 175;
		cantidadMangaLarga_CuelloComún_Premium = 175;

		cantidadPantalon_Chupín_Standard = 750;
		cantidadPantalon_Chupín_Premium = 750;
		cantidadPantalon_Común_Standard = 250;
		cantidadPantalon_Común_Premium = 250;

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
					cantidadMangaCorta_CuelloComún_Standard -= prenda->getUnidades();
				}
				else {
					if (prenda->getType()[1] == "Manga corta" && prenda->getCalidad() == "Premium") {
						cantidadMangaCorta_CuelloComún_Premium -= prenda->getUnidades();
					}
					else {
						if (prenda->getType()[1] == "Manga larga" && prenda->getCalidad() == "Standard") {
							cantidadMangaLarga_CuelloComún_Standard -= prenda->getUnidades();
						}
						else {
							if (prenda->getType()[1] == "Manga larga" && prenda->getCalidad() == "Premium") {
								cantidadMangaLarga_CuelloComún_Premium -= prenda->getUnidades();
							}
						}
					}
				}
			}
		}
		else {
			if (prenda->getType()[0] == "Pantalón") {
				if (prenda->getType().size() > 1) {
					if (prenda->getType()[1] == "Chupín" && prenda->getCalidad() == "Standard") {
						cantidadPantalon_Chupín_Standard -= prenda->getUnidades();
					}
					else {
						if (prenda->getType()[1] == "Chupín" && prenda->getCalidad() == "Premium") {
							cantidadPantalon_Chupín_Premium -= prenda->getUnidades();
						}
					}
				}
				else {
					if (prenda->getCalidad() == "Standard") {
						cantidadPantalon_Común_Standard -= prenda->getUnidades();
					}
					else {
						if (prenda->getCalidad() == "Premium") {
							cantidadPantalon_Común_Premium -= prenda->getUnidades();
						}
					}
				}
			}
		}
	}

	double getCantidadMangaCorta_CuelloMao_Standard() { return cantidadMangaCorta_CuelloMao_Standard; }
	double getCantidadMangaCorta_CuelloMao_Premium() { return cantidadMangaCorta_CuelloMao_Premium; }
	double getCantidadMangaCorta_CuelloComún_Standard() { return cantidadMangaCorta_CuelloComún_Standard; }
	double getCantidadMangaCorta_CuelloComún_Premium() { return cantidadMangaCorta_CuelloComún_Premium; }
	double getCantidadMangaLarga_CuelloMao_Standard() { return cantidadMangaLarga_CuelloMao_Standard; }
	double getCantidadMangaLarga_CuelloMao_Premium() { return cantidadMangaLarga_CuelloMao_Premium; }
	double getCantidadMangaLarga_CuelloComún_Standard() { return cantidadMangaLarga_CuelloComún_Standard; }
	double getCantidadMangaLarga_CuelloComún_Premium() { return cantidadMangaLarga_CuelloComún_Premium; }
	double getCantidadPantalon_Chupín_Standard() { return cantidadPantalon_Chupín_Standard; }
	double getCantidadPantalon_Chupín_Premium() { return cantidadPantalon_Chupín_Premium; }
	double getCantidadPantalon_Común_Standard() { return cantidadPantalon_Común_Standard; }
	double getCantidadPantalon_Común_Premium() { return cantidadPantalon_Común_Premium; }

	double totalCamisas() {
		return cantidadMangaCorta_CuelloMao_Standard + cantidadMangaCorta_CuelloMao_Premium + cantidadMangaCorta_CuelloComún_Standard + cantidadMangaCorta_CuelloComún_Premium + cantidadMangaLarga_CuelloMao_Standard + cantidadMangaLarga_CuelloMao_Premium + cantidadMangaLarga_CuelloComún_Standard + cantidadMangaLarga_CuelloComún_Premium;
	}

	double totalPantalon() {
		return cantidadPantalon_Chupín_Standard + cantidadPantalon_Chupín_Premium + cantidadPantalon_Común_Standard + cantidadPantalon_Común_Premium;
	}

	string getNombre() { return nombre; }
	string getDireccion() { return direccion; }
};