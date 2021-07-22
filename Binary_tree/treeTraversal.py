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

    def preOrderTraversal(self, root, result):
        if root:
            result.append(root.val)
            self.preOrderTraversal(root.left, result)
            self.preOrderTraversal(root.right, result)
        return result

    def postorderTraversal(self, root, result):
        if root:
            self.postorderTraversal(root.left, result)
            self.postorderTraversal(root.right, result)
            result.append(root.val)
        return result

    def inorderTraversal(self, root, result):
        if root:
            self.inorderTraversal(root.left, result)
            result.append(root.val)
            self.inorderTraversal(root.right, result)
        return result

tree = Node(10)
child1 = Node(20)
child2 = Node(30)

tree.right = child1
child1.left = child2

S = Solution()
S.print_tree_values(tree)
result = []
print(S.preOrderTraversal(tree, result))
result = []
print(S.inorderTraversal(tree, result))
result = []
print(S.postorderTraversal(tree, result))