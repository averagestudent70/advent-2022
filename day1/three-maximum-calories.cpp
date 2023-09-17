/**
 * Advent of Code Day 1.1
 * date solved: 17 sept 2023
 * 
 * Finds the 3 maximum total calories an elf has packed.
 * requires: file input
 */ 

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * From input, extracts and calculates total calories for each elf and
 * stores it in the calorie_dist vector.
 */ 

void calculate_total_calories(istream &input, vector<int> &calorie_dist) {
	string line;
	int total_cal = 0;
	
	while (getline(input, line)) {
		if (line.empty()) {
			// entry for new elf begins
			calorie_dist.push_back(total_cal);
			total_cal = 0;
			continue;
		}
		total_cal += stoi(line);
	}
	// takes the last elf into account
	calorie_dist.push_back(total_cal);
}

int main() 
{
	const string input_filename = "input";
	ifstream file(input_filename);

	if (not file.is_open()) {
		cerr << "Couldn't open file. Try again.\n";
		return -1;
	}

	vector<int> calorie_dist;
	calculate_total_calories(file, calorie_dist);
	sort(calorie_dist.begin(), calorie_dist.end(), greater<int>());

	cout << "Three maximum calories: " << calorie_dist[0] << ", " << calorie_dist[1]
		 << " and " << calorie_dist[2] << ".\n"
		 << "Sum: " << calorie_dist[0] + calorie_dist[1] + calorie_dist[2] << endl;

	return 0;
}
