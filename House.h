#include <string>
using namespace std;

// базовый класс "Дом"
class House{
private:
	string description;
	string floors;
	string color;
	int numberOfFlats;
	int totalAreaHouse;
	string adress;
	int yearOfConstruction;
public:
	virtual void info() = 0;
	virtual ~House() {}
	//методы типа seters
	void setDescription(string p1) { description = p1; }
	void setFloors(string p2) { floors = p2; }
	void setColor(string p3) { color = p3; }
	void setNumberOfFlats(int p4) { numberOfFlats = p4; }
	void setTotalAreaHouse(int p5) { totalAreaHouse = p5; }
	void setAdress(string p6) { adress = p6; }
	void setYearOfConstruction(int p7) { yearOfConstruction = p7; }
	//методы типа geters
	string getDescription() { return description; }
	string getFloors() { return floors; }
	string getColor() { return color; }
	int getNumberOfFlats() { return numberOfFlats; }
	int getTotalAreaHouse() { return totalAreaHouse; }
	string getAdress() { return adress; }
	int getYearOfConstruction() { return yearOfConstruction; }
};

// Фабрика объектов
class Factory{
public:
	virtual House* createHouse() = 0;
	virtual ~Factory() {};
};

#include "House.hpp"