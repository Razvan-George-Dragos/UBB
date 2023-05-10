from repository import Board
import random
class Service():
    def __init__(self):
        self.__repo=Board()
        self.__player=0
    def move(self,x,player):
        """calls the function move from the repository"""
        self.__repo.move(x,player)
        self.__player=player
    def print(self,k):
        """returns a line of the matrix in order to print it"""
        return self.__repo.__str__()
    def is_over(self):
        """checks if someone won"""
        return self.__repo.check_win()
    def check_move(self,pos):
        """checks if the move can be made"""
        return self.__repo.possible_move(pos)
    def computer(self):
        """
        this function works as a computer player and chooses where to move
        """
        ok=False
        x=self.__repo.computer_win_line()
        if x==-1:
            x=self.__repo.computer_win_line_between()
        if x==-1:
            x=self.__repo.computer_win_coloumn()
        if x==-1:
            x=self.__repo.computer_win_main_diag()
        if x==-1:
            x=self.__repo.computer_win_sec_diag()
        if x==-1:
            x=self.__repo.computer_win_main_diag_between()
        if x==-1:
            x=self.__repo.computer_win_sec_diag_between()
        if x==-1:
            print("random")
            while ok==False:
                x=random.randint(0,6)
                ok=self.__repo.possible_move(x)
        self.__repo.move(x,2)
        self.__player=2
    def no_winner(self):
        """checks if the board is full"""
        return self.__repo.end_of_game()
    def condition(self,x):
        if x.isdecimal()==False:
            return False
        else:
            x=int(x)
            if x<1 or x>7:
                return False
        return True



