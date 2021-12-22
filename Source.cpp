#include <cstdio>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"

const char* randomWord[] = { "Standard", "Expertise", "Nationalism", "Implication", "Update", "Annual", "Cause", "Judicial", "Entertain", "Incapable", "Consultation", "Pass", "Sentiment", "First", "Crusade", "Leak", "Code", "Pierce", "Flesh", "Endure", "Court", "Holiday", "Embarrassment", "Integrity", "Grace", "Top", "Professor", "Professional", "Manner", "Offense", "Rack", "Insure", "Need", "Compensation", "Album", "Parachute", "Cheque", "Loyalty", "Projection", "Drama", "Scene", "Authority", "Carve", "Lost", "Ice", "Fiction", "Accent", "Cower", "Nun", "Deliver" };

int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

bool SetString(char* current, const char* valueName)
{
	char string[21] = {'\0'};
	unsigned i = 0;
	while (true)
	{
		system("cls");
		printf("\n   Enter %s:\n   %s\n   _____________________________________________________\n\n"
			"   [Enter]\tAccept\n   [Backspace]\tCorrection\n   [ESC]\tCancel\n", valueName, string);
		int temp = GetKey();
		switch (temp)
		{
		case 27:
			return false;
		case 13:
			strcpy_s(current, 21, string);
			return true;
		case 8:
			if (i > 0)
				string[--i] = ' ';
			break;
		default:
			if (i < 20)
				string[i++] = (char)temp;
			break;
		}
	}
}

bool SetDouble(double& current, const char* valueName)
{
	char string[21] = { '\0' };
	unsigned i = 0;
	bool flag1 = true, flag2 = true;
	while (true)
	{
		system("cls");
		printf("\n   Enter %s:\n   %s\n   _____________________________________________________\n\n"
			"   [Enter]\tAccept\n   [Backspace]\tCorrection\n   [ESC]\tCancel\n", valueName, string);
		int temp = GetKey();
		switch (temp)
		{
		case 27:
			return false;
		case 13:
			current = atof(string);
			return true;
		case 8:
			if (i > 0)
			{
				i--;
				if (string[i] == ',' || string[i] == '.')
					flag1 = true;
				else if (i == 0 && string[i] == '-')
					flag2 = true;
				string[i] = '\0';
			}
			break;
		default:
			if (i < 20)
			{
				if (isdigit(temp))
					string[i++] = (char)temp;
				else if (flag1 && (temp == ',' || temp == '.'))
				{
					string[i++] = (char)temp;
					flag1 = false;
				}
				else if(i == 0 && flag2 && temp == '-')
				{
					string[i++] = (char)temp;
					flag2 = false;
				}
			}
			break;
		}
	}
}

bool SetUnsigned(unsigned& current, const char* valueName)
{
	char string[21] = { '\0' };
	unsigned i = 0;
	while (true)
	{
		system("cls");
		printf("\n   Enter %s:\n   %s\n   _____________________________________________________\n\n"
			"   [Enter]\tAccept\n   [Backspace]\tCorrection\n   [ESC]\tCancel/Return back\n", valueName, string);
		int temp = GetKey();
		switch (temp)
		{
		case 27:
			return false;
		case 13:
			current = atoi(string);
			return true;
		case 8:
			if (i > 0)
				string[--i] = '\0';
			break;
		default:
			if (i < 20 && isdigit(temp))
				string[i++] = (char)temp;
			break;
		}
	}
}

bool VehicleTypeMenu(int& vehicleType)
{
	while (true)
	{
		system("cls");
		printf("\n   OBJECT CREATION MENU\n   ________________________________________\n\n");
		switch (vehicleType)
		{
		case 0: printf(" > Create car\n   Create truck\n   Create motorcycle\n"); break;
		case 1: printf("   Create car\n > Create truck\n   Create motorcycle\n"); break;
		case 2: printf("   Create car\n   Create truck\n > Create motorcycle\n"); break;
		case 3: printf("   Create car\n   Create truck\n   Create motorcycle\n"); break;
		}
		printf("   ________________________________________\n\n   [Up/Down]\t\tNavigation\n   [Enter]\t\tAccept\n   [ESC]\t\tCancel object creation\n");
		switch (GetKey())
		{
		case 72:
			if (vehicleType > 0) vehicleType--;
			else vehicleType = 2;
			break;
		case 80:
			if (vehicleType < 2) vehicleType++;
			else vehicleType = 0;
			break;
		case 13:
			return true;
		case 27:
			vehicleType = 3;
			return false;
		}
	}
}

Vehicle* CreateVehicleByUser()
{
	int vehicleType = 0;
	double engineVolume = 0.0, tonnage = 0.0;
	char brandName[21] = { '\0' }, modelName[21] = { '\0' };
	if (VehicleTypeMenu(vehicleType) && SetString(brandName, "brand name") && SetString(modelName, "model name") && SetDouble(engineVolume, "engine volume"))
	{
		switch (vehicleType)
		{
		case 0:
			return new Car(engineVolume, brandName, modelName);
		case 1:
			if (!SetDouble(tonnage, "truck tonnage")) break;
			return new Truck(engineVolume, brandName, modelName, tonnage);
		case 2:
			return new Motorcycle(engineVolume, brandName, modelName);
		}
	}
	return NULL;
}

Vehicle* CreateVehicleByRandom()
{
	srand((unsigned)time(NULL));
	unsigned vehicleType = rand() % 3;
	double engineVolume = 1.0 + (rand() % 900), tonnage = 5.0 + (rand() % 96);
	char brandName[21] = { '\0' }, modelName[21] = { '\0' };
	strncpy_s(brandName, randomWord[rand() % 50], 21);
	system("cls"); 
	printf("\n   ");
	for (int i = 0; i < 3; i++) 
	{ 
		printf("."); 
		Sleep(400); 
	}
	strncpy_s(modelName, randomWord[rand() % 50], 21);
	switch (vehicleType)
	{
	case 0:
		return new Car(engineVolume, brandName, modelName);
	case 1:
		return new Truck(engineVolume, brandName, modelName, tonnage);
	case 2:
		return new Motorcycle(engineVolume, brandName, modelName);
	default:
		return NULL;
	}
}

void AddObjectToCollection(Vehicle **&collection, unsigned& size, Vehicle * vehicle)
{
	if (vehicle)
	{
		Vehicle** newCollection = new Vehicle * [size + 1];
		for (unsigned i = 0; i < size; i++)
			newCollection[i] = collection[i];
		newCollection[size++] = vehicle;
		delete[] collection;
		collection = newCollection;
	}
}

void DeleteObject(Vehicle**& collection, unsigned& size, const unsigned& index)
{
	if (collection && index <= size && index > 0)
	{
		delete collection[index - 1];
		for (unsigned i = index - 1; i < size; i++)
			collection[i] = collection[i + 1];
		Vehicle** newCollection = NULL;
		if (--size)
		{
			newCollection = new Vehicle * [size];
			for (unsigned i = 0; i < size; i++)
				newCollection[i] = collection[i];
		}
		delete[] collection;
		collection = newCollection;
	}
}

void DeleteCollection(Vehicle**& collection, unsigned& size)
{
	if (collection && size)
	{
		for (unsigned i = 0; i < size; i++)
			delete[] collection[i];
		size = 0;
		delete[] collection;
		collection = NULL;
	}
}

void PrintObject(Vehicle**& collection, const unsigned& size, unsigned& current)
{
	while (collection)
	{
		system("cls");
		collection[current]->Print();
		printf("   ________________________________________\n\n"
			"   [Up/Down]\tPrevious/Next object\n   [ESC]\tReturn to the list of objects\n");
		switch (GetKey())
		{
		case 72:
			if (current > 0) current--;
			else current = size - 1;
			break;
		case 80:
			if (current < size - 1) current++;
			else current = 0;
			break;
		case 27:
			return;
		}
	}
}

void PrintCollection(Vehicle **& collection, const unsigned& size, const double& baseRate)
{
	unsigned current = 0;
	while (collection)
	{
		system("cls");
		printf("\n   VEHICLES INFORMATION\n   ________________________________________\n\n"
			"       ¹ TYPE       BRAND                MODEL                TAX\n\n");
		for (unsigned i = 0; i < size; i++)
		{
			if (current == i)
				printf(" > % 5d ", i + 1);
			else
				printf("   % 5d ", i + 1);
			collection[i]->PrintVehicleInfo(baseRate);
		}
		printf("   ________________________________________\n\n   Base rate: %2.lf\n   ________________________________________\n\n"
			"   [Up/Down]\tNavigation\n   [Enter]\tDetailed info for current object\n   [ESC]\tReturn to main menu\n", baseRate);
		switch (GetKey())
		{
		case 72:
			if (current > 0) current--;
			else current = size - 1;
			break;
		case 80:
			if (current < size - 1) current++;
			else current = 0;
			break;
		case 13:
			PrintObject(collection, size, current);
			break;
		case 27:
			return;
		}
	}
}

int MainMenu(unsigned& m)
{
	while (true)
	{
		system("cls");
		printf("\n   MAIN MENU\n   ________________________________________\n\n");
		switch (m)
		{
		case 0:
			printf(" > Create object and paste to the end of collection\n   Paste random object to the end of collection\n   Delete object by index\n"
				"   Delete all objects\n   Print all object on screen\n   Change base rate\n   Shut down the programm\n\n"); break;
		case 1:
			printf("   Create object and paste to the end of collection\n > Paste random object to the end of collection\n   Delete object by index\n"
				"   Delete all objects\n   Print all object on screen\n   Change base rate\n   Shut down the programm\n\n"); break;
		case 2:
			printf("   Create object and paste to the end of collection\n   Paste random object to the end of collection\n > Delete object by index\n"
				"   Delete all objects\n   Print all object on screen\n   Change base rate\n   Shut down the programm\n\n"); break;
		case 3:
			printf("   Create object and paste to the end of collection\n   Paste random object to the end of collection\n   Delete object by index\n"
				" > Delete all objects\n   Print all object on screen\n   Change base rate\n   Shut down the programm\n\n"); break;
		case 4:
			printf("   Create object and paste to the end of collection\n   Paste random object to the end of collection\n   Delete object by index\n"
				"   Delete all objects\n > Print all object on screen\n   Change base rate\n   Shut down the programm\n\n"); break;
		case 5:
			printf("   Create object and paste to the end of collection\n   Paste random object to the end of collection\n   Delete object by index\n"
				"   Delete all objects\n   Print all object on screen\n > Change base rate\n   Shut down the programm\n\n"); break;
		case 6:
			printf("   Create object and paste to the end of collection\n   Paste random object to the end of collection\n   Delete object by index\n"
				"   Delete all objects\n   Print all object on screen\n   Change base rate\n > Shut down the programm\n\n"); break;
		}
		printf("   ________________________________________\n\n   [Up/Down]\tNavigation\n   [Enter]\tAccept\n");
		switch (GetKey())
		{
		case 72:
			if (m > 0) m--;
			else m = 6;
			break;
		case 80:
			if (m < 6) m++;
			else m = 0;
			break;
		case 13:
			return m;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Vehicle** collection = NULL;
	unsigned m = 0, size = 0, index = 0;
	double baseRate = 500.0;
	while (true)
	{
		switch (MainMenu(m))
		{
		case 0:
			AddObjectToCollection(collection, size, CreateVehicleByUser());
			break;
		case 1:
			AddObjectToCollection(collection, size, CreateVehicleByRandom());
			break;
		case 2:
			if (SetUnsigned(index, "index"))
				DeleteObject(collection, size, index);
			break;
		case 3:
			DeleteCollection(collection, size);
			break;
		case 4:
			PrintCollection(collection, size, baseRate);
			break;
		case 5:
			SetDouble(baseRate, "new base rate");
			break;
		case 6:
			DeleteCollection(collection, size);
			system("cls");
			return 0;
		}
	}
}