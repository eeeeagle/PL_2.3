#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle
{
private:
	double _engineVolume;
	char _brandName[21], _modelName[21];
public:
	Motorcycle(double engineVolume, const char* brandName, const char* modelName);
	Motorcycle(const Motorcycle& motorcycle) = default;
	void Print() const override;
	const char* GetType() const override;
	const char* GetBrandName() const override;
	const char* GetModelName() const override;
	double GetTax(const double& baseRate) const override;
};