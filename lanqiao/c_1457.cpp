#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector<int>> vv;
    vv.push_back({1});
    vv.push_back({1, 1});
    int i = 1;
    int n;
    vector<vector<int>>::iterator rowIt = vv.begin();  // Initialize rowIt
    vector<int>::iterator colIt;
    cin >> n;
    
    while (true) {
        vector<int> v;
        v.push_back(1);
        for (int j = 0; j < i; j++) {
            v.push_back((*rowIt)[j] + (*rowIt)[j + 1]);  // Use rowIt to access the current row
        }
        v.push_back(1);
        vv.push_back(v);
        
        // Check if n is present in the current row
        for (colIt = rowIt->begin(); colIt != rowIt->end(); colIt++) {
            if (*colIt == n)
                break;
        }
        
        if (colIt != rowIt->end()) {
            break;  // Exit the loop if n is found
        }
        
        rowIt++;  // Move to the next row
        i++;      // Increment i
    }
    
    cout << distance(vv.begin(), rowIt) << " " << distance(rowIt->begin(), colIt);

    return 0;
}
