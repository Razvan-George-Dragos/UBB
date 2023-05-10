class Year:
    def __init__(self,population,acres,harvest,rats,land_price):
        self.__population=population
        self.__acres=acres
        self.__harvest=harvest
        self.__rats=rats
        self.__land_price=land_price
    @property
    def population(self):
        return self.__population
    @property
    def acres(self):
        return self.__acres
    @property
    def harvest(self):
        return self.__harvest
    @property
    def rats(self):
        return self.__rats
    @property
    def land_price(self):
        return self.__land_price
