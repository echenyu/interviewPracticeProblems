#include <unordered_map>
#include <set>
#include "Player.h"

using namespace std;

class ScoreBoard {
public:
	ScoreBoard();
	void printRankings(); 
	int getRankOfPlayer(string name); 
	void updateRatingOfPlayer(string name, int score); 
	void insertPlayer(string name, int score); 

private:
	struct PersonCompare {
		bool operator() (Player *first, Player *second) {
			return first->score > second->score; 
		}
	};

	unordered_map<string, Player *> userRatings; 
	set<Player *, PersonCompare> playerRankings;  
};