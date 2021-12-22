#pragma once
#include "Vehicle.h"

class Truck : public Vehicle
{
private:
	char _brandName[21], _modelName[21];
	double _tonnage, _engineVolume;
public:
	Truck(double engineVolume, const char* brandName, const char* modelName, double tonnage);
	Truck(const Truck& truck) = default;
	void Print() const override;
	const char* GetType() const override;
	const char* GetBrandName() const override;
	const char* GetModelName() const override;
	double GetTax(const double& baseRate) const override;
};