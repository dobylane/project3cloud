#include <iostream>

using namespace std;

int main() {
    int servers, runtime;

    cout << "Num of servers" << endl;
    cin >> servers;

    cout << "Runtime?" << endl;
    cin >> runtime;

    for (int i = 0; i < servers * 100; i++) {
        // This will make the full servers queue loop
    }

    return 0;
}