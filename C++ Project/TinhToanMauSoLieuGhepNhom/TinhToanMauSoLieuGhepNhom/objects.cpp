#pragma once
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
#include <math.h>
#include <stdexcept>

const int MAX_COL = 1000;

inline void textDisplay(std::string text) {
	for (int i = 0; i < text.size(); i++) {
		std::cout << text[i] << std::flush;
		Sleep(25);
	}
	Sleep(50);
}

class DataSample {
private:
	int numOfGroup;
	struct DataChart {
		int freq = 0;
		double representativeVal = 0, x = 0, y = 0;
		std::string rangeOfValue = "";
	};
	std::vector<DataChart> Chart;

	std::string formatRange(double x, double y) {
		std::stringstream process;
		process << std::fixed << std::setprecision(3) << "[" << x << "; " << y << ")";
		return process.str();
	}

	void WriteData(int index) {
		try {
			std::cout << "Current data group's format: [x;y) where x < y" << "\n";
			std::cout << "X's value: ";
			std::cin >> Chart[index].x;
			std::cout << "\nY's value: ";
			std::cin >> Chart[index].y;
			if (Chart[index].x >= Chart[index].y) {
				throw std::invalid_argument("X must be less than Y!");
			}
			std::cout << "\nFrequency: ";
			std::cin >> Chart[index].freq;
			if (Chart[index].freq < 0) {
				throw std::invalid_argument("False input!");
			}
			system("cls");
			Chart[index].representativeVal = (Chart[index].x + Chart[index].y) / 2;
			Chart[index].rangeOfValue = formatRange(Chart[index].x, Chart[index].y);
			textDisplay("Complete! Current data group's information: \n");
			std::cout << "Range of value: " << Chart[index].rangeOfValue << "\n";
			std::cout << "Frequency: " << Chart[index].freq << "\n";
			std::cout << "Representative value: " << std::fixed << std::setprecision(3) << Chart[index].representativeVal << "\n";
		}
		catch (const std::ios_base::failure& e) {
			std::cout << "Input error: Please enter numbers only\n";
			std::cin.clear();
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << "\n";
		}
	}

	void Build(int inputNumOfGroup) {
		try {
			if (inputNumOfGroup <= 0) {
				throw std::invalid_argument("Invalid arg");
			}
			if (inputNumOfGroup > MAX_COL) {
				throw std::overflow_error("The data is over the limit");
			}
			Chart.resize(inputNumOfGroup + 1);
			for (int i = 1; i <= inputNumOfGroup; i++) {
				WriteData(i);
			}
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << "\n";
		}
	}
public:
	DataSample(int inputNumOfGroup) {
		numOfGroup = inputNumOfGroup;
		Build(numOfGroup);
	}

	~DataSample() {
		numOfGroup = 0;
		Chart.resize(1);
	}

	double variationRangeCalc() {

	}

	double quartileCalc() {

	}

	double quartileRangeCalc() {

	}

	double medianValCalc() {
		try {
			if (numOfGroup <= 0) {
				throw std::invalid_argument("You have not insert the number of groups yet!");
			}
			double result = 0;
			for (int index = 1; index <= numOfGroup; index++) {
				result += (Chart[index].representativeVal * Chart[index].freq);
			}
			result /= double(numOfGroup);
			return result;
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << "\n";
		}
	}

	double varianceCalc() {
	
	}

	double standardDeviationCalc() {
	
	}

	void chartPrint() {
		try {
			if (numOfGroup <= 0) {
				throw std::invalid_argument("Invalid arg! Please try again.");
			}
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << "\n";
		}
	}
};