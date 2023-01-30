// PuzzleGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
class puzzle
{
public:
     int x_cordinate;
     int y_cordinate;
     int numbers[3][4];
     int checkNumber;
     int arr[12];
     int  count;
     int movingXcordinate;
     int movingYcordinate;

    // bool checknumberRepetition;
     bool flag;
     puzzle()
     {
           x_cordinate=0;
           y_cordinate=0;
           for (int i=0; i < 3;i++)
           {
                for (int j=0; j < 4; j++)
                {
                     numbers[i][j] = 0;
                }
           }
           checkNumber = 0;
           for (int i = 0; i< 12; i++)
                arr[i] = 0;
            count = 1;
             movingXcordinate=0;
             movingYcordinate=0;
          // checknumberRepetition = true;
     }
     void number_generation()
     {
          srand(time(0));
          for (x_cordinate=0; x_cordinate < 3; x_cordinate++)
          {
               for (y_cordinate=0; y_cordinate < 4; y_cordinate++)
               {
                    if (x_cordinate == 0 && y_cordinate == 0)
                    {
                         numbers[x_cordinate][y_cordinate] = 0;
                         arr[0] = 0;
                         continue;
                    }
                    bool chk=false;
                    checkNumber = rand() % 11 + 1;
                    chk=chkNmbrRepition();
                    while (!chk)
                    {
                         checkNumber = rand() % 11 + 1;
                         chk = chkNmbrRepition();
                    }
                    if (chk)
                    {
                         numbers[x_cordinate][y_cordinate] = checkNumber;
                         arr[count] = checkNumber;
                         count++;
                    }
                    
               }
          }
          
     }
     void displayIntialGrid() 
     {
          cout << "\n";
          for (x_cordinate=0; x_cordinate < 3; x_cordinate++)
          {
               for (y_cordinate=0; y_cordinate < 4; y_cordinate++)
               {
                    cout << numbers[x_cordinate][y_cordinate] << "\t";
               }
               cout << "\n";
          }
     }

     bool chkNmbrRepition()
     {
          bool checknumberRepetition = true;
          while (checknumberRepetition)
          {
               for (int i = 0; i<= count; i++)
               {
                    if (arr[i] == checkNumber)
                    {
                         checknumberRepetition = false;
                         return checknumberRepetition;
                    }
               }
              
               return checknumberRepetition;
          }
         
     }
     void displayInitialNumbers()
     {
          displayAsteric();
          cout << "SET NUMBERS BE LIKE\n";
          displayAsteric();
          int numbering = 1;
          for (int i=0; i < 3; i++)
          {
               for (int j=0; j< 4; j++)
               {
                    if (numbering == 12)
                         cout << 0;
                    else
                    {
                         cout << numbering <<"\t";
                         numbering++;
                    }
                    
               }
               cout << "\n";
          }
          displayAsteric();
     }
     void displayAsteric()
     {
          for (int i = 0; i < 15; i++)
               cout << "*";
          cout << "\n";
     }
     void gameRules()
     {
          cout << "RULES OF GAME\n";
          displayAsteric();
          cout << "1   Digit  '0' in a box represents an empty box.\n2   you can only slide one box at a time.\n3   you have to set numbers in acending order from 1 to 11\n";

     }
     bool checkMatching()
     {
          int nmbr = 1;
          int arr[3][4];
          for (int i = 0; i < 3; i++)
          {
               for (int j = 0; j < 4; j++)
               {
                    if (nmbr == 12)
                         arr[i][j] = 0;
                    arr[i][j] = nmbr;
                    nmbr++;
               }
          }
          for (int i = 0; i < 3; i++)
          {
               for (int j = 0; j < 4; j++)
               {
                    if (numbers[i][j] == arr[i][j])
                         flag = true;
                    else
                    {
                         flag = false;
                         return flag;
                    }
               }
          }
          return flag;
     }
     void replace()
     {
          int temp = 0;
          for (x_cordinate = 0; x_cordinate < 3; x_cordinate++)
          {
               for (y_cordinate = 0; y_cordinate < 4; y_cordinate++)
               {
                    if (numbers[x_cordinate][y_cordinate] == 0)
                    {
                         playerChoosenNumber();
                         temp = numbers[x_cordinate][y_cordinate];
                         numbers[x_cordinate][y_cordinate] = numbers[movingXcordinate][movingYcordinate];
                         numbers[movingXcordinate][movingYcordinate] = temp;
                         displayIntialGrid();
                    }
               }
          }
     }
     void playerChoosenNumber()
     {
          int choosenNumber = 0;
          displayAsteric();
          cout << "move your recpective digit accordingly\n";
          cin >> choosenNumber;
          for (int i = 0; i< 3;i++)
          {
               for (int j = 0; j< 4;j++)
               {
                    if (numbers[i][j] == choosenNumber)
                    {
                         movingXcordinate = i;
                         movingYcordinate = j;
                    }
               }
          }

     }
};

int main()
{
     char ch;
     bool rsltFlag=false;
     puzzle obj;
     obj.displayAsteric();
     obj.gameRules();
     obj.displayInitialNumbers();
     cout << "do you want to start the game[y/n]\n";
     cin >> ch;
     if (ch == 'n')
          return 0;
     else
     {
          obj.number_generation();
          obj.displayAsteric();
          obj.displayIntialGrid();
          while (!rsltFlag)
          { 
               obj.replace();
               rsltFlag = obj.checkMatching();
          }
          obj.displayAsteric();
          cout << "YOU WIN \n";
          obj.displayAsteric();
     }
    system("pause");
    return 0;
}

