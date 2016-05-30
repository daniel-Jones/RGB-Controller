int incomingByte = 0;   // for incoming serial data
const int redPin = 2;
const int greenPin = 4;
const int bluePin = 3;

int red;
int green;
int blue;

String inData;
void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        red = 0;
        green = 0;
        blue = 0;
        pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                char recieved = Serial.read();
        inData += recieved; 

        // Process message when new line character is recieved
        if (recieved == '\n')
        {
            Serial.print("string: ");
            Serial.print(inData);
            String first  = Serial.readStringUntil(',');
    Serial.read(); //next character is comma, so skip it using this
    String second = Serial.readStringUntil(',');
    Serial.read();
    String third  = Serial.readStringUntil('\0');
    Serial.print(first + "\n");
    Serial.print(second + "\n");
    Serial.print(third + "\n");
            inData = ""; // Clear recieved buffer
        }
        }
}
