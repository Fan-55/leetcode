#include <vector>

using namespace std;

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
      stack.push_back(val);
      if (min_stack.empty()) {
        min_stack.push_back(val);
      } else {
        int current_min = min_stack.back();
        if (val < current_min) {
          min_stack.push_back(val);
        } else {
          min_stack.push_back(current_min);
        }
      }
    }

    void pop() {
      stack.pop_back();
      min_stack.pop_back();
    }

    int top() {
      int back = stack.back();
      return back;
    }

    int getMin() {
      return min_stack.back();
    }

private:
    vector<int> stack;
    vector<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 