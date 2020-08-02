#include "I2S32.h"                            // output

I2S i2s;                                      // I2S class used for output

float f = 340;                                // Frequency of sine wave
int fs = 44100;                               // Sample rate
int n = (int)floor(fs / f * 2);               // number of samples      
int16_t *audio = new int16_t[n * 4];          // array to hold sine wave

void setup() {

  // bclk, din, wsel
  i2s.begin(26, 25, 27);                      // Set pins for I2S
  i2s.setSampleRate(fs);                      // Set sample rate
  
  for (int i = 0; i < n / 2; i++) {          //fill array with sine waves
    audio[2 * i] = (int16_t)(sin(2 * PI * f * i / fs) * 320);
    audio[2 * i + 1] = (int16_t)(sin(2 * PI * f * i / fs) * 320);
  }
  
}

int16_t out[2];                              // create two channel array to hold left and right sample

void loop() {
  for (int i = 0; i < n / 2; i++) {
    out[0] = audio[2 * i];                  // fill left sample
    out[1] = audio[2 * i + 1];              // fill right sample
    i2s.write(&out, 4);                     // send it to I2S buffer    
  }
}