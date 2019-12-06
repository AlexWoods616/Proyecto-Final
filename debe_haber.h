#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class maybe_deudor {
public: 
	int mo;
	int multicast(int a);
	bool soplon(int b,int c);
};
int maybe_deudor::multicast(int a) {
	srand(time(NULL));
	mo = (rand() % 99) + 1;
	if (mo < 75) {
		a += (a / 10);
		return a;
	}
	else if (mo < 90) {
		a *= 2;
		return a;
	}
	else {
		a *= 3;
		return a;
	}
}
bool maybe_deudor::soplon(int a,int c) {
	if (c > 0 && a <  0) {
		cout << "Debes " << c << " dinero" << endl;
		return true;
	}
	return false;
}