#include <WiiChuck.h>

Accessory nunchuck;

void setup() {
  Serial.begin(115200);
  nunchuck.begin();
  if (nunchuck.type == Unknown) {
    /** If the device isn't auto-detected, set the type explicatly
     *  NUNCHUCK,
     WIICLASSIC,
     GuitarHeroController,
     GuitarHeroWorldTourDrums,
     DrumController,
     DrawsomeTablet,
     Turntable
     */
    nunchuck.type = NUNCHUCK;
  }
}

void loop() {
  Serial.println("-------------------------------------------");
  nunchuck.readData();    // Read inputs and update maps
  Serial.print("JOYX ");
  Serial.println(nunchuck.values[0]);
   Serial.print("JOYY ");
  Serial.println(nunchuck.values[1]);
  

}
