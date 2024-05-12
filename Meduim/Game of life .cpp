#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int neighborCount(vector<vector<char>>& m, int y, int x) {
    int c = 0;
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if ((i != y || j != x) && i >= 0 && j >= 0 && i < m.size() && j < m[0].size() && m[i][j] == '1') {
                c++;
            }
        }
    }
    return c;
}


int main() {
    int w, h;
    cin >> w >> h;

    vector<vector<char>> b(h, vector<char>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(b[i][j] == '1' && (neighborCount(b, i, j) < 2 || neighborCount(b, i, j) > 3)
               || b[i][j] == '0' && neighborCount(b, i, j) != 3)
                cout<<'0';
            else{
                cout<< '1';
            }
        }
        cout << endl;
    }



    return 0;
}
