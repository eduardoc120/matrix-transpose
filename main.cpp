#include <iostream>

using namespace std;

bool validateIntInput() {
    // Validation of the integer input
    if (cin.fail()) 
    {
        cout << "Invalid input. Please enter a valid integer." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

bool validateInputSize(int& data) 
{
    // validation of the matrix size that have to be more than 1, less than 10 and a valid integer
    if (!validateIntInput())
    {
        return false;
    }
    if (data > 10)
    {
        cout << "Error: the maximum size of the matrix is 10x10" << endl;
        return false;
    }
    if (data < 1)
    {
        cout << "Error: the matrix should have at least 1 row and 1 column" << endl;
        return false;
    }
    return true;
}


int main() 
{

    int columns = 0;
    int rows = 0;

    
    do 
    {
        cout << "Enter the number of matrix columns: ";
        cin >> columns;
    }
    while (!validateInputSize(columns));

    do 
    {
        cout << "Enter the number of matrix rows: ";
        cin >> rows;
    }
    while (!validateInputSize(rows));

    int matrix[columns][rows];
    int transposeMatrix[rows][columns];


    // Filling the matrix with user inputs

    cout << "Enter the items to the matrix" << endl;
    for (int i = 0; i < columns; i++)
    {
        for (int p = 0; p < rows; p++)
        {
            int input = 0;

            do {
                cout << "Location (" << i << "," << p << "): ";
                cin >> input;
            } while (!validateIntInput());

            matrix[i][p] = input;
        }
    }

    // Transpose the matrix

    for (int i = 0; i < rows; i++)
    {
        for (int p = 0; p < columns; p++)
        {
            transposeMatrix[i][p] = matrix[p][i];
        }
    }

    // Display matrix

    cout << "Original Matrix: " << endl;

    for (int i = 0; i < columns; i++)
    {
        for (int p = 0; p < rows; p++)
        {
            cout << matrix[i][p] << " ";
        }
        cout << endl;
    }

    cout << "Transpose Matrix: " << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int p = 0; p < columns; p++)
        {
            cout << transposeMatrix[i][p] << " ";
        }
        cout << endl;
    }

    return 0;
}
