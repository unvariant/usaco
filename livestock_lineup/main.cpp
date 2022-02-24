#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int cowtoi(string);

#define ncows 8
string cows[ncows] = {"Beatrice", "Belinder", "Bella", "Bessie, Betsy", "Blue", "Buttercup", "Sue"};
bool nodes[8][8] = {false};

int N;

int main() {
    ifstream fin ("lineup.in");
    ofstream fout("lineup.out");

    fin >> N;
    for(int i = 0; i < N; i++) {
        string cur; fin >> cur;
        string tmp; fin >> tmp >> tmp >> tmp >> tmp;
        string next; fin >> next;
        int cur_idx = cowtoi(cur);
        int next_idx = cowtoi(next);
        nodes[cur_idx][next_idx] = true;
        nodes[next_idx][cur_idx] = true;
    }

    for(int i = 0; i < ncows; i++) {
        for(int j = 0; j < ncows; j++) {
            cout << nodes[i][j] << " ";
        }; cout << "\n";
    }
}

int cowtoi(string cow) {
    for(int i = 0; i < ncows; i++) {
        if(cows[i] == cow) {
            return i;
        }
    }
    return -1;
}