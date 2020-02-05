#include <vector>
#include <stdlib.h>
#include "functions.h"

using namespace std;

int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g, int color_b, int sr) {
    
    int total_change = 0;
    int sum;
    int HCS;
    int HCU;
    int HCD;
    
    for (int i = 0; i < heightMap.at(0).size()-1; i++) {
        
        r.at(sr).at(i) = color_r;
            g.at(sr).at(i) = color_g;
            b.at(sr).at(i) = color_b;
        
        // Height Change straight
        HCS = abs(heightMap.at(sr).at(i)-heightMap.at(sr).at(i+1));
        
        // Height Change Up
        if (sr == 0) {
            HCU = HCS + 1000000; // so that the middle is the best path if you are at the top
        }
        else {
            HCU = abs(heightMap.at(sr-1).at(i+1)-heightMap.at(sr).at(i));
        }
        
        // Height Change Down
        if (sr == heightMap.size() - 1) {
            HCD = HCS + 1000000; // so that the bottom is always worst than the middle path cause there is no more bottom path
        }
        else {
            HCD = abs(heightMap.at(sr+1).at(i+1)-heightMap.at(sr).at(i));
        }
        
        // segment for which path is chosen next while changing that path's color
        
        // if up is less than down and up is less than straight then goes up
        if ((HCU < HCD) && (HCU < HCS)) {
            sr = sr - 1; // best path goes up
            total_change = total_change + HCU;

            //r.at(sr).at(i) = color_r;
            //g.at(sr).at(i) = color_g;
            //b.at(sr).at(i) = color_b;

        }
        // if down is less than or equal to up and down is less than straight then goes down
        else if ((HCD <= HCU) && (HCD < HCS)) {
            sr = sr + 1;
            total_change = total_change + HCD;
	
            //r.at(sr).at(i) = color_r;
            //g.at(sr).at(i) = color_g;
            //b.at(sr).at(i) = color_b;

        }
        // if straight is less than or equal to up or straight is less than or equal to down goes straight
        else if ((HCS <= HCU) || (HCS <= HCD)) {
            total_change = total_change + HCS;

            //r.at(sr).at(i) = color_r;
            //g.at(sr).at(i) = color_g;
            //b.at(sr).at(i) = color_b;

        }
        
        
        
    }
    
    r.at(sr).at(heightMap.at(0).size()-1) = color_r;
            g.at(sr).at(heightMap.at(0).size()-1) = color_g;
            b.at(sr).at(heightMap.at(0).size()-1) = color_b;
    
	return total_change;
}