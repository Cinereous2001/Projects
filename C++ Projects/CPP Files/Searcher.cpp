/************************************************
* Author: Mahir Rahman
* Course: CS1336.014
* Date: 11/26/2020
* Assignment: Lecture Homework #10 Exercise #1
* Compiler: VS Studio 2019
* Description: 
* The program searches for a certain value from
* an array in another array, and prints report
* depending on whether it found it or not.
* **********************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//Function prototype
int searchList(int stdList[], int numElems, int value);

int main()
{
   ifstream inFile1;    //Allows access to an input file
   ifstream inFile2;    //Alllows access to another input file
   const int LSTEST_ARRAY_SIZE = 50;  //Sets array size for lstest
   const int LSSTANDARD_ARRAY_SIZE = 100;  //Sets array size for lsstandard
   int lsTest [LSTEST_ARRAY_SIZE];  //Declares array for lstest
   int lsStandard [LSSTANDARD_ARRAY_SIZE];   //Declares array for lsstandard
   int returnVal; //Stores value returned by searchList function

   //Opens both files
   inFile1.open("LSStandard.txt");
   inFile2.open("LSTest.txt");

   //Checks whether file was opened correctly or not
   if (inFile1)
   {
      if (inFile2)
      {
         int count1 = 0;   //This acts as index for lsstandard array
         int count2 = 0;   //This acts as index for lstest array
         //Reads data from file into array and checks whether count is exceeded or not
         while (count1 < LSSTANDARD_ARRAY_SIZE && inFile1 >> lsStandard [count1])
            count1++;   //Increments count1
         while (count2 < LSTEST_ARRAY_SIZE && inFile2 >> lsTest[count2])
         {
            //Holds return value from searchList function
            returnVal = searchList(lsStandard, LSSTANDARD_ARRAY_SIZE, lsTest[count2]);
            //Performs different action depending on value from returnVal
            if (returnVal != -1)
            {
               //Prints report to screen
               cout << "Number " << setw(2) << count2 + 1 << " (" << setw(3) << lsTest[count2] 
                  << ") was located at index " << returnVal << "." << endl;
            }
            else
               cout << "Number " << setw(2) << count2 + 1 << " (" << setw(3) << lsTest[count2] << ") was not in the file." << endl;
            count2++;   //Increments count2
         }  //end while (count2 < LSTEST_ARRAY_SIZE && inFile2 >> lstest[count2])
      }
      else
      {
         cout << "File \"LSTest.txt\" could not be opened" << endl;
         inFile2.close();
         exit(EXIT_FAILURE);
      }  //end if (inFile2)
   } 
   else
   {
      cout << "File \"LSStandard.txt\" could not be opened" << endl;
      inFile1.close();
      exit(EXIT_FAILURE);
   }  //end if (inFile1)
   //Closes both files
   inFile1.close();
   inFile2.close();
   return 0;
}  //end func main()

/***************************************************************
* Function: searchList(int stdList[], int numElems, int value)
* Descr:    This function is used to find out if a particular
*           element is present in a given array
* Input:    int stdList[], int numElems, int value
* Return:   The return type is int. It returns the value
*           of -1 or i. The return value allows
*           us to know the print different report to console.
* *************************************************************/
int searchList(int stdList[], int numElems, int value)
{
   //Loops to check each element of array with value
   for (int i = 0; i < numElems; i++)
   {
      if (value == stdList[i])
      {
         return i;   //Returns index if value matches with element in array
      }
   }  //end for (int i = 0; i < numElems; i++)
   return -1;  //eturns -1 if element not found
}  //end func searcList(int stdList[], int numElems, int value)