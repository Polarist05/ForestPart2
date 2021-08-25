#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
bool a[100][100], a1[100][100];
int b, c;
queue<pair<int, int> > q;
int pos(int x, int y) {
	if (x >= 0 && x < c && y >= 0 && y < b && a[y][x] && !a1[y][x]) {
		a1[y][x] = 1;
		return 1;
	}
	else
		return 0;
}
int f1() {
	while (!q.empty()) {
		int y = q.front().second;
		int x = q.front().first;
		if (y + 1 == b) {
			while (!q.empty())
				q.pop();
			return 1;
		}
		if (pos(x+1,y)) { q.push({ x + 1,y }); }
		if (pos(x,y+1)) { q.push({ x,y + 1 }); }
		if (pos(x-1,y)) { q.push({ x - 1,y }); }
		if (pos(x,y-1)) { q.push({ x,y - 1 }); }
		if (pos(x+1,y+1)) { q.push({ x+1,y+1 }); }
		if (pos(x+1,y-1)) { q.push({ x+1,y-1 }); }
		if (pos(x-1,y+1)) { q.push({ x-1,y+1 }); }
		if (pos(x-1,y-1)) { q.push({ x-1,y-1 }); }
		q.pop();
	}
	return 0;
}
int main() {
	cin >> b >> c;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < c; i++) {
		if (a[0][i]) {
			a1[0][i] = 1;
			q.push({ i,0 });
		}
	}
	if (f1())
		printf("Yes");
	else
		printf("No");
}