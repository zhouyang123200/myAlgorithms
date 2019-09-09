import unittest
from all_seq_permutation import all_seq_permutation


class TestPermutation(unittest.TestCase):
    """test permutation"""

    def test_permutation_of_1_and_0(self):
        self.assertEqual(all_seq_permutation(1), 1, '1! = 1')
        self.assertEqual(all_seq_permutation(0), 0)

    def test_permutation_other_num(self):
        self.assertEqual(all_seq_permutation(3), 6)
        self.assertEqual(all_seq_permutation(5), 120)
