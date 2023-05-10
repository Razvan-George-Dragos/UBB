from drf_spectacular.utils import extend_schema
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status

from primu.models import RaceTracks
from primu.serializers import RaceTracksSerializer


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
            return Response(serializer.errors)


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
        return Response(status=status.HTTP_204_NO_CONTENT)
