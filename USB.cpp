// Name: Bananannn
// Sources of Help: 
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __USB_CPP__
#define __USB_CPP__

#include <map>
#include "USB.hpp"
#include "TwoD_Array.hpp"

int find_files_naive(int USBsize, std::vector<int>& files) {
  int min = -1;
  for (auto it = files.begin(); it != files.end(); ++it) {
    if (USBsize == *it) {   // 1 is the minimum number of possible files
      return 1;
    }
    else if (USBsize > *it) {
      // assume per the problem statement that the USB size is always met
      int files_used = find_files_naive(USBsize - *it, files) + 1;
      if (min == -1 || (files_used < min && files_used > 0)) {
        min = files_used;
      }
    }
    // do nothing if file size is larger than the USB size
  }
  return min;
}

std::map<int, int> memoize;

int find_files_memoized(int USBsize, std::vector<int>& files) {
  int min = -1;
  for (auto it = files.begin(); it != files.end(); ++it) {
    if (USBsize == *it) {   // 1 is the minimum number of possible files
        memoize.insert(std::pair<int, int>(*it, 1));
        return 1;
    }
    else if (USBsize > *it) {
      int files_used = 0;
      // assume per the problem statement that the USB size is always met
      if( memoize.find(USBsize - *it) != memoize.end() ){
          files_used = memoize[USBsize - *it] + 1;
      }
      else{
          files_used = find_files_memoized(USBsize - *it, files) + 1;
      }
      if (min == -1 || (files_used < min && files_used > 0)) {
        min = files_used;
      }
    }
    // do nothing if file size is larger than the USB size
  }
  memoize.insert(std::pair<int, int>(USBsize, min));
  return min;

}

int find_files_dp(int USBsize, std::vector<int>& files) {
    // Similar to the function of Question 1 in hw3

    TwoD_Array<int> * arr = new TwoD_Array<int>(1, USBsize+1);
    if(USBsize == 0){
        return 0;
    }
    for(int i = 0; i<USBsize+1; i++ ){
        arr->at(0,i) = i;
    }
    for( auto it = files.begin(); it != files.end(); it++){
        arr->at(0,(*it)) = 1;
    }
    arr->at(0,0) = 0;
    for( int i = 1; i < USBsize+1; i++ ){
        int min = BUFSIZ;
        for( int j = 0; j < files.size(); j++ ){
            if(files[j] > i) continue;
            int numf = 0;
                numf = arr->at(0,files[j]) + arr->at(0, i-files[j]);
                if( min > numf ){
                    min = numf;
                }
        }
        arr->at(0,i) = min;
    }
    //arr->printOut();
    return arr->at(0,USBsize);
}
#endif 
