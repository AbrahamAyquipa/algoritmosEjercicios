#pragma once
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

string months[12] = { "Enero", "Febrero","Marzo", "Abril","Mayo",
                     "Junio", "Julio", "Agosto","Setiembre","Octubre",
                     "Noviembre","Diciembre" };

class Fecha {
private:
    int day;
    int month;
    int year;
public:
    Fecha() {}
    Fecha(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    ~Fecha() {}

    void setDay(int v) { day = v; }
    void setMonth(int v) { month = v; }
    void setYear(int v) { year = v; }
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }


    string getDate() {
        string s;
        s.append(to_string(day));
        s.append("/");
        s.append(to_string(month));
        s.append("/");
        s.append(to_string(year));
        // dd/mm/yy
        return s;
    }
    void monthLetters() {
        // 7 de setiembre, 2020
        cout << day << " de " << months[month - 1] << "," << year << endl;
    }

    // anio bisiesto tiene que ser multiplo de 4
    // los anios que son multiplos de 100 no son bisiestos, salvo 
    // los que son multiplo de 100 y  al a vez multiplo de 400

    bool leapYear() {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            return true;
        else
            return false;
    }

    bool dateIsReal() {
        if (month >= 1 && month <= 12) {
            switch (month)
            {
            case 1: case 3: case 5: case 7: case 8: case 10:case 12:
                if (day >= 1 && day <= 31)
                    return true;
                else
                    return false;
                break;
            case 4:case 6: case 9: case 11:
                if (day >= 1 && day <= 30)
                    return true;
                else
                    return false;
                break;
            case 2:
                if (leapYear()) {
                    if (day >= 1 && day <= 29)
                        return true;
                    else
                        return false;
                }
                else {
                    if (day >= 1 && day <= 28)
                        return true;
                    else
                        return false;
                }
            }
        }
        else
            return false;
    }

};

