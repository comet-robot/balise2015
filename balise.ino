// définition des broches utilisées
int trig1 = A0;
int echo1 = A1;
int trig2 = A2;
int echo2 = A3;
int trig3 = A4;
int echo3 = A5;
int trig4 = 2;
int echo4 = 3;
int trig5 = 4;
int echo5 = 5;
int trig6 = 6;
int echo6 = 7;
int led = 13;
int avant_proche=8;
int arriere_proche=9;
int avant_critique=10;
int arriere_critique=11;





long lecture_echo;
long cm1;
long cm2;
long cm;

void setup()
{
  pinMode(led, OUTPUT);//led de test
  digitalWrite(led, LOW);
  
  pinMode(avant_proche, OUTPUT);
  digitalWrite(avant_proche, LOW);
  pinMode(avant_critique, OUTPUT);//led de test 
  digitalWrite(avant_critique, LOW);
  
  pinMode(arriere_proche, OUTPUT);
  digitalWrite(arriere_proche, LOW);
  pinMode(arriere_critique, OUTPUT);//led de test 
  digitalWrite(arriere_critique, LOW); 
  
  
  
  /*init de tout les capteurs*/
  pinMode(trig1, OUTPUT);
  digitalWrite(trig1, LOW);
  pinMode(echo1, INPUT);
  
  pinMode(trig2, OUTPUT);
  digitalWrite(trig2, LOW);
  pinMode(echo2, INPUT);
  
  pinMode(trig3, OUTPUT);
  digitalWrite(trig3, LOW);
  pinMode(echo3, INPUT);
  
  pinMode(trig4, OUTPUT);
  digitalWrite(trig4, LOW);
  pinMode(echo4, INPUT);
  
  pinMode(trig5, OUTPUT);
  digitalWrite(trig5, LOW);
  pinMode(echo5, INPUT);
  
  pinMode(trig6, OUTPUT);
  digitalWrite(trig6, LOW);
  pinMode(echo6, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  //capteur 1
  digitalWrite(trig1, HIGH);/*lance la detection*/
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  lecture_echo = pulseIn(echo1, HIGH);/*mesure la durée de echo à l'etat haut*/
  cm1 = lecture_echo / 58;/*transforme temps en longueur*/
  delay(20);
  
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  lecture_echo = pulseIn(echo1, HIGH);
  cm2 = lecture_echo / 58;
  Serial.print("distance capteur 1 :");
  Serial.println(cm);
  if(abs(cm2 - cm1) > 50) //pour éviter les aberrations
   {
     cm = min(cm1,cm2);
   }
   else{cm = (cm1 + cm2)/2;}
   if(cm < 40){//premiere zone  
    Serial.println("Arret capteur 1");
    digitalWrite(avant_proche, LOW);
    digitalWrite(avant_critique, HIGH);
  }
  else{
    if(cm < 60){
      Serial.println("proche capteur 1");
    digitalWrite(avant_proche, HIGH);
    digitalWrite(avant_critique, LOW);
      }
    else{
    digitalWrite(avant_proche, LOW);
    digitalWrite(avant_critique, LOW);
    Serial.print("distance capteur 1 :");
    Serial.println(cm);
  }
    
    }
  delay(20);
  
  //capteur 2
  /*digitalWrite(trig2, HIGH);//lance la detection
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  lecture_echo = pulseIn(echo2, HIGH);//mesure la durée de echo à l'etat haut
  cm1 = lecture_echo / 58;//transforme temps en longueur
  delay(20);
  
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  lecture_echo = pulseIn(echo2, HIGH);
  cm2 = lecture_echo / 58;
  if(abs(cm2 - cm1) > 50) //pour éviter les aberrations
   {
     cm = min(cm1,cm2);
     
   }
   else{cm = (cm1 + cm2)/2;}
   if(cm < 40){//premiere zone  
    Serial.println("Arret capteur 2");
    digitalWrite(led, HIGH);
    delay(10);
    digitalWrite(led, LOW);
  }
  else{
    Serial.print("distance capteur 2 :");
    Serial.println(cm);
    }
  delay(20);
  
  //capteur 3
  digitalWrite(trig3, HIGH);//lance la detection
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);
  lecture_echo = pulseIn(echo3, HIGH);//mesure la durée de echo à l'etat haut
  cm1 = lecture_echo / 58;//transforme temps en longueur
  delay(20);
  
  
  digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);
  lecture_echo = pulseIn(echo3, HIGH);
  cm2 = lecture_echo / 58;
  if(abs(cm2 - cm1) > 50) //pour éviter les aberrations
   {
     cm = min(cm1,cm2);
   }
   else{cm = (cm1 + cm2)/2;}
   if(cm < 40){//premiere zone  
    Serial.println("Arret capteur 3");
    digitalWrite(led, HIGH);
    delay(10);
    digitalWrite(led, LOW);
  }
  else{
    Serial.print("distance capteur 3 :");
    Serial.println(cm);
    }
  delay(20);*/
   //capteur 4
  digitalWrite(trig4, HIGH);//lance la detection
  delayMicroseconds(10);
  digitalWrite(trig4, LOW);
  lecture_echo = pulseIn(echo4, HIGH);//mesure la durée de echo à l'etat haut
  cm1 = lecture_echo / 58;//transforme temps en longueur
  delay(20);
  
  
  digitalWrite(trig4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig4, LOW);
  lecture_echo = pulseIn(echo4, HIGH);
  cm2 = lecture_echo / 58;
  if(abs(cm2 - cm1) > 50) //pour éviter les aberrations
   {
     cm = min(cm1,cm2);
   }
   else{cm = (cm1 + cm2)/2;}
if(cm < 40){//premiere zone  
    Serial.println("Arret capteur 2");
    digitalWrite(arriere_proche, LOW);
    digitalWrite(arriere_critique, HIGH);
  }
  else{
    if(cm < 60){
      Serial.println("proche capteur 2");
    digitalWrite(arriere_proche, HIGH);
    digitalWrite(arriere_critique, LOW);
      }
    else{
    digitalWrite(arriere_proche, LOW);
    digitalWrite(arriere_critique, LOW);
    Serial.print("distance capteur 2 :");
    Serial.println(cm);
  }
    
    }
  delay(20);
  /*
   //capteur 5
  digitalWrite(trig5, HIGH);//lance la detection
  delayMicroseconds(10);
  digitalWrite(trig5, LOW);
  lecture_echo = pulseIn(echo5, HIGH);//mesure la durée de echo à l'etat haut
  cm1 = lecture_echo / 58;//transforme temps en longueur
  delay(20);
  
  
  digitalWrite(trig5, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig5, LOW);
  lecture_echo = pulseIn(echo5, HIGH);
  cm2 = lecture_echo / 58;
  if(abs(cm2 - cm1) > 50) //pour éviter les aberrations
   {
     cm = min(cm1,cm2);
   }
   else{cm = (cm1 + cm2)/2;}
   if(cm < 40){//premiere zone  
    Serial.println("Arret capteur 5");
    digitalWrite(led, HIGH);
    delay(10);
    digitalWrite(led, LOW);
  }
  else{
    Serial.print("distance capteur 5 :");
    Serial.println(cm);
    }
  delay(20);
   //capteur 6
  digitalWrite(trig6, HIGH);//lance la detection
  delayMicroseconds(10);
  digitalWrite(trig6, LOW);
  lecture_echo = pulseIn(echo6, HIGH);//mesure la durée de echo à l'etat haut
  cm1 = lecture_echo / 58;//transforme temps en longueur
  delay(20);
  
  
  digitalWrite(trig6, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig6, LOW);
  lecture_echo = pulseIn(echo6, HIGH);
  cm2 = lecture_echo / 58;
  if(abs(cm2 - cm1) > 50) //pour éviter les aberrations
   {
     cm = min(cm1,cm2);
   }
   else{cm = (cm1 + cm2)/2;}
   if(cm < 40){//premiere zone  
    Serial.println("Arret capteur6");
  }
  else{
    Serial.print("distance capteur 6 :");
    Serial.println(cm);
    }
  delay(20);
  */
 // digitalWrite(trig4, HIGH);
  //delayMicroseconds(10);
 // digitalWrite(trig4, LOW);
  //lecture_echo = pulseIn(echo4, HIGH);
  //cm = lecture_echo / 58;
  //Serial.print("capteur 4: ");
  //Serial.println(cm);
  //delay(20);
  
  
  
  
  
  
  
}
