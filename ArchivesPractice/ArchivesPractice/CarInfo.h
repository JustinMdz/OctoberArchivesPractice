#pragma once
#include "FileManager.h"
class CarInfo
{
private:

	string brand;
	string model;
	string color;
	string engineState;
	string transmission;
	string fuelType;

	int passengerCapacity;
	int numberOfDoors;
	int year;

	double vin;
	double price;
	double mileAge;

public:
	CarInfo(string,string, string, string, string, string, int,int,int,double,double,double);
	void saveCar(FileManager*);
	void loadCard();
	void print();
};