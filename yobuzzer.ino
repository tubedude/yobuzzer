int led = D7;
int buzz = D3;
int pinNumber ;

void setup()
{

   pinMode(led, OUTPUT);
   pinMode(buzz, OUTPUT);

   Spark.function("led",ledToggle);
   Spark.function("horn",horn);
   Spark.function("yo", yo);
   digitalWrite(led, LOW);
   analogWrite(buzz, LOW);
}

void loop ()
{

}
int yo(String command) {
    horn(command);
    return ledToggle(command);
}

int horn(String command) {
    return buzzHorn("D3");
}
int buzzHorn(String pin) {
    pinNumber = getPin(pin);
    
    int x = 1;
    for (int i = 0; i > -1; i = i + x)
    {
        analogWrite(pinNumber, i);
        if (i == 20) x = -1;     // switch direction at peak
        delay(10);
    }
    return 1;

}

int getPin(String pin) {
    pinNumber = pin.charAt(1) - '0';
    if(pin.startsWith("A")) pinNumber = pinNumber + 10;
    return pinNumber;
}

int toggle(String pin, String command) {
    
    pinNumber = getPin(pin);
    
    if (command=="on") {
        digitalWrite(pinNumber,HIGH);
        return 1;
    }
    else if (command=="off") {
        digitalWrite(pinNumber,LOW);
        return 0;
    }
    else if (command=="toggle") {
      
      if (digitalRead(pinNumber)==HIGH) {
        ledToggle("off");
        return 0;
      }
      else if (digitalRead(pinNumber)==LOW) {
        ledToggle("on");
        return 1;

      }
      else {
          return -1;
      }
    }
    else {
        return -1;
    }
    
}
int ledToggle(String command) {
    return toggle("D7", command);
}
