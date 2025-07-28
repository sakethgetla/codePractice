import unittest
import random
from listNode import ListNode


class TestListNode(unittest.TestCase):

    # def test_sum(self):
    #     self.assertEqual(1, 5, "test")

    def test_equality(self):
        n1 = int(random.random() * 1000)
        n2 = n1
        n3 = int(random.random() * 1000)

        l1 = ListNode.createListFromNum(n1)
        l2 = ListNode.createListFromNum(n2)
        l3 = ListNode.createListFromNum(n3)

        self.assertTrue(ListNode.equal(l1, l2), "t1")
        self.assertTrue(l1 == l2, "test")

        self.assertFalse(ListNode.equal(l1, l3), "t1")
        self.assertFalse(l1 == l3, "test")

        self.assertEqual(l1, l2, "test")
        self.assertNotEqual(l1, l3, "test")

if __name__ == "__main__":
    unittest.main()
