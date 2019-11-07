#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
// #include<array>
using namespace std;
struct costData
{
    int a; // o cost
    int b; // x cost
    /* data */
};
string line;
vector<costData> data;
int result = 2147483647;
int min_cost(int oNum, int xNum, int len, int cost, int i, int n) { // i line 遍历数， n data 遍历数
    int val = 2147483647;
    if (i < len && oNum <= (len + 1) / 2 && xNum <= (len + 1) / 2) {
        if (line[i] == 'o') {
            oNum++;
            val = min_cost(oNum, xNum, len, cost, i + 1, n);
        } else if (line[i] == 'x') {
            xNum++;
            val = min_cost(oNum, xNum, len, cost, i + 1, n);
        } else if (line[i] == '*') {
//            cout << "oNum " << oNum << ' ' << "xNum " << xNum << endl;
            if (oNum - xNum == 0) {
                int costA = cost + data[n].a;
                val = min_cost(oNum + 1, xNum, len, costA, i + 1, n + 1);
            } else if (oNum - xNum > 0) {
                if (oNum < (len + 1) / 2) {
                    int costA = cost + data[n].a;
                    int costB = cost + data[n].b;
                    val = min_cost(oNum + 1, xNum, len, costA, i + 1, n + 1);
                    val = min_cost(oNum, xNum + 1, len, costB, i + 1, n + 1);
                } else if (oNum == (len + 1) / 2) {
                    int costB = cost + data[n].b;
                    val = min_cost(oNum, xNum + 1, len, costB, i + 1, n + 1);
                }
            }
        }
    } else if (i == len) {
        if (line[i] != '*') {
            return cost;
        } else if (line[i] == '*') {
            if (oNum - xNum > 0) {
                return cost + data[n].b;
            } else if (oNum - xNum < 0) {
                return cost + data[n].a;
            }
        }
    }
    if (val < result) result = val;
    return result;
}
int main(){
    // string line;
    cin >> line;
    int starNum = count(line.begin(),line.end(),'*');
    int oNum = 0;
    int xNum = 0;
    int min = 0;
    // vector<costData> data;
    for (int i = 0; i < starNum; i++) {
        costData Ddata;
        cin >> Ddata.a >> Ddata.b;
        data.push_back(Ddata);
    }
    min = min_cost(oNum, xNum, line.size() - 1, 0, 0, 0);
    cout << min << endl;
    return 0;
}