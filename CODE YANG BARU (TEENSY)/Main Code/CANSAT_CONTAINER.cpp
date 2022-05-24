// function to calibrate sensor: bmp388
int calibrate() {}

// function to get sensor data
int get_data() {)

// function to store data to eeprom
int store_data() {)

// function to maintain camera to the south & pointed 45 degree downward & Record Video
int maintain_camera() {}

// function to send data to GCS
int send_data() {)

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if (bmp.readAltitude(SEALEVELPRESSURE_HPA) == 400) {
    // jalannya mekanisme pelepasan parasut yang lebih besar
  }
  if (bmp.readAltitude(SEALEVELPRESSURE_HPA) == 300) {
    // jalannya mekanisme pelepasan payload
  }
}