#include "ScoreBoard.h"
#include <iostream>

using namespace std;

void addUser(ScoreBoard &scoreBoard);
void getUser(ScoreBoard &scoreBoard); 
void updateUser(ScoreBoard &scoreBoard); 

int main () {
	ScoreBoard scoreBoard; 
	while(1) {
		char option; 
		cout << "Pick an option: " << endl;
		cout << "1: Print scoreboard." << endl;
		cout << "2: Add player." << endl;
		cout << "3: Get player rank." << endl;
		cout << "4: Update player rank.\n" << endl;
		cout << "Please enter an option: ";

		cin >> option; 

		if(option == '1') {
			scoreBoard.printRankings(); 
		} else if(option == '2') {
			addUser(scoreBoard); 
		} else if(option == '3') {
			getUser(scoreBoard); 
		} else if(option == '4') {
			updateUser(scoreBoard); 
		} else {
			cout << "Input was not valid. Please pick an option." << endl;
			continue; 
		}

		char yOrN;
		cout << "Would you like to return to the main menu? (y/n) : ";
		cin >> yOrN;

		if(yOrN != 'y') {
			break;
		}
	}
}

void addUser(ScoreBoard &scoreBoard) {
	string name;
	int score; 
	
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter score: ";
	cin >> score; 
	scoreBoard.insertPlayer(name, score); 
}

void getUser(ScoreBoard &scoreBoard) {
	string name; 
	cout << "Enter name of user you want to know: ";
	cin >> name;
	cout << name << " is ranked: " << scoreBoard.getRankOfPlayer(name) << endl;
}

void updateUser(ScoreBoard &scoreBoard) {
	string name;
	int score;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter score: ";
	cin >> score; 
	scoreBoard.updateRatingOfPlayer(name, score); 
}