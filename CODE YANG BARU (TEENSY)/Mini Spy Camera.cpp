int trig = 0;
int led = 1;

void setup() {                
  // initialize the digital pins as output.
  pinMode(led, OUTPUT);
  pinMode(trig, OUTPUT);         

  digitalWrite(led, HIGH);  
  digitalWrite(trig, HIGH); 
}

void loop() {
  digitalWrite(trig, LOW);   
  digitalWrite(led, LOW);
  
  delay(50);               

  digitalWrite(trig, HIGH);    
  digitalWrite(led, HIGH);   

  //Delay between pictures
  delay(10000);                
}