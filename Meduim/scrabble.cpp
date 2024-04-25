#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;



bool isValidWord( string letters, string word) {
    vector<int> letterCount(26, 0);
    for (char c : letters) {
        letterCount[c - 'a']++;
    }

    vector<int> wordCount(26, 0);
    for (char c : word) {
            wordCount[c - 'a']++;
        }
    for (int i = 0; i < 26; ++i) {
        if (wordCount[i] > letterCount[i]) {
                return false;
            }
        }
    return true;

}


int main() {
    map<char, int> charMap = {
            {'a', 1}, {'b', 3}, {'c', 3}, {'d', 2}, {'e', 1}, {'f', 4}, {'g', 2}, {'h', 4},
            {'i', 1}, {'j', 8}, {'k', 5}, {'l', 1}, {'m', 3}, {'n', 1}, {'o', 1}, {'p', 3},
            {'q', 10}, {'r', 1}, {'s', 1}, {'t', 1}, {'u', 1}, {'v', 4}, {'w', 4}, {'x', 8},
            {'y', 4}, {'z', 10}
    };

    int N;
    cin >> N;
    cin.ignore();

    vector<string> list;
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        list.push_back(line);
    }

    string letters;
    getline(cin, letters);
    vector<string>new_v;
    for (auto  word : list) {
        if(isValidWord(letters,word))
        {
            new_v.push_back(word);
        }
    }


    string word;
    int maxScore = 0;
    for (auto it : new_v) {
        int tmp = 0;
        for (char ch : it) {
            tmp += charMap[ch];
        }
        if (tmp > maxScore) {
            word = it;
            maxScore = tmp;
        }
    }
    if(word.empty() )
        cout<<"invalid word"<<endl;
    else
        cout<<word<<endl;


    return 0;
}
