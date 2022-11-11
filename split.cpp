#include <iostream>
#include <vector>
#include <sstream>
#include <string>


using namespace std;

const vector<string> split(const string &str, const char &delimiter) {
    vector<string> result;
    stringstream ss(str);
    string tok;

    while (getline(ss, tok, delimiter)) {
        result.push_back(tok);
    }
    return result;
}

int main() {
    string str ="";
    while(cin>>str){
        vector<string> ret = split(str, ' ');
        for (auto& s : ret) {
            cout << s << "\n";
        }
    }
    return 0;
}