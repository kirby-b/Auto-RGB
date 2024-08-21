// Constants
const int photoRes = A0; // Photoresistor at Arduino analog pin A0

// Variables
int value; // Store value from photoresistor (0-1023)

// Define Pins
#define BLUE1 2
#define GREEN1 3
#define RED1 4
#define BLUE2 5
#define GREEN2 6
#define RED2 7
#define BLUE3 8
#define GREEN3 9
#define RED3 10

void setup(){
 pinMode(ledPin, OUTPUT); // Set lepPin - 9 pin as an output
 pinMode(photoRes, INPUT); // Set photoRes - A0 pin as an input
}

void loop(){
  value = analogRead(photoRes);
  
  // You can change value "25"
  if (value > 25){
    digitalWrite(ledPin, LOW); // Turn led off
  }
  else{
    digitalWrite(ledPin, HIGH); // Turn led on
  }

  delay(500); // Small delay
}


// RGB code from Elegoo


// void setup()
// {
// pinMode(RED, OUTPUT);
// pinMode(GREEN, OUTPUT);
// pinMode(BLUE, OUTPUT);
// digitalWrite(RED, HIGH);
// digitalWrite(GREEN, LOW);
// digitalWrite(BLUE, LOW);
// }

// // define variables
// int redValue;
// int greenValue;
// int blueValue;

// // main loop
// void loop()
// {
// #define delayTime 10 // fading time between colors

// redValue = 255; // choose a value between 1 and 255 to change the color.
// greenValue = 0;
// blueValue = 0;

// // this is unnecessary as we've either turned on RED in SETUP
// // or in the previous loop ... regardless, this turns RED off
// // analogWrite(RED, 0);
// // delay(1000);

// for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
// {
// redValue -= 1;
// greenValue += 1;
// // The following was reversed, counting in the wrong directions
// // analogWrite(RED, 255 - redValue);
// // analogWrite(GREEN, 255 - greenValue);
// analogWrite(RED, redValue);
// analogWrite(GREEN, greenValue);
// delay(delayTime);
// }

// redValue = 0;
// greenValue = 255;
// blueValue = 0;

// for(int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
// {
// greenValue -= 1;
// blueValue += 1;
// // The following was reversed, counting in the wrong directions
// // analogWrite(GREEN, 255 - greenValue);
// // analogWrite(BLUE, 255 - blueValue);
// analogWrite(GREEN, greenValue);
// analogWrite(BLUE, blueValue);
// delay(delayTime);
// }

// redValue = 0;
// greenValue = 0;
// blueValue = 255;

// for(int i = 0; i < 255; i += 1) // fades out blue bring red full when i=255
// {
// // The following code has been rearranged to match the other two similar sections
// blueValue -= 1;
// redValue += 1;
// // The following was reversed, counting in the wrong directions
// // analogWrite(BLUE, 255 - blueValue);
// // analogWrite(RED, 255 - redValue);
// analogWrite(BLUE, blueValue);
// analogWrite(RED, redValue);
// delay(delayTime);
// }
// }