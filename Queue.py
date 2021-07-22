class Queue:
    def __init__(self) -> None:
        self.queue = list()

    def add_to_queue(self, item):
        if item not in self.queue:
            self.queue.insert(0, item)
            return True
        return False

    def fetch_from_queue(self):
        if len(self.queue) > 0:
            return self.queue.pop()
        return ("No Elements in the queue")

queue = Queue()
print(queue.fetch_from_queue())
print(queue.add_to_queue(10))
print(queue.add_to_queue(20))
print(queue.add_to_queue(30))
print(queue.fetch_from_queue())