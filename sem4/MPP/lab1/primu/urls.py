"""primu URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from drf_spectacular.views import SpectacularAPIView, SpectacularSwaggerView, SpectacularRedocView

from primu import views
from primu.viewsFolder import CarViews, OwnerViews, OwnerCarsView, RimsViews, RaceTracksView
from primu.viewsFolder.CarViews import CarOrdByBrandApiView
from primu.viewsFolder.OwnerViews import OwnersOrdByNameApiView

urlpatterns = [
    path('api/schema/', SpectacularAPIView.as_view(), name='schema'),
    # Optional UI:
    path('api/schema/swagger-ui/', SpectacularSwaggerView.as_view(url_name='schema'), name='swagger-ui'),
    path('api/schema/redoc/', SpectacularRedocView.as_view(url_name='schema'), name='redoc'),
    path('admin/', admin.site.urls),
    path('cars/', CarViews.CarApiView.as_view()),
    path('cars/<int:page>', CarViews.CarApiView.as_view()),
    path('rims/', RimsViews.RimsApiView.as_view()),
    path('racetracks/', RaceTracksView.RaceTracksApiView.as_view()),
    path('rims/<int:page>', RimsViews.RimsApiView.as_view()),
    path('racetracks/<int:page>', RaceTracksView.RaceTrackDetailApiView.as_view()),
    path('owners/', OwnerViews.OwnersApiView.as_view()),
    path('ownerscars/', OwnerCarsView.OwnersCarsApiView.as_view()),
    path('owners/<int:page>', OwnerViews.OwnersApiView.as_view()),
    path('ownerscars/<int:page>', OwnerCarsView.OwnersCarsApiView.as_view()),
    path('car_owner_report/', OwnerCarsView.CarOwnerReport1ApiView.as_view(), name='car_owner_report'),
    path("multiplecarbrand/", RimsViews.MultipleRimsCarView.as_view()),
    path('car_rims_report/', CarViews.CarRimsReport1ApiView.as_view(), name='car_rims_report'),
    path("carOrdByBrand/<str:car_brand>/", CarOrdByBrandApiView.as_view(), name="car_brand"),
    path("ownersOrdByName/<str:car_brand>/", OwnersOrdByNameApiView.as_view(), name="owner_name")
]
