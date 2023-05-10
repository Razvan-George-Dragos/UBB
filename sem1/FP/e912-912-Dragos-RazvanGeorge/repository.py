from domain import Year
class Repo:
    def __init__(self):
        self.__l=[]
    def add(self,year):
        """adds another year to the list"""
        self.__l.append(year)
    def year1(self):
        """adds the first year to the list"""
        year=Year(100,1000,3,200,20)
        self.add(year)
    def specific_year(self,i):
        """returns the i-th year"""
        return self.__l[i]
    def len(self):
        """returns the lenght of the list(integer)"""
        return len(self.__l)