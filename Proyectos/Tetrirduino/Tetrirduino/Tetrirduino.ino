#include <Elegoo_GFX.h>    // Core graphics library
#include <Elegoo_TFTLCD.h> // Hardware-specific library


// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// When using the BREAKOUT BOARD only, use these 8 data lines to the LCD:
// For the Arduino Uno, Duemilanove, Diecimila, etc.:
//   D0 connects to digital pin 8  (Notice these are
//   D1 connects to digital pin 9   NOT in order!)
//   D2 connects to digital pin 2
//   D3 connects to digital pin 3
//   D4 connects to digital pin 4
//   D5 connects to digital pin 5
//   D6 connects to digital pin 6
//   D7 connects to digital pin 7
// For the Arduino Mega, use digital pins 22 through 29
// (on the 2-row header at the end of the board).

// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void setup() {
  Serial.begin(9600);
  Serial.println(F("TFT LCD test"));

#ifdef USE_Elegoo_SHIELD_PINOUT
  Serial.println(F("Using Elegoo 2.8\" TFT Arduino Shield Pinout"));
#else
  Serial.println(F("Using Elegoo 2.8\" TFT Breakout Board Pinout"));
#endif

  Serial.print("TFT size is "); Serial.print(tft.width()); Serial.print("x"); Serial.println(tft.height());

  tft.reset();

  uint16_t identifier = tft.readID();
   if(identifier == 0x9325) {
    Serial.println(F("Found ILI9325 LCD driver"));
  } else if(identifier == 0x9328) {
    Serial.println(F("Found ILI9328 LCD driver"));
  } else if(identifier == 0x4535) {
    Serial.println(F("Found LGDP4535 LCD driver"));
  }else if(identifier == 0x7575) {
    Serial.println(F("Found HX8347G LCD driver"));
  } else if(identifier == 0x9341) {
    Serial.println(F("Found ILI9341 LCD driver"));
  } else if(identifier == 0x8357) {
    Serial.println(F("Found HX8357D LCD driver"));
  } else if(identifier==0x0101)
  {     
      identifier=0x9341;
       Serial.println(F("Found 0x9341 LCD driver"));
  }else {
    Serial.print(F("Unknown LCD driver chip: "));
    Serial.println(identifier, HEX);
    Serial.println(F("If using the Elegoo 2.8\" TFT Arduino shield, the line:"));
    Serial.println(F("  #define USE_Elegoo_SHIELD_PINOUT"));
    Serial.println(F("should appear in the library header (Elegoo_TFT.h)."));
    Serial.println(F("If using the breakout board, it should NOT be #defined!"));
    Serial.println(F("Also if using the breakout, double-check that all wiring"));
    Serial.println(F("matches the tutorial."));
    identifier=0x9341;
  
  }
  
  tft.begin(identifier);
  tft.fillScreen(BLACK);
  tft.drawRect(79,9,152,302,WHITE);

  tft.drawRect(10,60,60,
  40,WHITE);
  tft.drawRect(10,160,60,100,WHITE);

  tft.setCursor(15,65);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.println("Score:");
  tft.setCursor(15,80);
  tft.println(0);
  
  tft.fillRect(80,10,15,15,YELLOW);
  tft.fillRect(95,25,15,15,RED);
  tft.fillRect(110,40,15,15,YELLOW);
  tft.fillRect(125,55,15,15,RED);
  tft.fillRect(140,70,15,15,YELLOW);
  tft.fillRect(155,85,15,15,RED);
  tft.fillRect(170,100,15,15,YELLOW);
  tft.fillRect(185,115,15,15,RED);
  tft.fillRect(200,130,15,15,YELLOW);
  tft.fillRect(215,145,15,15,RED);
  tft.fillRect(80,160,15,15,YELLOW);
  tft.fillRect(95,175,15,15,RED);
  tft.fillRect(110,190,15,15,YELLOW);
  tft.fillRect(125,205,15,15,RED);
  tft.fillRect(140,220,15,15,YELLOW);
  tft.fillRect(155,235,15,15,RED);
  tft.fillRect(170,250,15,15,YELLOW);
  tft.fillRect(185,265,15,15,RED);
  tft.fillRect(200,280,15,15,YELLOW);
  tft.fillRect(215,295,15,15,RED);
  
  
  

}



void loop() {
  // put your main code here, to run repeatedly:

}
