#include "000.config.h"

class MinStack
{
  public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        container.push(x);
        if (min.empty() || x <= getMin())
            min.push(x);
    }
    void pop()
    {
        if (container.top() == getMin())
            min.pop();
        container.pop();
    }
    int top()
    {
        return container.top();
    }
    int getMin()
    {
        return min.top();
    }

  private:
    stack<int> container;
    stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */