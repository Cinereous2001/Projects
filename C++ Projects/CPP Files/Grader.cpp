/************************************************
* Author: Mahir Rahman
* Date: 11/26/2020
* Compiler: VS Studio 2019
* Description:
* The program acts like a grading system that 
* prints report for all students, including all
* the incorrect answers, max and min score.
* **********************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
   ifstream inFile1, inFile2; //Allows access to input files
   ofstream outFile; //Allows access to an output file
   double min = 101, max = -1;   //Declares variable that will store minimum and maximum percentages
   int highestScorer, lowestScorer; //Declares variable that will store student number of highest and lowest grades

   //Opens the file
   inFile1.open("CorrectAnswers.txt");
   if (inFile1)
   {
      inFile2.open("StudentAnswers.txt");
      if (inFile2)
      {
         outFile.open("ExamAnalysis.txt");   //Opens output file
         if (outFile)
         {
            //Declares the size of different arrays
            const int STUDENT_ANSWERS_ARRAY_SIZE = 300;
            const int CORRECT_ANSWERS_ARRAY_SIZE = 20;
            //Declares the arrays to store correct and stud answer
            char studentAns[STUDENT_ANSWERS_ARRAY_SIZE];
            char correctAns[CORRECT_ANSWERS_ARRAY_SIZE];
            //These arrays hold the index for incorrect answers by student
            int incorrAns[20];
            int studIncorrAns[300];
            //Stores number of incorrect answers for each student
            int incorrAnsCount = 0;
            //Holds total number of incorrect answers
            int incorrAnsCount1 = 0;
            //Acts as counters
            int count1 = 0;   
            int count2 = 0;
            int count3 = 0;
            int counter = 0;
            //Holds the student's number whose grade is being reported
            int studNum = 1;
            double perc;   //Holds the percentage awarded for quiz
            //These enter data from file into the arrays
            while (count1 < CORRECT_ANSWERS_ARRAY_SIZE && inFile1 >> correctAns[count1])
               count1++;
            while (count2 < STUDENT_ANSWERS_ARRAY_SIZE && inFile2 >> studentAns[count2])
            {
               count2++;
               counter++;
            }
            //Closes both input files
            inFile1.close();
            inFile2.close();
            //Reinitializes counters to zero
            count1 = 0;
            count2 = 0;
            for (; count1 <= counter; count1++, count2++)
            {
               //Processes data for each student when counter exceeds 20 questions
               if (count2 > 19)
               {
                  //Calculates the percentage earned in the grade
                  perc = (static_cast <double> (20) - incorrAnsCount) / 20 * 100;
                  //These if conditions find out the maximum and minimum scores and their holders
                  if (perc < min)
                  {
                     min = perc;
                     lowestScorer = studNum;
                  }
                  if (perc > max)
                  {
                     max = perc;
                     highestScorer = studNum;
                  }
                  count2 = 0;
                  //Prints report to screen and file
                  cout << "Report for Student " << studNum << ":" << endl;
                  cout << "---------------------" << endl;
                  outFile << "Report for Student " << studNum << ":" << endl;
                  outFile << "---------------------" << endl;
                  cout << "Missed " << incorrAnsCount << " out of 20 questions for " << perc << " % correct." << endl;
                  outFile << "Missed " << incorrAnsCount << " out of 20 questions for " << perc << " % correct." << endl;
                  if (incorrAnsCount != 0)
                  {
                     cout << "Questions missed:" << endl;
                     outFile << "Questions missed:" << endl;
                  }
                  studNum++;  //Increments studNum

                  for (int i = 0; i < incorrAnsCount; i++)
                  {
                     int index1 = incorrAns[i]; //Stores the location of the correct answer for student's incorrect answer
                     int index = studIncorrAns[count3];  //Stores the location of the incorrect answer by students in studentAns[]
                     //Prints report to screen and output file 
                     cout << setw(3) << incorrAns[i] + 1 << "(" << studentAns[index] << "/" << correctAns[index1] << ")";
                     outFile << setw(3) << incorrAns[i] + 1 << "(" << studentAns[index] << "/" << correctAns[index1] << ")";
                     if (i < incorrAnsCount - 1)
                     {
                        cout << ",";
                        outFile << ",";
                     }
                     else
                     {
                        cout << endl;
                        outFile << endl;
                     }

                     count3++;   //Incremens counter
                  }  //end for (int i = 0; i < incorrAnsCount; i++)
                  incorrAnsCount = 0;  //Reinitializes incorrect answer count
                  //Checks whether student passed or not
                  if (perc >= 70)
                  {
                     cout << "This student passed the exam!" << endl << endl;
                     outFile << "This student passed the exam!" << endl << endl;
                  }
                  else
                  {
                     cout << "This student failed the exam." << endl << endl;
                     outFile << "This student failed the exam." << endl << endl;
                  }  //end if (perc >= 70)
               }
               //Checks whether answers match to correct answers
               if (correctAns[count2] != studentAns[count1])
               {
                  incorrAns[incorrAnsCount] = count2;
                  studIncorrAns[incorrAnsCount1] = count1;
                  incorrAnsCount++; //Incremnts incorrect answer count
                  incorrAnsCount1++;
               }  //end if (correctAns[count2] != studentAns[count1])
            }  //end for (; count1 <= counter; count1++, count2++)
         }
         else
         {
            //Output file couldnt be opened
            cout << "Output file \"ExamAnalysis.txt\" could not be opened." << endl;
            outFile.close();
            exit(EXIT_FAILURE);
         }  //end if (outFile)
      }
      else
      {
         cout << "File \"StudentAnswers.txt\" could not be opened" << endl;
         inFile2.close();
         exit(EXIT_FAILURE);
      }  //end if (inFile2)
   }
   else
   {
      cout << "File \"CorrectAnswers.txt\" could not be opened." << endl;
      inFile1.close();
      exit(EXIT_FAILURE);
   }  //end if (inFile1)
   //Prints details about highest and lowest scorers
   cout << "Student " << highestScorer << " had the best grade with " << max << "%." << endl;
   outFile << "Student " << highestScorer << " had the best grade with " << max << "%." << endl;
   cout << "Student " << lowestScorer << " had the worst grade with " << min << "%." << endl;
   outFile << "Student " << lowestScorer << " had the worst grade with " << min << " % ." << endl;
   outFile.close();  //Closes output file
   return 0;
}  //end func main()
   
