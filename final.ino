#include <dht.h>
dht DHT;
#define DHT11_PIN 7

const int moistureAO=0;
int AO=0;
int tmp=0;
//int LED=13;
int WATERPUMP = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println("Soil Moisture");
  pinMode(moistureAO,INPUT);
//  pinMode(LED, OUTPUT);
  pinMode(WATERPUMP,OUTPUT);
}

void loop() {
  Start:
  // put your main code here, to run repeatedly:
  tmp=analogRead( moistureAO);
  if ( tmp!= AO ){
    AO=tmp;
    Serial.println("  ");
    
    Serial.print("Soil Moisture A = ");
    Serial.println(AO);
  int chk = DHT.read11(DHT11_PIN);
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
  }
 delay(1000);
  if(AO>290){
    //Serial.println("LED High");
    //digitalWrite(LED,HIGH);
    digitalWrite(WATERPUMP,250);
    delay(1000);
    //digitalWrite(LED,LOW);
    //Serial.println("LED Low");
    digitalWrite(WATERPUMP,0);
  }
  else{
    //digitalWrite(LED,LOW);
  }
 
    goto Start;
    delay(1000);
     
}
