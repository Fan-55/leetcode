#include <vector>

using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
      stack.push_back(x);
    }

    int pop() {
      int front =  stack.front();
      stack.erase(stack.begin());
      return front;
    }

    int peek() {
      return stack.front();
    }

    bool empty() {
      return stack.size() <= 0;
    }
private:
    vector<int> stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 