from django.db.models import Count
from rest_framework import serializers
from .models import Car, Rims, RaceTracks, Owners, OwnersCars


class CarSerializer(serializers.ModelSerializer):
    class Meta:
        model = Car
        fields = ['id', 'brand', 'mod', 'chasisNr', 'hp', 'yearOfRegistration']

    def validate_hp(self, value):
        if value < 2:
            raise serializers.ValidationError("You need at least 2 hp for a car to move.")
        else:
            return value

    def validate_yearOfRegistration(self, value):
        if 1875 > value or 2023 < value:
            raise serializers.ValidationError("You can't have a road legal car older than 1875 or newer than 2023.")
        else:
            return value



class CarOwnerSerializer(serializers.ModelSerializer):
    num_cars = serializers.IntegerField(read_only=True)

    class Meta:
        model = Owners
        fields = ['id', 'name', 'num_cars']


class CarRimsSerializer(serializers.ModelSerializer):
    num_rims = serializers.IntegerField(read_only=True)

    class Meta:
        model = Car
        fields = ['id', 'brand', 'mod', 'num_rims']


class OwnersSerializer(serializers.ModelSerializer):
    class Meta:
        model = Owners
        fields = ['id', 'name', 'addres', 'cnp']


class OwnersCarsSerializer(serializers.ModelSerializer):
    class Meta:
        model = OwnersCars
        fields = ['id', 'price', 'kmWhenBought', 'car', 'owner']


class RimsSerializer(serializers.ModelSerializer):
    class Meta:
        model = Rims
        fields = ['id', 'rimBrand', 'rimModel', 'height', 'width', 'carModel']

    def validate_height(self, value):
        if value < 10:
            raise serializers.ValidationError("Wheels for a road car need to be at least 10 inch diameter.")
        else:
            return value


class RaceTracksSerializer(serializers.ModelSerializer):
    class Meta:
        model = RaceTracks
        fields = ['id', 'name', 'lenght', 'style', 'surface', 'recordHolder']


class CarSerializerdetail(serializers.ModelSerializer):
    rims = RimsSerializer(many=True, read_only=True)

    class Meta:
        model = Car
        fields = ['id', 'brand', 'mod', 'rims']
        depth = 1


class RimsSerializerDetail(serializers.ModelSerializer):
    cars = CarSerializer(many=True, read_only=True)

    class Meta:
        model = Rims
        fields = '__all__'
        depth = 1


class CarSerializerAgg(serializers.ModelSerializer):
    num_rims = serializers.IntegerField(read_only=True)
    class Meta:
        model = Car
        fields = ['id', 'brand', 'mod', 'chasisNr', 'hp', 'yearOfRegistration', 'num_rims']
