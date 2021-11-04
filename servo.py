# https://cdn-shop.adafruit.com/product-files/2442/FS90R-V2.0_specs.pdf

import RPi.GPIO as GPIO

class ContinuousServo:
    def __init__(self, pin, min_us=700, stop_us=1500, max_us=2300, frequency=50):
        GPIO.setup(pin, GPIO.OUT)
        self.pwm = GPIO.PWM(pin, frequency)
        self.pwm.start(0)
        self.min = min_us
        self.stop = stop_us
        self.max = max_us
        self.period = 1000000//frequency # dalam mikro sekon


    def set_angle(self, angle):
        percent = (angle / 360) * 100
        #print(f"Percent = {percent}")
        self.speed(percent)

        
    # -100% full speed backwards and 100% full speed forwards.
    def speed(self, percent=0):
        if (percent == 0):
            period = self.stop
        elif (percent < 0):
            period = round(self.stop + ((self.stop - self.min) * percent / 100))
        else:
            period = round(self.stop +((self.max - self.stop) * percent / 100))

        #print(f"Period = {period}")
        self.pulse(period)


    def pulse(self, period):
        if period < 0:
            period = -period
        else:
            period = max(min(period, self.max), self.min) # boundary
            duty = (period * 100) / self.period

            #print(f"Duty pulse = {duty}")
            self.pwm.ChangeDutyCycle(duty)


    def off(self):
        self.pwm.stop()

          
#servo = ContinuousServo(min_us=200, stop_us=1500, max_us=2200, frequency=50)
servo = ContinuousServo()
servo.set_angle(420)
#servo.speed(-25)
