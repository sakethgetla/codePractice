# Definition for a binary tree node.
class TreeNode:
    # que = []
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
    # print in root, left, right format
    def __str__(self):
        q = [self]
        s = ''
        while (len(q) > 0):
            currNode = q.pop(0)
            if currNode != None:
                q.append(currNode.left)
                q.append(currNode.right)

            # if currNode.left != None:
            #     q.append(currNode.left)
            #
            # if currNode.right != None:
            #     q.append(currNode.right)
            #
            s += str( currNode.val  ) + ', ' if currNode else 'None, '
        return s

# # def printTree(t: TreeNode) -> List[int]:
# def printTree(t: TreeNode) -> str:
#     q = [t]
#     s = ''
#     while (len(q) > 0):
#         currNode = q.pop(0)
#         if currNode.right != None:
#             q.append(currNode.right)
#
#         if currNode.left != None:
#             q.append(currNode.left)
#
#         s += currNode.val
#     return s
