#define E1 10  // Enable Pin for motor 1
#define I1 8     // Control pin 1 for motor 1
#define I2 9     // Control pin 2 for motor 1


#define S1 11  // Enable Pin for motor 1
#define M1 12    // Control pin 1 for motor 1
#define M2 13    // Control pin 2 for motor 1

const int PIN_BOTON = 7;

byte estado_anterior = 0;
byte estado_nuevo; 
byte estado_led = LOW;


void setup()
   {
        // initialize pins
        pinMode( 8, OUTPUT);
        pinMode( 9, OUTPUT);
        pinMode( 10, OUTPUT);
        pinMode(PIN_BOTON, INPUT); //initialize pins
        pinMode( 11, OUTPUT);
        pinMode( 12, OUTPUT);
        pinMode( 13, OUTPUT);
   }
void loop()
   {   estado_nuevo = digitalRead(PIN_BOTON); //Read the state of the button
  if ((estado_anterior == 0) && (estado_nuevo == 1)) { //If "pressed" the button
    if (estado_led == LOW) {
      //if OFF the turn it ON
        digitalWrite(E1, HIGH);     // Activate Motor1
        digitalWrite(I1, HIGH);     // Start
        digitalWrite(I2, LOW);
        digitalWrite(S1, HIGH);     // Activate Motor2
        digitalWrite(M1, HIGH);     // Start
        digitalWrite(M2, LOW);
        delay(1000); 
        
    estado_led = HIGH; //Change the status of the led to ON 
  }
  else { //if the led is ON turn it OFF
        digitalWrite(E1, LOW);     // Activate Motor1
        digitalWrite(I1, LOW);     // Start
        digitalWrite(I2, LOW);
        digitalWrite(S1, LOW);     // Activate Motor2
        digitalWrite(M1, LOW);     // Start
        digitalWrite(M2, LOW);
        delay(1000); //Turn OFF the led
    estado_led = LOW; //Change the status of the led to ON
  }
  }
  estado_anterior = estado_nuevo; //update the status of the button
  delay(10);
  }
 
