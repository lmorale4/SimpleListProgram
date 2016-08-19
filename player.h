#include <iostream>
using namespace std;

class TennisPlayer{
	public:
		TennisPlayer();
		// assign arbitrary values to the data members
		
		TennisPlayer(string fName, string lName, int ranking, int totPoints, string initCounry);
		//1 for each data member

		string getFirstName() const;
		// reurn the first name
		
		string getLastName() const;
		// reurn the last name

		int getRank() const;
		// reurn the ranking
	
		int getPoints() const;
		// reurn the total points

		string getCountry() const;
		// reurn the country

		void setRank(int ranking);
		// sets the rank to ranking

		void setPoints(int totPoints);
		// sets the points to totPoints

		friend ostream& operator<<(ostream & out,const TennisPlayer & t);
		// sends the value of t to out

	private:
		string firstName;
		string lastName;
		int rank;
		int points;
		string country;

};

