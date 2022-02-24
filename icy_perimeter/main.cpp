#include <iostream>
#include <fstream>

std::string blob[1000];
bool v[1000][1000] = {false};
int N;
int visited = 0;
int max_area = 0;
int min_perimeter = INT32_MAX;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve(int y, int x, int * area, int * perimeter) {
	if(v[y][x] || y < 0 || x < 0 || y > N - 1 || x > N - 1) {
		return;
	}
	visited++;
	if(blob[y][x] == '.') {
		return;
	}

	*area = *area + 1;
	v[y][x] = true;

	for(int i = 0; i < 4; i++) {
		int ny = y + dir[i][0], nx = x + dir[i][1];
		if(ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1) {
			*perimeter = *perimeter + 1;
			continue;
		}

		if(blob[ny][nx] != '#') {
			*perimeter = *perimeter + 1;
		}
	}

	solve(y, x + 1, area, perimeter);
	solve(y, x - 1, area, perimeter);
	solve(y + 1, x, area, perimeter);
	solve(y - 1, x, area, perimeter);
}

int main() {
	std::ifstream fin ("perimeter.in");
	std::ofstream fout("perimeter.out");

	fin >> N;
	for(int i = 0; i < N; i++) {
		std::string tmp; fin >> tmp;
		blob[i] = tmp;
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(visited == N * N) {
				goto end;
			}
			int area = 0, perimeter = 0;
			solve(i, j, &area, &perimeter);
			if(area > max_area) {
				max_area = area;
				min_perimeter = perimeter;
			} else if(area == max_area && perimeter < min_perimeter) {
				min_perimeter = perimeter;
			}
		}
	}
	end:;
	fout << max_area << " " << min_perimeter << "\n";
}
