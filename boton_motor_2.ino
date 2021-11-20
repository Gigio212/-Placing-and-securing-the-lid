#define E1 10    // Enable Pin for motor 1
#define I1 8     // Control pin 1 for motor 1
#define I2 9     // Control pin 2 for motor 1

#define S1 11    // Enable Pin for motor 2
#define M1 12    // Control pin 1 for motor 2
#define M2 13    // Control pin 2 for motor 2

#define J1 5    // Control pin 1 for motor 3
#define J2 4    // Control pin 2 for motor 3
#define K1 3    // Enable Pin motor 3

#define IR 6     // Sensor IR 

const int PIN_BOTON = 7;

enum estados {parado, corriendo};
enum estados estado;
int estado_nuevo; 


void setup()
   {
        // initialize pins
        pinMode( 8, OUTPUT);
        pinMode( 9, OUTPUT);
        pinMode( 10, OUTPUT);
        pinMode(PIN_BOTON, INPUT);
        pinMode( 11, OUTPUT);
        pinMode( 12, OUTPUT);
        pinMode( 13, OUTPUT);
        pinMode( 6,   INPUT);
        pinMode( 5,  OUTPUT);
        pinMode( 4,  OUTPUT);
        pinMode( 3,  OUTPUT);
        // Serial.begin(9600);
        estado = parado;
   }


void control_motores(int boton) {
        switch (estado) {
          case (parado):
            digitalWrite(E1, LOW);     // Motor1
            digitalWrite(I1, LOW);    
            digitalWrite(I2, LOW);
            digitalWrite(S1, LOW);     // Motor2
            digitalWrite(M1, LOW);    
            digitalWrite(M2, LOW);
            digitalWrite(K1, LOW);     // Motor 3
            digitalWrite(J1, LOW);
            digitalWrite(J2, LOW);

            if (boton == 1){
                estado = corriendo;
                delay(500);
            }
            break;


          case (corriendo):
            if (digitalRead(IR)==HIGH){
              digitalWrite(J1, HIGH);
              digitalWrite(J2, LOW);
              analogWrite(K1, 200);
              delay(500);
            }
            
            analogWrite(E1, 255);       // Activate Motor1
            digitalWrite(I1, HIGH);     // Start
            digitalWrite(I2, LOW);
            digitalWrite(S1, HIGH);     // Activate Motor2
            digitalWrite(M1, HIGH);     // Start
            digitalWrite(M2, LOW);
            digitalWrite(K1, LOW);      // Motor 3
            digitalWrite(J1, LOW);
            digitalWrite(J2, LOW);

            if (boton == 1){
              estado = parado;
              delay(500);
            }
            break;
        }    
}


void loop()
  {
        estado_nuevo = digitalRead(PIN_BOTON); //Read the state of the button
        control_motores(estado_nuevo);
        // Serial.print("Estado: ");
        // Serial.println(estado_nuevo);
        delay(100);
  }
