"""from django.http import JsonResponse
from django.shortcuts import render
from django.views.decorators.csrf import csrf_exempt
from drf_spectacular.utils import extend_schema, OpenApiParameter

from .models import Car, Rims, RaceTracks, Owners, OwnersCars
from .serializers import CarSerializer, RimsSerializer, RaceTracksSerializer, CarSerializerdetail, RimsSerializerDetail, \
    OwnersSerializer, OwnersCarsSerializer, CarOwnerSerializer, CarRimsSerializer
from rest_framework.decorators import api_view, APIView
from rest_framework.response import Response
from rest_framework import status
from django_filters import rest_framework as filters
from django.db.models import Count
from rest_framework.views import APIView
from rest_framework.generics import GenericAPIView"""

"""
class RimsFilter(filters.FilterSet):
    class Meta:
        model = Rims
        fields = {
            'rimBrand': ['icontains'],
            'height': ['gte']
        }"""


"""
class CarApiView(GenericAPIView):
    @extend_schema(responses={201: CarSerializer}, )
    @api_view(['GET', 'POST'])
    def cars_list(request):
        if request.method == 'GET':
            cars = Car.objects.all()
            serializer = CarSerializer(cars, many=True)
            return Response(serializer.data)

        if request.method == 'POST':
            serializer = CarSerializer(data=request.data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data, status=status.HTTP_201_CREATED)
            else:
                return Response(serializer.errors)
                """

"""
class CarApiView(APIView):
    @extend_schema(responses={201: CarSerializer}, )
    def get(self, request):
        cars = Car.objects.all()
        serializer = CarSerializer(cars, many=True)
        return Response(serializer.data)

    @extend_schema(request=CarSerializer, responses={201: CarSerializer})
    def post(self, request):
        serializer = CarSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        else:
            return Response(serializer.errors)"""

"""
class MultipleRimsCarView(APIView):
    serializer_class = None
    @csrf_exempt
    @api_view(['POST'])
    def bulkAdd(request):
        rim_id_new_brand_list = request.data.get('rims_id_new_brand_list')

        # Loop through the list of car ids and new car brands to update
        for item in rim_id_new_brand_list:
            rim = Rims.objects.get(id=item['rims_id'])
            rim.carModel = Car.objects.get(id=item['newcar'])
            rim.save()

        return Response({'message': 'Cars updated successfully.'})"""
"""
class MultipleRimsCarView(APIView):
    serializer_class = RimsSerializer

    @csrf_exempt
    @api_view(['POST'])
    def bulkAdd(request):
        rim_id_new_brand_list = request.data.get('rims_id_new_brand_list')

        # Loop through the list of car ids and new car brands to update
        for item in rim_id_new_brand_list:
            rim = Rims.objects.get(id=item['rims_id'])
            rim.carModel = Car.objects.get(id=item['newcar'])
            rim.save()

        return Response({'message': 'Cars updated successfully.'})"""
"""
class MultipleRimsCarView(APIView):
    @csrf_exempt
    @extend_schema(request={"type": "object",
                             "properties": {"rims_id_new_brand_list": {"type": "array",
                                                                       "items": {"type": "object",
                                                                                 "properties": {"rims_id": {"type": "integer"},
                                                                                                "newcar": {"type": "integer"}}
                                                                       }
                                                                      }
                                            },
                             },
                   responses={200: {"description": "Cars updated successfully"}})
    def post(self, request):
        rim_id_new_brand_list = request.data.get('rims_id_new_brand_list')

        # Loop through the list of car ids and new car brands to update
        for item in rim_id_new_brand_list:
            rim = Rims.objects.get(id=item['rims_id'])
            rim.carModel = Car.objects.get(id=item['newcar'])
            rim.save()

        return Response({'message': 'Cars updated successfully.'})"""






"""
@api_view(['GET', 'POST'])
def owners_list(request):
    serializer_class = OwnersSerializer
    if request.method == 'GET':
        cars = Owners.objects.all()
        serializer = OwnersSerializer(cars, many=True)
        return Response(serializer.data)

    if request.method == 'POST':
        serializer = OwnersSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)"""

"""
class OwnersApiView(APIView):
    @extend_schema(responses={200: OwnersSerializer(many=True)})
    def get(self, request):
        owners = Owners.objects.all()
        serializer = OwnersSerializer(owners, many=True)
        return Response(serializer.data)

    @extend_schema(request=OwnersSerializer, responses={201: OwnersSerializer})
    def post(self, request):
        serializer = OwnersSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        else:
            return Response(serializer.errors)"""


"""
@api_view(['GET', 'POST'])
def ownersCars_list(request):
    serializer_class = OwnersCarsSerializer
    if request.method == 'GET':
        cars = OwnersCars.objects.all()
        serializer = OwnersCarsSerializer(cars, many=True)
        return Response(serializer.data)

    if request.method == 'POST':
        serializer = OwnersCarsSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)"""

"""
class OwnersCarsApiView(APIView):
    @extend_schema(responses={200: OwnersCarsSerializer(many=True)}, )
    def get(self, request):
        cars = OwnersCars.objects.all()
        serializer = OwnersCarsSerializer(cars, many=True)
        return Response(serializer.data)

    @extend_schema(request=OwnersCarsSerializer, responses={201: OwnersCarsSerializer()})
    def post(self, request):
        serializer = OwnersCarsSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        else:
            return Response(serializer.errors)"""


"""
@api_view(['GET', 'POST'])
def rims_list(request):
    serializer_class = RimsSerializer
    id = request.query_params.get('id')
    height1 = request.query_params.get('height')
    if request.method == 'GET':
        if id:
            rims = Rims.objects.filter(id=id)
        elif height1:
            rims = Rims.objects.filter(height__gt=height1)
        else:
            rims = Rims.objects.all()
        serializer = RimsSerializer(rims, many=True)
        return Response(serializer.data)

    if request.method == 'POST':
        serializer = RimsSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        else:
            return Response(serializer.errors)"""

"""
class RimsApiView(APIView):
    @extend_schema(parameters=[OpenApiParameter(name='id', type=int, required=False),
                               OpenApiParameter(name='height', type=int, required=False)],
                   responses={200: RimsSerializer(many=True)})
    def get(self, request):
        id = request.query_params.get('id')
        height1 = request.query_params.get('height')
        if id:
            rims = Rims.objects.filter(id=id)
        elif height1:
            rims = Rims.objects.filter(height__gt=height1)
        else:
            rims = Rims.objects.all()
        serializer = RimsSerializer(rims, many=True)
        return Response(serializer.data)

    @extend_schema(request=RimsSerializer, responses={201: RimsSerializer})
    def post(self, request):
        serializer = RimsSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        else:
            return Response(serializer.errors)"""


"""
@api_view(['GET', 'POST'])
def racetracks_list(request):
    serializer_class = RaceTracksSerializer
    if request.method == 'GET':
        cars = RaceTracks.objects.all()
        serializer = RaceTracksSerializer(cars, many=True)
        return Response(serializer.data)

    if request.method == 'POST':
        serializer = RaceTracksSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)"""

"""
class RaceTracksApiView(APIView):
    @extend_schema(responses={200: RaceTracksSerializer(many=True)})
    def get(self, request):
        cars = RaceTracks.objects.all()
        serializer = RaceTracksSerializer(cars, many=True)
        return Response(serializer.data)

    @extend_schema(request=RaceTracksSerializer, responses={201: RaceTracksSerializer})
    def post(self, request):
        serializer = RaceTracksSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        else:
            return Response(serializer.errors)"""


"""
@api_view(['GET', 'PUT', 'DELETE'])
def car_detail(request, id):
    # serializer_class = CarSerializer
    try:
        car = Car.objects.get(pk=id)
    except Car.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)

    if request.method == 'GET':
        serializer = CarSerializerdetail(car)
        return Response(serializer.data)

    elif request.method == 'PUT':
        serializer = CarSerializer(car, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    elif request.method == 'DELETE':
        car.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)"""

"""
class CarDetailView(APIView):
    @extend_schema(responses={200: CarSerializer})
    def get(self, request, id):
        try:
            car = Car.objects.get(pk=id)
        except Car.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)
        serializer = CarSerializer(car)
        return Response(serializer.data)

    @extend_schema(request=CarSerializer, responses={200: CarSerializer})
    def put(self, request, id):
        try:
            car = Car.objects.get(pk=id)
        except Car.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)
        serializer = CarSerializer(car, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    @extend_schema(responses={204: "No Content"})
    def delete(self, request, id):
        try:
            car = Car.objects.get(pk=id)
        except Car.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)
        car.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)"""


"""
@api_view(['GET', 'PUT', 'DELETE'])
def owners_detail(request, id):
    serializer_class = OwnersSerializer
    try:
        car = Owners.objects.get(pk=id)
    except Owners.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)

    if request.method == 'GET':
        serializer = OwnersSerializer(car)
        return Response(serializer.data)

    elif request.method == 'PUT':
        serializer = OwnersSerializer(car, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    elif request.method == 'DELETE':
        car.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)"""

"""
class OwnersDetailView(APIView):
    @extend_schema(responses={200: OwnersSerializer})
    def get(self, request, id):
        try:
            owner = Owners.objects.get(pk=id)
        except Owners.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)
        serializer = OwnersSerializer(owner)
        return Response(serializer.data)

    @extend_schema(request=OwnersSerializer, responses={200: OwnersSerializer})
    def put(self, request, id):
        try:
            owner = Owners.objects.get(pk=id)
        except Owners.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)
        serializer = OwnersSerializer(owner, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    @extend_schema(responses={204: 'No Content'})
    def delete(self, request, id):
        try:
            owner = Owners.objects.get(pk=id)
        except Owners.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)
        owner.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)"""


"""
@api_view(['GET', 'PUT', 'DELETE'])
def ownersCars_detail(request, id):
    serializer_class = OwnersCarsSerializer
    try:
        car = OwnersCars.objects.get(pk=id)
    except OwnersCars.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)

    if request.method == 'GET':
        serializer = OwnersCarsSerializer(car)
        return Response(serializer.data)

    elif request.method == 'PUT':
        serializer = OwnersCarsSerializer(car, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    elif request.method == 'DELETE':
        car.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)"""

"""
class OwnersCarsDetailApiView(APIView):
    @extend_schema(responses={200: OwnersCarsSerializer})
    def get(self, request, id):
        try:
            car = OwnersCars.objects.get(pk=id)
        except OwnersCars.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)

        serializer = OwnersCarsSerializer(car)
        return Response(serializer.data)

    @extend_schema(request=OwnersCarsSerializer, responses={200: OwnersCarsSerializer})
    def put(self, request, id):
        try:
            car = OwnersCars.objects.get(pk=id)
        except OwnersCars.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)

        serializer = OwnersCarsSerializer(car, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    @extend_schema(responses={204: 'No Content'})
    def delete(self, request, id):
        try:
            car = OwnersCars.objects.get(pk=id)
        except OwnersCars.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)

        car.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)"""


"""
@api_view(['GET', 'PUT', 'DELETE'])
def rims_detail(request, id):
    # serializer_class = RimsSerializer
    try:
        car = Rims.objects.get(pk=id)
    except Rims.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)

    if request.method == 'GET':
        serializer = RimsSerializerDetail(car)
        return Response(serializer.data)

    elif request.method == 'PUT':
        serializer = RimsSerializer(car, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    elif request.method == 'DELETE':
        car.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)"""

"""
class RimsDetailApiView(APIView):
    @extend_schema(responses={200: RimsSerializerDetail})
    def get(self, request, id):
        try:
            rim = Rims.objects.get(pk=id)
        except Rims.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)

        serializer = RimsSerializerDetail(rim)
        return Response(serializer.data)

    @extend_schema(request=RimsSerializer, responses={200: RimsSerializer})
    def put(self, request, id):
        try:
            rim = Rims.objects.get(pk=id)
        except Rims.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)

        serializer = RimsSerializer(rim, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    @extend_schema(responses={204: 'No Content'})
    def delete(self, request, id):
        try:
            rim = Rims.objects.get(pk=id)
        except Rims.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)

        rim.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)"""


"""
@api_view(['GET', 'PUT', 'DELETE'])
def racetracks_detail(request, id):
    serializer_class = RaceTracksSerializer
    try:
        car = RaceTracks.objects.get(pk=id)
    except RaceTracks.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)

    if request.method == 'GET':
        serializer = RaceTracksSerializer(car)
        return Response(serializer.data)

    elif request.method == 'PUT':
        serializer = RaceTracksSerializer(car, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    elif request.method == 'DELETE':
        car.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)"""

"""
class RaceTrackDetailApiView(APIView):
    @extend_schema(responses={200: RaceTracksSerializer})
    def get(self, request, id):
        try:
            track = RaceTracks.objects.get(pk=id)
        except RaceTracks.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)

        serializer = RaceTracksSerializer(track)
        return Response(serializer.data)

    @extend_schema(request=RaceTracksSerializer, responses={200: RaceTracksSerializer})
    def put(self, request, id):
        try:
            track = RaceTracks.objects.get(pk=id)
        except RaceTracks.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)

        serializer = RaceTracksSerializer(track, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    @extend_schema(responses={204: 'No Content'})
    def delete(self, request, id):
        try:
            track = RaceTracks.objects.get(pk=id)
        except RaceTracks.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)

        track.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)"""


"""
def car_owner_report(request):
    owners = Owners.objects.annotate(num_cars=Count('ownerscars'))

    owners = owners.order_by('-num_cars')

    context = {'owners': owners}
    return render(request, 'owner_report.html', context)


def car_rims_report(request):
    cars = Car.objects.annotate(num_cars=Count('rims'))
    cars = cars.order_by('-num_cars')
    context = {'cars': cars}
    return render(request, 'car_report.html', context)
"""
"""
@api_view(['GET', 'POST'])
def car_owner_report1(request):
    serializer_class = CarOwnerSerializer
    if request.method == 'GET':
        owners = Owners.objects.annotate(num_cars=Count('ownerscars'))
        owners = owners.order_by('-num_cars')
        serializer = CarOwnerSerializer(owners, many=True) 
        return Response(serializer.data)"""

"""
class CarOwnerReport1ApiView(APIView):
    @extend_schema(responses={200: CarOwnerSerializer(many=True)})
    def get(self, request):
        owners = Owners.objects.annotate(num_cars=Count('ownerscars')).order_by('-num_cars')
        serializer = CarOwnerSerializer(owners, many=True)
        return Response(serializer.data)"""

"""
@api_view(['GET', 'POST'])
def car_rims_report1(request):
    serializer_class = CarRimsSerializer
    if request.method == 'GET':
        cars = Car.objects.annotate(num_rims=Count('rims'))
        cars = cars.order_by('-num_rims')
        serializer = CarRimsSerializer(cars, many=True)
        return Response(serializer.data)"""

"""
class CarRimsReport1ApiView(APIView):
    @extend_schema(responses={200: CarRimsSerializer(many=True)})
    def get(self, request):
        cars = Car.objects.annotate(num_rims=Count('rims'))
        cars = cars.order_by('-num_rims')
        serializer = CarRimsSerializer(cars, many=True)
        return Response(serializer.data)"""
