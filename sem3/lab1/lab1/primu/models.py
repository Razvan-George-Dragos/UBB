from django.db import models
class Car(models.Model):
    brand=models.CharField(max_length=30)
    mod=models.CharField(max_length=35)
    chasisNr=models.CharField(max_length=20)
    hp=models.IntegerField
    yearOfRegistration=models.IntegerField

    def __str__(self):
        return self.brand + ' ' + self.mod