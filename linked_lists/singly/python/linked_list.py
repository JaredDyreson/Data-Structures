#!/usr/bin/env python3.8
import time

class Node():
    def __init__(self, value):
        self.value = value
        self.next = None
    def __repr__(self):
        return f'{self.value}'

    def __eq__(self, other):
        return self.value == other.value
    def __le__(self, other):
        return self.value < other.value

class LinkedList():
    def __init__(self, head=None, tail=None):
        self.head = head
        self.tail = tail
        self.size = 0

    """
    Accessors
    """

    def front(self):
        return self.head.value

    def back(self):
        return self.back.value
    
    """
    Capacity   
    """

    def empty(self) -> bool:
        return (self.size == 0)

    def size_(self) -> int:
        return self.size

    """
    Modifiers
    """

    def pop(self):
        current = self.head
        if(current):
            self.head = current.next
            self.size-=1

    def clear(self):
        while(not self.empty()):
            self.pop()

    def add_front(self, node: Node):
        if not(isinstance(node, Node)):
            raise ValueError
        if not(self.head):
            self.head = self.tail = node
            return
        current = self.head
        while(current.next):
            current = current.next
        current.next = node
        self.tail = current.next
        self.size+=1

    def insert_at(self, index: int, node: Node):
        if not(isinstance(node, Node)):
            raise ValueError
        if not(self.head):
            self.head = node
            return

        current = self.head
        while(current.next and (current.value != index)):
            current = current.next

        node.next = current.next
        current.next = node
        self.size+=1

    def print_list(self, node: Node):
        if not(node):
            print()
            return
        print(f'{node.value} ', end='')
        return self.print_list(node.next)

    def sum_list(self) -> int:
        if not(self.head):
            return 0
        current = self.head
        counter = 0
        while(current):
           counter+=(current.value) 
           current = current.next
        return counter

    def find_node(self, index: int):
        if not(self.head):
            return None
        current = self.head
        while(current and current.value != index):
            current = current.next

        return None if (current is None) else current

    def sum_list_recurse_api(self, node: Node):
        if not(node):
            return 0
        return node.value + self.sum_list_recurse_api(node.next)

    def sum_list_recurse(self):
        """
        This solution takes longer because it utilizes recursion
        """

        self.sum_list_recurse_api(self.head)

    def remove(self, index: int):
        if not(isinstance(index, int)):
            raise ValueError
        current = self.head
        if(current):
            if(current.value == index):
                self.head = current.next
                current = None
                self.size-=1
                return
        while(current):
            if(current.value == index):
                break
            previous = current
            current = current.next
        if not(current):
            return
        previous.next = current.next
        self.size-=1

def time_function(func):
    
    tic = time.perf_counter()
    func()
    toc = time.perf_counter()
    print(f'{func.__name__} took {toc - tic:0.4f} seconds')
    # time_function(L.sum_list_recurse)
    # time_function(L.sum_list)

def main():

    L.insert_at(3, Node(69))
    result = L.find_node(Node(1))
    print(result)

L = LinkedList()
for x in [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]:
    L.add_front(Node(x))
L.clear()
print(L.tail)
# for x in range(0, 10):
    # L.remove(x)
    # L.print_list(L.head)
