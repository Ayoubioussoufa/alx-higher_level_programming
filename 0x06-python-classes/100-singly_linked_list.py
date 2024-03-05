#!/usr/bin/python3
class Node:
    def __init__(self, data, next_node=None):
        self._data = data
        self._next_node = next_node
    
    @property
    def data(self):
        return self._data
    
    @data.setter
    def data(self, value):
        if not isinstance(value, int):
            raise TypeError("data must be an integer")
        self._data = value
    
    @property
    def next_node(self):
        return self._next_node
    
    @next_node.setter
    def next_node(self, value):
        if not isinstance(value, Node) and value != None:
            raise TypeError("next_node must be a Node object")
        self._next_node = value


class SinglyLinkedList(Node):
    def __init__(self):
        self._head = None

    def sorted_insert(self, value):
        new = Node(value)
        if self._head is None:
            new.next_node = None
            self._head = new
        elif self._head.data > value:
            new.next_node = self._head
            self._head = new
        else:
            tmp = self._head
            while (tmp.next_node is not None and
                    tmp.next_node.data < value):
                tmp = tmp.next_node
            new.next_node = tmp.next_node
            tmp.next_node = new

    def __str__(self):
        values = []
        tmp = self._head
        while tmp is not None:
            values.append(str(tmp.data))
            tmp = tmp.next_node
        return ('\n'.join(values))