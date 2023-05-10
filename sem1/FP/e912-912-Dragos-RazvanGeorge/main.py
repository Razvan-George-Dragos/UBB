from service import Service
from repository import Repo
from domain import Year
import random
class Ui:
    def __init__(self):
        self.__command=Service()

    def printer(self,yr,an,gr,foame,noi):
        print("In year",end=" ")
        print(an)
        print(foame, end=" ")
        print("people starved")
        print(noi, end=" ")
        print("people came to the city")
        print("city population is", end=" ")
        print(yr.population)
        print("city owns", end=" ")
        print(yr.acres, end=" ")
        print("of land")
        print("harvest was", end=" ")
        print(yr.harvest, end=" ")
        print("units per acre")
        print("rats ate", end=" ")
        print(yr.rats, end=" ")
        print("units")
        print("land price is", end=" ")
        print(yr.land_price)
        print("grain stocks are ", end=" ")
        print(gr, end=" ")
        print("units")
    def start(self):
        self.__command.year1()
        print("In year",end=" ")
        print(self.__command.year_nr()+1)
        print("0 people starved")
        print("0 people came to the city")
        print("city population is", end=" ")
        y=self.__command.specific_year(0)
        print(y.population)
        print("city owns 100 acres of land")
        print("harvest was 3 units per acre")
        print("land price is 20 units per acre")
        print("grain stocks are 2800 units per acre")
        ok=1
        while ok<=5:
            a=input("acres to buy/sell(+/-) ->")
            fp=input("units to feed the population ->")
            ap=input("acres to plant ->")
            ex=""
            try:
                if fp.isdecimal()==False or ap.isdecimal==False:
                    ex+="invalid values"
                    raise Exception
            except Exception:
                print(str(ex))

            if ex=="":
                a=int(a)
                fp=int(fp)
                ap=int(ap)
                curyr = self.__command.current_year()
                if curyr.acres + a < 0:
                    ex += "not enough land to sell"
                    print(str(ex))
                elif fp>self.__command.grainul():
                    ex+="impossible to feed with so much"
                    print(str(ex))
                foame = self.__command.starved()
                if ex=="":
                    p=y.population
                    self.__command.next_year(p,a,fp,ap)
                    yr=self.__command.year_nr()+1
                    gr=self.__command.grainul()

                    noi=self.__command.noi()
                    yea=self.__command.current_year()
                    self.printer(yea,yr,gr,foame,noi)
                foame = self.__command.starved()
                curyr = self.__command.current_year()
                if foame>=curyr.population//2:
                    ex="You lost"
                    ok=7
                elif curyr.population>100 and curyr.acres>1000:
                    ex+="Congratulations, you won"
                    ok=8

            ok+=1
        if ok==7:
            print("You lost")
        else:
            print("Congratulations, you did good")









console=Ui()
console.start()