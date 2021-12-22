#include "Truck.h"
#include <string>
#include <cstdio>

Truck::Truck(double engineVolume, const char* brandName, const char* modelName, double tonnage)
{
	strcpy_s(_brandName, 21, brandName);
	strcpy_s(_modelName, 21, modelName);
	_engineVolume = _tonnage = 0.0;
	if (engineVolume > 0.0 && tonnage > 0.0)
		_engineVolume = engineVolume, _tonnage = tonnage;
};

void Truck::Print() const
{
	printf("\n   TRUCK\n\n   Brand:\t\t%s\n   Model:\t\t%s\n   Engine volume:\t%.1lf\n"
		"   Tonnage:\t\t%.1lf\n", _brandName, _modelName, _engineVolume, _tonnage);
}

double Truck::GetTax(const double& baseRate) const
{
	return (baseRate * _engineVolume * ((_tonnage / 2.0) + 1));
}

const char* Truck::GetType() const
{
	return "Truck";
}

const char* Truck::GetBrandName() const
{
	return _brandName;
}

const char* Truck::GetModelName() const
{
	return _modelName;
}