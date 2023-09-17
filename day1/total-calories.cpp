/**
 * Advent of Code Day 1.1
 * date solved: 17 sept 2023
 * 
 * finds the maximum total calories an elf has packed.
 * requires: file input
 */ 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
	const string input_filename = "input";
	ifstream file(input_filename);

	if (not file.is_open()) {
		cerr << "Couldn't open file. Try again.\n";
		return -1;
	}

	string line;
	int max_cal = 0, current_cal = 0, number_elves = 0;
	
	while (getline(file, line)) {
		// cout << "." << line << "\t" << current_cal  << "\t" << max_cal << endl;
		if (line.empty()) {
			// entry for new elf begins
			max_cal = current_cal > max_cal ? current_cal : max_cal;
			current_cal = 0;
			number_elves++;
			continue;
		}
		current_cal += stoi(line);
	}
	// takes the last entry into account
	max_cal = current_cal > max_cal ? current_cal : max_cal;

	cout << "Maximum calorie found: " << max_cal << endl;
	cout << "Total number of elves: " << number_elves << endl;

	return 0;
}
