// Constants
const int photoRes = A0; // Photoresistor at Arduino analog pin A0

// Variables
int value; // Store value from photoresistor (0-1023)
int redValue;
int greenValue;
int blueValue;
int arr_len = 9;

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

int leds[] = {BLUE1,GREEN1,RED1,BLUE2,GREEN2,RED2,BLUE3,GREEN3,RED3};

void setup(){
  pinMode(photoRes, INPUT); // Set photoRes - A0 pin as an input
  for( int i = 0; i < arr_len; ++i ){
    pinMode(leds[i], OUTPUT);
    digitalWrite(led[i], LOW);
  }
}

void loop(){
  #define delayTime 10 // fading time between colors
  if(checkPhotoRes() == true){
    redValue = 255; // choose a value between 1 and 255 to change the color.
    greenValue = 0;
    blueValue = 0;

    for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
    {
      if(checkPhotoRes() == false){
        break;
      }
      redValue -= 1;
      greenValue += 1;
      analogWrite(RED1, redValue);
      analogWrite(GREEN1, greenValue);
      analogWrite(RED2, redValue);
      analogWrite(GREEN2, greenValue);
      analogWrite(RED3, redValue);
      analogWrite(GREEN3, greenValue);
      delay(delayTime);
    }

    redValue = 0;
    greenValue = 255;
    blueValue = 0;

    for(int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
    {
      if(checkPhotoRes() == false){
        break;
      }
      greenValue -= 1;
      blueValue += 1;
      analogWrite(GREEN1, greenValue);
      analogWrite(BLUE1, blueValue);
      analogWrite(GREEN2, greenValue);
      analogWrite(BLUE2, blueValue);
      analogWrite(GREEN3, greenValue);
      analogWrite(BLUE3, blueValue);
      delay(delayTime);
    }

    redValue = 0;
    greenValue = 0;
    blueValue = 255;

    for(int i = 0; i < 255; i += 1) // fades out blue bring red full when i=255
    {
      if(checkPhotoRes() == false){
        break;
      }
      blueValue -= 1;
      redValue += 1;
      analogWrite(BLUE1, blueValue);
      analogWrite(RED1, redValue);
      analogWrite(BLUE2, blueValue);
      analogWrite(RED2, redValue);
      analogWrite(BLUE3, blueValue);
      analogWrite(RED3, redValue);
      delay(delayTime);
    }
  }
}

bool checkPhotoRes(){
  value = analogRead(photoRes);
  
  // You can change value "25"
  if (value > 25){
    return true
  }
  else{
    return false
  }

  delay(500); // Small delay
}

