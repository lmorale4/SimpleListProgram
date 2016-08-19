/*
Linda Morales
Assignment #2
Section C57
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "SimpleList.h"
using namespace std;

/* Program makes a SimpleList of TennisPlayer and uses it
   to retrive information.
*/
void processFile(SimpleList& sList);
// input: a SimpleList pointer
// output: none
// side effects: opens file, processes data, and puts it in a SimpleList

TennisPlayer createTennisPlayer(string line, int lineNum);
// input: the line(string) from the file and the number of the line (int)
// output: a TennisPlayer
// side effects: reads through file to get information to 
//  create a TennisPlayer object

bool checkRank();
// input: none
// output: a bool
// side effects: checks if user rank is within range 1-20

TennisPlayer getPlayerByRank(SimpleList sList, int rank);
// input: a SimpleList and an int
// output: a TennisPlayer object
// side effects: gets the player of a given rank from a list

int getRankFromLName(SimpleList sList, string lName);
// input: a SimpleList and a string
// output: an int
// side effects: gets the rank of a player given a last name

int askForRank();
// input: none
// output: an int
// side effects: asks user for a rank and returns it

string askForLastName();
// input: none
// output: a string
// side effects: asks user for the last name of a player

void question1(SimpleList sList);
// input: a SimpleList object
// output: none
// side effects: asks user for a rank and displays 
//  player with that rank

void question2(SimpleList sList);
// input: a SimpleList 
// output: none
// side effects: asks user for the last name of the
//  player they want to search

void question3(SimpleList sList);
// input: a SimpleList
// output: none
// side effects:asks user for two ranks and displayes 
//  the difference between the player's points

string charToStr(char c);
// input: a char
// output: a string
// side effects: converts a char into a string

int stringToInt(string str);
// input: a string
// output: an int
// side effects: converts a string to an int

int main(){
  SimpleList sList;
	processFile(sList);
  
  int q;
  cout << "What would you like to do?"<<endl;
  cout << "1. Look up player by rank?" << endl;
  cout << "2. Look up player ranking by last name?" << endl; 
  cout << "3. Find the difference in points by ranks?"<<endl;
  cout << "Choose the number of the question you wish ";
  cout << "to have answered to continue. (1-3) " << endl;
  cin >> q;
  while(q){
    while(q < 1 && q > 3){
      cout << "Please choose a number between 1 and 3 "<< endl;
      cin >> q;
    }
    if(q == 1){
       question1(sList);
    }
    else if(q == 2){
      question2(sList);
    }
    else if(q == 3){
			 question3(sList);
		}
		else{
			cout << "We do not recognize that question\n";
		}
    
    cout << "\nChoose another number to continue. " << endl;
    cout << "Enter any other key to quit: " <<endl;
    cin >> q;
  }
}

void processFile(SimpleList& sList){
	string line;
  ifstream myFile("players.txt");
  if(myFile.is_open()){
    int lineNum = 1;
    while(getline(myFile, line)){
      if(line.length() > 0){
        sList.insert(createTennisPlayer(line, lineNum), sList.listSize());
        lineNum++;
      }
    }
  }
  else cout << "We were unable to open this file";
  myFile.close();
}

TennisPlayer createTennisPlayer(string line, int lineNum){
  string str1;
  string str2;
  string fName;
  string lName;
  string points;
  string country;
  for(int i = 0; i< line.length(); i++){
    str1 = charToStr(line[i]);
    if(str1.compare(" ") > 0){
      str2 += str1;
    }
    else{
      if(fName.length() == 0){
        fName += str2;
      }
      else if(lName.length() ==  0){
        lName += str2;
      }
      else if(points.length() == 0){
        points += str2;
      }   
      else{
        country += str2 + " ";
      }
      str2="";
    }
  }
  country += str2;
  int totPoints = stringToInt(points);
  TennisPlayer t(fName,lName, lineNum, totPoints ,country);
  lineNum++; 
  return t;
}

bool checkRank(int uRank){
  return (uRank > 0 && uRank < 21);
}

TennisPlayer getPlayerByRank(SimpleList sList, int rank){
  return sList.retrieve(rank -1);
}

int getRankFromLName(SimpleList sList, string lName){
  int rank = 21;
  for(int i=0; i<sList.listSize(); i++){
    if(lName.compare(sList.retrieve(i).getLastName()) == 0){
      rank = sList.retrieve(i).getRank();
      i = sList.listSize();
    }
  }
  return rank;
}

int askForRank(){
  int uRank;
  cout << "Select a Rank from 1-20: ";
  cin >> uRank;
  return uRank;
}

string askForLastName(){
  string uStr;
  cout << "What is the Last Name of the Player? ";
  cin >> uStr;
  return uStr;
}

void question1(SimpleList sList){
  int uRank = askForRank();
  while(!(checkRank(uRank))){
   cout << "Sorry! that player is not available."<< endl;
   uRank = askForRank();
  }
  TennisPlayer t = getPlayerByRank(sList, uRank);
  cout << t <<endl;
}

void question2(SimpleList sList){
  string uStr = askForLastName();
  int rank = getRankFromLName(sList, uStr);
  if(rank > 20){
    cout << "Sorry! This player is not ranked in our records."<< endl;
  }
  else cout << uStr << " is ranked number " << rank << endl;
}

void question3(SimpleList sList){
  int rank1 = askForRank();
  while(!(checkRank(rank1))){
   cout << "Sorry! that player is not available."<< endl;
   rank1 = askForRank();
  }
  int rank2 = askForRank();
  while(!(checkRank(rank2))){
   cout << "Sorry! that player is not available."<< endl;
   rank2 = askForRank();
  }
  TennisPlayer t1 = getPlayerByRank(sList, rank1);
  TennisPlayer t2 = getPlayerByRank(sList, rank2);
  
  int points1 = t1.getPoints();
  int points2 = t2.getPoints();

  int difference = points1 - points2;
  if(difference < 0){
    difference *= -1;
  }

  cout << "The players are separated by " << difference;
  cout << " points." << endl; 
}

string charToStr(char c){
   stringstream ss;
   string str;
   ss << c;
   ss >> str;
   return str;
}

int stringToInt(string str){
   stringstream ss;
   int num;
   ss << str;
   ss >> num;
   return num;
}