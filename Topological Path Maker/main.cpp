#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <stdlib.h>
#include "functions.h"

using namespace std;


int main() {
    
    int row = 0;
    int column = 0;
    string prompt;
    int max_val = -100000000;
    int min_val = 100000000;
    vector <int> temp;
    vector<vector<int>> vect2d;
    int k;
    double rgb_val;
    int Hchange;
    vector <int> Hchanges;
    int best_path = 0;
    
    
	cout << "Enter number of rows: "; cin >> column;
	cout << "Enter number of columns: "; cin >> row;
	cout << "Enter file name: "; cin >> prompt;
    
    // checking is input is an integer
    if (!cin) {
        cout << "Error: Rows and columns have to an integer." << endl;
        return -1;
    }
    
    // checking if input is less than 0
    if((column < 0) || (row < 0)) {
        cout << "Error: Number of rows and number of columns can not be negative." << endl;
        return -1;
    }


    
    vector<vector<int>> R(column);
    vector<vector<int>> G(column);
    vector<vector<int>> B(column);

	ifstream infs(prompt);

    //making 2d vector with values from input file
    int size = 0;
	while (infs >> k) {
        if(k < min_val) {
             min_val = k;
        }
        if(k > max_val) {
            max_val = k;
        }
        temp.push_back(k);
        if(temp.size() == row) {
            vect2d.push_back(temp);
            temp.clear();
            size++;
        }
    }
    
    //int size = 0;
    //for(int i = 0; i < vect2d.size(); i++) {
      //  size += vect2d[i].size();
    //}
    //if (size != column * row) {
       //  cout << "Error: There are either too many or too little data values." << endl;
       // return -1;
    //}
    
    
    if(vect2d.size() != column) {
        cout << "Error: There are either too many or too little data values." << endl;
        return -1;
    }
    for (int i = 0; i < column; ++i) {
        if(vect2d[i].size() != row) {
            cout << "Error: There are either too many or too little data values." << endl;
            return -1;
        }
    }
    // Calculating colors
    for(int i = 0; i < vect2d.size(); i++) {
        for(int j = 0; j < vect2d.at(i).size(); j++) {
            if(max_val == min_val) {
                rgb_val=0;
            }
            else {
                rgb_val = (vect2d.at(i).at(j) - min_val)*255.0/(max_val - min_val);
                rgb_val = round(rgb_val);
                R.at(i).push_back((int)rgb_val);
                G.at(i).push_back((int)rgb_val);
                B.at(i).push_back((int)rgb_val);
            }
        }
    }
    
    // PART 2 STUFF
    // colors are paths red first
    for (int i = 0; i < column; i++) {
        Hchange = colorPath(vect2d,R,G,B,252,25,63,i);
        Hchanges.push_back(Hchange);
        //cout << Hchanges.at(i) << " ";
    }
    
    int best_change = 100000000;
    // gets which is green path
    for (int i = 0; i < Hchanges.size(); i++) {
        if (best_change > Hchanges.at(i)) {
            best_change = Hchanges.at(i);
            best_path = i;
            //cout << best_path;
        }
    }
    
    // colors best path green
    colorPath(vect2d,R,G,B,31,253,13,best_path);
    
    
    // making output file ppm
    string outFileName = prompt+".ppm";
    
    ofstream out(outFileName.c_str());
    
    out << "P3" << endl;
    out << row << " " << column << endl;
    out << 255 << endl;

   for(int i = 0; i < vect2d.size(); i++) {
       for(int j = 0; j < vect2d.at(i).size(); j++) {
           out << R.at(i).at(j) << " " << G.at(i).at(j) << " " << B.at(i).at(j) << " ";
            out << std::endl;
       }
   }
}