from django.db import models

class Car(models.Model):
    brand=models.CharField(max_length=30)
    mod=models.CharField(max_length=35)
    chasisNr=models.CharField(max_length=20)
    hp=models.IntegerField(default=0)
    yearOfRegistration=models.IntegerField(default=0)

    def __str__(self):
        return f"{self.brand} {self.mod}"

class Rims(models.Model):
    rimBrand=models.CharField(max_length=30)
    rimModel=models.CharField(max_length=30)
    height=models.IntegerField(default=0)
    width=models.IntegerField(default=0)
    carModel=models.ForeignKey(Car,related_name='rims',on_delete=models.CASCADE)

    def __str__(self):
        return f"{self.rimBrand} {self.rimModel}"

class RaceTracks(models.Model):
    name=models.CharField(max_length=30)
    lenght=models.IntegerField(default=0)
    style=models.CharField(max_length=30)
    surface=models.CharField(max_length=30)
    recordHolder=models.ForeignKey(Car,on_delete=models.CASCADE)

    def __str__(self):
        return f"{self.name}"

class Owners(models.Model):
    name=models.CharField(max_length=30)
    addres=models.CharField(max_length=40)
    cnp=models.CharField(max_length=20)

    def __str__(self):
        return f"{self.name}"

class OwnersCars(models.Model):
    price=models.IntegerField(default=0)
    kmWhenBought=models.IntegerField(default=0)
    car=models.ForeignKey(Car,on_delete=models.CASCADE)
    owner=models.ForeignKey(Owners,on_delete=models.CASCADE)

    def __str__(self):
        return f"{self.owner} {self.car}"






