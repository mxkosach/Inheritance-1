#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Transporter
{
	double tarif;
	int speed;
public:
	Transporter() {
		tarif = 0;
		speed = 0;
	};

	Transporter(double tarif, int speed) {
		this->tarif = tarif;
		this->speed = speed;
	};

	void setTarif(double tarif) {
		this->tarif = tarif;
	};

	void setSpeed(int speed) {
		this->speed = speed;
	};

	double getTarif() {
		return tarif;
	};

	int getSpeed() {
		return speed;
	};

	virtual void show(int dist) = 0;

	int calcPrice(int dist) {
		return dist * tarif;
	};
	double calcTime(int dist) {
		return (dist * 1.0) / speed;
	};
};


class Plane :public Transporter
{
public:
	Plane() : Transporter() {
		setTarif(1);
		setSpeed(700);
	};
	void show(int dist) override {
		cout << left << setw(10) << "plane" << setw(11) << getTarif() << setw(14) << getSpeed() << setw(11) << calcPrice(dist) << setw(10) <<fixed<<setprecision(1)<< calcTime(dist) << endl;
	}

};

class Train :public Transporter
{
public:
	Train() : Transporter() {
		setTarif(0.1);
		setSpeed(60);
	};

	void show(int dist) override {
		cout << left << setw(10) << "train" << setw(11) << getTarif() << setw(14) << getSpeed() << setw(11) << calcPrice(dist) << setw(10) << calcTime(dist) << endl;
	}
};

class Car :public Transporter
{
public:
	Car() : Transporter() {
		setTarif(0.2);
		setSpeed(90);
	};

	void show(int dist) override {
		cout << left << setw(10) << "car" << setw(11) << getTarif() << setw(14) << getSpeed() << setw(11) << calcPrice(dist) << setw(10) << calcTime(dist) << endl;
	}
};