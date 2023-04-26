#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
   vector<int> arrayOne{1, 2, 3};
   vector<int> arrayTwo{7, 8, 9};
   vector<int> mergedArray(6);

   unsigned int i, j;
   
   for (i = 0; i < arrayOne.size(); i++) {
      for (j = 0; i < arrayTwo.size(); j++) {
         if (i < 2) {
            if (arrayOne[i] < arrayTwo[j]) {
               mergedArray[i] = arrayOne[i];
            } else {
               mergedArray[i] = arrayTwo[j];
            }
         } else {
            if (arrayOne[i] < arrayTwo[j]) {
               mergedArray[i + j] = arrayOne[i];
            } else {
               mergedArray[i + j] = arrayTwo[j];
            }
         }
      }
   }
   
   for (i = 0; i < mergedArray.size(); i++) {
      cout << mergedArray[i];
   }
   
   return 0;
}
