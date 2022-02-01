import RPi.GPIO as GPIO
from time import sleep

buzzer_pin = 23

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer_pin, GPIO.OUT, initial=GPIO.LOW)

# ketika output altitude dari bmp 388 bernilai 0
# maka buzzer akan menyala
while (some_altitude_function == 0):
    GPIO.output(buzzer_pin, GPIO.HIGH)
    sleep(5) # buzzes for 5 secs
    GPIO.output(buzzer_pin, GPIO.LOW)
    
GPIO.cleanup()
