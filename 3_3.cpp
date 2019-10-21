//#include "stdafx.h"
#include <stdio.h>
#include <algorithm>
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
int maxSumValue(vector<int> data, int xMoney, int yGoods) {
    vector<int>::iterator begin = data.begin() + yGoods * 3;
    vector<int>::iterator end = data.begin() + yGoods * 3 + 3;
    int max = 0;
    int i,j;
    data.erase(begin, end);
    vector<int>currentData = {0, 0, 0};
    for (int n = 0; n <= data.size(); n += 3) {
        for (int m = 0; m < data[n + 2]; m++) {
            currentData.insert(currentData.end(), data[n]);
            currentData.insert(currentData.end(), data[n + 1]);
            currentData.insert(currentData.end(), data[n + 2]);
        }
    }
    int goodsNum = data.size() / 3;
    vector<vector<int> > c(goodsNum + 1, vector<int>(xMoney + 1, 0)); 
    // int c[goodsNum][yMoney] = {0};

	for(i = 1; i <= goodsNum; i++) {
		for(j = 1; j <= xMoney; j++) {
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
    // if (data.size() > 3) sort(data); // 两种以上商品排序
    // while (xMoney)
    // {
    //     for (int i = 0; i < data.size(); i +=3) {
    //         if (xMoney - data[i] >= 0 && data[i + 2] != 0) {
    //             xMoney = xMoney - data[i];
    //             data[i + 2]--;
    //             max = max + data[i + 1];
    //             // if (data[i + 2] == 0) {
    //             //     vector<int>::iterator deleteBegin = data.begin() + i * 3;;
    //             //     vector<int>::iterator deleteEnd = data.begin() + i * 3 + 3;
    //             //     data.erase(deleteBegin, deleteEnd);
    //             // }
    //             break;
    //         }
    //     }
    // }
    return c[goodsNum][xMoney];
}
int main() {
    int goodsNum, Q = 0; 
    vector<int>data;
    vector<int>limData;
    // cin >> goodsNum;
    scanf("%d", &goodsNum);
    for (int n = 0; n < goodsNum; n++) {
            int goodsValue[3];
            for (int m = 0; m < 3; m++) {
                scanf("%d", &goodsValue[m]);
                // cin >> goodsValue[m];
            }
            data.insert(data.end(), goodsValue, goodsValue + 3);
    }
    // for (int i = 0; i < data.size(); i ++) {
    //     cout << data[i] << endl;
    // }
    scanf("%d", &Q);
    // cin >> Q;
    for (int n = 0; n < Q; n++) {
        int limValue[2];
        for (int m = 0; m < 2; m++) {
            scanf("%d", &limValue[m]);
            // cin >> limValue[m];
        }
        limData.insert(limData.end(), limValue, limValue + 2);
    }
    for (int n = 0; n < Q; n++) {
        int max = 0;
        max = maxSumValue(data, limData[n * 2], limData[(n * 2) + 1]);
        printf("%d\n", max);
        // cout << max << endl;
    }
    return 0;
}
