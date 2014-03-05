//SRF05//



#define ECHOPIN 2                            // Pin to receive echo pulse
#define TRIGPIN 3                            // Pin to send trigger pulse
int msg = 0;


void setup(){

  Serial.begin(9600);

  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}



void loop(){

  digitalWrite(TRIGPIN, LOW);                   // Set the trigger pin to low for 2uS
  delayMicroseconds(2);

  digitalWrite(TRIGPIN, HIGH);                  // Send a 10uS high to trigger ranging
  delayMicroseconds(10);

  digitalWrite(TRIGPIN, LOW);                   // Send pin low again

  int distance = pulseIn(ECHOPIN, HIGH);        // Read in times pulse

  // distance= distance/58;                        // Calculate distance from time of pulse                 

  if(distance > 4100)
    distance = 4100;
   
  if(distance < 200)
    distance = 200;

  msg = map(distance, 200, 4100, 0, 255);

  Serial.write(msg);                     

  delay(10);                                    // Wait 10mS before next ranging

}
