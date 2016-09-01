#include "ScoreBoard.h"
#include <iostream>

ScoreBoard::ScoreBoard() {}

void ScoreBoard::printRankings() {
	if(playerRankings.size() == 0) {
		cout << "There are no users in the leaderboard." << endl;
		return; 
	}

	int rank = 1; 
	for(auto i : playerRankings) {
		cout << "Rank: " << rank << ", Name: " << i->name << ", Score: " << i->score << endl;
		rank++; 
	}
} 

int ScoreBoard::getRankOfPlayer(string name) {
	if(userRatings.find(name) != userRatings.end()) {
		return std::distance(playerRankings.begin(), playerRankings.find(userRatings[name])) + 1; 
	}
	return -1; 
}

void ScoreBoard::updateRatingOfPlayer(string name, int score) {
	if(userRatings.find(name) != userRatings.end()) {
		Player *currentPlayer = userRatings[name]; 
		currentPlayer->score = score; 
		playerRankings.erase(currentPlayer); 
		playerRankings.insert(currentPlayer); 
	} else {
		cout << "Player not found. Creating new player..." << endl;
		insertPlayer(name, score); 
	}
	return; 
}

void ScoreBoard::insertPlayer(string name, int score) {
	if(userRatings.find(name) != userRatings.end()) {
		cout << "Player already exists. Updating player's score to the score entered." << endl;
		updateRatingOfPlayer(name, score); 
	} else {
		Player *newPlayer = new Player; 
		newPlayer->name = name; 
		newPlayer->score = score;
		userRatings[name] = newPlayer; 
		playerRankings.insert(newPlayer); 
	}
}

