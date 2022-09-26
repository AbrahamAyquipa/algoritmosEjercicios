#include "pch.h"
#include <ctime>
#include <conio.h>
#include "ArrPlanV.h"

int main() {
	srand(time(NULL));
	ArrPlanV* arr = new ArrPlanV();
	arr->agregarPlanV();
	arr->agregarPlanV();
	arr->agregarPlanV();
	arr->agregarPlanV();
	arr->agregarPlanV();
	arr->agregarPlanV();
	arr->agregarPlanV();
	arr->agregarPlanV();
	arr->agregarPlanV();
	arr->agregarPlanV();
	
	cout << "\nReporte Vacaciones en rango de fechas";
	cout << "\n----------------------------------------\n";
	arr->reporte1(1990, 2021);
	getch(); system("cls");

	cout << "\nReporte Vacaciones Hotel Westin";
	cout << "\n---------------------------------\n";
	arr->reporte2("Westin");
	getch(); system("cls");

	cout << "\nReporte Plan de Vacaciones";
	cout << "\n---------------------------\n";
	arr->reporte3();
	getch(); system("cls");

	arr->reporte31();
	cin.get();
	cin.ignore();
	return 0;
}
