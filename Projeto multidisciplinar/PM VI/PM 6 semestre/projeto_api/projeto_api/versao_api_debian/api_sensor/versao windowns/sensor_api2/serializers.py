# api_sensor/serializers.py
from rest_framework import serializers
from .models import Sensor

class SensorSerializer(serializers.ModelSerializer):
    class Meta:
        model = Sensor
        fields = '__all__'  # ou você pode listar ['id', 'nome', 'valor', 'data']
