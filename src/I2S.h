#ifndef I2S_H 
#define I2S_H

#include "Arduino.h"
#include "pcm.h"
#include "driver/i2s.h"

class I2S {
	public:
		void begin(int bck, int dout, int ws);
		//void end();
		
		//pcm read();
		void write(void *buffer, size_t nBytes);
		
		void setSampleRate(uint32_t Fs);
		//void setApll();
		//void setBitsPerSample(int bitsPerSample);
		//void setBufferSize(int nBuff, int buffSize);
		
};
#endif