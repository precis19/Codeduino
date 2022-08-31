const int ledPin = 13;

void setup() {

Serial.begin(9600);
pinMode(ledPin, OUTPUT);

  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  static int delayPeriod = 100; 
/* si pas de static(delayPeriod est toujours 200, countDir est toujours 1)
si il ya static int delayPeriod, alors (delayPeriod + 100)*(int countDir = 1) ainsi de suite--> 1000 sous condition delayPeriod += 100*(countDir = 1) */

  static int countDir = 1;
digitalWrite(ledPin, HIGH);
delay(delayPeriod);
digitalWrite(ledPin, LOW);
delay(delayPeriod);
 
countDir = checkDirChange(delayPeriod, countDir);

delayPeriod += 100 * countDir; // (int delayPeriod + 100)*(int countDir = 1) = 200
Serial.print("New Wait Time : ");
Serial.println(delayPeriod);
}

int checkDirChange(int delayPeriod, int countDir)
{
  if((delayPeriod == 1000) || (delayPeriod == 0)) // une fois que delayPeriod est static et = 1000 alors int countDir = -1, donc on a ensuite delayPeriod= 1000+100*(-1) et --> 900 que countDir redevient 1 )
  {
    countDir *=-1;

    if(countDir < 0)
    { Serial.println("Going Down"); }  
    else{Serial.println("Going up");}
  }
return  countDir;
}  
