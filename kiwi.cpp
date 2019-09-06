
#include <iostream>
#include <fstream>
#include "ArgumentManager.h"

class Kiwi {
private:
	int size;
	int ** field;
	int ripe;
	int rotten;
public:
	Kiwi(ifstream &farm);
	void increment(int row, int day);
	bool wasHarvested(int row);
	int getSize();
	int getRipe();
	int getRotten();
	void getField(ofstream &output);
	~Kiwi();
};


Kiwi::Kiwi(ifstream &farm) {
	ripe = 0;
	rotten = 0;
	
	//read size (first int in the file)
	farm >> size;

	//create array
	field = new int *[size];
	for (int j = 0; j < size; j++) {
		field[j] = new int[size];
	}

	//fill array by reading from file
	for (int j = 0; j < size; j++) {
		for (int k = 0; k < size; k++) {
			farm >> field[j][k];
		}
	}
}

//this represents the harvest on a certain day in the 7 day period
void Kiwi::increment(int row, int day) {
	//if harvesting kiwis, count ripe and rotten and reset values in row to 0
	if (wasHarvested(row)) {
		for (int i = 0; i < size; i++) {
			if (field[row][i] >= 6 && field[row][i] < 9)
				ripe++;
			else if (field[row][i] >= 9)
				rotten++;
			field[row][i] = 0;
		}
	}

	//otherwise increment by 1
	else {
		if (day != 7) { //don't increment by 1 at the end of day 7
			for (int i = 0; i < size; i++) {
				field[row][i] = field[row][i] + 1;
			}
		}
	}
}

//if the row is to be harvested
bool Kiwi::wasHarvested(int row) {
	int ready = 0;
	int half = size / 2;

	for (int i = 0; i < size; i++) {
		if (field[row][i] >= 6) {
			ready++;
		}
	}
	if (ready >= half)
		return true;
	else
		return false;
}

int Kiwi::getSize() {
	return size;
}

int Kiwi::getRipe() {
	return ripe;
}

int Kiwi::getRotten() {
	return rotten;
}

void Kiwi::getField(ofstream &output) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			output << field[i][j] << " ";
			if (j == size - 1)
				output << endl;
		}
	}
}

Kiwi::~Kiwi() {
	for (int i = 0; i < size; i++) {
		delete[] field[i];
	}
	delete[] field;
}

int main(int argc, char* argv[])
{
	ifstream farm;
	ofstream result;
	ArgumentManager am(argc, argv);
	string input = am.get("input");
	string output = am.get("output");

	farm.open(input);
	result.open(output);

	Kiwi kiwi_farm(farm);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < kiwi_farm.getSize(); j++) {
			kiwi_farm.increment(j, i);
		}
	}

	kiwi_farm.getField(result);
	result << "\nHarvested kiwis: " << kiwi_farm.getRipe() << endl;
	result << "Rotten kiwis: " << kiwi_farm.getRotten() << endl;

	farm.close();
	result.close();

	return 0;
}

