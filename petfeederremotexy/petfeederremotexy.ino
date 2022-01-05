
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "elif"
#define REMOTEXY_WIFI_PASSWORD "123456789"
#define REMOTEXY_SERVER_PORT 6377
#pragma pack(pop)

#define PIN_FEEDBUTTON 9

#include <Servo.h>  
Servo myservo; 

// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,1,0,0,0,42,0,13,16,1,
  1,0,23,36,18,18,0,31,0,129,
  0,13,2,36,7,24,80,101,116,32,
  70,101,101,100,101,114,0,129,0,25,
  56,14,6,24,70,101,101,100,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t feedButton; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;



void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_FEEDBUTTON, OUTPUT);
  myservo.attach(9);
  myservo.write(180);
  }
  


void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_FEEDBUTTON, (RemoteXY.feedButton==0)?LOW:HIGH);

  if (RemoteXY.feedButton!=0) {
    /*  button pressed */
    myservo.write(0);
    delay(250);
    myservo.write(180);
  }
 

   


}
