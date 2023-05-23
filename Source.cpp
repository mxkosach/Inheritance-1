#include "Transorter.h"
#include <conio.h>
#pragma once
int calcDist();
int cin_variant(int max);
string city[6] = { "Brest","Vitebsk","Gomel","Grodno","Minsk","Mogilev" };
int dist[6][6] = {
0,	633,	649,	235,	351, 522,
633,	0,	329,	567,	291, 167,
649,	329,	0,	597,	312, 177,
649,	567,	597,	0,	276, 473,
351,	291,	312,	276,	0, 204,
522,	167,	177,	473,	204, 0
};

int main()
{


	Plane boing;
	Train stadler;
	Car truck;
	while (true)
	{
		int dist = calcDist();
		cout << left << setw(10) << "By:" << setw(11) << "Tarif($)" << setw(14) << "Speed(km/h)" << setw(11) << "Price($)" << setw(10) << "Time(h)" << endl;
		boing.show(dist);
		truck.show(dist);
		stadler.show(dist);

		cout << "------------------------------------------------------\n";
		cout << "To make another calculation press R\n";
		cout << "To exit press any key\n";
		char key = _getch();
		if (key == 'r') {
			system("cls");
			continue;
		}
		else
			break;
	}
	//system("pause");
	return 0;
}

int calcDist() {
	cout << "Select the departure city:\n";
	for (int i = 0; i < 6; i++)
		cout << i + 1 << '.' << city[i] << endl;
	int a = cin_variant(6), b = 0;
	cout << "----------------------------\n";
	cout << "Select the arrival city:\n";
	for (int i = 0; i < 6; i++)
		cout << i + 1 << '.' << city[i] << endl;
	while (true)
	{
		b = cin_variant(6);
		if (b == a)
			cout << "Ops... The city of departure and arrival are the same.\nSelect another city of arrival:\n";
		else
			break;
	}

	int km = dist[a - 1][b - 1];
	system("cls");
	cout << city[a - 1] << " -> " << city[b - 1] << endl << "Distance: " << km << " km\n";
	cout << "------------------------------------------------------\n";
	return km;
}

int cin_variant(int max) {
	char s;
	int v;
	while (true)
	{
		cout << ">>";
		cin >> s;
		v = atoi(&s);
		if (v <= max && v > 0)
			break;
		else
			cout << "Incorrect number!\n";
	}
	return v;
}