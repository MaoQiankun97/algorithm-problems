class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        if root is None:
            return 0

        result = 0
        queue_size = 10000
        queue = [root] * queue_size
        front = 0
        rear = 0
        queue[rear] = root
        rear = (rear + 1) % queue_size
        while front != rear:
            top = queue[front]
            front = (front + 1) % queue_size
            if top.left is not None:
                queue[rear] = top.left
                rear = (rear + 1) % queue_size
            if top.right is not None:
                queue[rear] = top.right
                rear = (rear + 1) % queue_size

            if top.val % 2 == 0:
                if top.left is not None:
                    if top.left.left is not None:
                        result += top.left.left.val
                    if top.left.right is not None:
                        result += top.left.right.val

                if top.right is not None:
                    if top.right.left is not None:
                        result += top.right.left.val
                    if top.right.right is not None:
                        result += top.right.right.val

        return result


root = TreeNode(61)
root.left = TreeNode(13)
root.right = TreeNode(46)
root.right.right = TreeNode(56)
root.right.right.left = TreeNode(72)
a = Solution()
print(a.sumEvenGrandparent(root))
