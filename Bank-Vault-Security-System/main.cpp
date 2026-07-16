#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int sumDig(int num) {
    int s = 0;
    while (num > 0) {
        s += num % 10;
        num /= 10;
    }
    return s;
}

void invRow(vector<vector<int>>& m, int r) {
    for (int j = 0; j < 6; j++) {
        m[r][j] = 1 - m[r][j];
    }
}

int maxColSum(const vector<vector<int>>& m) {
    int maxS = -1;
    int maxC = 0;
    
    for (int j = 0; j < 6; j++) {
        int s = 0;
        for (int i = 0; i < 6; i++) {
            s += m[i][j];
        }
        if (s > maxS) {
            maxS = s;
            maxC = j;
        }
    }
    return maxC;
}

void printM(const vector<vector<int>>& m) {
    cout << "\nHere is the final matrix:\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int pwd;
    
    cout << "Enter 4-digit password: ";
    cin >> pwd;
    
    if (pwd < 1000 || pwd > 9999) {
        cout << "Wrong! Password must be 4 digits." << endl;
        return 1;
    }
    
    int dSum = sumDig(pwd);
    if (!isPrime(dSum)) {
        cout << "System locked! Sum of digits is not a prime number." << endl;
        return 1;
    }
    
    cout << "Password OK.\n";
    
    vector<vector<int>> mat(6, vector<int>(6));
    
    cout << "\nEnter 6x6 matrix (only 0 and 1):\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> mat[i][j];
            if (mat[i][j] != 0 && mat[i][j] != 1) {
                cout << "Error! Use only 0 or 1." << endl;
                return 1;
            }
        }
    }
    
    for (int i = 0; i < 6; i++) {
        int cnt = 0;
        for (int j = 0; j < 6; j++) {
            if (mat[i][j] == 1) cnt++;
        }
        
        if (cnt % 2 == 1) {
            invRow(mat, i);
        }
    }
    
    cout << "\n--- Row Status ---\n";
    for (int i = 0; i < 6; i++) {
        int cnt = 0;
        for (int j = 0; j < 6; j++) {
            if (mat[i][j] == 1) cnt++;
        }
        
        char code;
        string warn;
        
        if (cnt > 4) {
            code = 'A';
            warn = "High Security";
        } else if (cnt >= 2 && cnt <= 4) {
            code = 'B';
            warn = "Normal Security";
        } else {
            code = 'C';
            warn = "Low Security";
        }
        
        switch (code) {
            case 'A':
                cout << "Row " << i + 1 << " has " << cnt << " ones -> Code " << code << ": " << warn << endl;
                break;
            case 'B':
                cout << "Row " << i + 1 << " has " << cnt << " ones -> Code " << code << ": " << warn << endl;
                break;
            case 'C':
                cout << "Row " << i + 1 << " has " << cnt << " ones -> Code " << code << ": " << warn << endl;
                break;
            default:
                cout << "Row " << i + 1 << ": something wrong" << endl;
        }
    }
    
    int mc = maxColSum(mat);
    
    int mcSum = 0;
    for (int i = 0; i < 6; i++) {
        mcSum += mat[i][mc];
    }
    
    cout << " Final Result ";
    cout << "Column " << mc + 1 << " has the biggest sum." << endl;
    cout << "Sum of that column = " << mcSum << endl;
    
    printM(mat);
    
    return 0;
}