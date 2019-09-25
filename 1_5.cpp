#include <stdio.h>
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
}