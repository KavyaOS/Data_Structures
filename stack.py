class Stack:
    def __init__(self):
        self.stack = []

    def add(self, item):
        if item not in self.stack:
            self.stack.append(item)
            return True
        else:
            return False

    def peek(self):
        return self.stack[-1]

A_Stack = Stack()
print(A_Stack.add(10))
print(A_Stack.add(20))
print(A_Stack.peek())
