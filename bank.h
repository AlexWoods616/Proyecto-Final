#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include "cliente.h"
#include "trabajador.h"
#include "sorteo.h"
#include "debe_haber.h"
#include <Windows.h>

using namespace std;

class banco {
		cliente cln;
		trabajador trb;
		suerte lala;
		maybe_deudor cuck;
		fstream main, aux;
		int dd,admin_chose;
		int din, cont,id_aux,id;
		string nombre, apellido, sentencia,sentencia2;
		string elec;
	public:
		void ask_cliente();
		void make_cliente();
		void busqueda_cliente();
		int movimientos_cliente(string a,string b,int c, int d);
		void delete_cliente();
		void ask_trabajador();
		void make_trabajador_dia();
		void make_trabajador_tarde();
		void make_trabajador_noche();
		void busqueda_trabajador();
		void delete_trabajador();
		void run_bank();
};

void banco::ask_cliente() {
	cout << "eres nuevo o registrado: [1/2] ";
	cin >> elec;
		if (elec == "1") {
			banco::make_cliente();
		}
		if (elec == "2") {
			banco::busqueda_cliente();
		}
}

void banco::make_cliente() {
	main.open("Porfavor_funca.txt", ios::in);
	aux.open("help.txt", ios::out);
	cln.pedir_datos(nombre, apellido);
	cout << "cuanto dinero deseas depositar? : ";
	cin >> din;
	cln.set_dinero(din);
	dd = 0;
	cout << cln.get_nombre() << " " << cln.get_apellido() << " " << cln.get_dinero() << endl;
	aux << cln.get_nombre() << " " << cln.get_apellido() << " " << cln.get_dinero() << dd;
	while (main >> nombre >> apellido >> din >> dd) {
		aux << endl << nombre << apellido << din  << dd;
	}
	main.close();
	aux.close();
	remove("Porfavor_funca.txt");
	if (rename("help.txt", "Porfavor_funca.txt") == 0)
		cout << "guardado";
	else
		cout << "hora de hacer la suicidacion Karen";
}

void banco::busqueda_cliente() {
	srand(time(NULL));
	int lucky = (rand() % 99) + 1;
	string acep;
	dd = 0;
	main.open("Porfavor_funca.txt", ios::in);
	aux.open("help.txt", ios::out);
	cout << "ingresa el nombre o apellido que quieres buscar: ";
	cin >> sentencia;
	while (main >> nombre >> apellido >> din >> dd) {
		cln.set_nombre(nombre); cln.set_apellido(apellido); cln.set_dinero(din);
		if (sentencia == nombre || sentencia == apellido) {
			cout << "nombre: " << nombre << endl << "apellido: " << apellido << endl <<"dinero: " << din << endl;
				cln.set_nombre(nombre); cln.set_apellido(apellido); cln.set_dinero(din);
				cln.set_dinero(banco::movimientos_cliente(cln.get_nombre(), cln.get_apellido(), cln.get_dinero(),dd));
				if (cln.get_dinero() < 0) {
					dd = cln.get_dinero() * -1;
					cln.set_dinero(0);
				}
				if (lucky < 11)
					lala.run(cln.get_dinero());
				cout << "nombre: " << cln.get_nombre() << endl << "apellido: " << cln.get_apellido() << endl << "dinero: " << cln.get_dinero() << endl;
		}
		aux << cln.get_nombre() << " " << cln.get_apellido() << " " << cln.get_dinero() << " " << dd << endl;
	}
	main.close();
	aux.close();
	remove("Porfavor_funca.txt");
	if (rename("help.txt", "Porfavor_funca.txt") == 0)
		cout << "guardado";
	else
		cout << "hora de hacer la suicidacion Karen";
}

int banco::movimientos_cliente(string a, string b, int c, int d) {
	srand(time(NULL));
	int vari = (rand() % 9) + 1;
	cout << "quiere hacer movimientos [y/n]: ";
	cin >> elec;
	if (elec == "y") {
		int mov;
		string el_mo;
		cout << "desea retirar o ingresar dinero?: [1/2] ";
		cin >> el_mo;
		if (el_mo == "1") {
			cout << "cuanto quiere retirar: ";
			cin >> mov;
			c -= mov;
			if (cuck.soplon(c, d))
				return 0;
			else
				return c;
		}
		if (el_mo == "2") {
			cout << "cuanto quiere ingresar: ";
			cin >> mov;
			c += mov;
			if (vari < 11)
				return cuck.multicast(c);
			else
				return c;
		}
	}
	if (elec == "n") {
		return c;
	}
}

void banco::delete_cliente() {
	main.open("Porfavor_funca.txt", ios::in);
	aux.open("help.txt", ios::out);
	cout << "Ingresa el nombre de la rata: ";
	cin >> sentencia;
	while (main >> nombre >> apellido >> din >> dd) {
		if (sentencia != nombre)
			aux << nombre << " " << apellido << " " << din << " " << dd <<endl;
	}
	main.close();
	aux.close();
	remove("Porfavor_funca.txt");
	if (rename("help.txt", "Porfavor_funca.txt") == 0)
		cout << "guardado";
	else
		cout << "hora de hacer la suicidacion Karen";
}

void banco::ask_trabajador() {
	cout << "eres nuevo o quieres buscar tu nombre [1/2] : ";
	cin >> elec;
	if (elec == "1") {
		int hora;
		cout << "que horarios quieres: \n 1.- dia. \n 2.- tarde. \n 3.- noche. \n";
		cin >> hora;
		if (hora == 1)
			banco::make_trabajador_dia();
		if (hora == 2)
			banco::make_trabajador_tarde();
		if (hora == 3)
			banco::make_trabajador_noche();
	}
	if (elec == "2")
		banco::busqueda_trabajador();
}

void banco::make_trabajador_dia() {
	main.open("trabajadores.txt", ios::in);
	aux.open("trabajador_aux.txt", ios::out);
	srand(time(NULL));
	trb.pedir_datos(nombre, apellido);
	id_aux = 1000000 + rand() % (10000000 - 1000000);
	while (main >> id >> nombre >> apellido) {
		if (id_aux == id) {
			id_aux = 1000000 + rand() % (10000000 - 1000000);
			main.seekg(0);
		}
		aux << id << " " << nombre << " " << apellido << endl;
	}
	cout << id_aux << endl;
	cout << id_aux << " " << trb.get_nombre() << " " << trb.get_apellido() << endl;
	aux << id_aux << " "<< trb.get_nombre() << " " << trb.get_apellido();
	main.close();
	aux.close();
	remove("trabajadores.txt");
	if (rename("trabajador_aux.txt", "trabajadores.txt") == 0)
		cout << "guardado";
	else
		cout << "hora de hacer la suicidacion Karen";
}

void banco::make_trabajador_tarde() {
	main.open("Trab_tarde.txt", ios::in);
	aux.open("Trab_tarde_aux.txt", ios::out);
	srand(time(NULL));
	trb.pedir_datos(nombre, apellido);
	id_aux = 2000000 + rand() % (20000000 - 2000000);;
	while (main >> id >> nombre >> apellido) {
		if (id_aux == id) {
			id_aux = 2000000 + rand() % (20000000 - 2000000);;
			main.seekg(0);
		}
		aux << id << " " << nombre << " " << apellido << endl;
	}
	cout << id_aux << endl;
	cout << id_aux << " " << trb.get_nombre() << " " << trb.get_apellido() << endl;
	aux << id_aux << " " << trb.get_nombre() << " " << trb.get_apellido();
	main.close();
	aux.close();
	remove("Trab_tarde.txt");
	if (rename("Trab_tarde_aux.txt", "Trab_tarde.txt") == 0)
		cout << "guardado";
	else
		cout << "hora de hacer la suicidacion Karen";
}

void banco::make_trabajador_noche() {
	main.open("Trab_noche.txt", ios::in);
	aux.open("Trab_noche_aux.txt", ios::out);
	srand(time(NULL));
	trb.pedir_datos(nombre, apellido);
	id_aux = 2000000 + rand() % (20000000 - 2000000);;
	while (main >> id >> nombre >> apellido) {
		if (id_aux == id) {
			id_aux = 3000000 + rand() % (30000000 - 3000000);;
			main.seekg(0);
		}
		aux << id << " " << nombre << " " << apellido << endl;
	}
	cout << id_aux << endl;
	cout << id_aux << " " << trb.get_nombre() << " " << trb.get_apellido() << endl;
	aux << id_aux << " " << trb.get_nombre() << " " << trb.get_apellido();
	main.close();
	aux.close();
	remove("Trab_noche.txt");
	if (rename("Trab_noche_aux.txt", "Trab_noche.txt") == 0)
		cout << "guardado";
	else
		cout << "hora de hacer la suicidacion Karen";
}

void banco::busqueda_trabajador() {
	cout << "ingresa tu id: ";
	cin >> id_aux;
	main.open("trabajadores.txt", ios::in);
	while (main >> id >> nombre >> apellido) {
		if (id_aux == id) {
			cout << "turno: dia" << endl << "id: " << id << "nombre: " << nombre << endl << "apellido: " << apellido;
		}
	}
	main.close();
	main.open("Trab_tarde.txt", ios::in);
	while (main >> id >> nombre >> apellido) {
		if (id_aux == id) {
			cout << "turno: tarde" << endl << "id: " << id << "nombre: " << nombre << endl << "apellido: " << apellido;
		}
	}
	main.close();
	main.open("Trab_noche.txt", ios::in);
	while (main >> id >> nombre >> apellido) {
		if (id_aux == id) {
			cout << "turno: noche" << endl << "id: " << id << "nombre: " << nombre << endl << "apellido: " << apellido;
		}
	}
	main.close();
}

void banco::delete_trabajador() {
	cout << "Ingrese el id del prro: ";
	cin >> id_aux;
	main.open("trabajadores.txt", ios::in);
	aux.open("trabajador_aux.txt", ios::out);
	while (main >> id >> nombre >> apellido) {
		if(id_aux!=id)
			aux << id << " " << nombre << " " << apellido <<endl;
	}
	main.close();
	aux.close();
	remove("trabajadores.txt");
	if (rename("trabajador_aux.txt", "trabajadores.txt") == 0)
		cout << "guardado ";
	else
		cout << "hora de hacer la suicidacion Karen";
	main.open("Trab_tarde.txt", ios::in);
	aux.open("Trab_tarde_aux.txt", ios::out);
	while (main >> id >> nombre >> apellido) {
		if (id_aux != id)
			aux << id << " " << nombre << " " << apellido << endl;
	}
	main.close();
	aux.close();
	remove("Trab_tarde.txt");
	if (rename("Trab_tarde_aux.txt", "Trab_tarde.txt") == 0)
		cout << "guardado ";
	else
		cout << "hora de hacer la suicidacion Karen";
	main.open("Trab_noche.txt", ios::in);
	aux.open("Trab_noche_aux.txt", ios::out);
	while (main >> id >> nombre >> apellido) {
		if (id_aux != id)
			aux << id << " " << nombre << " " << apellido << endl;
	}
	main.close();
	aux.close();
	remove("Trab_noche.txt");
	if (rename("Trab_noche_aux.txt", "Trab_noche.txt") == 0)
		cout << "guardado ";
	else
		cout << "hora de hacer la suicidacion Karen";
}

void banco::run_bank() {
	cout << "cliente o trabajador [1/2]";
	cin >> elec;
	//PlaySound(TEXT("System Of A Down - Toxicity.wav"), 0, SND_SYNC);
	if (elec == "1")
		banco::ask_cliente();
	if (elec == "2")
		banco::ask_trabajador();
	if (elec == "admin") {
		cout << "Cliente o Trabajador [1/2]: ";
		cin >> admin_chose;
		if (admin_chose == 1)
			banco::delete_cliente();
		else
			banco::delete_trabajador();
	}
}