from repository import Repo
from domain import Year
import random
class Service:
    def __init__(self):
        self.__repo=Repo()
        self.__year = 0
        self.__grain = 2800
        self.__starved=0
        self.__newcommers=0
    def year1(self):
        """adds the first year"""
        self.__repo.year1()
    def specific_year(self,i):
        """
        :param i: indicele din sir
        :return: type Year, Year-ul cu indicele i
        """
        return self.__repo.specific_year(i)
    def current_year(self):
        """

        :return:type Year, the current year
        """
        return self.__repo.specific_year(self.__year)
    def year_nr(self):
        """
        :return: type integer, the number of the year
        """
        return self.__year
    def grainul(self):
        """

        :return:type integer, the grain of the current year
        """
        return self.__grain
    def starved(self):
        """

        :return: type integer, the number of starved people in the current year
        """
        return self.__starved
    def noi(self):
        """

        :return: type integer, the number of newcommers in the current year
        """
        return self.__newcommers
    def rats_eat(self,gr):
        """

        :param gr: the grain
        :return:type integer, the number of grain that the rats have eaten in the current year
        """

        x=random.randint(1,100)
        y=0
        if x<=20:
            gr=gr//10
            y=random.randint(0,gr)
        return y
    def next_year(self,population,a,fp,ap):
        """this function obtains the parameters of the next year"""
        harv = random.randint(1, 6)
        gr=self.__grain-ap+(harv*ap)
        aa=self.__repo.specific_year(self.__year)
        if a<0:
            gr=gr+a*aa.land_price
        elif a>0:
            gr = gr - a * aa.land_price
        self.__grain=gr
        r = self.rats_eat(self.__grain)
        self.__grain-=r
        self.__year+=1
        landpr=random.randint(15,25)
        if fp//20>=population:
            self.__starved=0
        else:
            self.__starved=population-(fp//20)
        coming=0
        if self.__starved==0:
            coming = random.randint(0, 10)
        self.__newcommers=coming
        population=population+coming

        year=self.__repo.specific_year(self.__year-1)
        cityarea=year.acres+a
        newy=Year(population,cityarea,harv,r,landpr)
        self.__repo.add(newy)


