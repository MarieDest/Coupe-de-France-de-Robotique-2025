#include <Wire.h>
#define MAX_DISTANCE 200
#define Carte_Principale_Addresse 0x1E  


//ATTENTION LA NANO DANS LE MOYEN DE DETECTION ULTRASON UTILISE UNE VIELLE VERSION DU BOOTLOADER 
//ALLER DANS TOOLS, PROCESSOR ET CHOISIR (OLD BOOTLOADER)

// pour le HC595 voir https://eskimon.fr/tuto-arduino-901-ajouter-des-sorties-num%C3%A9riques-%C3%A0-larduino-le-74hc595#programmons-pour-utiliser-ce-composant


// Broche connectée au ST_CP du 74HC595
const int verrou = 8;
// Broche connectée au SH_CP du 74HC595
const int horloge = 9;
// Broche connectée au DS du 74HC595
const int data = 7;
float timeOut = MAX_DISTANCE *60;
int soundVelocity = 340;
const int Threashold = 50;
bool truc_detecte = false;
long currentTime = 0;
long timeSignalSend = 0;
 byte pinsUltrasons[8]={
    A0, //Ultrason 1
    A3, //Ultrason 2
    2, //Ultrason 3
    3, //Ultrason 4
    A1, //Ultrason 5
    6, //Ultrason 6
    5, //Ultrason 7
    4, //Ultrason 8
  };

void setup()
{
    // On met les broches en sortie
    pinMode(verrou, OUTPUT);
    pinMode(horloge, OUTPUT);
    pinMode(data, OUTPUT);
    for (int i = 0; i < 8; i++)
    {
      pinMode(pinsUltrasons[i],INPUT);
    }
    Serial.begin(9600);
    Wire.begin(Carte_Principale_Addresse);  
    currentTime = millis();
    timeSignalSend = millis();
    Wire.onRequest(requestEvent);
    delay(3000);
}


void loop()
{
    for (int i = 0; i < 8; i++)
    {  
        // On active le verrou le temps de transférer les données
        digitalWrite(verrou, LOW);
        // on envoie la donnée
        // ici, c'est assez simple.
        // On va décaler l'octet 00000001 i fois puis l'envoyer
        shiftOut(data, horloge, MSBFIRST, ~(0x01 << i));
        // et enfin on relache le verrou
        digitalWrite(verrou, HIGH);
        // une petite pause pour constater l'affichage
         delayMicroseconds(10);
         shiftOut(data, horloge, MSBFIRST, 0x00);
         int pingTime = pulseIn(pinsUltrasons[i],HIGH,timeOut);
         int distance = (float) pingTime * soundVelocity /2/ 10000;
         Serial.println("Ultrason i = "+String(i)+"distance = "+String(distance));
         determine_signal_to_send(distance);
         delay(50);//1000   
    }
}
void determine_signal_to_send(int distance){
  currentTime = millis();
  if( distance <Threashold && distance!=0){
    if(!truc_detecte){
       Serial.println("\n\n\n /////////////truc detecte///////////////// \n\n\n");
       truc_detecte = true;
       timeSignalSend = millis();
    }else{
      timeSignalSend = millis();
    }
  }else{
    if((abs(currentTime - timeSignalSend)>2000) && (truc_detecte)){
       Serial.println("\n\n\n *************plus de  truc detecte *************\n\n\n");
      truc_detecte = false;
    }
  }
 
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  if(truc_detecte){
    Wire.write("truc detecte");
  }else{
    Wire.write("rien detecte");
  }
// respond with message of 12 bytes
  // as expected by master
}
