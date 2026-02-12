class MinStack(object):

    def __init__(self):
        self.stack = [] # (val, min_so_far)

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        if not self.stack:
            cur_min = val
        else:
            cur_min = min(self.stack[-1][1], val)
        self.stack.append((val, cur_min))

    def pop(self):
        """
        :rtype: None
        """
        self.stack.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1][0]

    def getMin(self):
        """
        :rtype: int
        """
        return self.stack[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()