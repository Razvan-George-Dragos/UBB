from django.test import TestCase
from primu.models import Owners, RaceTracks, Car

class OwnerModelTestcase(TestCase):
    @classmethod
    def setUpTestData(cls):
        Owners.objects.create(name="Razvan",addres="rovine",cnp="1234")

    def test_string_method(self):
        teacher = Owners.objects.get(name="Razvan")
        expected_string = "Razvan"
        self.assertEqual(str(teacher), expected_string)

class RaceTracksModelTestcase(TestCase):
    @classmethod
    def setUpTestData(cls):
        RaceTracks.objects.create(name="Razvan",lenght=12,style="1234",surface='dasfa',recordHolder=Car.objects.create(brand='asfs',mod='as',chasisNr='bs',hp=10,yearOfRegistration=1234))

    def test_string_method(self):
        teacher = RaceTracks.objects.get(name="Razvan")
        expected_string = "Razvan"
        self.assertEqual(str(teacher), expected_string)

