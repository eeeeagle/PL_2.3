#include "Car.h"
#include <string>
#include <cstdio>

Car::Car(double engineVolume, const char* brandName, const char* modelName) 
{
	strcpy_s(_brandName, 21, brandName);
	strcpy_s(_modelName, 21, modelName);
	_engineVolume = 0.0;
	if (engineVolume > 0.0)
		_engineVolume = engineVolume;
};

void Car::Print() const
{
	printf("\n   CAR\n\n   Brand:\t\t%s\n   Model:\t\t%s\n"
		"   Engine volume:\t%.1lf\n\n", _brandName, _modelName, _engineVolume);
}

double Car::GetTax(const double& baseRate) const
{
	return (baseRate * _engineVolume);
}

const char* Car::GetType() const
{
	return "Car";
}

const char* Car::GetBrandName() const
{
	return _brandName;
}

const char* Car::GetModelName() const
{
	return _modelName;
}