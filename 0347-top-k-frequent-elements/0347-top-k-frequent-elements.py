from heapq import heapify, heappop, heappush
from collections import defaultdict

class Solution:
    def topKFrequent1(self, nums: List[int], k: int) -> List[int]: # Max Heap: O(k log(n))
        count = Counter(nums)
        max_heap = [[-c, n] for n, c in count.items()]
        heapify(max_heap) # O(n)
        return [heappop(max_heap)[1] for i in range(k)]

    def topKFrequent(self, nums: List[int], k: int) -> List[int]: # Min Heap: O(k log(n))
        count = Counter(nums)
        min_heap = []
        for n, c in count.items():
            if len(min_heap) < k:
                heappush(min_heap, [c, n])
            elif len(min_heap) == k and min_heap[0][0] < c:
                heappop(min_heap)
                heappush(min_heap, [c, n])

        return [heappop(min_heap)[1] for i in range(k)]

# class Solution:
    # def topKFrequent(self, nums: List[int], k: int) -> List[int]: # Max Heap: O(k log(n))
    #     count = defaultdict(int)

    #     for n in nums: # O(n)
    #         count[n] += 1

    #     max_heap = [[-c, n] for n, c in count.items()]
    #     heapify(max_heap) # O(n)

    #     return [heappop(max_heap)[1] for i in range(k)]
        
    # def topKFrequent(self, nums: List[int], k: int) -> List[int]: # Min Heap: O(n log(k))-- more efficient if k<<n
    #     count = defaultdict(int)

    #     for n in nums:
    #         count[n] += 1

    #     min_heap = []

    #     for n, c in count.items():
    #         if len(min_heap) < k:
    #             heappush(min_heap, [c, n])
    #         elif len(min_heap) == k and min_heap[0][0] < c:
    #             heappop(min_heap)
    #             heappush(min_heap, [c, n])

    #     return [heappop(min_heap)[1] for i in range(k)]
    
    
    # def topKFrequent(self, nums: List[int], k: int) -> List[int]: # Bucket Sort O(n) (credits to NeetCode https://www.youtube.com/embed/YPTqKIgVk-k)
    #     count = defaultdict(int)
    #     freq_bucket = [[] for i in range(len(nums)+1)] # freq -> [nums]
    #     # freq_bucket is of size len(nums) + 1, to have 0...n freq buckets, 
    #     # so we can simply check for freq[i] instead of freq[i-1]

    #     for n in nums:
    #         count[n] += 1

    #     for n, c in count.items():
    #         freq_bucket[c].append(n)

    #     result = []

    #     for i in range(len(freq_bucket)-1, 0, -1):
    #         for n in freq_bucket[i]:
    #             result.append(n)
    #             if len(result) == k:
    #                 return result
