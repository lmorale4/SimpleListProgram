#include "player.h"

TennisPlayer::TennisPlayer(){
	firstName = "";
	lastName = "";
	rank = 0;
	points = 0;
	country = "";
}

TennisPlayer::TennisPlayer(string fName, string lName, int ranking, int totPoints, string initCountry){
	firstName = fName;
	lastName = lName;
	rank = ranking;
	points = totPoints;
	country = initCountry;
}

string TennisPlayer::getFirstName() const{
	return firstName;
}

		
string TennisPlayer::getLastName() const{
	return lastName;
}


int TennisPlayer::getRank() const{
	return rank;
}

	
int TennisPlayer::getPoints() const{
	return points;
}


string TennisPlayer::getCountry() const{
	return country;
}


void TennisPlayer::setRank(int ranking){
	rank = ranking;
}


void TennisPlayer::setPoints(int totPoints){
	points = totPoints;
}

ostream& operator<< (ostream & out, const TennisPlayer & t){
	out << t.lastName << ", " << t.firstName << endl << "Country: " << t.country << endl;
        out << "Ranking: " << t.rank << endl << "Total Points: " << t.points << endl ;
	return out;
}

