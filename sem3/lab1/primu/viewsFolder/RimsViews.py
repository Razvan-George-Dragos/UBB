from django.views.decorators.csrf import csrf_exempt
from drf_spectacular.utils import extend_schema, OpenApiParameter
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status

from primu.models import Rims, Car
from primu.serializers import RimsSerializer, RimsSerializerDetail


class RimsApiView(APIView):
    @extend_schema(parameters=[OpenApiParameter(name='id', type=int, required=False),
                               OpenApiParameter(name='height', type=int, required=False)],
                   responses={200: RimsSerializer(many=True)})
    def get(self, request, page=None):
        id = request.query_params.get("id", None)
        if id is not None:
            height1 = request.query_params.get('height')
            if id:
                rims = Rims.objects.filter(id=id)
            elif height1:
                rims = Rims.objects.filter(height__gt=height1)
            else:
                rims = Rims.objects.all()
            serializer = RimsSerializer(rims, many=True)
            return Response({"data":serializer.data, "totalRows":Rims.objects.count()})
        if page is None:
            page = 0
        offset = 10
        rims = Rims.objects.all().order_by("id")[page*offset:(page+1)*offset]
        serializer = RimsSerializer(rims, many=True)
        return Response({"data": serializer.data, "totalRows": Rims.objects.count()})

    @extend_schema(request=RimsSerializer, responses={201: RimsSerializer})
    def post(self, request):
        serializer = RimsSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        else:
            return Response(serializer.errors)

    @extend_schema(request=RimsSerializer, responses={200: RimsSerializer})
    def put(self, request):
        id = request.query_params.get("id", None)
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
    def delete(self, request):
        id = request.query_params.get("id", None)
        try:
            rim = Rims.objects.get(pk=id)
        except Rims.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)

        rim.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)

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
        return Response(status=status.HTTP_204_NO_CONTENT)

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

        return Response({'message': 'Cars updated successfully.'})
