from collections import defaultdict
from heapq import *
import itertools
import math


class PQueue:
    def __init__(self):
        self.pq = []                         # list of entries arranged in a heap
        self.entry_finder = {}               # mapping of tasks to entries
        self.REMOVED = '<removed-task>'      # placeholder for a removed task
        self.counter = itertools.count()     # unique sequence count

    def add_task(self, task, priority=0):
        'Add a new task or update the priority of an existing task'
        if task in self.entry_finder:
            self.remove_task(task)
        count = next(self.counter)
        entry = [priority, count, task]
        self.entry_finder[task] = entry
        heappush(self.pq, entry)

    def remove_task(self, task):
        'Mark an existing task as REMOVED.  Raise KeyError if not found.'
        entry = self.entry_finder.pop(task)
        entry[-1] = self.REMOVED

    def pop_task(self):
        'Remove and return the lowest priority task. Raise KeyError if empty.'
        while self.pq:
            priority, count, task = heappop(self.pq)
            if task is not self.REMOVED:
                del self.entry_finder[task]
                return task
        raise KeyError('pop from an empty priority queue')


def g(adj, n, m):
    MAX_WEIGHT = math.inf
    dist = {1: 0}

    Q = PQueue()

    for v in range(1, n + 1):
        if v != 1:
            dist[v] = MAX_WEIGHT
        Q.add_task(v, dist[v])

    while True:
        try:
            # print(Q.pq)
            u = Q.pop_task()
            for v, w in adj[u]:
                alt = dist[u] + w
                if alt < dist[v]:
                    dist[v] = alt
                    Q.add_task(v, alt)
        except KeyError:
            break

    return dist


def main():
    adj = defaultdict(list)

    n, m = [int(x) for x in input().split()]

    for _ in range(m):
        a, b, c = [int(x) for x in input().split()]
        adj[a].append((b, c))

    result = g(adj, n, m)

    print(" ".join(
        str(result[i])
        for i in range(1, n + 1)
    ))


main()
