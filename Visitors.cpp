#include <iostream>
#include<fstream>
#include <cassert>

using namespace std;

//#1
//loading data from .txt file
bool CheckAndAddLine(char (&SeatInLine)[20],string & line, int & NumberOfVisitors){
	if(line.length() != 20) return false;

	for(int i = 0; i < 20; ++i){
		if(line[i] == '0') SeatInLine[i] = '-';
		else if(line[i] == '1'){ 
			SeatInLine[i] = 'X';
			NumberOfVisitors++;
			}
		else return false;
	}
	return true;
}

bool loadVisitors(	char (&SeatsOccupacy)[15][20], const string & filename,int & VIPVis,int & NormalVis){
	
	ifstream file(filename);

	string oneline;

	
	for(int i = 0; i < 15; ++i){
		if( !(file >> oneline) ) return false;
		if(i >= 7 && i <= 11){
			if( !CheckAndAddLine( SeatsOccupacy[i],oneline,VIPVis) ) return false;
		}
		else{
			if( !CheckAndAddLine( SeatsOccupacy[i],oneline,NormalVis) ) return false;
		}
	}
	if(file >> oneline) return false;
	

	return true;
}

//nezapomenout osetrit pripadne chyby na vstupu,
//pozor na chybejici a prebivajici znaky, chybne znaky a dalsi kulisarny


//#2
//print hall occupancy
void printVisitors(char (&SeatsOccupacy)[15][20]){
	cout << "Obvsazenost: " << endl;
	for(int i = 0; i < 15; ++i){
		for(int j = 0; j < 20; ++j)
			cout << SeatsOccupacy[i][j];
		cout << endl;
	}
}

//#3
//profit from occuied seats
void printProfit(int & VIPs,int & NormalVis){
	cout << "Obsazeno beznych mist: " << NormalVis << ", celkova cena: " << (NormalVis*100) << ",-" << endl;
	cout << "Obsazeno VIP mist:\t" << VIPs << ", celkova cena: " << (VIPs*150) << ",-" << endl;
	cout << "Obsazeno celkem:\t" << (NormalVis+VIPs) << ", celkova cena: " << (NormalVis*100 + VIPs*150) << ",-" << endl;
}

//Visitors function
bool visitors(const string & filename){
	char SeatsOccupacy [15][20] = {0};
	int VIPVis = 0;
	int NormalVis = 0;
	if( !loadVisitors(SeatsOccupacy,filename,VIPVis,NormalVis) ) return false;
	printVisitors(SeatsOccupacy);
	printProfit(VIPVis,NormalVis);
	return true;
}


int main(){
	assert( visitors("TestData//testovaci1.txt") == true);
	assert( visitors("TestData//testovaci2.txt") == true);
	assert( visitors("TestData//testovaci3.txt") == true);
	assert( visitors("TestData//testovaci4.txt") == false);
	assert( visitors("TestData//testovaci5.txt") == false);
	assert( visitors("TestData//testovaci6.txt") == false);
	assert( visitors("TestData//testovaci7.txt") == false);

	return 0;
}
