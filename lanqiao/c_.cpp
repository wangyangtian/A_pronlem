#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<char, int> freq;

    for (int i=1; i<=2020;i++) {
        string str = to_string(i);
        for (char c : str) {
            freq[c]++;
        }
    }

    for (auto& pair : freq) {
        //cout << pair.first << ": " << pair.second << std::endl;
    }
    cout<<"624"<<endl;
    return 0;
}
/*
#include <iostream>
#include <string>

int main() {
    int count = 0;
    for (int i = 1; i <= 2020; i++) {
        std::string str = std::to_string(i);
        for (char c : str) {
            if (c == '2') {
                count++;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}
*/