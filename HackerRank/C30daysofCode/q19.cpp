#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
    //Write your code here
    private:
    stack<char> m_stack;
    queue<char> m_queue;

    public:
    Solution()
    {
        m_stack = std::stack<char>();
        m_queue = std::queue<char>();
    }

    char popCharacter()
    {
       char ch = m_stack.top(); 
       m_stack.pop();
      return ch;
    }

    void pushCharacter(char ch)
    {
        m_stack.push(ch);
    }

    void enqueueCharacter(char ch)
    {
        m_queue.push(ch);
    }

    char dequeueCharacter()
    {
        char ch;
       ch =  m_queue.front();
       m_queue.pop();
       return ch;
    }

};

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}