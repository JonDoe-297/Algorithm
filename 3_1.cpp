#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void sort(vector<int> &data) { // 两种以上商品排序
    for (int i = 4; i < data.size(); i += 3)
	{
		for (int j = i - 3; j >= 0 && data[j + 3] > data[j]; j -= 3)
		{
			swap(data[j], data[j + 3]);
            swap(data[j - 1], data[j + 2]);
            swap(data[j + 1], data[j + 4]);
		}
	}
}
int maxSumValue(vector<int> data, int xDay, int yMoney) {
    int max = 0;
    if (data.size() > 3) sort(data); // 两种以上商品排序
    for (int i = 0; i < data.size(); i +=3) {
        if (yMoney - data[i] >= 0 && data[i + 2] <= xDay) {
            yMoney = yMoney - data[i];
            max = max + data[i + 1];
            // break;
        }
        if (yMoney == 0) break;
    }
    return max;
}
int main() {
    int N, M = 0;
    vector<int>data;
    vector<int>limData;
    int num = 0;
    cin >> N >> M;
    for (int n = 0; n < N; n++) {
        int goodsValue[3];
        for (int m = 0; m < 3; m++) {
            cin >> goodsValue[m];
        }
        data.insert(data.end(), goodsValue, goodsValue + 3);
    }
    for (int n = 0; n < M; n++) {
        int limValue[2];
        for (int m = 0; m < 2; m++) {
            cin >> limValue[m];
        }
        limData.insert(limData.end(), limValue, limValue + 2);
    }
    for (int n = 0; n < M; n++) {
        int max = 0;
        max = maxSumValue(data, limData[n * 2], limData[(n * 2) + 1]);
        cout << max << endl;
    }
    return 0;
}

