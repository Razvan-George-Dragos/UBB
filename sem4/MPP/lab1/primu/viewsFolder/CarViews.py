from django.db.models import Count
from drf_spectacular.utils import extend_schema
from rest_framework.views import APIView

from primu.serializers import CarSerializer, CarRimsSerializer, CarSerializerAgg
from rest_framework.response import Response

from primu.models import Car
from rest_framework import status, generics


class CarApiView(APIView):
    @extend_schema(responses={201: CarSerializer}, )
    def get(self, request, page=None):
        id = request.query_params.get("id", None)

        if id is not None:
            try:
                car = Car.objects.get(pk=id)
            except Car.DoesNotExist:
                return Response(status=status.HTTP_404_NOT_FOUND)
            serializer = CarSerializer(car)
            return Response({"data": serializer.data, "totalRows": Car.objects.count()})
        if page is None:
            page = 0
        offset = 10
        cars = Car.objects.all().order_by("id").annotate(num_rims=Count('rims'))[page * offset:(page + 1) * offset]
        serializer = CarSerializerAgg(cars, many=True)
        return Response({"data": serializer.data, "totalRows": Car.objects.count()})

    @extend_schema(request=CarSerializer, responses={201: CarSerializer})
    def post(self, request):
        serializer = CarSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        else:
            return Response(serializer.errors)

    @extend_schema(request=CarSerializer, responses={200: CarSerializer})
    def put(self, request):
        id = request.query_params.get("id", None)
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
    def delete(self, request):
        id = request.query_params.get("id", None)
        try:
            car = Car.objects.get(pk=id)
        except Car.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)
        car.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)


class CarDetailView(APIView):
    @extend_schema(responses={200: CarSerializer})
    def get(self, request, page):

        id = request.query_params.get("id", None)
        try:
            car = Car.objects.get(pk=id)
        except Car.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)
        serializer = CarSerializer(car)
        return Response(serializer.data)

    @extend_schema(request=CarSerializer, responses={200: CarSerializer})
    def put(self, request, page):
        id = request.query_params.get("id", None)

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
        return Response(status=status.HTTP_204_NO_CONTENT)


class CarRimsReport1ApiView(APIView):
    @extend_schema(responses={200: CarRimsSerializer(many=True)})
    def get(self, request):
        cars = Car.objects.annotate(num_rims=Count('rims'))
        cars = cars.order_by('-num_rims')
        serializer = CarRimsSerializer(cars, many=True)
        return Response(serializer.data)


class CarOrdByBrandApiView(generics.ListCreateAPIView):
    serializer_class = CarSerializer

    def get_queryset(self):
        car_brand = self.kwargs.get("car_brand")
        query_set = Car.objects.all()
        if car_brand is not None:
            query_set = query_set.filter(brand__icontains=car_brand)
            return query_set[:10]
