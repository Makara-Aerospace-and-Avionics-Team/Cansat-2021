from picamera import PiCamera
import time

camera = PiCamera()
camera.resolution = (640,840)

camera.start_preview() #untuk mulai camera
time.sleep(2) #harus menunggu

camera.start_recording("lomba_maat.h264")
time.sleep(5) #jika ingin looking merekam 5 detik. nanti bisa pake millis atau sejenisnya
camera.stop_recording()