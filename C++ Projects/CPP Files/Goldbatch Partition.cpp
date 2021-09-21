/********************************************************
  Author:     Mahir Rahman
  Date:       11/8/2020
  Compiler:   Visual Studio 2019

  Description:
  This program calculates and displays on the screen 
  a Goldbach partition for all even integers
   between 4 and 100.
********************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Function prototype
bool isPrime(int num);

int main()
{
   int evenNumber = 4;  //This stores the current even integer
   int leftHandNum = 2; //This holds the current left hand number and
                        //is checked to see whether prime 
                        //or not

   //The part of report printed to screen
   cout << "A sample Goldbach Partition for all even integers between 4"
      << " and 100" << endl << endl;
   //The while loop executes while the even integer is 4 to 100 inclusive
   //and leftHandNum is 2 to 99 inclusive
   while (evenNumber <= 100 && leftHandNum < 100)
   {
      //Executes if leftHandNum is prime
      if (isPrime(leftHandNum))
      {
         //Executes if even integer and left hand int difference is prime
         if (isPrime(evenNumber - leftHandNum))
         {
            //Prints report to screen
            cout << "Even integer " << setw(3) << evenNumber << " = " << setw(3) << leftHandNum
               << " +" << setw(3) << evenNumber - leftHandNum << endl;
            evenNumber += 2;  //Increments even number by 2 to keep it even
            leftHandNum = 2;      //Initializes leftHandNum to 2 again
         }
         else
            leftHandNum++;  //Increments leftHandNum
      }  //end if (isPrime(evenNumber - leftHandNum))
      else
         leftHandNum++;
   }  //end while (evenNumber <= 100 && leftHandNum < 100)
   return 0;
}  //end func main()

/***************************************************************
* Function: isPrime(int)
* Descr:    This function is used to know if a given number
*           is prime or not using modulus.
* Input:    int number
* Return:   The return type is int. It returns the value
*           of 1 or 0. The return value allows
*           us to know if number is prime or not.
* *************************************************************/
bool isPrime(int num)
{
   bool primeNum = true;    //Gives true or false depending on prime or not
   int count = 2;    //Increments each time loop is executed

   if (num < 2)
   {
      primeNum = false;
   }  //end if (num < 2)
   while (count < num)
   {
      if (num % count == 0)
      {
         primeNum = false;
      }  //end if (num % count == 0)
      count = count + 1;   //Increments count by 1
   }  //end while (count < num)
   return primeNum;
}  //end func isPrime(int num)
