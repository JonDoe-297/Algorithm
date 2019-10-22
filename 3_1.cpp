#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
// void swap(int &a, int &b)
// {
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }
// void sort(vector<int> &data) { // 两种以上商品排序
//     for (int i = 4; i < data.size(); i += 3)
// 	{
// 		for (int j = i - 3; j >= 0 && data[j + 3] > data[j]; j -= 3)
// 		{
// 			swap(data[j], data[j + 3]);
//             swap(data[j - 1], data[j + 2]);
//             swap(data[j + 1], data[j + 4]);
// 		}
// 	}
// }
// int maxSumValue(vector<int> data, int xDay, int yMoney) { // 贪心
//     int max = 0;
//     if (data.size() > 3) sort(data); // 两种以上商品排序
//     for (int i = 0; i < data.size(); i +=3) {
//         if (yMoney - data[i] >= 0 && data[i + 2] <= xDay) {
//             yMoney = yMoney - data[i];
//             max = max + data[i + 1];
//             // break;
//         }
//         if (yMoney == 0) break;
//     }
//     return max;
// }
int maxSumValue(vector<int> data, int xDay, int yMoney) { // 动态规划
    int i,j;
    for (int n = 3; n < data.size(); n += 3) {
        if(data[n + 2] > xDay) {
            vector<int>::iterator begin = data.begin() + n;
            vector<int>::iterator end = data.begin() + n + 3;
            data.erase(begin, end);
        }
    }
    int goodsNum = data.size() / 3;
    vector<vector<int> > c(goodsNum, vector<int>(yMoney + 1, 0)); 
    // int c[goodsNum][yMoney] = {0};

	for(i = 1; i < goodsNum; i++) {
		for(j = 1; j <= yMoney; j++) {
			// 递推关系式出炉
			if(j < data[i * 3]) {
				c[i][j] = c[i - 1][j];
			}
			else {
				int x = c[i - 1][j];
				int y = c[i - 1][j - data[i * 3]] + data[i * 3 + 1];
				c[i][j] = x < y ? y : x;
			}
		}
    }
    // cout << goodsNum << endl;
    // cout << yMoney << endl;
    for(i = 0; i < goodsNum; i++) {
        for(j = 0;j <= yMoney; j++) {
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }

    return c[goodsNum - 1][yMoney];
}
int main() {
    int N, M = 0;
    vector<int>data = {0, 0, 0};
    vector<int>limData;
    int num = 0;
    cin >> N >> M;
    for (int n = 0; n < N; n++) {
        int goodsValue[3];
        for (int m = 0; m < 3; m++) {
            scanf("%d", &goodsValue[m]);
            // cin >> goodsValue[m];
        }
        data.insert(data.end(), goodsValue, goodsValue + 3);
    }
    for (int n = 0; n < M; n++) {
        int limValue[2];
        for (int m = 0; m < 2; m++) {
            scanf("%d", &limValue[m]);
            // cin >> limValue[m];
        }
        limData.insert(limData.end(), limValue, limValue + 2);
    }
    for (int n = 0; n < M; n++) {
        int max = 0;
        max = maxSumValue(data, limData[n * 2], limData[(n * 2) + 1]);
        printf("%d\n", max);
        // cout << max << endl;
    }
    return 0;
}

