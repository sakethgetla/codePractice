## # imports
## from typing import List
## from typing import Optional
## from treeNode import TreeNode
## from listNode import ListNode
## 
## 
## # t = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
## # t = TreeNode(1, None, TreeNode(2))
## 
## a = 1
## b = 2
## 
## print(a, b)
## 
## a, b = b, a
## print(a, b)
## 
## 
## s = set()
## s.add(1)
## s.add(2)
## s.add(4)
## print(s, 4 not in s, 4 in s)
## 
## 
## s = Solution()
## n = 20
## o = s.guessNumber(n)
## print (n, o)
## assert o ==


import unittest

class TestStringMethods(unittest.TestCase):

    def test_upper(self):
        self.assertEqual('foo'.upper(), 'FOO')

    def test_isupper(self):
        self.assertTrue('FOO'.isupper())
        self.assertFalse('Foo'.isupper())

    def test_split(self):
        s = 'hello world'
        self.assertEqual(s.split(), ['hello', 'world'])
        # check that s.split fails when the separator is not a string
        with self.assertRaises(TypeError):
            s.split(2)

if __name__ == '__main__':
    unittest.main()
