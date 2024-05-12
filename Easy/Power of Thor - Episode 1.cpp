#include <iostream>
using namespace std;

int main() {
    int lightX, lightY, initialTX, initialTY;
    cin >> lightX >> lightY >> initialTX >> initialTY;

    while (true) {
        string direction = "";

        if (lightY < initialTY) {
            direction += "N";
            initialTY--;
        } else if (lightY > initialTY) {
            direction += "S";
            initialTY++;
        }

        if (lightX < initialTX) {
            direction += "W";
            initialTX--;
        } else if (lightX > initialTX) {
            direction += "E";
            initialTX++;
        }

        cout << direction << endl;
    }

    return 0;
}
