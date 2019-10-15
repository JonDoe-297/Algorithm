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
    data.erase(begin, end);
    if (data.size() > 3) sort(data); // 两种以上商品排序
    while (xMoney)
    {
        for (int i = 0; i < data.size(); i +=3) {
            if (xMoney - data[i] >= 0 && data[i + 2] != 0) {
                xMoney = xMoney - data[i];
                data[i + 2]--;
                max = max + data[i + 1];
                // if (data[i + 2] == 0) {
                //     vector<int>::iterator deleteBegin = data.begin() + i * 3;;
                //     vector<int>::iterator deleteEnd = data.begin() + i * 3 + 3;
                //     data.erase(deleteBegin, deleteEnd);
                // }
                break;
            }
        }
    }
    return max;
}
int main() {
    int goodsNum, Q =0; 
    vector<int>data;
    vector<int>limData;
    cin >> goodsNum;
    for (int n = 0; n < goodsNum; n++) {
            int goodsValue[3];
            for (int m = 0; m < 3; m++) {
                cin >> goodsValue[m];
            }
            data.insert(data.end(),goodsValue,goodsValue + 3);
    }
    cin >> Q;
    for (int n = 0; n < Q; n++) {
        int limValue[2];
        for (int m = 0; m < 2; m++) {
            cin >> limValue[m];
        }
        limData.insert(limData.end(),limValue,limValue + 2);
    }
    for (int n = 0; n < Q; n++) {
        int max = 0;
        max = maxSumValue(data, limData[n * 2], limData[(n * 2) + 1]);
        cout << max << endl;
    }
    return 0;
}