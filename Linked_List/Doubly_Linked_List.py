class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None

class Singly_linked_list:
    def __init__(self):
        self.head_value = None

    def print_list(self):
        node = self.head_value
        while node is not None:
            print(node.val)
            node = node.next

list1 = Singly_linked_list()
list1.head_value = Node("Mon")
element2 = Node("Tue")
element3 = Node("Wed")

# Link element1 to list1
list1.head_value.next = element2
element2.next = element3

element2.prev = list1.head_value
element3.prev = element2

list1.print_list()