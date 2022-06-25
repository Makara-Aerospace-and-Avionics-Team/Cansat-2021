// Masukkan library yang diperlukan
#include <Servo.h>
#include <Adafruit_FXOS8700.h>
#include <Adafruit_FXAS21002C.h>

#include <SPI.h>

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10
#define SEALEVELPRESSURE_HPA (1013.25)

int buzzerPin = 13;

/* Assign a unique ID to this sensor at the same time */
Adafruit_FXOS8700 accelmag = Adafruit_FXOS8700(0x8700A, 0x8700B);
Adafruit_FXAS21002C gyro = Adafruit_FXAS21002C(0x0021002C);

Adafruit_BMP3XX bmp;

// Buat Objek servo
Servo myservo;

// variabel untuk kamera
int trig = 0;
int led = 1;

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
  Serial.begin(115200);
  
  // put your setup code here, to run once:
  myservo.attach(9); // sambungkan ke pin tempat servo
  
  // inisialisasi pin untuk kamera
  pinMode(led, OUTPUT);
  pinMode(trig, OUTPUT);         

  digitalWrite(led, HIGH);  
  digitalWrite(trig, HIGH);

  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bmp.readAltitude(SEALEVELPRESSURE_HPA) == 0) {
    digitalWrite(buzzerPIN, HIGH);
    delay(5000);
    digitalWrite(buzzerPIN, LOW);
    delay(2000);
  }
}