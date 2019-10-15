/*#include <stdio.h>
#include <iostream>
using namespace std;
int singleNum(int data[]) {
    int val = 0;
    for(int n; n <= (sizeof(data)/sizeof(data[0])); n++) {
        val ^= data[n];
    }
    return val;
}

int main( )
{
    int numSize;
    int num = 0;
    int data[10];

    scanf("%d",&numSize);
    num = singleNum(data);
    printf("%d\n",num);
    return 0;
}*/



//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int singleNum(vector<int> data) {
        int val = 0;
        for (int n=0; n < data.size(); n++) {
               val ^= data[n];
        }
        return val;
}
int main() {
        int numSize;
        vector<int>data;
        int num = 0;
        scanf("%d", &numSize);
        for (int n = 0; n < numSize; n++) {
               int dataNum = 0;
               scanf("%d", &dataNum);
               data.push_back(dataNum);
        }
        num = singleNum(data);
        printf("%d\n", num);
        return 0;
}

