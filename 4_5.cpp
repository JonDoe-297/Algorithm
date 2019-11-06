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

// int min_cost(costData data, char lineData, int starNum, int oNum, int xNum, int len, int cost, int i) {
//     if (i <= len) {
//         if (lineData)
//     }
// }
int min_cost(int oNum, int xNum, int len, int cost, int i, int n) { // i line 遍历数， n data 遍历数
    int costL = 0;
    int costR = 0;
    cout << "cost " << cost << endl;
    if (i < len && oNum <= (len + 1) / 2 && xNum <= (len + 1) / 2) {
        if (line[i] == 'o') {
            oNum++;
            cost += min_cost(oNum, xNum, len, cost, i + 1, n);
        } else if (line[i] == 'x') {
            xNum++;
            cost += min_cost(oNum, xNum, len, cost, i + 1, n);
        } else if (line[i] == '*') {
            cout << "oNum " << oNum << ' ' << "xNum " << xNum << endl;
            if (oNum - xNum == 0) {
                // cout << cost << endl;
                cost += min_cost(++oNum, xNum, len, cost + data[n].a, i + 1, ++n);
            } else if (oNum - xNum > 0) {
                if (oNum < (len + 1) / 2) {
                    int o = oNum;
                    int x = xNum;
                    cout << cost << endl;
                    cout << data[n].a << endl;
                    costL = cost += min_cost(++o, xNum, len, cost + data[n].a, i + 1, ++n);
                    costR = cost += min_cost(oNum, ++x, len, cost + data[n].b, i + 1, ++n);  
                } else if (oNum == (len + 1) / 2) {
                    // cout << i << " " << n << endl;
                    cout << cost << endl;
                    cost += min_cost(oNum, ++xNum, len, cost + data[n].b, i + 1, ++n);  
                }
            }
        }
    } else if (i == len) {
        if (line[i] != '*') {
            // oNum++;
            return cost;
        } else if (line[i] == '*') {
            if (oNum - xNum > 0) {
                return cost + data[n].b;
            } else if (oNum - xNum < 0) {
                return cost + data[n].a;
            }
        }
    }
    // cout << (costL < costR ? costL : costR) << endl;
    return costL < costR ? costL : costR;
}
int main(){
    // string line;
    cin >> line;
    int starNum = count(line.begin(),line.end(),'*');
    // int oNum = count(line.begin(),line.end(),'o');
    // int xNum = count(line.begin(),line.end(),'x');
    // int starNum = 0;
    int oNum = 0;
    int xNum = 0;
    int min = 0;
    // vector<costData> data;
    for (int i = 0; i < starNum; i++) {
        costData Ddata;
        cin >> Ddata.a >> Ddata.b;
        data.push_back(Ddata);
    }
    min = min_cost(oNum, xNum, line.size() - 1,min, 0, 0);
    cout << min << endl;
    return 0;
}