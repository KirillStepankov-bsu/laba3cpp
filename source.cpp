#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int GetElementFromMatrix(vector<vector<int>> matrix, int i, int j);

int MaxElementInColumm(vector<vector<int>> matrix, int i, int j){
    int max_in_columm = GetElementFromMatrix(matrix, 0, j); 
    for(int q = 1; q < i; q++){
        if(GetElementFromMatrix(matrix, q, j) > max_in_columm)
            max_in_columm = GetElementFromMatrix(matrix, q, j);
    }
    return max_in_columm;
}

int GetElementFromMatrix(vector<vector<int>> matrix, int i, int j){
    if((i+j)%2==0)
        return 1;
    if(i%2==0)
        return matrix[i][ceil((j+1)/2)-1];
    return matrix[i][ceil((j+2)/2)-1];
}

void PrintMatrix(vector<vector<int>> matrix, int i, int j){
    for(int q = 0; q<i; q++){
        cout << "| ";
        for(int p = 0; p<j; p++){
            cout << setw(5) << left << GetElementFromMatrix(matrix, q, p) << " | ";
        }
        cout << endl;
    }

}

void EnterMatrixElements(vector<vector<int>>& matrix, int i, int j){
    cout << "Enter 1 if you want enter matrix from keyboard and 0 if from random: ";
    bool oper;
    cin >> oper;

    srand(time(0));

    switch (oper)
    {
    case 1:
        cout << "Enter empty elements(#) of matrix line by line: \n";
        if(j%2==0){
            for(int q = 0; q< i; q++){
                for(int p = 0; p < j/2; p++){
                    int val; cin >> val;
                    matrix[q].push_back(val);
                }
            }
            break;
        }
        for(int q = 0; q < i; q++){
            for(int p = 0; p<ceil(j/2)+(q%2); p++){
                int val; cin >> val;
                matrix[q].push_back(val);
            }
        }
        break;
    
    default:
        for(int q = 0; q < i; q++){
            for(int p = 0; p<ceil(j/2)+(q%2); p++){
                matrix[q].push_back(rand());
            }
        }
        break;
    }
}


int main(){
    int i, j;
    cout << "Enter size of matrix [i,j]. Example: 4 6: ";
    cin >> i >> j;
    if(i>10 || j>10){
        cout << "Invalid input";
        return 1;
    }

    for(int e = 0; e<i; e++){
        cout << "| ";
        for (int q = 0; q < j; q++){
            cout << ((q+e)%2 == 0 ? "1" : "#") << " | ";
        }
        cout << endl;
    }
    vector<vector<int>> matrix(i, vector<int>());

    EnterMatrixElements(matrix, i, j); 

    cout << "Your source matrix: \n";
    PrintMatrix(matrix, i, j);

    for(int q = 0; q < i; q++){
        int zero_amount=0, sum=0;
        for(int e = 0; e < j; e++){
            if(GetElementFromMatrix(matrix, q, e)==0)
                zero_amount++;
            sum+=GetElementFromMatrix(matrix, q, e);    
        }
        if(zero_amount > 0)
            cout << "The sum of elements on row [" << q+1 << "] with zero: " << sum << endl;
    }

    int osedl_amount = 0;

    for(int q = 0; q < i; q++){
        for(int p = 0; p < j; p++){
            if(GetElementFromMatrix(matrix, q, p) == 1){
                if(MaxElementInColumm(matrix, i, p) == 1)
                    osedl_amount++;
            }
        }
    }

    cout << "The number of sedl elements: " << osedl_amount;

}