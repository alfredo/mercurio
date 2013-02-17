#include <LiquidCrystal.h>
#define POTENTIOMETER A0
#define BUTTON A1
#define MAXREADING 1023
#define MINBUTTON 700  // Button must be pressed quite well.
#define LCDCHARS 16    // Chars on the LCD

// Setup LCD.
LiquidCrystal lcd(11, 12, 2, 3, 4, 5);
// Stores potentiometer readings.
int potentiometerVal = 0;
// List of values for the potentiometer
// Added the whitespace to clear the LCD. Yes this could be done better.
char* destinationList[] = {
  "Test",
  "Staging",
  "Production"
  };
int destinationSize = sizeof(destinationList)/sizeof(int);
int segmentStep = destinationSize / MAXREADING;
String destination = "";
String lastDestination = "";
// Button value reading.
int buttonVal = 0;
// Debouncing variables.
long lastDebounceTime = 0;
long debounceDelay = 500;
boolean isBlocked = false;


void setup() {
  // Start talking to the serial.
  Serial.begin(9600);
  // Set up the LCD's number of columns and rows. 
  lcd.begin(LCDCHARS, 2);
  lcd.print("mercurio target:");
}


void loop() {
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Unblock it once the debounceDelay time has passed.
    isBlocked = false;
  }
  // Read the potentiometer input.
  potentiometerVal = analogRead(POTENTIOMETER);
  buttonVal = analogRead(BUTTON);
  destination = getDestination(potentiometerVal);
  // Only update the LCD when the destination has changed.
  if ( destination != lastDestination){
    printDestination(destination);
  } else {
    lastDestination = destination;
  }
  if (buttonVal > MINBUTTON && destination != "" && isBlocked == false) {
    // Actions to perform once a valid button press has been received.
    // The only value the serial expects is the destination.
    Serial.println("target=" + destination);
    // Capture when was the last time the button was pressed and block it.
    lastDebounceTime = millis();
    isBlocked = true;
  }
}

// Prints the target in the LCD.
void printDestination(String destination) {
  String fancyDestination = destination;
  int missingChars;
  // Fill in the rest of the display blocks with whitespace.
  missingChars = LCDCHARS - fancyDestination.length();
  if (missingChars > 0) {
    for (int i=0 ; i < missingChars; i++ ) {
      fancyDestination += " ";
    }
  }
  // Write output in the second line.
  lcd.setCursor(0, 1);
  // Show potentiometer reading in the LCD. Inmediate feedback from the target.
  lcd.print(fancyDestination);
}

// Determines the destination from the potentiometer reading.
String getDestination(int reading) {
  int i = 0;
  String destination;
  i = (reading * destinationSize) / MAXREADING;
  // When the potentiometer is at its MAXREADING value would return
  // a index not in the list.
  if (i == destinationSize) {
    i--;
  }
  destination = String(destinationList[i]);
  return destination;
}

