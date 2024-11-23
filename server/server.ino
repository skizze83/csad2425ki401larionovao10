void setup() {
  // Set up the serial port
  Serial.begin(9600);
  // Additional output to confirm the start of operation
  Serial.println("Arduino ready");
}

void loop() {
  // Check if there are incoming data
  if (Serial.available() > 0) {
    // Receive the message
    String message = Serial.readString();
    
    message.trim();

    message = message + " modified";

    // Send the modified message back
    Serial.println(message);

    // Additional output to confirm the message has been sent
    Serial.println("Message sent back to client");
  }
}
