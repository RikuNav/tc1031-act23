// =================================================================
//
// File: main.cpp
// Author: Ricardo Navarro Gómez - A01708825
// Date: 11/09/2022
//
// =================================================================
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iomanip>
#include "header.h"
#include "ship.h"
#include "selection.h"

using namespace std;

int main(int argc, char* argv[]) {

  ifstream input;
  ofstream mysolution;

  if (argc != 3){
    cout<< "Error"<<endl;
    return -1;
  }

  input.open(argv[1]);
  if (!input.is_open()){
    cout << "Error al abrir el archivo\n";
    return -1;
  }

	mysolution.open(argv[2]);
	int num;
	string prefix, date, time, ubi;
	char entry;
	//Read the file first line
	input >>num >> prefix;
	//Ships vector with the amount of ships
	vector <Ship> ships;
	ships.resize(num);
	//Ships with prefix
	vector<Ship>ships_only_ubi;

	//We fill the vector with ships from the file
	for (int i=0; i<num; i++){
		input >> date >> time >> entry >> ubi;
		ships[i] = Ship(date, time, entry, ubi);
	}

	//We sort the ships by date
	selectionSort(ships);

	int rJan = 0;
	int mJan = 0;
	int rFeb = 0;
	int mFeb = 0;
	int rMar = 0;
	int mMar = 0;
	//We search for the prefix in the vector with all the ships
	for (int i = 0; i < num; i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		if(first_3 == prefix){
			int fecha = ships[i].month;
			char clave = ships[i].entry;
			if(fecha == 1){
				if(clave == 'R'){
					rJan++;
				}
				else{
					mJan++;
				}
			}
			else if(fecha == 2){
				if(clave == 'R'){
					rFeb++;
				}
				else{
					mFeb++;
				}
			}
			else if(fecha == 3){
				if(clave == 'R'){
					rMar++;
				}
				else{
					mMar++;
				}
			}
		}
	}

	mysolution << "jan\n";
	mysolution << "M " << mJan << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 1 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "R " << rJan << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 1 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "feb\n";
	mysolution << "M " << mFeb << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 2 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "R " << rFeb << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 2 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "mar\n";
	mysolution << "M " << mMar << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'M'){
			mysolution << ships[i].ubi << " ";
		}	
	}
	mysolution << "\n";
	mysolution << "R " << rMar << ": ";
	for(int i = 0; i < ships.size(); i++){
		string ubi = ships[i].ubi;
		string first_3 = ubi.substr(0, 3);
		int fecha = ships[i].month;
		char clave = ships[i].entry;
		if(first_3 == prefix && fecha == 3 && clave == 'R'){
			mysolution << ships[i].ubi << " ";
		}	
	}

	input.close();
	mysolution.close();

	return 0;
}