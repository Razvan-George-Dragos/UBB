from django.contrib import admin
from .models import Car, Rims, RaceTracks, Owners, OwnersCars

admin.site.register(Car)
admin.site.register(Rims)
admin.site.register(RaceTracks)
admin.site.register(Owners)
admin.site.register(OwnersCars)
