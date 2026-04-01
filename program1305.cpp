#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

vector<string> extractHashtags(string text) {
    vector<string> hashtags;
    regex pattern("#[a-zA-Z0-9_]+");
    sregex_iterator iter(text.begin(), text.end(), pattern);
    sregex_iterator end;
    
    while (iter != end) {
        hashtags.push_back(iter->str());
        iter++;
    }
    
    return hashtags;
}

int main() {
    cout << "=== Extract Hashtags from Social Media Post ===" << endl << endl;
    
    vector<string> posts = {
        "Just finished #coding #cpp #programming",
        "Beautiful sunset #nature #photography #nofilter",
        "#Motivational Monday with #DailyInspiration and #GoalSetting",
        "No hashtags here",
        "#single",
        "#multiple #hashtags #in #different #places #everywhere",
        "Check out #GitHub and #GitLab for #OpenSource projects",
        "#CppProgramming #Algorithms #DataStructures #Interview #Preparation"
    };
    
    for (string post : posts) {
        cout << "Post: \"" << post << "\"" << endl;
        vector<string> tags = extractHashtags(post);
        cout << "Hashtags found: " << tags.size() << endl;
        for (string tag : tags) {
            cout << "  " << tag << endl;
        }
        cout << endl;
    }
    
    return 0;
}
