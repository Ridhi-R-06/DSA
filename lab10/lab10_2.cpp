#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<string>> words(3, vector<string>(n));
        unordered_map<string, int> freq;

        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> words[i][j];
                freq[words[i][j]]++;
            }
        }

        vector<int> score(3, 0);

        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = freq[words[i][j]];
                if (count == 1) {
                    score[i] += 3;
                } else if (count == 2) {
                    score[i] += 1;
                }
            }
        }

        
        for (int i = 0; i < 3; ++i) {
            cout << score[i] << (i < 2 ? " " : "\n");
        }
    }
    return 0;
}
