#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Global Vars for array size
const int row = 3;
const int col = 3;

// Prototypes
int check_x(char arr[][col], const int row);
int check_o(char arr[][col], const int row);

int main()
{
    char arr[row][col];

    // Initializing the matrix wit *
    for (int i = 0; i < row; i++)
    {
        if (i != 0)
        {
            cout << endl;
        }
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = '*';
            cout << setw(3) << arr[i][j];
        }
    }

    // Loop for the total amount of inputs
    for (int i = 0; i < 5; i++)
    {
        int row_input_p1, col_input_p1;
        int row_input_p2, col_input_p2;

        cout << "\nPlayer 1 enter coordinates to specify (X) on the board : ";
        cin >> row_input_p1 >> col_input_p1;
        // Updating array
        arr[row_input_p1][col_input_p1] = 'X';
        check_x(arr, row);

        // TO check for tie
        if (i == 4)
        {
            cout << "\nIT's a tie" << endl;
            return 0;
        }

        cout << "\nPlayer 2 enter coordinates to specify (O) on the board : ";
        cin >> row_input_p2 >> col_input_p2;
        // Updating array
        arr[row_input_p2][col_input_p2] = 'O';
        check_o(arr, row);

        // To clear screen
        system("cls");

        // Printing the board
        for (int i = 0; i < row; i++)
        {
            if (i != 0)
            {
                cout << endl;
            }
            for (int j = 0; j < col; j++)
            {
                cout << setw(3) << arr[i][j];
            }
        }
    }
}

// Checking X coordinates
int check_x(char arr[][col], const int row)
{
    // Local Var to check sequence
    int r1_count = 0;
    int r2_count = 0;
    int r3_count = 0;
    int c1_count = 0;
    int c2_count = 0;
    int c3_count = 0;
    int l_diag = 0;
    int u_diag = 0;

    // To check XXX in rows
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0)
            {
                if (arr[i][j] == 'X')
                {
                    if (r1_count == 2)
                    {
                        cout << "\nHORRAH!! Player (X) won" << endl;
                        exit(0);
                    }
                    r1_count += 1;
                }
            }
            else if (i == 1)
            {
                if (arr[i][j] == 'X')
                {
                    if (r2_count == 2)
                    {
                        cout << "\nHORRAH!! Player (X) won" << endl;
                        exit(0);
                    }
                    r2_count += 1;
                }
            }
            else if (i == 2)
            {
                if (arr[i][j] == 'X')
                {
                    if (r3_count == 2)
                    {
                        cout << "\nHORRAH!! Player (X) won" << endl;
                        exit(0);
                    }
                    r3_count += 1;
                }
            }
        }
    }

    // To check XXX in col
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            if (j == 0)
            {
                if (arr[i][j] == 'X')
                {
                    if (c1_count == 2)
                    {
                        cout << "\nHORRAH!! Player (X) won" << endl;
                        exit(0);
                    }
                    c1_count += 1;
                }
            }
            else if (j == 1)
            {
                if (arr[i][j] == 'X')
                {
                    if (c2_count == 2)
                    {
                        cout << "\nHORRAH!! Player (X) won" << endl;
                        exit(0);
                    }
                    c2_count += 1;
                }
            }
            else if (j == 2)
            {
                if (arr[i][j] == 'X')
                {
                    if (c3_count == 2)
                    {
                        cout << "\nHORRAH!! Player (X) won" << endl;
                        exit(0);
                    }
                    c3_count += 1;
                }
            }
        }
    }

    // To check XXX in lower diagonal
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                if (arr[i][j] == 'X')
                {
                    if (l_diag == 2)
                    {
                        cout << "\nHORRAH!! Player (X) won" << endl;
                        exit(0);
                    }
                    l_diag += 1;
                }
            }
        }
    }

    // TO check XXX in upper diagonal
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            if ((i == 1 && j == 1) || (i == 2 && j == 0) || (i == 0 && j == 2))
            {
                if (arr[i][j] == 'X')
                {
                    if (u_diag == 2)
                    {
                        cout << "\nHORRAH!! Player (X) won" << endl;
                        exit(0);
                    }
                    u_diag += 1;
                }
            }
        }
    }
}

// Checking O coordinates
int check_o(char arr[][col], const int row)
{
    // Local Var to check sequence
    int r1_count_O = 0;
    int r2_count_O = 0;
    int r3_count_O = 0;
    int c1_count_O = 0;
    int c2_count_O = 0;
    int c3_count_O = 0;
    int l_diag_O = 0;
    int u_diag_O = 0;

    // To check OOO in rows
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0)
            {
                if (arr[i][j] == 'O')
                {
                    if (r1_count_O == 2)
                    {
                        cout << "\nHORRAH!! Player (O) won" << endl;
                        exit(0);
                    }
                    r1_count_O += 1;
                }
            }
            else if (i == 1)
            {
                if (arr[i][j] == 'O')
                {
                    if (r2_count_O == 2)
                    {
                        cout << "\nHORRAH!! Player (O) won" << endl;
                        exit(0);
                    }
                    r2_count_O += 1;
                }
            }
            else if (i == 2)
            {
                if (arr[i][j] == 'O')
                {
                    if (r3_count_O == 2)
                    {
                        cout << "\nHORRAH!! Player (O) won" << endl;
                        exit(0);
                    }
                    r3_count_O += 1;
                }
            }
        }
    }

    // To check OOO in col
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            if (j == 0)
            {
                if (arr[i][j] == 'O')
                {
                    if (c1_count_O == 2)
                    {
                        cout << "\nHORRAH!! Player (O) won" << endl;
                        exit(0);
                    }
                    c1_count_O += 1;
                }
            }
            else if (j == 1)
            {

                if (arr[i][j] == 'O')
                {
                    if (c2_count_O == 2)
                    {
                        cout << "\nHORRAH!! Player (O) won" << endl;
                        exit(0);
                    }
                    c2_count_O += 1;
                }
            }
            else if (j == 2)
            {
                if (arr[i][j] == 'O')
                {
                    if (c3_count_O == 2)
                    {
                        cout << "\nHORRAH!! Player (O) won" << endl;
                        exit(0);
                    }
                    c3_count_O += 1;
                }
            }
        }
    }

    // To check in lower diagonal
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                if (arr[i][j] == 'O')
                {
                    if (l_diag_O == 2)
                    {
                        cout << "\nHORRAH!! Player (O) won" << endl;
                        exit(0);
                    }
                    l_diag_O += 1;
                }
            }
        }
    }

    // TO check in upper diagonal
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            if ((i == 1 && j == 1) || (i == 2 && j == 0) || (i == 0 && j == 2))
            {
                if (arr[i][j] == 'O')
                {
                    if (u_diag_O == 2)
                    {
                        cout << "\nHORRAH!! Player (O) won" << endl;
                        exit(0);
                    }
                    u_diag_O += 1;
                }
            }
        }
    }
}