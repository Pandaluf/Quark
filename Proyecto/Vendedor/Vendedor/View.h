#pragma once
#include <iostream>
#include <Windows.h>
#include "IView.h"
#include "Presenter.h"

void cotizarText() {
	cout << "COIZADOR EXPRESS - MENÚ PRINCIPAL\n";
	cout << "-----------------------------------------------------\n";
	cout << "Presiona 3 para volver al menú principal\n";
	cout << "-----------------------------------------------------\n";
}

class View : public IView {
private:
	Presenter* presenter;
public:
	View() {
		SetConsoleTitleW(L"Vendedor");
		setlocale(LC_ALL, "es_Es");
		presenter = new Presenter(this);
		mostrarMenuPrincipal();
	}

	~View() {
		delete presenter;
	}

	void mostrarMenuPrincipal() {
		short opcion;
		do {
			system("cls");
			cout << "COIZADOR EXPRESS - MENÚ PRINCIPAL\n";
			cout << "-----------------------------------------------------\n";
			cout << presenter->getTienda()->getNombre() << " | " << presenter->getTienda()->getDireccion() << "\n";
			cout << "-----------------------------------------------------\n";
			cout << presenter->getVendedor()->getNombre() << " " << presenter->getVendedor()->getApellido() <<" | " << presenter->getVendedor()->getCodigoVendedor() << "\n";
			cout << "-----------------------------------------------------\n\n";
			cout << "SELECCIONE UNA OPCIÒN DEL MENÚ:\n\n";
			cout << "1) Historial de Cotizaciones\n";
			cout << "2) Realizar Cotización\n";
			cout << "3) Salir\n";
			cin >> opcion;

		} while (opcion != 1 && opcion != 2 && opcion != 3);

		ejecutarOpcion(opcion);
	}

	void ejecutarOpcion(short& opcion) {
		if (opcion == 1) {
			system("cls");
			presenter->mostrarCotizaciones();
			cout << "\n";
			system("pause");
			mostrarMenuPrincipal();
		}
		else {
			if (opcion == 2) {
				cotizar();
				cout << "\n";
				system("pause");
				mostrarMenuPrincipal();
			}
			else {
				exit(1);
			}
		}
	}

	void cotizar() {
		short opcion;

		vector<string> tipo;

		do {
			system("cls");
			cotizarText();
			cout << "PASO 1: Selecciona la prenda a cotizar:\n";
			cout << "1) Camisa\n";
			cout << "2) Pantalón\n";
			cout << "-----------------------------------------------------\n";
			cin >> opcion;
		} while (opcion != 1 && opcion != 2 && opcion != 3);

		if (opcion == 1) tipo.push_back("Camisa");
		else tipo.push_back("Pantalón");

		opcionPrenda(opcion, tipo);
	}

	void opcionPrenda(short& opcion, vector<string>& tipo) {
		short opcionParte3;
		double precioUnitario;
		int unidades;
		short RN = 0;
		string calidad;
		double cantidadPrenda = 0;

		if (opcion == 1) {
			short opcionParte2a;
			short opcionParte2b;

			do {
				system("cls");
				cotizarText();
				cout << "PASO 2.a: La camisa a cotizar, ¿Es Manga corta?\n";
				cout << "1) Sí\n";
				cout << "2) No\n";
				cout << "-----------------------------------------------------\n";
				cin >> opcionParte2a;
			} while (opcionParte2a != 1 && opcionParte2a != 2 && opcionParte2a != 3);

			if(opcionParte2a == 3) mostrarMenuPrincipal();

			if (opcionParte2a == 1) {
				tipo.push_back("Manga corta");
				RN = 1;
			} else tipo.push_back("Manga larga");

			//**************************************************************************
			//**************************************************************************

			do {
				system("cls");
				cotizarText();
				cout << "PASO 2.b: La camisa a cotizar, ¿Es Cuello Mao?\n";
				cout << "1) Sí\n";
				cout << "2) No\n";
				cout << "-----------------------------------------------------\n";
				cin >> opcionParte2b;
			} while (opcionParte2b != 1 && opcionParte2b != 2 && opcionParte2b != 3);

			if (opcionParte2b == 3) mostrarMenuPrincipal();

			if (opcionParte2b == 1) {
				tipo.push_back("Cuello Mao");
				RN = 2;
			}

			if (opcionParte2a == 1 && opcionParte2b == 1) {
				RN = 3;
			}
				
			

		}
		else {
			if (opcion == 2) {
				short opcionParte2;
				do {
					system("cls");
					cotizarText();
					cout << "PASO 2: El Pantalón a cotizar, ¿Es Chupín?\n";
					cout << "1) Sí\n";
					cout << "2) No\n";
					cout << "-----------------------------------------------------\n";
					cin >> opcionParte2;
				} while (opcionParte2 != 1 && opcionParte2 != 2 && opcionParte2 != 3);
				
				if (opcionParte2 == 1) {
					tipo.push_back("Chupín");
					RN = 4;
				}

			}
			else {
				mostrarMenuPrincipal();
			}
		}

		//**************************************************************************
		//**************************************************************************
		//**************************************************************************

		do {
			system("cls");
			cotizarText();
			cout << "PASO 3: Seleccione la calidad de la prenda\n";
			cout << "1) Standard\n";
			cout << "2) Premium\n";
			cout << "-----------------------------------------------------\n";
			cin >> opcionParte3;
		} while (opcionParte3 != 1 && opcionParte3 != 2 && opcionParte3 != 3);

		if (opcionParte3 == 1) {
			calidad = "Standard";
		}
		else {
			if (opcionParte3 == 2) {
				calidad = "Premium";
			}
		}

		if (opcionParte3 == 3) mostrarMenuPrincipal();

		//**************************************************************************
		//**************************************************************************

		do {
			system("cls");
			cotizarText();
			cout << "PASO 4: Ingrese el precio unitario de la prenda\n";
			cin >> precioUnitario;
		} while (precioUnitario < 0 && precioUnitario != 3);

		if (precioUnitario == 3) mostrarMenuPrincipal();

		//**************************************************************************
		//**************************************************************************

		if (tipo[0] == "Camisa") {
			if (tipo.size() > 2) {
				if (tipo[1] == "Manga corta" && tipo[2] == "Cuello Mao" && calidad == "Standard") {
					cantidadPrenda = presenter->getTienda()->getCantidadMangaCorta_CuelloMao_Standard();
				}
				else {
					if (tipo[1] == "Manga corta" && tipo[2] == "Cuello Mao" && calidad == "Premium") {
						cantidadPrenda = presenter->getTienda()->getCantidadMangaCorta_CuelloMao_Premium();
					}
					else {
						if (tipo[1] == "Manga larga" && tipo[2] == "Cuello Mao" && calidad == "Standard") {
							cantidadPrenda = presenter->getTienda()->getCantidadMangaLarga_CuelloMao_Standard();
						}
						else {
							if (tipo[1] == "Manga larga" && tipo[2] == "Cuello Mao" && calidad == "Premium") {
								cantidadPrenda = presenter->getTienda()->getCantidadMangaLarga_CuelloMao_Premium();
							}
						}
					}
				}
			}
			else {
				if (tipo[1] == "Manga corta" && calidad == "Standard") {
					cantidadPrenda = presenter->getTienda()->getCantidadMangaCorta_CuelloComún_Standard();
				}
				else {
					if (tipo[1] == "Manga corta" && calidad == "Premium") {
						cantidadPrenda = presenter->getTienda()->getCantidadMangaCorta_CuelloComún_Premium();
					}
					else {
						if (tipo[1] == "Manga larga" && calidad == "Standard") {
							cantidadPrenda = presenter->getTienda()->getCantidadMangaLarga_CuelloComún_Standard();
						}
						else {
							if (tipo[1] == "Manga larga" && calidad == "Premium") {
								cantidadPrenda = presenter->getTienda()->getCantidadMangaLarga_CuelloComún_Premium();
							}
						}
					}
				}
			}
		}
		else {
			if (tipo[0] == "Pantalón") {
				if (tipo.size() > 1) {
					if (tipo[1] == "Chupín" && calidad == "Standard") {
						cantidadPrenda = presenter->getTienda()->getCantidadPantalon_Chupín_Standard();
					}
					else {
						if (tipo[1] == "Chupín" && calidad == "Premium") {
							cantidadPrenda = presenter->getTienda()->getCantidadPantalon_Chupín_Premium();
						}
					}
				}
				else {
					if (calidad == "Standard") {
						cantidadPrenda = presenter->getTienda()->getCantidadPantalon_Común_Standard();
					}
					else {
						if (calidad == "Premium") {
							cantidadPrenda = presenter->getTienda()->getCantidadPantalon_Común_Premium();
						}
					}
				}
			}
		}

		/**********************************************************************************************/
		/**********************************************************************************************/

		do {
			system("cls");
			cotizarText();
			cout << "\nINFORMACIÓN:\n";
			cout << "EXISTE " << cantidadPrenda <<" CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA\n\n";
			cout << "PASO 5: Ingrese la cantidad de unidades a cotizar\n";
			cin >> unidades;

		} while (unidades <= 0 && unidades != 3 && cantidadPrenda - unidades < 0);

		if (unidades == 3) mostrarMenuPrincipal();

		//**************************************************************************
		//**************************************************************************

		if (cantidadPrenda - unidades < 0) {
			cout << "No hay unidades suficientes de la prenda seleccionada\n";
		}
		else {
			presenter->insertarPrenda(precioUnitario, calidad, unidades, RN, tipo);
		}
	}

	void mostrarTexto(vector<Cotizacion> cotizaciones) {
		for (int i = 0; i < cotizaciones.size(); i++) {
			cotizaciones[i].showCotizacion();
		}
	}
	
	void mostrarTexto(Cotizacion cotizacion) {
		cotizacion.showCotizacion();
	}

};