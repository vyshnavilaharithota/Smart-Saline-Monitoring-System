#include <Servo.h>
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
char auth[] = "B_XLQ_2t66gkDFO25c6G7Bw_eSnFu-Mo";
char ssid[] = "Galaxy F41CJ7";
char pass[] = "12345678";

Servo servo;
#define IR1 D7
#define IR2 D6

bool ir1, ir2;

void setup()
{
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
    pinMode(IR1, INPUT);
    pinMode(IR2, INPUT);
    servo.attach(2); //D4
    servo.write(0);
}

void loop()
{
    ir1 = digitalRead(IR1);
    ir2 = digitalRead(IR2);
    if (ir2 != 0 && ir1 == 0)
    {
        Blynk.notify("Just before Saline Level Critical");
        servo.write(180);
        Serial.print("Just before Critical level");
    }
    else if (ir2 == 0 && ir1 == 0)
    {
        Blynk.notify("Saline Level Critical");
        servo.write(0);
        Serial.print("Critical level");
    }
    else
    {
        servo.write(180);
        Serial.print("Empty");
    }
}