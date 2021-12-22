#include "Vehicle.h"
#include <string>
#include <cstdio>

void Vehicle::PrintVehicleInfo(const double& baseRate)
{
	printf("%-10s %-20s %-20s %.1lf\n", this->GetType(), this->GetBrandName(), this->GetModelName(), this->GetTax(baseRate));
}