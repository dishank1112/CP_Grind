class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def add(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node

    def print_list(self):
        temp = self.head
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("None")

    def delete_nth(self, n):
        if not self.head:
            raise Exception("Cannot delete from an empty list.")
        if n <= 0:
            raise Exception("Invalid index.")
        if n == 1:
            self.head = self.head.next
            return
        temp = self.head
        for _ in range(n - 2):
            if not temp.next:
                raise Exception("Index out of range.")
            temp = temp.next
        if not temp.next:
            raise Exception("Index out of range.")
        temp.next = temp.next.next

ll = LinkedList()
ll.add(10)
ll.add(20)
ll.add(30)
ll.add(40)
ll.print_list()
ll.delete_nth(3)
ll.print_list()
