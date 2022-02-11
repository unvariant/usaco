#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int children[100000];

int main() {
    ifstream fin ("planting.in");
    ofstream fout("planting.out");

    int N; fin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b; fin >> a >> b;
        children[a - 1]++;
        children[b - 1]++;
    }

    int colors = 0;
    for(int i = 0; i < N; i++) {
        if(children[i] > colors) {
            colors = children[i];
        }
    }
    fout << colors + 1 << "\n";
}