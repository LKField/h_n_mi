import netP5.*;
import oscP5.*;

/**
 * oscP5message by andreas schlegel
 * example shows how to create osc messages.
 * oscP5 website at http://www.sojamo.de/oscP5
 */
 
import oscP5.*;
import netP5.*;

OscP5 oscP5;
//NetAddress myRemoteLocation;

void setup() {
  size(400,400);
  frameRate(25);
  /* start oscP5, listening for incoming messages at port 12000 */
//  oscP5 = new OscP5(this,12000);
  oscP5 = new OscP5(this,9999);
  
  /* myRemoteLocation is a NetAddress. a NetAddress takes 2 parameters,
   * an ip address and a port number. myRemoteLocation is used as parameter in
   * oscP5.send() when sending osc packets to another computer, device, 
   * application. usage see below. for testing purposes the listening port
   * and the port of the remote location address are the same, hence you will
   * send messages back to this sketch.
   */
//  myRemoteLocation = new NetAddress("172.16.20.180",9999);
}


void draw() {
  background(0);  
}


/* incoming osc message are forwarded to the oscEvent method. */
void oscEvent(OscMessage theOscMessage) {
  /* print the address pattern and the typetag of the received OscMessage */
  print("### received an osc message.");
  print(" addrpattern: "+theOscMessage.addrPattern());
  println(" typetag: "+theOscMessage.typetag());
 
 //String data = theOscMessage.arguments;
 theOscMessage.printData();
 //println(" data: "+data);
  
}

//void oscEvent(OscBundle theBundle) {
//  println("received a bundle", theBundle);
//  for (OscMessage m : theBundle.get()) {
//    oscEvent(m); /* forward each message inside the bundle to oscEvent(OscMessage) */
//  }
//}

//void oscEvent(OscMessage theMessage) {
//  println("received a message", theMessage);
//}
