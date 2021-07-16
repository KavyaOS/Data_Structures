class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def print_tree_values(self, root):
        if root is None:
            return root
        self.print_tree_values(root.left)
        print(root.val)
        self.print_tree_values(root.right)

tree = Node(10)
child1 = Node(20)
child2 = Node(30)

tree.right = child1
child1.left = child2

Solution().print_tree_values(tree)