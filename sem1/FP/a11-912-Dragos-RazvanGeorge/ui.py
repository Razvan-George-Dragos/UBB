from sevice import Service
from repository import Board
class Ui:
    def __init__(self):
        self.__command=Service()
        self._board=Board()
        self.__winner=0
    def start(self):
        over=False
        while over==False:
            #for i in range(6):
               # print(self.__command.print(i))
            print(self.__command.print(1))

            x=input("your move:")
            ok=self.__command.condition(x)
            err = ""
            try:
                if x.isdecimal()==False:
                    err+="invalid command"
                else:
                    x=int(x)
                    if x<1 or x>7:
                        err+="invalid command"
                raise Exception(err)
            except Exception as err:
                print(str(err))
            if ok==True:
                x=x-1
                if self.__command.check_move(x)==True:
                    self.__command.move(x,1)
                    self.__winner=1
                    if self.__command.is_over() == False:
                        self.__command.computer()
                        self.__winner = 2
                    over = self.__command.is_over()
                else:
                    print("impossible move")
                    over=self.__command.no_winner()
                    if over==True:
                        self.__winner=0
        for i in range(6):
            print(self.__command.print(i))
        if self.__winner==1:
            print("You WON")
        elif self.__winner==2:
            print("You LOST")
        else:
            print("It is a DRAW")

console=Ui()
console.start()