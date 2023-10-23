#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//The size for the max of a matrix
const int Max_size = 100;

//These are all the function prototypes that show what parameters they all take
void readMatrixfromFile(int Matrix1[Max_size][Max_size], int Matrix2[Max_size][Max_size], const string&filename);
void printMatrix(int result[Max_size][Max_size], int &size);
void AddMatrix(int Matrix1[Max_size][Max_size], int Matrix2[Max_size][Max_size], int size);
void SubtractMatrix(int Matrix1[Max_size][Max_size], int Matrix2[Max_size][Max_size], int size);
void MultiplyMatrix(int Matrix1[Max_size][Max_size], int Matrix2[Max_size][Max_size], int size);

int main(){
    //These are the variables needed
    int Matrix1[Max_size][Max_size];
    int Matrix2[Max_size][Max_size];
    int result[Max_size][Max_size];
    int size;
    //This will run all the functions and follow all the output parameters
    cout << "Jordan Mcdaniels \n";
    cout << "Lab-6: MatrixManipulation \n \n";
    cout << "Matrix-A \n";
    //This will create the matrixs and store them into the variables
    readMatrixfromFile(Matrix1[Max_size][Max_size], Matrix2[Max_size][Max_size], "matrix_input.txt");
    printMatrix(Matrix1[Max_size][Max_size], size);
    cout << "Matrix-B \n";
    printMatrix(Matrix2[Max_size][Max_size], size);
    AddMatrix(Matrix1[Max_size][Max_size], Matrix2[Max_size][Max_size],size);
    MultiplyMatrix(Matrix1[Max_size][Max_size], Matrix2[Max_size][Max_size],size);
    SubtractMatrix(Matrix1[Max_size][Max_size], Matrix2[Max_size][Max_size],size);

}
//Reads the data of the matrix from the file and then puts them both into a matrix along with the size
void readMatrixfromFile(int Matrix[Max_size][Max_size], int Matrix[Max_size][Max_size], const string&filename){
    //This loop will create both of the matrixs using the size and then putting the input into the first matrix
    //This will open the file and then put the first number into the size value
    ifstream myfile (const string&filename);
    myfile.open(string&filename);
    myfile >> size;
    //Read first line for size
    //Read each num from second line and go through the for loop
    for (int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            //Puts each indivudal number into each value of the matrix
           myfile >> Matrix1[i][j];
        }
    }
    for (int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
           myfile >> Matrix2[i][j];
        }
    }
}
//This will print out the matrix in a nice and readable form
void printMatrix(int result[Max_size][Max_size], int size){
    //This will go through each of the matrixs numbers and print them out row by row
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            cout << result[i][j] << " ";
            //This will go to the next line when j has reached the same value as size
            if (j == size - 1){
                cout << "\n";
            }
        }
    }
    cout << "\n";
}
//This will add the two matrixs together and then print the result 
void AddMatrix(int Matrix1[Max_size][Max_size], int Matrix2[Max_size][Max_size], int size){
    cout << "Matrix Sum (A+B) \n";
    //This will go through the matrixs and add them both putting each value into a new matrix
    for (int i = 0; i < size; ++i){
        for (int j =0; j < size; ++j){
            result[i][j] = Matrix1[i][j] + Matrix2[i][j];
        }
    }
    //This prints the new matrix before going back to main()
    printMatrix(result[Max_size][Max_size], int size);
}
//This will subtract the two matrixs and put the new value into a third matrix
void SubtractMatrix(int Matrix1[Max_size][Max_size], int Matrix2[Max_size][Max_size], int size){
    cout << "Matrix Difference (A-B) \n";
    for (int i = 0; i < size; ++i){
        for (int j =0; j < size; ++j){
            //This will put the value into the third matrix and then print the value
            result[i][j] = Matrix1[i][j] - Matrix2[i][j];
        }}
        printMatrix(result[Max_size][Max_size], int size);
}
//This multiplys the matrixs and puts the result into a new matrix
void MultiplyMatrix(int Matrix1[Max_size][Max_size], int Matrix2[Max_size][Max_size], int size){
    cout << "Matrix Multiplication (A*B) \n";
    //This will loop through the matrix like normal going through all values
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            //Here it will get the values for each indivual number and add them into that spot
            //This will continue until there are no more numbers needing to be multiplied
            for (int k = 0; k < size; k++)
            result[i][j] += Matrix1[i][k] * Matrix2[k][j];
        }
    }
    printMatrix(result[Max_size][Max_size], int size);
}