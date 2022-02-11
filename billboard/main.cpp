#include <iostream>
#include <fstream>
using namespace std;

struct point {
    int x;
    int y;
};

struct board {
    struct point low;
    struct point high;
};

int min(int a, int b) {
    if(a < b) {
        return a;
    } else {
        return b;
    }
}

int max(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int intersect(struct board a, struct board b) {
    int y_int = max(min(a.high.y, b.high.y) - max(a.low.y, b.low.y), 0);
    int x_int = max(min(a.high.x, b.high.x) - max(a.low.x, b.low.x), 0);
    
    return x_int * y_int;
}

int main() {
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");

    struct board first, second, t;
    int a, b, c, d;
    fin >> a >> b >> c >> d;
    first = {{a, b}, {c, d}};
    fin >> a >> b >> c >> d;
    second = {{a, b}, {c, d}};
    fin >> a >> b >> c >> d;
    t = {{a, b}, {c, d}};

    int area = abs(first.high.x - first.low.x)   * abs(first.high.y - first.low.y) +
               abs(second.high.x - second.low.x) * abs(second.high.y - second.low.y);
    int uncovered = area - intersect(first, t) - intersect(second, t);
    fout << uncovered << "\n";
}