#include "easy_input.h"


double inputDouble(string output)
{
	string temp;
	temp = inputString(output);
	double result = atof(temp.c_str());
	return result;
}

int inputInt(string output)
{
	int result = (int)inputDouble(output);
	return result;
}

string inputString(string output)
{
	string result;
	cout << output;
	getline(cin >> ws, result);
	return result;
}