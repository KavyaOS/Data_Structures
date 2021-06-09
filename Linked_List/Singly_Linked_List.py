class Node:
    def __init__(self, data_value=None):
        self.data_value= data_value
        self.nextval = None

class Singly_linked_list:
    def __init__(self):
        self.head_value = None

list1 = Singly_linked_list()
list1.head_value = Node("Mon")
element2 = Node("Tue")
element3 = Node("Wed")

# Link element1 to list1
list1.head_value.nextval = element2

#Link element2 to list1
list1.head_value.nextval = element3
