// SerialMouse sketch
#define potXPin 0
#define potYPin 1

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int x = (512 - analogRead(potXPin)) / 4;// range is -127 to +127
  int y = (512 - analogRead(potYPin)) / 4;
  Serial.print(x,DEC);
  Serial.print(",");
  Serial.print(y,DEC);
  Serial.println();  // send a cr/lf
  delay(50); // send position 20 times a second
}

/**** PROCESSING SKETCH   *********


//WARNING: This sketch takes over your mouse
 //Press escape to close running sketch 

import processing.serial.*;
import java.awt.Robot;
import java.awt.AWTException;
import java.awt.event.KeyEvent;



Serial myPort;     // Create object from Serial class
Robot myRobot;     // create object from Robot class;


public static final char HEADER = 'M';    // character to identify the start of a message
public static final short LF = 10;        // ASCII linefeed
public static final short portIndex = 1;  // select the com port, 0 is the first port


void setup() {
  size(200, 200);
  println(Serial.list());
  println(" Connecting to -> " + Serial.list()[2]);
  myPort = new Serial(this,Serial.list()[2], 9600);

  try {
    myRobot = new Robot(); // the Robot class gives access to the mouse
  }
  catch (AWTException e) {  // this is the Java exception handler
    e.printStackTrace();
  }
}

void draw() {

}

void serialEvent(Serial p) {
  String message = myPort.readStringUntil(LF); // read serial data
  if(message != null)
  {
    print(message);
    String [] data  = message.split(","); // Split the comma-separated message
    if(data[0].charAt(0) == HEADER) // check for header character in the first field
    {
      if( data.length > 2)
      {
        int x = Integer.parseInt(data[1]);
        int y = Integer.parseInt(data[2]);
        print("x= " + x);
        println(", y= " + y);
        myRobot.mouseMove(x,y); // move mouse to received x and y position
      }
    }
  }
}

******/
