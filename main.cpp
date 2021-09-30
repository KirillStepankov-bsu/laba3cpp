#include <iostream>
#include <vector>
#include <iostream>
#include <cstdlib> 
#include <iomanip>
using namespace std;

/*int GetElementOfMatrix(vector<vector<int>> matr, int i, int j){
    if((i+j)%2==0)
        return 1;
    return matr[i][j];
}*/

int IndexOfMinElementInRow(vector<int> row){
    int min = 0;
    for(int i = 1; i < row.size(); i++){
        if(row[i] < row[min])
            min = i;
    }
    return min;
}

void PrintMatrix(vector<vector<int>> matr){
    for(int e = 0; e<matr.size(); e++){
        cout << "| ";
        for(int q = 0; q<matr[e].size(); q++){
            cout << setw(5) << left << matr[e][q] << " | ";
        }
        cout << endl;
    }
}

int main(){
    unsigned int i, j;

    cout << "Enter size of matrix [i,j]. Example: 4 6: ";
    cin >> i >> j;
    if(i>10 || j>10){
        cout << "Invalid input";
        return 1;
    }

    vector<vector<int>> matrix(i, vector<int>(j, 1));

    for(int e = 0; e<i; e++){
        cout << "| ";
        for (int q = 0; q < j; q++)
        {
            cout << ((q+e)%2 == 0 ? "1" : "#") << " | ";
        }
        cout << endl;
    }

    cout << "Enter 1 if you want enter matrix from keyboard and 0 from random: ";
    bool oper; cin >> oper;

    srand(time(0)); 

    switch (oper)
    {
    case 1:
        cout << "Enter empty elements(#) of matrix line by line: \n";
        for(int e = 0; e<i; e++){
            int q = 0+(e+1)%2;
            while(q<j){
                cin >> matrix[e][q];
                q+=2;
            }
        }
        cout << "Your source matrix: \n";
        PrintMatrix(matrix);
        break;
    
    default:
        cout << "Enter empty elements(#) of matrix line by line: \n";
        for(int e = 0; e<i; e++){
            int q = 0+(e+1)%2;
            while(q<j){
                matrix[e][q] = rand();
                q+=2;
            }
        }
        cout << "Your source matrix: \n";
        PrintMatrix(matrix);
        break;
    }
    

    for(int q = 0; q < matrix.size(); q++){
        int zero_amount=0, sum=0;
        for(int e = 0; e < matrix[q].size(); e++){
            if(matrix[q][e]==0)
                zero_amount++;
            sum+=matrix[q][e];    
        }
        if(zero_amount > 0)
            cout << "The sum of elements on row [" << q+1 << "] with zero: " << sum << endl;
    }

    int osedl_amount = 0;
    for(int q = 0; q < matrix.size(); q++){
        int max_in_colum = matrix[q][IndexOfMinElementInRow(matrix[q])];
        for(int e = 1; e < matrix.size(); e++){
            if(matrix[e][IndexOfMinElementInRow(matrix[q])] > max_in_colum)
                max_in_colum = matrix[e][IndexOfMinElementInRow(matrix[q])];
        }
        if(max_in_colum == matrix[q][IndexOfMinElementInRow(matrix[q])])
            osedl_amount++;
    }
    
    cout << "The amount of osedl elements: " << osedl_amount << endl;
}
