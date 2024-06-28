#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      vector<int> stack;
      for (auto current_asteroid:asteroids) {
        bool should_add_to_stack = true;
        while(!stack.empty() && stack.back() > 0 && current_asteroid < 0) {
          if (abs(current_asteroid) > stack.back()) {
            stack.pop_back();
          } else if (abs(current_asteroid) < stack.back()) {
            /// do nothing
            should_add_to_stack = false;
            break;
          } else {
            /// both explode
            stack.pop_back();
            should_add_to_stack = false;
            break;
          }
        }
        if (should_add_to_stack) {
          stack.push_back(current_asteroid);
        }
      }
      return stack;
    }
};
