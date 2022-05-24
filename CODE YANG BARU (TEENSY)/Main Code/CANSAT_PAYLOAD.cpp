// function to calibrate sensor: bmp388
int calibrate() {}

// function to get sensor data
int get_data() {)

// function to store data to eeprom
int store_data() {)

// function to send data to container
int send_data() {)

// function to maintain camera to the south & pointed 45 degree downward & Record Video
int maintain_camera() {}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if (bmp.readAltitude(SEALEVELPRESSURE_HPA) == 0) {
    // aktifkan buzzer
  }
}