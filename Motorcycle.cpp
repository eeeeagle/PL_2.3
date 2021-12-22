#include "Motorcycle.h"
#include <string>
#include <cstdio>

Motorcycle::Motorcycle(double engineVolume, const char* brandName, const char* modelName) 
{
	strcpy_s(_brandName, 21, brandName);
	strcpy_s(_modelName, 21, modelName);
	_engineVolume = 0.0;
	if (engineVolume > 0.0)
		_engineVolume = engineVolume;
};

void Motorcycle::Print() const
{
	printf("\n   MOTORCYCLE\n\n   Brand:\t\t%s\n   Model:\t\t%s\n"
		"   Engine volume:\t%.1lf\n\n", _brandName, _modelName, _engineVolume);
}

double Motorcycle::GetTax(const double& baseRate) const
{
	return (0.3 * baseRate * _engineVolume);
}

const char* Motorcycle::GetType() const
{
	return "Motorcycle";
}

const char* Motorcycle::GetBrandName() const
{
	return _brandName;
}

const char* Motorcycle::GetModelName() const
{
	return _modelName;
}
