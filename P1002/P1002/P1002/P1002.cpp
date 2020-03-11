#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, horseX, horseY;
	cin >> n >> m >> horseX >> horseY;
	vector <int> horseXF, horseYF;
	//不能走的点
	horseXF.push_back(horseX), horseYF.push_back(horseY);
	if (0 <= horseX - 2) {
		if (0 <= horseY - 1) {//左二上一
			horseXF.push_back(horseX - 2), horseYF.push_back(horseY - 1);
		}
		if (horseY + 1 <= m) {//左二下一
			horseXF.push_back(horseX - 2), horseYF.push_back(horseY + 1);
		}
	}
	if (0 <= horseX - 1) {
		if (0 <= horseY - 2) {//左一上二
			horseXF.push_back(horseX - 1), horseYF.push_back(horseY - 2);
		}
		if (horseY + 2 <= m) {//左一下二
			horseXF.push_back(horseX - 1), horseYF.push_back(horseY + 2);
		}
	}
	if (horseX + 1 <= n) {
		if (0 <= horseY - 2) {//右一上二
			horseXF.push_back(horseX + 1), horseYF.push_back(horseY - 2);
		}
		if (horseY + 2 <= m) {//右一下二
			horseXF.push_back(horseX + 1), horseYF.push_back(horseY + 2);
		}
	}
	if (horseX + 2 <= n) {
		if (0 <= horseY - 1) {//右二上一
			horseXF.push_back(horseX + 2), horseYF.push_back(horseY - 1);
		}
		if (horseY + 1 <= m) {//右二下一
			horseXF.push_back(horseX + 2), horseYF.push_back(horseY + 1);
		}
	}

	m = m + 1, n = n + 1;
	long long int map[22][22];
	int i,j;
	//初始化左边界上边界
	for (i = 0; i < n + 1; i++) {
		map[0][i] = 0;
	}
	for (i = 0; i < m + 1; i++) {
		map[i][0] = 0;
	}
	//初始化棋盘
	for (i = 1; i < m + 1; i++) {
		for (j = 1; j < n + 1; j++) {
			map[i][j] = 1;
		}
	}
	//马阻挡处
	map[horseY + 1][horseX + 1] = 0;
	vector<int>::iterator itX, itY;
	for (itX = horseXF.begin(), itY = horseYF.begin(); itX != horseXF.end(); itX++, itY++) {
		map[(*itY) + 1][(*itX) + 1] = 0;
	}
	//递推结果
	if (map[1, 1] == 0) {
		map[m][n] = 0;
	}
	else {
		for (i = 1, j = 2; j < n + 1; j++) {
			if (map[i][j] != 0) {
				map[i][j] = map[i - 1][j] + map[i][j - 1];
			}
		}
		for (i = 2; i < m + 1; i++) {
			for (j = 1; j < n + 1; j++) {
				if (map[i][j] != 0) {
					map[i][j] = map[i - 1][j] + map[i][j - 1];
				}
			}
		}
	}
	//输出结果
	cout << map[m][n] << endl;
	return 0;
}
