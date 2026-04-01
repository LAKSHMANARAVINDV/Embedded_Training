#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

vector<string> findRepeatedWords(string sentence) {
    vector<string> repeated;
    regex pattern("\\b(\\w+)\\s+\\1\\b", regex::icase);
    sregex_iterator iter(sentence.begin(), sentence.end(), pattern);
    sregex_iterator end;
    
    while (iter != end) {
        repeated.push_back(iter->str());
        iter++;
    }
    
    return repeated;
}

int main() {
    cout << "=== Detect Repeated Words in Sentence ===" << endl << endl;
    
    vector<string> sentences = {
        "the the cat sat on the mat",
        "hello hello world",
        "This is is a a test",
        "She said she she will come",
        "No repeated words here",
        "the The same word different case",
        "I went went to the store store",
        "Error error occurred occurred in the the system"
    };
    
    for (string sentence : sentences) {
        cout << "Sentence: \"" << sentence << "\"" << endl;
        vector<string> repeated = findRepeatedWords(sentence);
        if (repeated.empty()) {
            cout << "No repeated words found" << endl;
        } else {
            cout << "Repeated words: ";
            for (int i = 0; i < repeated.size(); i++) {
                cout << "\"" << repeated[i] << "\"";
                if (i < repeated.size() - 1) cout << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}
