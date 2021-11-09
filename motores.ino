#define E1 10  // Enable Pin for motor 1
#define I1 8     // Control pin 1 for motor 1
#define I2 9     // Control pin 2 for motor 1

#define S1 11  // Enable Pin for motor 1
#define M1 12    // Control pin 1 for motor 1
#define M2 13    // Control pin 2 for motor 1

void setup()
   {
        // initialize pins
        pinMode( 8, OUTPUT);
        pinMode( 9, OUTPUT);
        pinMode( 10, OUTPUT);
        pinMode( 11, OUTPUT);
        pinMode( 12, OUTPUT);
        pinMode( 13, OUTPUT);
   }
void loop()
   {    digitalWrite(E1, HIGH);     // Activate Motor1
        digitalWrite(I1, HIGH);     // Start
        digitalWrite(I2, LOW);
        digitalWrite(S1, HIGH);     // Activate Motor1
        digitalWrite(M1, HIGH);     // Start
        digitalWrite(M2, LOW);
        delay(1000);
  }
