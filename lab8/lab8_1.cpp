#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long sum = 0, max_val = 0, num;

        for (int i = 0; i < n; i++) {
            cin >> num;
            sum += num;
            if (num > max_val) {
                max_val = num; 
            }
        }

        cout << max_val << "\n";
    }

    return 0;
}
