from texttable import Texttable
class Board:
    def __init__(self):
        self.__field = [[0]*7 for i in range(6)]
    def __str__(self):
        t = Texttable()
        header_row = ['/']
        for i in range(7):
            header_row.append(chr(65+i))
        t.header(header_row)

        for i in range(6):

            display_row = [i]
            for j in range(7):
                val = self.__field[i][j]
                if val == 0:
                    display_row.append(' ')
                else:
                    display_row.append(val)
            t.add_row(display_row)

        return t.draw()
    def move(self,pos,player):
        """
        function to make a move
        :param pos: the position
        :param player: the player(user/computer)
        """
        i = 5
        while i >= 0:
            if self.__field[i][pos] == 0:
                self.__field[i][pos] = player
                i = -2
            i -= 1
    def possible_move(self,pos):
        """
        :param pos:the position
        :return: True if the move can be made, False if not
        """
        if self.__field[0][pos]!=0:
            return False
        return True
    def end_of_game(self):
        """
        :return:True if the board is full, False if not
        """
        i=0
        for j in range(7):
            if self.__field[i][j]==0:
                return False
        return True
    def for_printing(self,k):
        """
        used to print the matrix
        """
        l=[]
        for i in range(6):
            for j in range(7):
                if i==k:
                    l.append(self.__field[i][j])
        return l
    def __getitem__(self,i,j):
        return self.__field[i][j]
    def check_win_line(self):
        """
        checks if there are 4 elements on the same line which are consecutive and with the same value
        """
        for i in range(6):
            j=0
            while j<=3:
                if self.__field[i][j]==self.__field[i][j+1] and self.__field[i][j]==self.__field[i][j+2] and self.__field[i][j]==self.__field[i][j+3] and self.__field[i][j]!=0:
                    return True
                j+=1
        return False
    def check_win_coloumn(self):
        """
        checks if there are 4 elements on the same coloumn which are consecutive and with the same value
        :return:
        """
        i=0
        while i<=2:
            j=0
            while j<=6:
                if self.__field[i][j]==self.__field[i+1][j] and self.__field[i][j]==self.__field[i+2][j] and self.__field[i][j]==self.__field[i+3][j] and self.__field[i][j]!=0:
                    return True
                j+=1
            i=i+1
        return False
    def check_win_maindiag(self):
        """
        checks if there are 4 elements on the same diagonal which are consecutive and with the same value
        """
        for i in range(3):
            for j in range(4):
                if self.__field[i][j] == self.__field[i + 1][j+1] and self.__field[i][j] == self.__field[i + 2][j+2] and self.__field[i][j] == self.__field[i + 3][j+3] and self.__field[i][j]!=0:
                    return True
        return False
    def check_win_secdiag(self):
        """
        checks if there are 4 elements on the same diagonal which are consecutive and with the same value
        """
        i=3
        while i<=5:
            for j in range(4):
                if self.__field[i][j] == self.__field[i-1][j+1] and self.__field[i][j] == self.__field[i-2][j+2] and self.__field[i][j] == self.__field[i-3][j+3] and self.__field[i][j]!=0:
                    return True
            i=i+1
        return False
    def check_win(self):
        """
        :return:True if someone won, False if not
        """
        if self.check_win_line()==True or self.check_win_coloumn()==True or self.check_win_maindiag()==True or self.check_win_secdiag()==True:
            return True
        else:
            return False

    def computer_win_line(self):
        """
        checks if the computer could win/lose on a line if it moves/doesn't move on in a specific spot
        :return: the spot or -1 if it is not the case
        """
        for i in range(6):
            j=0
            while j<=4:
                if self.__field[i][j]==self.__field[i][j+1] and self.__field[i][j]==self.__field[i][j+2] and self.__field[i][j]!=0:
                    if j<4 and i+1<6 and self.__field[i][j+3]==0 and self.__field[i+1][j+3]!=0:
                        return j+3
                    elif j>0 and i+1<6 and self.__field[i][j-1]==0 and self.__field[i+1][j-1]!=0:
                        return j-1
                    elif i==5:
                        if j>0 and self.__field[i][j-1]==0:
                            return j-1
                        elif j<4 and self.__field[i][j+3]==0:
                            return j+3
                j+=1
        return -1
    def computer_win_line_between(self):
        """
        checks if the computer could win/lose on a line if it moves/doesn't move on in a specific spot
        :return: the spot or -1 if it is not the case
        """
        for i in range(6):
            j=0
            while j<=3:
                if self.__field[i][j]==self.__field[i][j+1] and self.__field[i][j]==self.__field[i][j+3] and self.__field[i][j]!=0:
                    if i+1<6 and self.__field[i+1][j+2]!=0:
                        return j+2
                    elif i==5:
                        return j+2
                elif self.__field[i][j]==self.__field[i][j+2] and self.__field[i][j]==self.__field[i][j+3] and self.__field[i][j]!=0:
                    if i+1<6 and self.__field[i+1][j+1]!=0:
                        return j+1
                    elif i==5:
                        return j+1
                j=j+1
        return -1
    def computer_win_coloumn(self):
        """
        checks if the computer could win/lose on a coloumn if it moves/doesn't move on in a specific spot
        :return: the spot or -1 if it is not the case
        """
        i = 0
        while i <= 2:
            j = 0
            while j <= 6:
                if self.__field[i+2][j] == self.__field[i + 1][j] and self.__field[i+3][j] == self.__field[i + 2][j] and self.__field[i+1][j] != 0:
                    if self.__field[i][j]==0:
                        return j
                j += 1
            i = i + 1
        return -1
    def computer_win_main_diag(self):
        """
        checks if the computer could win/lose on the main diagonal if it moves/doesn't move on in a specific spot
        :return: the spot or -1 if it is not the case
        """
        for i in range(4):
            for j in range(5):
                if self.__field[i][j] == self.__field[i + 1][j + 1] and self.__field[i][j] == self.__field[i + 2][j + 2] and self.__field[i][j] != 0:
                    if i>0 and j>0 and self.__field[i][j-1]!=0 and self.__field[i-1][j-1]==0:
                        return j-1
                    elif i+3<5 and j+3<6 and self.__field[i+3][j+3]==0 and self.__field[i+4][j+3]!=0:
                        return j+3
                    elif i+3==5 and j+3<7 and self.__field[i+3][j+3]==0:
                        return j+3
        return -1
    def computer_win_main_diag_between(self):
        """
        checks if the computer could win/lose on the main diagonal if it moves/doesn't move on in a specific spot
        :return: the spot or -1 if it is not the case
        """
        for i in range(3):
            for j in range(4):
                if self.__field[i][j] == self.__field[i + 1][j + 1] and self.__field[i][j] == self.__field[i + 3][j + 3] and self.__field[i][j] != 0:
                    if self.__field[i+3][j+2]!=0 and self.__field[i+2][j+2]==0:
                        return j+2
                elif self.__field[i][j] == self.__field[i + 2][j + 2] and self.__field[i][j] == self.__field[i + 3][j + 3] and self.__field[i][j] != 0:
                    if self.__field[i+1][j+1]==0 and self.__field[i+2][j+1]!=0:
                        return j+1
        return -1
    def computer_win_sec_diag(self):
        """
        checks if the computer could win/lose on the second diagonal if it moves/doesn't move on in a specific spot
        :return: the spot or -1 if it is not the case
        """
        i = 2
        while i <= 5:
            for j in range(5):
                if self.__field[i][j] == self.__field[i - 1][j + 1] and self.__field[i][j] == self.__field[i - 2][j + 2] and self.__field[i][j] != 0:
                    if i>2 and j<4 and self.__field[i-3][j+3]==0 and self.__field[i-2][j+3]!=0:
                        return j+3
                    elif j>0 and i<5 and self.__field[i+1][j-1]==0:
                        if i<4 and self.__field[i+2][j-1]!=0:
                            return j-1
                        elif i==4:
                            return j-1
            i = i + 1
        return -1
    def computer_win_sec_diag_between(self):
        """
        checks if the computer could win/lose on the second diagonal if it moves/doesn't move on in a specific spot
        :return: the spot or -1 if it is not the case
        """
        i = 3
        while i <= 5:
            for j in range(4):
                if self.__field[i][j] == self.__field[i - 1][j + 1] and self.__field[i][j] == self.__field[i - 3][j + 3] and self.__field[i][j] != 0:
                    if self.__field[i-2][j+2]==0 and self.__field[i-1][j+2]!=0:
                        return j+2
                elif self.__field[i][j] == self.__field[i - 2][j + 2] and self.__field[i][j] == self.__field[i - 3][j + 3] and self.__field[i][j] != 0:
                    if self.__field[i-1][j+1]==0 and self.__field[i][j+1]!=0:
                        return j+1
            i = i + 1
        return -1

