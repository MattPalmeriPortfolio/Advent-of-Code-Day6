#include <fstream>
#include <iostream>
//main
int main()
{
	using namespace std;
	//initialize variables
	unsigned long long int fishSchool[9]{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	char nextInput;
	unsigned long long int numFish = 0, temp;
	int day;
	//open stream
	ifstream inStream("input6.txt");
	if (inStream.fail())
		exit(1);
	//get input
	while (!(inStream.eof()))
	{
		inStream.get(nextInput);
		switch (static_cast<int>(nextInput) - 48)
		{
		case 0:
			fishSchool[0] += 1;
			break;
		case 1:
			fishSchool[1] += 1;
			break;
		case 2:
			fishSchool[2] += 1;
			break;
		case 3:
			fishSchool[3] += 1;
			break;
		case 4:
			fishSchool[4] += 1;
			break;
		case 5:
			fishSchool[5] += 1;
			break;
		case 6:
			fishSchool[6] += 1;
			break;
		default:
			break;
		}
		inStream.get(nextInput);
	}
	inStream.close();

	for (day = 1; day < 81; day++)
	{
		temp = fishSchool[0];
		for (int i = 1; i < 9; i++)
			fishSchool[i - 1] = fishSchool[i];
		fishSchool[6] += temp;
		fishSchool[8] = temp;
	}
	for (int i = 0; i < 9; i++)
	{
		numFish += fishSchool[i];
	}
	cout << "Day 80: " << numFish << endl;
	for (day; day < 257; day++)
	{
		temp = fishSchool[0];
		for (int i = 1; i < 9; i++)
			fishSchool[i - 1] = fishSchool[i];
		fishSchool[6] += temp;
		fishSchool[8] = temp;
	}
	numFish = 0;
	for (int i = 0; i < 9; i++)
	{
		numFish += fishSchool[i];
	}
	cout << "Day 256: " << numFish << endl;
	return 0;
}