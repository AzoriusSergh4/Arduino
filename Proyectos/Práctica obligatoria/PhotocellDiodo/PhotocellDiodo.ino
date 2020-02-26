// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6 
int sensor = 0;
int photocell = 0;
int redValue;
int greenValue;
int blueValue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED, OUTPUT); 
  pinMode(GREEN, OUTPUT); 
  pinMode(BLUE, OUTPUT); 
  digitalWrite(RED, LOW); 
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW); 
}

void loop() {
  photocell = analogRead(sensor);
  if(photocell < 256){
      greenValue = 0+photocell;
      blueValue = 255-photocell;
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
       Serial.print("AZUL: ");
      Serial.println(blueValue);
      Serial.print("VERDE: ");
      Serial.println(greenValue);  
  }
  if(photocell>255 && photocell < 511){
    photocell = photocell-256;
    redValue = 0+photocell;
    greenValue= 255-photocell;
    analogWrite(GREEN, greenValue);
    analogWrite(RED, redValue);
     Serial.print("ROJO: ");
      Serial.println(redValue);
      Serial.print("VERDE: ");
      Serial.println(greenValue);  
  }
  if(photocell > 510){
    redValue = 255;
    analogWrite(RED, redValue);
    Serial.print("ROJO: ");
      Serial.println(redValue);
    }
     
 

}
