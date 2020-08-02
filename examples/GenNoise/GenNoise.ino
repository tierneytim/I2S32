#include "I2S32.h"                       // output
I2S i2s;                                 // I2S class used for output

void setup() {

  // bclk, din, wsel
  i2s.begin(26, 25, 27);                  // Set pins for I2S
  int fs = 44100;                         // define sample rate
  i2s.setSampleRate(fs);                  // Set sample rate

}

int16_t audio[2];                         //create array to hold left and right channel

void loop() {
    audio[0] = random(-320,320);          // put noise in left channel    
    audio[1] = random(-320,320);          // put noise in right channel
    i2s.write(audio, 4);                  // send it to I2S buffer
}