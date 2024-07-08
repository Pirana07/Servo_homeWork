#include <Servo.h>
#include <IRremote.h>

const int recvPin = 2; // პინი დაკავშირებულია IR მიმღებთან
const int servoPin = 9; // პინი დაკავშირებულია სერვოსთან

Servo myServo;
IRrecv irrecv(recvPin);
decode_results results;

int angle = 0; // სერვოს საწყისი პოზიცია

void setup() {
  myServo.attach(servoPin);
  myServo.write(angle);
  Serial.begin(9600); // სერიული კომუნიკაციის ინიცირება გამართვისთვის
    IrReceiver.begin(recvPin);
    

}

void loop() {
  if (IrReceiver.decode()) {
    int x = IrReceiver.decodedIRData.command;
    IrReceiver.resume();
   

    
    if (x == 4) { // მარცხნივ  ღილაკი
      angle += 30;
      myServo.write(angle);
    } else if (x == 6) { // ღილაკი მარჯვნივ
            angle -= 30;

      myServo.write(angle);
    }

    irrecv.resume(); // მიიღეთ შემდეგი მნიშვნელობა
  }
}


