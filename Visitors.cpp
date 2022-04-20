#include <iostream>
#include <iomanip>
#include <fstream>
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

//#2
//print hall occupancy
void printVisitors(char (&SeatsOccupacy)[15][20]){
	for(int i = 0; i < 15; ++i){
		cout << setw(2) << (i+1) << ".";
		for(int j = 0; j < 20; ++j)
			cout << SeatsOccupacy[i][j];
		cout << endl;
	}
}

//#3
//profit from occuied seats
void printProfit(int & VIPs,int & NormalVis){
	cout << "Obsazeno beznych mist:  " << setw(3) << NormalVis << ", celkova cena: " << (NormalVis*100) << ",-" << endl;
	cout << "Obsazeno VIP mist:\t" << setw(3) << VIPs << ", celkova cena: " << (VIPs*150) << ",-" << endl;
	cout << "Obsazeno celkem:\t"  << setw(3) << (NormalVis+VIPs) << ", celkova cena: " << (NormalVis*100 + VIPs*150) << ",-" << endl;
}

//Visitors function
bool visitors(const string & filename){
	char SeatsOccupacy [15][20] = {0};
	int VIPVis = 0;
	int NormalVis = 0;
	if( !loadVisitors(SeatsOccupacy,filename,VIPVis,NormalVis) ){
		cout << "Nespravny vstup." << endl;
		return false;
	}
	printVisitors(SeatsOccupacy);
	printProfit(VIPVis,NormalVis);
	return true;
}

//get name of file - added after deadline
string GetFileName(){
	string Filename;
	cout << "Zadejte jmeno souboru:" << endl;
	cin >> Filename;
	return Filename;
}


int main(){
	visitors(GetFileName());

//testing more test data
	assert( visitors("TestData//testovaci1.txt") == true);
	assert( visitors("TestData//testovaci2.txt") == true);
	assert( visitors("TestData//testovaci3.txt") == true);
	assert( visitors("TestData//testovaci4.txt") == false);
	assert( visitors("TestData//testovaci5.txt") == false);
	assert( visitors("TestData//testovaci6.txt") == false);
	assert( visitors("TestData//testovaci7.txt") == false);
	return 0;
}
