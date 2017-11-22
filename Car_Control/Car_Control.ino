
int vchannel1 =0;   //default signal value
int vchannel2 =0;
int vchannel3=0;
int vchannel4=0;
int vchannel5=0;
int vchannel6=0;    

float lvelocity=0;    //left motor velocity
float rvelocity=0;    //right motor velocity

#define channel1 2    //channl 1 connect to PWM pin 2
#define channel2 3    //channl 2 connect to PWM pin 3
#define channel3 9    //channl 3 connect to PWM pin 4
#define channel4 5    //channl 4 connect to PWM pin 5
#define channel5 6    //channl 5 connect to PWM pin 6
#define channel6 7

#define lmotor1 10    //leftmotor direction pin
#define lmotor2 11
#define lcontrol 8    //leftmotor speed controlling pin

#define rmotor1 53    //rightmotor direction pin 
#define rmotor2 51
#define rcontrol 9    //rightmotor speed controlling pin

void setup() 

{
  
    pinMode(channel1, INPUT);
    pinMode(channel2, INPUT);
    pinMode(channel3, INPUT);
    pinMode(channel4, INPUT);
    pinMode(channel5, INPUT);
    pinMode(channel6, INPUT);

    pinMode(lmotor1, OUTPUT);
    pinMode(lmotor2, OUTPUT);
    pinMode(rmotor1, OUTPUT);
    pinMode(rmotor2, OUTPUT);
    pinMode(lcontrol, OUTPUT);
    pinMode(rcontrol, OUTPUT);

    Serial.begin(9600);
    

}

void loop() 

{
  
    vchannel1=pulseIn(2,HIGH,20000);    //Decoding RF signal  
    vchannel2=pulseIn(3,HIGH,50000);
    vchannel3=pulseIn(4,HIGH,50000);
    vchannel4=pulseIn(5,HIGH,25000);
    vchannel5=pulseIn(6,HIGH,50000);
    //vchannel6=pulseIn(7,HIGH,25000);

     Serial.println(vchannel1);

Serial.print("channel 1 = ");   //active to callibrate                                                                                                                 ````````````````` `
Serial.println(vchannel1);
Serial.println(" ");

Serial.print("channel 2 = ");
Serial.println(vchannel2);
Serial.println(" ");

Serial.print("channel 3 = ");
Serial.println(vchannel3);
Serial.println(" ");

Serial.print("channel 4 = ");
Serial.println(vchannel4);
Serial.println(" ");



Serial.print("channel 5 = ");
Serial.println(vchannel5);
Serial.println(" ");

Serial.print("channel 6 = ");
Serial.println(vchannel6);
Serial.println(" ");




    if(vchannel5<1100)    //Forward direction checking
        {

            if(vchannel1>1500)  //Right direction checking
        
                {
                    lvelocity = (vchannel1-1490)*.53;   //velocity algorithm
                    if(lvelocity>252) lvelocity =255;   

                    digitalWrite(lmotor1, HIGH);    //move the bot right
                    digitalWrite(lmotor2, LOW);
                    analogWrite(lcontrol, lvelocity);

                    digitalWrite(rmotor1, LOW);
                    digitalWrite(rmotor2, HIGH);
                    analogWrite(rcontrol, lvelocity);

                    Serial.println("Front_RIGHT ");
 
  
                }

            if ((vchannel1>970) && (vchannel1<1450))   //left direction checking
                {
                    lvelocity=(1470-vchannel1)*.532;    //velocity algorithm
                    if(lvelocity>250) lvelocity =255;

                    digitalWrite(lmotor1, LOW);   //move the bot left
                    digitalWrite(lmotor2, HIGH);
                    analogWrite(lcontrol, lvelocity);

                    digitalWrite(rmotor1, HIGH);
                    digitalWrite(rmotor2, LOW);
                    analogWrite(rcontrol, lvelocity);
  
                    Serial.println("Front_LEFT ");
  
                }


            if(vchannel1>1450 && vchannel1<1500)    //straight forward checking  
                
                {
                    
                    rvelocity = (vchannel3-950)*.261;  //velocity algorithm
                    if(rvelocity>252) rvelocity =255;
                    if(rvelocity<60) rvelocity =0;
  
                    digitalWrite(lmotor1, HIGH);   //move the bot straight forward 
                    digitalWrite(lmotor2, LOW);
                    analogWrite(lcontrol, rvelocity);

                    digitalWrite(rmotor1, HIGH);
                    digitalWrite(rmotor2, LOW);
                    analogWrite(rcontrol, rvelocity);
                   
                    Serial.println("FORWARD ");
                } 


        }



    if (vchannel5>1100)   //checking backward direction
        
        {

            if(vchannel1>1500)    //right direction checking
               
                {
                    
                    lvelocity = (vchannel1-1490)*.53;   //velocity algorithm
                    if(lvelocity>252) lvelocity =255;

                    digitalWrite(lmotor1, HIGH);   //move bot right in back
                    digitalWrite(lmotor2, LOW);
                    analogWrite(lcontrol, lvelocity);

                    digitalWrite(rmotor1, LOW);
                    digitalWrite(rmotor2, HIGH);
                    analogWrite(rcontrol, lvelocity);

                    Serial.println("Back_RIGHT ");
 
              }

          if (vchannel1<1450 && vchannel1>400)   //left direction checking
              
             {
                  
                    lvelocity=(1470-vchannel1)*.532;    //velocity algorithm
                    if(lvelocity>250) lvelocity =255;

                    digitalWrite(lmotor1,LOW);    //move the bot left in back
                    digitalWrite(lmotor2,HIGH);
                    analogWrite(lcontrol, lvelocity);

                    digitalWrite(rmotor1, HIGH);
                    digitalWrite(rmotor2, LOW);
                    analogWrite(rcontrol, lvelocity);
  
                    Serial.println("Back_LEFT ");
  
              }

          if(vchannel1>1450 && vchannel1<1500)    //straight back checking
          
             {
   
                    rvelocity = (vchannel3-950)*.261;   //velocity checking
                   if(rvelocity>252) rvelocity =255;
                   if(rvelocity<60) rvelocity =0;

                   digitalWrite(lmotor1, LOW);   //move the bot straight back
                   digitalWrite(lmotor2, HIGH);
                   analogWrite(lcontrol, rvelocity);

                   digitalWrite(rmotor1, LOW);
                   digitalWrite(rmotor2, HIGH);
                   analogWrite(rcontrol, rvelocity);
                                                                                              
                   Serial.println("BACKWARD ");
  
             }
        }

}
