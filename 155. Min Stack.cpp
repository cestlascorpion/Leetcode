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
        //如果压入的元素大于当前min栈中的元素不需要存储它的相关信息
        //在考虑pop出最小值，需要更新min值的问题上，
        //pop出最小值前会把元素x先pop出去（元素x在栈顶）
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