// Name: Bananannn
// Sources of Help: 
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __RODCUT_CPP__
#define __RODCUT_CPP__

#include "RodCut.hpp"
#include "TwoD_Array.hpp"
#include <vector>
#include <iostream>

int rodcut(std::map<int, int> prices, int length) {
    std::vector<int> price;
    int numRows = prices.size();
    int numCols = length;

    TwoD_Array<int> arr = TwoD_Array<int>(1, numCols+1);
    // initial codition
    if( length == 0 ){
        return 0;
    }
    // cut length one out of length one will sell one profit
    // fill in the table
    // i represents the length of the rod
    for( int i = 1; i<numCols+1; i++ ){
        int max = 0;
        if( i == 0 ){
            max = prices.find(i)->second;
        }
        for( int j = 0; j<=i-1; j++ ){
            int tempprice = 0;
            
            if( prices.find(i) != prices.end() ){
                tempprice = prices.find(i)->second;
                if( max < tempprice ){
                    max = tempprice;
                }
            }
            
            tempprice = arr.at(0,j)+arr.at(0, i-j);
            if( max < tempprice ){
                max = tempprice;
            }
            
        }
        arr.at(0,i) = max;
    }

  return arr.at(0,length);
}
#endif
