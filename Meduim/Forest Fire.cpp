#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> grid;

int calcFireFrom(int i, int j, int nbArea) {
    int nbFire = 0;
    for (int k = 0; k < nbArea; k++) {
        for (int l = 0; l < nbArea; l++) {
            if(grid[i + k][j + l])
                nbFire +=  1;
            else
                nbFire += 0;
        }
    }
    return nbFire;
}

int main() {
    int L, water;
    cin >> L >> water;

    // game loop
    while(1){
        int N;
        cin >> N;
        grid.assign(L, vector<bool>(L, false));

        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            grid[y][x] = true;
        }

        vector<int> attackInfo(9, 0);
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                if (i + 2 < L && j + 2 < L) {
                    // check for planes
                    int nbFireIn3x3 = calcFireFrom(i, j, 3);
                    if (nbFireIn3x3 > attackInfo[0]) {
                        attackInfo[0] = nbFireIn3x3;
                        attackInfo[1] = i;
                        attackInfo[2] = j;
                    }
                }

                if (i + 1 < L && j + 1 < L) {
                    int nbFireIn2x2 = calcFireFrom(i, j, 2);
                    if (nbFireIn2x2 > attackInfo[3]) {
                        attackInfo[3] = nbFireIn2x2;
                        attackInfo[4] = i;
                        attackInfo[5] = j;
                    }
                }

                if (grid[i][j]) {
                    attackInfo[6] = 1;
                    attackInfo[7] = i;
                    attackInfo[8] = j;
                }
            }

        }

        if (attackInfo[0] > 5 && water>=2100) {
            cout << "C " << attackInfo[2] << " " << attackInfo[1] << endl;
            water-=2100;

        }
        else if (attackInfo[3] > 1  && water>=1200) {
            cout << "H " << attackInfo[5] << " " << attackInfo[4] << endl;
            water-=1200;

        }
        else {
            cout << "J " << attackInfo[8] << " " << attackInfo[7] << endl;
            water-=600;

        }



            for(auto it:grid)
            {
                for(auto row:it)
                    cout<<row<<" ";

                cout<<endl;
            }

    }



    return 0;
}
