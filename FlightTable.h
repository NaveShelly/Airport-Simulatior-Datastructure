#include "PassengerTree.h"
#include <fstream>
#include <math.h> 
class FlightTable
{

private:
PassengerTree** table;
int tableSize;

public:
FlightTable(int size)
{
	tableSize = size;
	table = new PassengerTree*[size / 3];
	for (int i = 0;i < size / 3;i++)
		table[i] = NULL;
}
void newFlightTable(int arr[])
{
	tableSize = tableSize;
	table = new PassengerTree*[tableSize / 3];
	for (int i = 0;i < tableSize / 3;i++)
		table[i] = NULL;
	for (int i = 0;i < tableSize;i++)
	{
		addPassenger(arr[i]);
	}
}
	//~FlightTable();
void addPassenger(int passId)
{
	if (table[passId % 3] == NULL)
	{
		table[passId % 3] = new PassengerTree();
	}
	*table[passId % 3]->insertNode(table[passId % 3]->treeRoot, passId);
	table[passId % 3]->numOfNodes = table[passId % 3]->numofnodes(table[passId % 3]->treeRoot) + 1;
}
void removePassenger(int passId);
void OUTPUT1(char *argv[])
{
	ofstream output(argv[3]);
	for (int i = 0;i < tableSize / 3;i++)
	{
		if (table[i] == NULL)
		{
			char tmp[] = " 0,0 ";
			output << tmp;
		}
		else
		{
			output << table[i]->numOfNodes;
			char tmp[] = ",";
			output << tmp;
			int x = table[i]->treeRoot->height;
			output << x;
		}
	}
}
void output2(char *argv[])
{
	ofstream output(argv[3], std::ios::app);
	output << endl;
	int avg = 0;
	for (int i = 0;i < tableSize / 3;i++)
	{
		if (table[i] != NULL)
			avg += table[i]->treeRoot->height + 1;
	}
	avg = avg / (tableSize / 3);
	output << avg << endl;
}
int* output3(char *argv[])
{
	ofstream output(argv[3], std::ios::app);
	int *arr = new int[tableSize];
	arr = MakePassengerList(argv);
	this->newFlightTable(arr);
	for (int i = 0;i < tableSize;i++)
	{
		int x = arr[i];
		output << x;
		if (i != tableSize - 1)
			output << ", ";
	}
	return arr;
}
void output4(char *argv[],int*arr)
{
	ofstream output(argv[3], std::ios::app);
	output << endl;
	minarray(arr, tableSize);
	output << statistich1(tableSize / 2, arr, 0) << ",";
	output << statistich1(3 * tableSize / 4, arr, 0) << ",";
	output << statistich1(tableSize - sqrt(tableSize), arr, 0) << ",";
	output << statistich1(sqrt(tableSize), arr, tableSize - sqrt(tableSize));
}
void output5(char *argv[],int*arr)
{
	ofstream output(argv[3], std::ios::app);
	output << endl;
	minarray(arr, tableSize);
	output << statistich2(tableSize / 2, arr, 0) << ",";
	output << statistich2(3 * tableSize / 4, arr, 0) << ",";
	output << statistich2(tableSize - sqrt(tableSize), arr, 0) << ",";
	output << statistich2(sqrt(tableSize), arr, tableSize - sqrt(tableSize));
}
int statistich1(int size, int *arr,int start)
{
	int *Seat = new int[tableSize];
	bool flag = false;
	int Que = 0, steps = 0, place, check = 0;
	for (int i = 0;i < tableSize;i++)
		Seat[i] = 0;
	int j = 0;
	while (Que < start)
	{
		if (Seat[h1(arr[Que]) + j] == 0)
		{
			Seat[h1(arr[Que]) + j] = arr[Que];
			Que++;
			j = 0;
		}
		else if (Seat[h1(arr[Que]) - j] == 0)
		{
			Que++;
			Seat[h1(arr[Que]) - j] = arr[Que];
			j = 0;
		}
		else
		{
			j++;
		}
	}
	while (Que != tableSize && check!=tableSize && size!=0)
	{
		place = h1(arr[Que])+check;
		if (place > tableSize-1)
		{
			place = tableSize-1;
				for (place;place >= 0;place--)
				{
					if (Seat[place] == 0)
					{
						Seat[place] = arr[Que];
						Que++;
						check = 0;
						flag = true;
						steps--;
						size--;
						break;
					}
					else
					{
						steps++;
					}
				}
		}
		else if(Seat[place] == 0)
		{
			Seat[place] = arr[Que];
			Que++;
			check = 0;
			size--;
			flag = true;
		}
		else if(flag == false)
		{
			place = h1(arr[Que]) - check;
			if (place <= 0)
			{
				place = 0;
				for (place;place < tableSize;place++)
				{
					if (Seat[place] == 0)
					{
						Seat[place] = arr[Que];
						Que++;
						check = 0;
						flag = true;
						size--;
						break;
					}
					else
					{
						steps++;
					}
				}
			}
			if (Seat[place] == 0)
			{
				Seat[place] = arr[Que];
				Que++;
				check = 0;
				size--;
				flag = true;
			}
		}
		if(flag==false)
		{
			check++;
			if (place != tableSize - 1 && place != 0)
			{
				steps++;
			}
		}
		flag = false;
	}
	return steps;
}
int statistich2(int size, int *arr,int start)
{
	int *Seat = new int[tableSize];
	bool flag = false;
	int Que = 0, steps = 0, place, check = 0;
	for (int i = 0;i < tableSize;i++)
		Seat[i] = 0;
	int j = 0;
	while (Que < start)
	{
		if (Seat[h2(arr[Que]) + j] == 0)
		{
			Seat[h2(arr[Que]) + j] = arr[Que];
			Que++;
			j = 0;
		}
		else if (Seat[h2(arr[Que]) - j] == 0)
		{
			Que++;
			Seat[h2(arr[Que]) - j] = arr[Que];
			j = 0;
		}
		else
		{
			j++;
		}
	}
	while (Que != tableSize && check != tableSize && size != 0)
	{
		place = h2(arr[Que]) + check;
		if (place > tableSize - 1)
		{
			place = tableSize - 1;
			for (place;place >= 0;place--)
			{
				if (Seat[place] == 0)
				{
					Seat[place] = arr[Que];
					Que++;
					check = 0;
					flag = true;
					steps--;
					size--;
					break;
				}
				else
				{
					steps++;
				}
			}
		}
		else if (Seat[place] == 0)
		{
			Seat[place] = arr[Que];
			Que++;
			check = 0;
			size--;
			flag = true;
		}
		else if (flag == false)
		{
			place = h2(arr[Que]) - check;
			if (place <= 0)
			{
				place = 0;
				for (place;place < tableSize;place++)
				{
					if (Seat[place] == 0)
					{
						Seat[place] = arr[Que];
						Que++;
						check = 0;
						flag = true;
						size--;
						break;
					}
					else
					{
						steps++;
					}
				}
			}
			if (Seat[place] == 0)
			{
				Seat[place] = arr[Que];
				Que++;
				check = 0;
				size--;
				flag = true;
			}
		}
		if (flag == false)
		{
			check++;
			if (place != tableSize - 1 && place != 0)
			{
				steps++;
			}
		}
		flag = false;
	}
	return steps;
}
int* minarray(int *arr, int counter)
{
	int flag = 0;
	int *arr1 = new int[counter];
	arr1[0] = arr[0];
	int min = arr[0];
	int w = 0;
	for (int i = 0;i < counter;i++)
	{
		min = arr[w];
		for (int j = 0;j < counter;j++)
		{
			if (min > arr[j] && arr[j] > arr1[i - 1])
			{
				min = arr[j];
				flag = 1;
			}
		}
		if (flag == 0 && arr1[i - 1] == min)
		{
			w++;
			i--;
		}
		flag = 0;
		arr1[i] = min;
	}
	return arr1;
}
int h1(int num)
{
	return num%tableSize;
}
int h2(int num)
{
	int tmp = num;
	int idlen = 100000000;
	int reversenum = 0;
	while (num != 0)
	{
		reversenum += (num % 10)*idlen;
		num = num / 10;
		idlen = idlen / 10;
	}
	reversenum = reversenum%tableSize;
	num = tmp;
	return reversenum;
}
int* MakePassengerList(char *argv[])
{
	int counter1 = 0;
	ifstream input(argv[2]);
	int *tmp = new int[tableSize];
	char *word = new char[10];
	while (!input.eof())
	{
		input >> word;
		if (atoi(word) != 0)
		{
			tmp[counter1] = atoi(word);
			counter1++;
		}
	}
	int *arr = new int[tableSize];
	ifstream input1(argv[1]);
	int counter = 0;
	while (!input1.eof())
	{
		input1 >> word;
		if (atoi(word) != 0)
		{
			arr[counter] = atoi(word);
			counter++;
		}
	}
	int flag = 0;
	for (int i = 0;i < tableSize;i++)
	{
		if (arr[i] != tmp[i])
			flag = 1;
	}
	if (flag == 0)
	{
		arr = minarray(arr, tableSize);
		return arr;
	}
	else
	{
		int *newlist = new int[tableSize];
		int v = 0;
		for (int i = 0;i < tableSize;i++)
		{
			for (int j = 0;j < counter1;j++)
			{
				if (arr[i] == tmp[j])
				{
					newlist[v] = tmp[i];
					v++;
				}
			}
		}
		int check;
		flag = 0;
		for (int i = 0;i < counter1 && v <= tableSize;i++)
		{
			check = tmp[i];
			for (int j = 0;j < tableSize;j++)
			{
				if (check == newlist[j])
					flag = 1;
			}
			if (flag == 0)
			{
				newlist[v] = check;
				v++;
			}
			flag = 0;
		}
		return newlist;
	}
}
void displayTable()
{
	for (int i = 0;i < tableSize / 3;i++)
	{
		if (table[i] == NULL)
		{
			cout << " 0,0 ";
		}
		else {
			cout << table[i]->numOfNodes << ", ";
			cout << table[i]->treeRoot->height + 1;
		}
	}
}
};
