class Twitter:

    def __init__(self):
        self.time = 0
        self.tweets = defaultdict(list) # userId -> list of (time, tweetId)
        self.follows = defaultdict(set) # followerId -> set of followeeIds

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.time += 1
        self.tweets[userId].append((self.time, tweetId))

    def getNewsFeed(self, userId: int) -> List[int]:
        people = set(self.follows[userId])
        people.add(userId)

        heap = [] # max heap

        for p in people:
            arr = self.tweets[p]
            if arr:
                idx = len(arr) - 1
                t, tid = arr[idx]
                heapq.heappush(heap, (-t, tid, p, idx))

        res = []
        while heap and len(res) < 10:
            neg_t, tid, p, idx = heapq.heappop(heap)
            res.append(tid)

            # push this person's next older tweet
            idx -= 1
            if idx >= 0:
                t, tid2 = self.tweets[p][idx]
                heapq.heappush(heap, (-t, tid2, p, idx))

        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId != followeeId:
            self.follows[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId in self.follows:
            self.follows[followerId].remove(followeeId)
        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)