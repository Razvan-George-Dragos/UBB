# Generated by Django 4.1.7 on 2023-03-06 08:38

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('primu', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='car',
            name='hp',
            field=models.IntegerField(default=0),
        ),
        migrations.AddField(
            model_name='car',
            name='yearOfRegistration',
            field=models.IntegerField(default=0),
        ),
    ]
