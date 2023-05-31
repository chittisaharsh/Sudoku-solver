/*
This is a Sudoku Solver made using C language

PROJECT BY:-
Name - Chitti Saharsh
Class - CSBS
Division - J1
Roll no - RBT22CB003
*/

/*
VARIABLES

s - no of elements of matrix i.e, 9
ele - 9 x 9 matrix for taking input of element of sudoku
i - used for 'for' loop
j - used for 'for' loop
temp - temprorily storing the input before assigning
row - used for row no in sol function
col - used for column no in sol function
valid - flag to check if the no is valid at that specific location
row_start - used for checking the element in 3x3 box
col_start - used for checking the element in 3x3 box
num - used for storing numbers from 1 - 9 and is used in loop
*/

//input method to the column form 
//invalid input showing option

#include<stdio.h>

#define s 9                                  
int ele[s][s];
void printboard();                      //function to print the sudoku 
void iniele();                         //function to initialize each element with 0

int sol(int , int);                    //function to solve the sudoku

int validity(int , int , int);

int main()
{
    int i,j,temp,row=0,col,r;
    iniele();                          //calling function to initialize elements

    while(row<9)
    {
        entry:
        
        printf("For row %d\n",row+1);
        printf("Enter the position and the value: ");
        scanf("%d %d",&col,&temp);
        col--;   
        if(temp>=0 && temp<=9)
        {
            if(validity(row,col,temp)==1)
            {
                ele[row][col]=temp;
            }
            else
            {
                r=validity(row,col,temp);
                if(r==2)
                {
                    printf("Element repeated in row\n");
                }
                else 
                  if(r==3)
                  {
                      printf("Element repeated in col\n");
                  }
                  else 
                    if(r==4)
                    {
                        printf("Element repeated in 3x3 box\n");
                    }

                printf("INVALID INPUT\n\n");
                goto entry;
            }
        }
        else
        {
            printf("INVALID INPUT\n\n");
            goto entry;
        }
        printf("\n\n");


        printf("\n\n1 - Next row\n2 - Next col\n");
        scanf("%d",&i);
        if(i==1)
        {
            printboard();
            row++;
            if(row>=9)
            {
                goto out;
            }
        }
        else
        {
            goto entry;
        }
        

    }

    out:
    if(sol(0,0)==1)
    {
	  printf("Solution\n\n\n");
	  printboard();
    }

    else
    {
	  printf("No Solutions found");
    }

    return 0;
}

void printboard()
{
    printf("    1  2  3     4  5  6     7  8  9\n");
    printf(" -------------------------------------\n");
    printf("1|  %d  %d  %d  |  %d  %d  %d  |  %d  %d  %d  |\n",ele[0][0],ele[0][1],ele[0][2],ele[0][3],ele[0][4],ele[0][5],ele[0][6],ele[0][7],ele[0][8]);
    printf("2|  %d  %d  %d  |  %d  %d  %d  |  %d  %d  %d  |\n",ele[1][0],ele[1][1],ele[1][2],ele[1][3],ele[1][4],ele[1][5],ele[1][6],ele[1][7],ele[1][8]);
    printf("3|  %d  %d  %d  |  %d  %d  %d  |  %d  %d  %d  |\n",ele[2][0],ele[2][1],ele[2][2],ele[2][3],ele[2][4],ele[2][5],ele[2][6],ele[2][7],ele[2][8]);
    printf(" -------------------------------------\n");
    printf("4|  %d  %d  %d  |  %d  %d  %d  |  %d  %d  %d  |\n",ele[3][0],ele[3][1],ele[3][2],ele[3][3],ele[3][4],ele[3][5],ele[3][6],ele[3][7],ele[3][8]);
    printf("5|  %d  %d  %d  |  %d  %d  %d  |  %d  %d  %d  |\n",ele[4][0],ele[4][1],ele[4][2],ele[4][3],ele[4][4],ele[4][5],ele[4][6],ele[4][7],ele[4][8]);
    printf("6|  %d  %d  %d  |  %d  %d  %d  |  %d  %d  %d  |\n",ele[5][0],ele[5][1],ele[5][2],ele[5][3],ele[5][4],ele[5][5],ele[5][6],ele[5][7],ele[5][8]);
    printf(" -------------------------------------\n");
    printf("7|  %d  %d  %d  |  %d  %d  %d  |  %d  %d  %d  |\n",ele[6][0],ele[6][1],ele[6][2],ele[6][3],ele[6][4],ele[6][5],ele[6][6],ele[6][7],ele[6][8]);
    printf("8|  %d  %d  %d  |  %d  %d  %d  |  %d  %d  %d  |\n",ele[7][0],ele[7][1],ele[7][2],ele[7][3],ele[7][4],ele[7][5],ele[7][6],ele[7][7],ele[7][8]);
    printf("9|  %d  %d  %d  |  %d  %d  %d  |  %d  %d  %d  |\n",ele[8][0],ele[8][1],ele[8][2],ele[8][3],ele[8][4],ele[8][5],ele[8][6],ele[8][7],ele[8][8]);
    printf(" -------------------------------------\n");

}


void iniele()
{
    int i,j;
    for(i=1;i<=9;i++)
    {
	  for(j=1;j<=9;j++)
	  {
	    ele[i][j]=0;
	  }
    }
}


int sol(int row, int col) 
{
    int i, j, num;
    if (row == s - 1 && col == s) 
    {
        return 1;                             //if the sudoku is solved , returning the value 1
    }
    if (col == s)                             //if the element is reached at the last column then incrementing row 
    {
        row++;
        col = 0;
    }
    if (ele[row][col] > 0)                     //if the element is already given by user 
    {
        return sol(row, col + 1);
    }
    for (num = 1; num <= s; num++)             //numbers from 1 - 9
    {
        int valid = 1;                         //valid is a flag 
        for (i = 0; i < s; i++) 
        {
            if (ele[row][i] == num)             //if the number is already in row 
            {
                valid = 0;                      //setting flag to 0
                break;
            }
        }
        if (valid) 
        {
            for (i = 0; i < s; i++) 
            {
                if (ele[i][col] == num)          //checking the elements of column 
                {
                    valid = 0; 
                    break;
                }
            }
        }
        int row_start = (row / 3) * 3;
        int col_start = (col / 3) * 3;
        for (i = row_start; i < row_start + 3; i++) 
        {
            for (j = col_start; j < col_start + 3; j++) 
            {
                if (ele[i][j] == num)             // checking the elements from the 3x3 box
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid) 
            {
                break;
            }
        }
        if (valid)                                // if the value of flag stays 1 then assigning the value
        {
            ele[row][col] = num;
            if (sol(row, col + 1)) 
            {
                return 1;
            }
        }
    }
    ele[row][col] = 0;
    return 0;
}


int validity(int row, int col, int num)
{
    int i,j;

    if(num==0)
    {
        return 1;
    }
    int valid = 1;                         //valid is a flag 
        for (i = 0; i < s; i++) 
        {
            if (ele[row][i] == num)             //if the number is already in row 
            {
                valid = 0;                      //setting flag to 0
                return 2;
            }
        }
        if (valid==1) 
        {
            for (i = 0; i < s; i++) 
            {
                if (ele[i][col] == num)          //checking the elements of column 
                {
                    valid = 0; 
                    return 3;
                }
            }
        }
        int row_start = (row / 3) * 3;
        int col_start = (col / 3) * 3;
        for (i = row_start; i < row_start + 3; i++) 
        {
            for (j = col_start; j < col_start + 3; j++) 
            {
                if (ele[i][j] == num)             // checking the elements from the 3x3 box
                {
                    valid = 0;
                    return 4;
                }
                
            }

            if (valid==0) 
            {
                return 5;
            }
        }
        if(valid==1)
        {
            return 1;
        }
}