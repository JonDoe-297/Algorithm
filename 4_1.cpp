#include<iostream>
#include<vector>
// #include<array>
using namespace std;
struct detailData
{
    int c;
    int a;
    /* data */
};
int min_cost(vector<detailData> data, int s) {
    int len = data.size();
    int minCost = 0;
    int starDay = 0;
    for (int i = 0; i < len; i++) {
        int productCost = data[i].c * data[i].a;
        int storeCost = data[starDay].c * data[i].a + (s * (i - starDay) * data[i].a);
        if (productCost > storeCost ) {
            minCost += storeCost;
        } else {
            minCost += productCost;
            starDay = i;
            /* code */
        }
    }
    return minCost;
}
int main(){
    int n, s = 0;
    cin >> n >> s;
    // array<detailData, 5> data;
    vector<detailData> data;
    int min = 0;
    for(int i = 0; i < n; i++) {
        detailData Ddata;
        cin >> Ddata.c >> Ddata.a;
        data.push_back(Ddata);
    }
    min = min_cost(data, s);
    cout << min << endl;
    return 0;
}