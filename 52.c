class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


# Build tree from level order input
def build_tree(arr):
    if not arr or arr[0] == -1:
        return None

    root = Node(arr[0])
    queue = [root]
    i = 1

    while queue and i < len(arr):
        curr = queue.pop(0)

        # Left child
        if arr[i] != -1:
            curr.left = Node(arr[i])
            queue.append(curr.left)
        i += 1

        if i >= len(arr):
            break

        # Right child
        if arr[i] != -1:
            curr.right = Node(arr[i])
            queue.append(curr.right)
        i += 1

    return root


# LCA function
def find_lca(root, n1, n2):
    if root is None:
        return None

    if root.data == n1 or root.data == n2:
        return root

    left = find_lca(root.left, n1, n2)
    right = find_lca(root.right, n1, n2)

    if left and right:
        return root

    return left if left else right


# ---- Input ----
n = int(input())
arr = list(map(int, input().split()))
n1, n2 = map(int, input().split())

root = build_tree(arr)
lca = find_lca(root, n1, n2)

print(lca.data)
