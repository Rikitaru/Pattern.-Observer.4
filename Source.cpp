#include <iostream>
#include <fstream>
#include <vector>
#include "House.h"

// �������� ��������� ������������� �������� �� ������
void initialization(string, House*);

// �������� �������� ��� ������ ������ ��������
int main(int argc, char* argv[]){
	setlocale(LC_ALL, "rus");

	BrHouseFactory* brHouse = new BrHouseFactory;
	BrMonHouseFactory* brMonHouse = new BrMonHouseFactory;
	CottageFactory* cottageHouse = new CottageFactory;
	PanelHouseFactory* panelHouse = new PanelHouseFactory;

	vector<House*> Houses;

	Houses.push_back(brHouse->createHouse());
	Houses.push_back(brMonHouse->createHouse());
	Houses.push_back(cottageHouse->createHouse());
	Houses.push_back(panelHouse->createHouse());

	ifstream FilesNames("inputFilesNames.txt");
	ofstream OutputFile("OutputFile.txt");
	string line;
	for (register int i = 0; i<(int)Houses.size(); i++){
		//Houses[i]->info();
		getline(FilesNames, line);
		initialization(line, Houses[i]);
		
		OutputFile << "�������� ����: " << Houses[i]->getDescription() << endl;
		OutputFile << "���������: " << Houses[i]->getFloors() << endl;
		OutputFile << "����: " << Houses[i]->getColor() << endl;
		OutputFile << "����� �������: " << Houses[i]->getNumberOfFlats() << endl;
		OutputFile << "����� ������� ����: " << Houses[i]->getTotalAreaHouse() << endl;
		OutputFile << "�����: " << Houses[i]->getAdress() << endl;
		OutputFile << "��� ���������� �������������: " << Houses[i]->getYearOfConstruction() << endl;
		OutputFile << endl;
	}
	OutputFile.close();
	FilesNames.close();
	system("pause");

	return 0;
}

// ���������� ��������� ������������� �������� �� ������
void initialization(string fileName, House* instance){
	ifstream house(fileName);
	string line;
	getline(house, line);
	instance->setDescription(line);
	getline(house, line);
	instance->setFloors(line);
	getline(house, line);
	instance->setColor(line);
	getline(house, line);
	instance->setNumberOfFlats(atoi(line.c_str()));
	getline(house, line);
	instance->setTotalAreaHouse(atoi(line.c_str()));
	getline(house, line);
	instance->setAdress(line);
	getline(house, line);
	instance->setYearOfConstruction(atoi(line.c_str()));
	house.close();
}