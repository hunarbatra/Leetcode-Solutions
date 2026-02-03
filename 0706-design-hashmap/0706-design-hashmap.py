class MyHashMap:

    def __init__(self):
        self.h = {}

    def put(self, key: int, value: int) -> None:
        self.h[key] = value

    def get(self, key: int) -> int:
        if key not in self.h:
            return -1
        return self.h[key]

    def remove(self, key: int) -> None:
        if key in self.h:  
            del self.h[key]


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)