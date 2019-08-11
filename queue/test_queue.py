import unittest

from queue import Queue


class TestQueue(unittest.TestCase):
    """test queue"""

    def setUp(self):
        self.queue = Queue()

    def test_queue_length_attr(self):
        self.assertEqual(self.queue.length, 0, 'the length attr error!')

    def test_put_action(self):
        self.queue.put(1)
        self.assertEqual(self.queue.length, 1, 'put method error!')
        self.queue.put(2)
        self.assertEqual(self.queue.length, 2, 'put 2 element shuold 2')

    def test_get_action(self):
        self.queue.put(1)
        value = self.queue.get()
        self.assertEqual(value, 1, 'get value should be 1')

    def test_get_empty_queue(self):
        value = self.queue.get()
        self.assertIsNone(value, 'the result of getting empty queue should be\
             None')
