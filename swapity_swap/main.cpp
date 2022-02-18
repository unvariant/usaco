#include <iostream>
#include <fstream>
using namespace std;

int N,  K;
int a1, a2;
int b1, b2;

/*
2 5
3 7
*/

bool overlap() {
    if((b1 < a1 && a1 < b2) ||
       (b1 < a2 && a2 < b2) ||
       (a1 < b1 && b1 < a2) ||
       (a1 < b2 && b2 < a2)
    ) {
        return true;
    } else {
        return false;
    }
}

void reverse(int * arr, int start, int end) {
    for(int i = 0; i < (end - start >> 1) + (end - start & 1); i++) {
        int tmp = arr[start + i];
        arr[start + i] = arr[end - i];
        arr[end - i] = tmp;
    }
}

void printArr(int * arr, int length) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }; cout << "\n";
}

int main() {
    ifstream fin ("swap.in");
    ofstream fout("swap.out");

    fin >> N  >> K;
    fin >> a1 >> a2;
    fin >> b1 >> b2;
    int arr[N];
    for(int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    if(overlap()) {
        for(int i = 0; i < K; i++) {
            reverse(arr, a1 - 1, a2 - 1);
            reverse(arr, b1 - 1, b2 - 1);
        }
    } else if(K & 1) {
            reverse(arr, a1 - 1, a2 - 1);
            reverse(arr, b1 - 1, b2 - 1);
    }
    for(int i = 0; i < N; i++) {
        fout << arr[i] << "\n";
    }
}

/*
1 2 3 4 5 6 7

1 5 4 3 2 6 7
1 5 7 6 2 3 4

1 2 6 7 5 3 4
1 2 4 3 5 7 6
*/