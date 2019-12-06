#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class suerte {
	int num1,num2,cuanto;
public:
	void ganaste_dinero(int a);
	void ganaste_entradas();
	void ganaste_cachorros();
	void suerte_suerte();
	void gg_bro();
	void run(int b);
};

void suerte::run(int b) {
	srand(time(NULL));
	num1 = (rand() % 99) + 1;
	if (num1 < 6)
		ganaste_dinero(b);
	else if (num1 < 11)
		ganaste_entradas();
	else if (num1 < 21)
		ganaste_cachorros();
	else if (num1 < 51)
		suerte_suerte();
	else
		gg_bro();
}

void suerte::ganaste_dinero(int a) {
	srand(time(NULL));
	cuanto = (rand() % 999) + 1;
	a += cuanto;
}

void suerte::ganaste_entradas() {
	srand(time(NULL));
	num2 = (rand() % 2) + 1;
	if (num2 == 1)
		cout << "Ganaste 2 entradas al cine" << endl;
	else if (num2 == 2)
		cout << "Ganaste 3 boletos para Fisa" << endl;
	else
		cout << "Ganaste 1 entrada a la comicon" << endl;
}

void suerte::ganaste_cachorros() {
	srand(time(NULL));
	num2 = (rand() % 2) + 1;
	if (num2 == 1)
		cout << "Ganaste un husky" << endl;
	else if (num2 == 2)
		cout << "Ganaste un chiwawa" << endl;
	else
		cout << "Ganaste un pug" << endl;
}

void suerte::suerte_suerte() {
	srand(time(NULL));
	num2 = (rand() % 5) + 1;
	if (num2 == 1)
		cout << "Ganaste una TV" << endl;
	else if (num2 == 2)
		cout << "Ganaste una cafetera" << endl;
	else if (num2 == 3)
		cout << "Ganaste una licuadora" << endl;
	else if (num2 == 4)
		cout << "Ganaste una lavadora" << endl;
	else if (num2 == 5)
		cout << "Ganaste un polo de la seleccion" << endl;
	else
		cout << "Ganaste una tostadora" << endl;
}

void suerte::gg_bro() {
	cout << "(~^-^)~ Sorry bro ~(^-^~)";
}
