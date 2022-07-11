#include<iostream>
#include<iomanip> // imported this iomanip library to use format manipulators
#include<fstream> // imported this to read a file

using namespace std;

struct Bowler {
	string name;
	int scores[5];
	int averageScore;
};

// Declaring the constants
int const PLAYERS = 10;

bool GetBowlingData(Bowler bowler_arr[], int& count) { // This function calls the struct Bowler

	ifstream in("BowlingScores.txt"); // File to be read from

	if (!in.fail()) { // if file reading does not fail then return the records in the file

		while (!in.eof()) {

			in >> bowler_arr[count].name >> bowler_arr[count].scores[0] >> bowler_arr[count].scores[1] >> bowler_arr[count].scores[2] >> bowler_arr[count].scores[3] >> bowler_arr[count].scores[4];

			count++;

		}

		return true;

	}

	return false; // returns false if the file reading is a failure

}

void GetAverageScore(Bowler bowler_arr[], double avgScores[], int count) { // created this function to get average scores which calls the struct Bowler

	// created this for loop to read scores of every bowler
	for (int i = 0; i < count; i++) { 

		avgScores[i] = 0;

		for (int j = 0; j < 5; j++) {

			avgScores[i] += bowler_arr[i].scores[j];

		}

		bowler_arr[i].averageScore =  avgScores[i] / 5.0;

	}

}

// Function created to print the results. This function itself does not return anything unless called in main function
void PrettyPrintResults(Bowler bowler_arr[],  int count) {

	cout << left << setw(15) << "Name" << "Score1\tScore2\tScore3\tScore4\tScore5\tAvgScore" << endl; //Displaying header in column format

	// This loop is to print all names and scores
	//For a single iteration of bowlerNames, bowlerScores are iterated 4 times
	for (int i = 0; i < count; i++) {

		cout << left << setw(15) << bowler_arr[i].name << "\t";

		for (int j = 0; j < 5; j++) // one bowler has 4 different scores 

			cout << bowler_arr[i].scores[j] << "\t";

		cout << bowler_arr[i].averageScore << endl;

	}

}
// Main function where all the other functions are called
int main() {

	cout << setfill('*');  //setfill() fills character based on the specified character
	cout << setw(60) << "*" << endl; //setw() helps set the field width used for output operations
	cout << setfill('*');
	cout << setw(11) << "*" << " Program to calculate bowling scores " << setw(12) << "*" << endl;
	cout << setfill('*');
	cout << setw(60) << "*" << endl;
	cout << endl;

	cout << setfill(' '); // Reseting the specified character

	//declaring the array variables 

	double avg_Scores[PLAYERS];

	Bowler bowler_arr[100];

	int count= 0;

	//Calling all the functions created above
	if (GetBowlingData(bowler_arr,  count)) {

		GetAverageScore(bowler_arr, avg_Scores, count);

		PrettyPrintResults(bowler_arr, count);

	}

	return 0;

}