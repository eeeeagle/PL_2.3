#pragma once
class Vehicle
{
public:
	virtual void Print() const = 0;
	virtual double GetTax(const double& baseRate) const = 0;
	virtual const char* GetType() const = 0;
	virtual const char* GetBrandName() const = 0;
	virtual const char* GetModelName() const = 0;
	void PrintVehicleInfo(const double& _baseRate);
};