import unittest
from unittest import mock
from matches_equation import calc_nums, main, digital_num


class TestMatchEqution(unittest.TestCase):
    """test match equation"""

    def test_calc_nums_one_number(self):
        for test_num in range(10):
            self.assertEqual(calc_nums(test_num), digital_num[test_num])

    def test_calc_nums_mult_number(self):
        self.assertEqual(calc_nums(1234), 16)
        self.assertEqual(calc_nums(11111), 10)
        self.assertEqual(calc_nums(14), 6)

    @mock.patch('builtins.print')
    def test_main(self, mock_print):
        main()
        mock_print.assert_called_with('11 + 0 = 11')
