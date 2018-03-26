// Name: Bananannn
// Sources of
// Help:https://docs.google.com/presentation/d/1C9ESECYBoTcMzp0Vl8ur7KL-xj6Bh
//      u3fn2vYe26GXuA/edit#slide=id.g10af7c5269_0_15 // PA3 Slides
//      http://vlsicad.ucsd.edu/courses/cse101-w18/slides-w18/cse101-w18-
//      Lecture10-dp-part1-tablet.pdf            // Lecture nodes page 11
//
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __GRID_SUM_CPP__
#define __GRID_SUM_CPP__

#include "TwoD_Array.hpp"
#include "GridSum.hpp"

// Perform the precomputation step here
GridSum::GridSum (TwoD_Array<int>& grid) {
    pg = new TwoD_Array<int>(grid.getNumRows(), grid.getNumCols());
    for( int i = 0; i < grid.getNumRows(); i++ ){
        for( int j = 0; j < grid.getNumCols(); j++ ){
            if( i == 0 && j == 0 ){
                pg->at(i, j) = grid.at(i, j);
            }
            else{
                if( i == 0 ){
                    pg->at(i, j) = pg->at(i, j-1)+grid.at(i, j);
                }
                else if( j == 0 ){
                    pg->at(i, j) = pg->at(i-1, j)+grid.at(i, j);
                }
                else{
                    // The sum from (0,0) to (i, j)
                    int sum = pg->at(i-1, j)+pg->at(i, j-1)-pg->at(i-1, j-1)+
                    grid.at(i,j);
                    pg->at(i,j) = sum;
                }
            }
        }
    }
    //pg->printOut();
}

// Perform the query step here
int GridSum::query (int x1, int y1, int x2, int y2) {
    if( x1 == 0 && y1 == 0 ){
        return pg->at(x2, y2);
    }
    // Find the specific sum
    if( x1 == 0 ){
        return pg->at(x2,y2) - pg->at(x2, y1-1);
    }
    if( y1 == 0 ){
        return pg->at(x2,y2) - pg->at(x1-1, y2);
    }
    if( x2 == 0 ){
        return pg->at(x2,y2) - pg->at(x1, y1-1);
    }
    if( y2 == 0 ){
        return pg->at(x2,y2) - pg->at(x1-1, y1);
    }
    int A = pg->at(x2, y2);
    //std::cout<<"A index ("<<x2<<","<<y2<<")"<<A<<std::endl;
    int B = pg->at(x2, y1-1);
    //std::cout<<"B index ("<<x2<<","<<y1<<")"<<B<<std::endl;
    int C = pg->at(x1-1, y2);
    //std::cout<<"C index ("<<x1<<","<<y2<<")"<<C<<std::endl;
    int D = pg->at(x1-1, y1-1);
    //std::cout<<"D index ("<<x1<<","<<y1<<")"<<D<<std::endl;

    int sum = A-B-C+D;
    return sum;
}

#endif
