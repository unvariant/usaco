#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N, M, K;
vector<int> h;
int cows[101] = {0};   // cows[i] contains the position of cow i
int order[101] = {0};

int main() {
    ifstream fin ("milkorder.in");
    ofstream fout("milkorder.out");

    fin >> N >> M >> K;

    for(int i = 0; i < M; i++) {
        int a; fin >> a;
        h.push_back(a);
    }

    for(int i = 0; i < K; i++) {
        int a, b; fin >> a >> b;
        if(a == 1) {
            fout << b << "\n";
            return 0;
        }
        cows[a] = b;
        // indicates that cow i is at position cows[i]

        order[b] = a;
        // indicates that at cow a is at position b - 1
    }

    int right = N, i = M - 1;
    for(; i > -1; i--) {
        if(h[i] == 1) {
            break;
        } else {
            if(cows[h[i]] != 0) {
                right = cows[h[i]];
            } else {
                while(order[right] != 0) {
                    right--;
                }
                order[right] = h[i];
                right--;
            }
        }
    }

    int result = 1;
    if(i > -1) {
        for(int j = 0; j < i + 1; j++) {
            if(cows[h[j]] != 0) {
                result = cows[h[j]];
            } else {
                while(order[result] != 0) {
                    result++;
                }
                order[result] = h[j];
                result++;
            }
        }
        result--;
    } else {
        while(order[result] != 0) {
            result++;
        }
    }

    fout << result << "\n";
}