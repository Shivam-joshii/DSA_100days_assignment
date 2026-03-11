heap = []

def heapify_up(i):
    while i > 0 and heap[(i-1)//2] > heap[i]:
        p = (i-1)//2
        heap[p], heap[i] = heap[i], heap[p]
        i = p

def heapify_down(i):
    n = len(heap)
    while True:
        smallest = i
        left = 2*i + 1
        right = 2*i + 2

        if left < n and heap[left] < heap[smallest]:
            smallest = left
        if right < n and heap[right] < heap[smallest]:
            smallest = right

        if smallest != i:
            heap[i], heap[smallest] = heap[smallest], heap[i]
            i = smallest
        else:
            break

def insert(x):
    heap.append(x)
    heapify_up(len(heap)-1)

def extractMin():
    if len(heap) == 0:
        print(-1)
        return
    print(heap[0])
    heap[0] = heap[-1]
    heap.pop()
    if heap:
        heapify_down(0)

def peek():
    if len(heap) == 0:
        print(-1)
    else:
        print(heap[0])

n = int(input())

for _ in range(n):
    op = input().split()

    if op[0] == "insert":
        insert(int(op[1]))
    elif op[0] == "extractMin":
        extractMin()
    elif op[0] == "peek":
        peek()
