#include <iostream>
#include <stack>
#include <queue>
#include <cctype>
#include <string>
using namespace std;

bool isPalindrome(const string& input) {
    stack<char> s;
    queue<char> q;

    for (char c : input) {
        if (isalnum(c)) {
            char lowerChar = tolower(c);
            s.push(lowerChar);
            q.push(lowerChar);
        }
    }

    while (!s.empty()) {
        if (s.top() != q.front()) {
            return false; 
        }
        s.pop();
        q.pop();
    }

    return true; 
}

int main() {
    cout << boolalpha; 
    cout << "Is 'racecar' a palindrome? " << isPalindrome("racecar") << endl;
    cout << "Is 'hello' a palindrome? " << isPalindrome("hello") << endl;
    cout << "Is 'A man, a plan, a canal, Panama' a palindrome? " << isPalindrome("A man, a plan, a canal, Panama") << endl;

    return 0;
}
