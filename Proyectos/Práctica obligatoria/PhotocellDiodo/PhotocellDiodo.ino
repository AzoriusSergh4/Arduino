// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6 
int sensor = 0;
int photocell = 0;
int redValue;
int greenValue;
int blueValue;

//Cotas
#define LOWERBOUND 150
#define UPPERBOUND 660
#define MAXRGB 255 
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
  Serial.print("SENSOR: ");
  Serial.println(photocell);
  if(photocell <= LOWERBOUND){
      blueValue = 255;
      analogWrite(BLUE, blueValue);
      Serial.print("AZUL: ");
      Serial.println(blueValue);
    }
  if(photocell > LOWERBOUND && photocell <= LOWERBOUND+MAXRGB){
    photocell = photocell - LOWERBOUND;
      greenValue = 0 + photocell;
      blueValue = MAXRGB - photocell;
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
       Serial.print("AZUL: ");
      Serial.println(blueValue);
      Serial.print("VERDE: ");
      Serial.println(greenValue);  
  }
  if(photocell>LOWERBOUND+MAXRGB && photocell <= UPPERBOUND){
    photocell = photocell-MAXRGB-LOWERBOUND;
    redValue = 0+photocell;
    greenValue= 255-photocell;
    analogWrite(GREEN, greenValue);
    analogWrite(RED, redValue);
     Serial.print("ROJO: ");
      Serial.println(redValue);
      Serial.print("VERDE: ");
      Serial.println(greenValue);  
  }
  if(photocell > UPPERBOUND){
    redValue = 255;
    analogWrite(RED, redValue);
    Serial.print("ROJO: ");
      Serial.println(redValue);
    }
     
 

}
