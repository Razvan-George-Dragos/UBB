import unittest
from repository import Board
from sevice import Service

class MyTestCase(unittest.TestCase):
    def setUp(self):
        self.__rep=Board()
        self.__rep.move(1,1)
        self.__rep.move(2,1)
        self.__rep.move(3,1)
        self.__rep.move(2,1)
        self.__rep.move(3,1)
    def test_possible_move(self):
        self.assertTrue(self.__rep.possible_move(5))
        self.__rep.move(2, 1)
        self.__rep.move(2, 1)
        self.__rep.move(2, 1)
        self.__rep.move(2, 1)
        self.assertFalse(self.__rep.possible_move(2))
    def test_end_of_game(self):
        self.assertFalse(self.__rep.end_of_game())
        self.__rep.move(2, 1)
        self.__rep.move(2, 1)
        self.__rep.move(2, 1)
        self.__rep.move(2, 1)
        self.__rep.move(1, 1)
        self.__rep.move(1, 1)
        self.__rep.move(1, 1)
        self.__rep.move(1, 1)
        self.__rep.move(1, 1)
        self.__rep.move(3, 1)
        self.__rep.move(3, 1)
        self.__rep.move(3, 1)
        self.__rep.move(3, 1)
        self.__rep.move(4, 1)
        self.__rep.move(4, 1)
        self.__rep.move(4, 1)
        self.__rep.move(4, 1)
        self.__rep.move(4, 1)
        self.__rep.move(4, 1)
        self.__rep.move(5, 1)
        self.__rep.move(5, 1)
        self.__rep.move(5, 1)
        self.__rep.move(5, 1)
        self.__rep.move(5, 1)
        self.__rep.move(5, 1)
        self.__rep.move(6, 1)
        self.__rep.move(6, 1)
        self.__rep.move(6, 1)
        self.__rep.move(6, 1)
        self.__rep.move(6, 1)
        self.__rep.move(6, 1)
        self.__rep.move(0, 1)
        self.__rep.move(0, 1)
        self.__rep.move(0, 1)
        self.__rep.move(0, 1)
        self.__rep.move(0, 1)
        self.__rep.move(0, 1)
        self.assertTrue(self.__rep.end_of_game())
    def test_for_printing(self):
        l=[]
        l=self.__rep.for_printing(1)
        self.assertEqual(len(l),7)
    def test_check_win_line(self):
        self.assertFalse(self.__rep.check_win_line())
        self.assertFalse(self.__rep.check_win())
        self.__rep.move(4, 1)
        self.assertTrue(self.__rep.check_win_line())
        self.assertTrue(self.__rep.check_win())
    def test_check_win_coloumn(self):
        self.assertFalse(self.__rep.check_win_coloumn())
        self.assertFalse(self.__rep.check_win())
        self.__rep.move(2, 1)
        self.__rep.move(2, 1)
        self.assertTrue(self.__rep.check_win_coloumn())
        self.assertTrue(self.__rep.check_win())
    def test_check_win_sec_diag(self):
        self.assertFalse(self.__rep.check_win_secdiag())
        self.assertFalse(self.__rep.check_win())
        self.__rep.move(3, 1)
        self.__rep.move(4, 2)
        self.__rep.move(4, 1)
        self.__rep.move(4, 1)
        self.__rep.move(4, 1)
        self.assertTrue(self.__rep.check_win_secdiag())
        self.assertTrue(self.__rep.check_win())
    def test_check_win_main_diag(self):
        self.assertFalse(self.__rep.check_win_maindiag())
        self.assertFalse(self.__rep.check_win())
        self.__rep.move(1, 2)
        self.__rep.move(1, 1)
        self.__rep.move(1, 1)
        self.__rep.move(2, 1)
        self.__rep.move(4, 1)
        self.assertTrue(self.__rep.check_win_maindiag())
        self.assertTrue(self.__rep.check_win())
    def test_computer_win_line(self):
        self.assertEqual(self.__rep.computer_win_line(),0)
    def test_computer_win_coloumn(self):
        self.assertEqual(self.__rep.computer_win_coloumn(),-1)
        self.__rep.move(2, 1)
        self.assertEqual(self.__rep.computer_win_coloumn(),2)
    def test_computer_win_main_Diag(self):
        self.assertEqual(self.__rep.computer_win_main_diag(),-1)
        self.__rep.move(1, 2)
        self.__rep.move(1, 1)
        self.__rep.move(1, 1)
        self.__rep.move(2, 1)
        self.assertEqual(self.__rep.computer_win_main_diag(),4)
    def test_computer_win_line_between(self):
        self.assertEqual(self.__rep.computer_win_line_between(),-1)
        self.__rep.move(5,1)
        self.assertEqual(self.__rep.computer_win_line_between(),4)
    def test_computer_win_main_between(self):
        self.assertEqual(self.__rep.computer_win_main_diag_between(),-1)
        self.__rep.move(0, 2)
        self.__rep.move(0, 2)
        self.__rep.move(0, 2)
        self.__rep.move(0, 1)
        self.__rep.move(1, 2)
        self.assertEqual(self.__rep.computer_win_main_diag_between(),1)
    def test_comp_sec_diag(self):
        self.assertEqual(self.__rep.computer_win_sec_diag(),-1)
        self.__rep.move(4, 2)
        self.__rep.move(4, 2)
        self.__rep.move(4, 2)
        self.__rep.move(3, 1)
        self.assertEqual(self.__rep.computer_win_sec_diag(), 4)
    def test_comp_win_sec_diag_between(self):
        self.assertEqual(self.__rep.computer_win_sec_diag_between(), -1)
        self.__rep.move(4, 2)
        self.__rep.move(4, 2)
        self.__rep.move(4, 2)
        self.__rep.move(4, 1)
        self.assertEqual(self.__rep.computer_win_sec_diag_between(), 3)

class MyTest(unittest.TestCase):
    def setUp(self):
        self.__srv=Service()
    def test_condition(self):
        self.assertFalse(self.__srv.condition("aaa"))
        self.assertTrue(self.__srv.condition("5"))









