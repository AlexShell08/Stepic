#include <iostream>
#include <string>

using namespace std;

int main()
{

    string text, pattern;
    long long hashPattern = 0, hashText = 0;
    cin >> pattern;
    cin >> text;

    for(int i = 0; i < text.size(); i++){
        if(i <  pattern.size()){
            hashPattern += static_cast<long long>(pattern[i]);
            hashText +=  static_cast<long long>(text[i]);
        }
        else{
            hashText +=  static_cast<long long>(text[i]) -
                        static_cast<long long>(text[i - pattern.size()]);
        }
        if(i >= pattern.size() - 1 && hashText == hashPattern){
            if(pattern == text.substr(i - (pattern.size() - 1), pattern.size()))
                cout << i - (pattern.size() - 1) << " ";
        }
    }

    return 0;
}
