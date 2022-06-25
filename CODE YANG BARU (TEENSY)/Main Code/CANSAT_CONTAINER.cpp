// Masukkan library yang diperlukan
#include <Servo.h>
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

#include <Wire.h>
#include <SPI.h>

#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10
#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BMP3XX bmp;

/* Assign a unique ID to this sensor at the same time */
Adafruit_FXOS8700 accelmag = Adafruit_FXOS8700(0x8700A, 0x8700B);
Adafruit_FXAS21002C gyro = Adafruit_FXAS21002C(0x0021002C);

// Buat Objek servo
Servo myservo;

// variabel untuk kamera
int trig = 0;
int led = 1;

// you can change the pin numbers to match your wiring:
SoftwareSerial mySerial(8, 7);
Adafruit_GPS GPS(&mySerial);

// Set GPSECHO to 'false' to turn off echoing the GPS data to the Serial console
// Set to 'true' if you want to debug and listen to the raw GPS sentences
#define GPSECHO  true

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
  myservo.attach(9); // sambungkan ke pin tempat servo

  // inisialisasi pin untuk kamera
  pinMode(led, OUTPUT);
  pinMode(trig, OUTPUT);         

  digitalWrite(led, HIGH);  
  digitalWrite(trig, HIGH);

  Serial.begin(115200);

  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (bmp.readAltitude(SEALEVELPRESSURE_HPA) == 400) {
    // jalannya mekanisme pelepasan parasut yang lebih besar
  }
  if (bmp.readAltitude(SEALEVELPRESSURE_HPA) == 300) {
    // jalannya mekanisme pelepasan payload
  }

  // implementasi mqtt
  int rc;
  struct mosquitto * mosq;

  mosquitto_lib_init();

  mosq = mosquitto_new("publisher-test", true, NULL);

  // diubah berdasarkan mqtt broker yang digunakan 
  rc = mosquitto_connect(mosq, "localhost", 1883, 60);
  
  if(rc != 0){
    printf("Client could not connect to broker! Error Code: %d\n", rc);
    mosquitto_destroy(mosq);
    return -1;
  }
  printf("We are now connected to the broker!\n");

  // berisi pesan yang akan di publish
  mosquitto_publish(mosq, NULL, "test/t1", 6, "Hello", 0, false);

  mosquitto_disconnect(mosq);
  mosquitto_destroy(mosq);

  mosquitto_lib_cleanup();
  return 0;
}