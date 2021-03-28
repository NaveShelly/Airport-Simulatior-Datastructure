#include "FlightTable.h"
#include <fstream>
void main(int argc, char *argv[])
{
	int size = 0;
	ifstream input(argv[1]);
	char *word=new char[10];
	while (!input.eof())
	{
		input >> word;
		size++;
	}
	size--;
	input.clear();
	input.seekg(0, ios::beg);
	FlightTable hash(size);
	for (int i = 0;i < size;i++)
	{
		input >> word;
		hash.addPassenger(atoi(word));
	}
	hash.OUTPUT1(argv);
	hash.output2(argv);
	int* arr = new int[size];
	arr=hash.output3(argv);
	hash.output4(argv,arr);
	hash.output5(argv, arr);
	return;
}