// Seguidor de Líneas
 
int E1 = 9; //  Enable para L293D
int I1 = 5; //  Pin IN L293D
int I2 = 6; //  Pin IN L293D

int E2 = 10; // Enable para L293D
int I3 = 7; //  Pin IN L293D
int I4 = 8; //  Pin IN L293D
 
int speed = 100;
boolean direction = 1; // 1 (true) indica adelante, 0 indica reversa
int izq = 0;
int der = 0;
 
int limite = 400; // Valor inicial para la pista
 
void setup()
{
    enciende_motores();
    Serial.begin(9600);
}
 
void loop()
{
    sensor_lectura();
    avanza_robot();
    delay(1);
}
 
void sensor_lectura()
{
    //Canales de Entrada y salida para los sensores. Sólo será salida.
    izq = analogRead(A0);
    der = analogRead(A5);
    Serial.print("Izquierda: ");
    Serial.print(izq);
    Serial.print(" Derecha: ");
    Serial.println(der);
}
 
void avanza_robot(){
    if ( izq < limite && der < limite ) {
        // El robot se desplazará siempre que los sensores estén en una superficie menor al valor establecido
          digitalWrite(E1, HIGH);     
          digitalWrite(E2, HIGH);  
          digitalWrite(I1, HIGH);  
          digitalWrite(I3, HIGH);   
          digitalWrite(I2, LOW);  
          digitalWrite(I4, LOW);
        delay(100);  
        
        digitalWrite(E1, LOW);     
          digitalWrite(E2, LOW);  
          digitalWrite(I1, LOW);  
          digitalWrite(I3, LOW);   
          digitalWrite(I2, LOW);  
          digitalWrite(I4, LOW);
        delay(200);  
          
        Serial.println("Avanzando");
    }
    else if ( izq > limite && der < limite) {
          digitalWrite(E1, HIGH);       
          digitalWrite(I3, HIGH);  
          digitalWrite(I4, LOW);  
          
           digitalWrite(E2, LOW); 
          digitalWrite(I1, LOW);          
          digitalWrite(I2, LOW);     
        
        delay(100);
      
       digitalWrite(E1, LOW);       
          digitalWrite(I3, LOW);  
          digitalWrite(I4, LOW);  
          
           digitalWrite(E2, LOW); 
          digitalWrite(I1, LOW);          
          digitalWrite(I2, LOW);     
        
       delay(200);  
          
        Serial.println("A la Izquierda");
    }
    else if ( izq < limite && der > limite) {
          digitalWrite(E1, LOW);       
          digitalWrite(I3, LOW);  
          digitalWrite(I4, LOW); 
      
          digitalWrite(E2, HIGH); 
          digitalWrite(I1, HIGH);          
          digitalWrite(I2, LOW);       
      
     delay(100);
 
 digitalWrite(E1, LOW);       
          digitalWrite(I3, LOW);  
          digitalWrite(I4, LOW); 
      
          digitalWrite(E2, LOW); 
          digitalWrite(I1, LOW);          
          digitalWrite(I2, LOW); 
delay(200);
          
        Serial.println("A la derecha");
    }
    else if  (izq >= limite && der >= limite) {    // En caso de que los dos sensores estén sobre la línea negra o cualquier otra superficie con valor elevado
                                                  //el seguidor de líneas se detendrá
          digitalWrite(E1, LOW);     
          digitalWrite(E2, LOW);  
          digitalWrite(I1, LOW);  
          digitalWrite(I3, LOW);   
          digitalWrite(I2, LOW);  
          digitalWrite(I4, LOW);   
        Serial.println("Por favor colocame sobre la pista.");
    }
}
 
void enciende_motores()
{
    // Salidas
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
 
    // Motor
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    digitalWrite(I1, 1);
    digitalWrite(I2, 0);
    digitalWrite(I3, 1);
    digitalWrite(I4, 0);
}

//Desarrollo y programación seguidor de líneas Luis Fragoso
 
