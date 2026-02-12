class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        n = len(tasks)
        arr = [(tasks[i][0], tasks[i][1], i) for i in range(n)]
        arr.sort()

        heap = [] # (processing_time, idx)
        res = []
        t = 0
        i = 0

        while i < n or heap:
            # if nothing is available, jump to the next enqueue time
            if not heap and t < arr[i][0]:
                t = arr[i][0]

            # add all tasks that have arrived by time t
            while i < n and arr[i][0] <= t:
                enqueue, proc, idx = arr[i]
                heapq.heappush(heap, (proc, idx))
                i += 1

            proc, idx = heapq.heappop(heap)
            res.append(idx)
            t += proc

        return res
            