#pragma once
#include <iostream>
#include <string>

using namespace std;
class Date {
private :
	int d, m, a;
public: 
	Date() {
		d = rand() % 31 + 1;
		m = rand() % 12 + 1;
		a = 1950 + rand() % 72;
	}

	~Date() {}

	int getD() { return d; }
	int getM() { return m; }
	int getA() { return a; }

	string getFechaCompleta() {
		//dd//mm//aa
		string aux;
		aux.append(to_string(d));
		aux.append("/");
		aux.append(to_string(m));
		aux.append("/");
		aux.append(to_string(a));
		return aux;
	}
};
