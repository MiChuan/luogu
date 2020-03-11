#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
using namespace std;

int getIndex(vector<double>&m, vector<double>&v, vector<double>&w, int low, int high) {
	double wtemp = w[low], mtemp = m[low], vtemp = v[low];
	while (low < high) {
		while (low < high && w[high] >= wtemp) {
			high--;
		}
		w[low] = w[high];
		m[low] = m[high];
		v[low] = v[high];
		//low++;
		while (low < high && w[low] <= wtemp) {
			low++;
		}
		w[high] = w[low];
		m[high] = m[low];
		v[high] = v[low];
	}
	w[low] = wtemp;
	m[low] = mtemp;
	v[low] = vtemp;
	return low;
}

void quickSort(vector<double>&m, vector<double>&v, vector<double>&w, int low, int high) {
	if (low < high) {
		int index = getIndex(m, v, w, low, high);

		quickSort(m, v, w, low, index - 1);
		quickSort(m, v, w, index + 1, high);
	}
}

int main()
{
	int n;
	double t,c,cv,tm,tv;
	vector<double>m;
	vector<double>v;
	vector<double>w;
	cin >> n >> t;
	c = 0;//能取的最大重量
	cv = 0;//背包中金币价值
	int i;
	for (i = 0; i < n; i++) {
		cin >> tm >> tv;
		m.push_back(tm);
		v.push_back(tv);
		w.push_back(v[i] / m[i]); //计算单位价格
	}
	//按单位价格快速排序
	quickSort(m, v, w, 0, n - 1);
	for (i = n - 1; i >= 0; i--) {
		if ((t - c) > 0) {//背包还有空间
			if ((t - c) >= m[i]) {//背包空间能放下当前堆所有金币
				c = c + m[i];
				cv = cv + v[i];
			}
			else {//背包放当前堆一部分金币
				cv = cv + w[i] * (t - c);
				c = t;
			}
		}
		else if (t - c == 0) break;
	}
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << cv << endl;
	return 0;
}