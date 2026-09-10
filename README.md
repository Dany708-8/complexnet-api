# ComplexNet API — Monitoreo descentralizado de ocupación de salones

Proyecto integrador del curso Sistemas Complejos (PCIA5016), Universidad Sergio Arboleda.

Sistema de nodos descentralizados (sensores ESP32 + nodos de cómputo) que
monitorean en tiempo real la ocupación de salones de un campus, sin depender
de un servidor central.

## Estado actual: Corte 1

Prueba de concepto de comunicación entre un nodo sensor y un nodo de cómputo:

- `firmware/esp32_sensor/sensor_pir.ino`: un ESP32 con sensor PIR detecta
  movimiento y envía su estado por UDP.
- `src/nodo_computo.py`: un script en Python escucha ese puerto y muestra
  el estado del salón por consola.

## Cómo correr la prueba de concepto

1. Abre `sensor_pir.ino` en el IDE de Arduino, cambia `ssid`, `password` e
   `ipDestino` (IP de tu laptop) y súbelo al ESP32.
2. En la laptop, corre:
   ```
   python src/nodo_computo.py
   ```
3. Mueve algo frente al sensor PIR y deberías ver el estado impreso en consola.

## Documentación

El documento técnico completo de diseño (modelo matemático, arquitectura,
diagramas UML, protocolo de comunicación) está en `docs/`.

## Próximos pasos (Corte 2)

- Descubrimiento entre más de dos nodos.
- Registro de recursos / salones.
- Propagación de estado entre varios nodos de cómputo.
- Panel de monitoreo real.
