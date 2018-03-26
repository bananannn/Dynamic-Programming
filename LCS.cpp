// Name: Bananannn
// Sources of
// Help:https://docs.google.com/presentation/d/1C9ESECYBoTcMzp0Vl8ur7KL-xj6B
// hu3fn2vYe26GXuA/edit#slide=id.g118c6e750c_1_256
// http://vlsicad.ucsd.edu/courses/cse101-w18/slides-w18/cse101-w18-Lecture10-d
// p-part1-tablet.pdf      // Page 28
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __LCS_CPP__
#define __LCS_CPP__

#include "LCS.hpp"
#include <vector>

std::string lcs(std::string s1, std::string s2) {
 /*   s1.insert(0, "x");
    s2.insert(0, "y");
    TwoD_Array<std::string> * table = new TwoD_Array<std::string>(s1.size(),
    s2.size());*/
    // initializing the left column
    /*for( int i = 0; i<s1.size(); i++ ){
        table->at(i, 0) = "0";
    }
    // initializing the first row
    for( int j = 0; j < s2.size(); j++ ){
        table->at(0, j) = "0";
    }*/

    // update the table
   /* for( int i = 1; i<s1.size(); i++ ){
        for( int j = 1; j<s2.size(); j++ ){
            if(s1[i] == s2[j]){
                if( i-1 == 0 || j-1 == 0 ){
                    table->at(i,j) = s1[i];qioo
                }
                else{
                    std::string temp = table->at(i-1,j-1);
                    temp += s1[i];
                    table->at(i,j) = temp;
                }
            }
            else{
                // If the string is 0, we ignore it
                   
                if( table->at(i-1, j).size() > table->at(i, j-1).size()){
                    if( table->at(i-1, j) != "0" ){
                        table->at(i,j) = table->at(i-1,j);
                    }
                }
                else{
                    if( table->at(i-1, j) != "0" ){
                        table->at(i,j) = table->at(i, j-1);
                    }
                }
            }
        }
    }

    return table->at(s1.size()-1, s2.size()-1); 
    */



    s1.insert(0, "x");
    s2.insert(0, "y");
    TwoD_Array<int> * table = new TwoD_Array<int>(s1.size(),
    s2.size());
    // initializing the left column
    for( int i = 0; i<s1.size(); i++ ){
        table->at(i, 0) = 0;
    }
    // initializing the first row
    for( int j = 0; j < s2.size(); j++ ){
        table->at(0, j) = 0;
    }

    // update the table
    for( int i = 1; i<s1.size(); i++ ){
        for( int j = 1; j<s2.size(); j++ ){
            if(s1[i] == s2[j]){
                table->at(i,j) = 1+table->at(i-1,j-1);
            }
            else{
                if(table->at(i-1,j) > table->at(i, j-1)){
                    table->at(i,j) = table->at(i-1,j);
                }
                else{
                    table->at(i,j) = table->at(i,j-1);
                }
            }
        }
    }

    // find the string by reversing the algorithm
    int i = s1.size()-1;
    int j = s2.size()-1;
    std::vector<char> arrStr;
    std::string temp;
    while(  i > 0 ){
        while( j > 0 ){
            if(s1[i] == s2[j]){
                arrStr.push_back(s1[i]);
                i -= 1;
                j -= 1;
            }
            else{
                if( table->at(i-1, j) > table->at(i, j-1) ){
                    i -= 1;
                }
                else if( table->at(i-1,j)<table->at(i,j-1) ){
                    j -= 1;
                }
                else{
                    i -= 1;
                    j -= 1;
                }
            }
        }
    }

    for( int i = arrStr.size()-1; i>=0; i-- ){
        
        temp += arrStr[i];
    }


    return temp;

}
#endif
