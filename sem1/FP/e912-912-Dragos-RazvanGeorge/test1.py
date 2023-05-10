import unittest
from repository import Repo
from domain import Year
from service import Service

class Test_repo(unittest.TestCase):
    def setUp(self):
        self.__rep=Repo()
        self.__service=Service()
    def test_add(self):
        y=Year(100,20,2,50,12)
        self.__rep.add(y)
        self.assertEqual(self.__rep.len(),1)
    def test_spec_year(self):
        y = Year(100, 20, 2, 50, 12)
        self.__rep.add(y)
        self.assertEqual(self.__rep.specific_year(0),y)
    def test_year_1(self):
        self.__rep.year1()
        self.assertEqual(self.__rep.len(),1)
    def test_domain(self):
        y = Year(100, 20, 2, 50, 12)
        self.assertEqual(y.population,100)
        self.assertEqual(y.acres,20)
        self.assertEqual(y.harvest,2)
        self.assertEqual(y.rats,50)
        self.assertEqual(y.land_price,12)
    def test_grain(self):
        self.assertEqual(self.__service.grainul(),2800)
    def test_rats_eat(self):
        gr=self.__service.grainul()
        self.assertLess(self.__service.rats_eat(gr),gr//10)



