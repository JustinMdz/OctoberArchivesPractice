#include "CarInfo.h"

CarInfo::CarInfo(string carBrand, string carModel, string carColor, string carEngineState,
	string carTransmission, string carFuelType,
	int carPassengerCapacity, int carNumberOfDoors, int carYear, double carVin,
	double carPrice, double carMileAge)
{
	this->brand = carBrand;
	this->model = carModel;
	this->color = carColor;
	this->engineState = carEngineState;
	this->transmission = carTransmission;
	this->fuelType = carFuelType;
	this->passengerCapacity = carPassengerCapacity;
	this->numberOfDoors = carNumberOfDoors;
	this->year = carYear;
	this->vin = carVin;
	this->price = carPrice;
	this->mileAge = carMileAge;
}

void CarInfo::saveCar(FileManager* manager)
{
	int carAttributtes = 12;
	string fileName = "Cars.txt";
	string* carLine;
	carLine = new string[carAttributtes];

	carLine[0] = brand;
	carLine[1] = model;
	carLine[2] = color;
	carLine[3] = engineState;
	carLine[4] = transmission;
	carLine[5] = fuelType;

	carLine[6] = to_string(passengerCapacity);
	carLine[7] = to_string(numberOfDoors);
	carLine[8] = to_string(year);

	carLine[9] = to_string(vin);
	carLine[10] = to_string(price);
	carLine[11] = to_string(mileAge);

	manager->save(fileName, carLine, carAttributtes);
}

void CarInfo::print()
{
	cout << "Brand: " << brand << endl
		<< "Model: " << model << endl
		<< "Color: " << color << endl
		<< "Engine State: " << engineState << endl
		<< "Transmission: " << transmission << endl
		<< "FuelType: " << fuelType << endl
		<< "Passenger Capacity: " << passengerCapacity << endl
		<< "Car Doors: " << numberOfDoors << endl
		<< "Car Year: " << year << endl
		<< "VIN: " << vin << endl
		<< "Car Price: " << price << endl
		<< "Mile Age: " << mileAge << endl << endl;
}