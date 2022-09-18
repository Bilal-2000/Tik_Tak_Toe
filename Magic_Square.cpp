#include <iostream>
using namespace std;

// Global vars for 2D array
const int rows = 3;
const int col = 3;

// Func prototype
bool check_Magic(int arr[][col], const int rows);

int main()
{
    // Driver input
    int arr[rows][col] = {2, 7, 6,
                          9, 5, 1,
                          4, 3, 8};

    if (check_Magic(arr, rows))
    {
        cout << "The given input is a Magic Square" << endl;
    }
    else
        cout << "Not a magic Square" << endl;
    return 0;
}

bool check_Magic(int arr[][col], const int rows)
{
    // Local vars to calculate sum
    int first_row = 0;
    int second_row = 0;
    int third_row = 0;
    int first_col = 0;
    int second_col = 0;
    int third_col = 0;
    int first_dial = 0;
    int second_dial = 0;

    // To calculate each rows
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 2)
            {
                third_row += arr[i][j];
            }
            else if (i == 1)
            {
                second_row += arr[i][j];
            }
            else
            {
                first_row += arr[i][j];
            }
        }
    }

    // To calculate each column
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if (j == 2)
            {
                third_col += arr[i][j];
            }
            else if (j == 1)
            {
                second_col += arr[i][j];
            }
            else
            {
                first_col += arr[i][j];
            }
        }
    }

    // To calculate lower diagonal
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                first_dial += arr[i][j];
            }
        }
    }

    // To calculate upper diagonal
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            if ((i == 1 && j == 1) || (i == 2 && j == 0) || (i == 0 && j == 2))
            {
                second_dial += arr[i][j];
            }
        }
    }
    if (first_row == second_row && first_row == third_row)
    {
        if (first_col == second_col && second_col == third_col)
        {
            if (first_dial == second_dial)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
