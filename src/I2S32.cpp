#include "I2S32.h"
void I2S::begin(int bck, int dout, int ws){
 // i2s configuration
  static const i2s_config_t i2s_config = {
    .mode = static_cast<i2s_mode_t>(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = 44100,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = static_cast<i2s_comm_format_t>(I2S_COMM_FORMAT_I2S|I2S_COMM_FORMAT_I2S_MSB),
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1, // default interrupt priority
    .dma_buf_count = 6,
    .dma_buf_len = 200,
    .use_apll = false,
    .tx_desc_auto_clear = true
  };
  
  // i2s pinout
  static const i2s_pin_config_t pin_config = {
    .bck_io_num =bck,//26
    .ws_io_num = ws, //27
    .data_out_num = dout, //25
    .data_in_num = I2S_PIN_NO_CHANGE
  };
  
  // now configure i2s with constructed pinout and config
  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM_0, &pin_config);
 
}
void I2S::setSampleRate(uint32_t Fs){
 i2s_set_sample_rates(I2S_NUM_0, Fs);
}
void I2S::write(void *buffer, size_t nBytes){
	size_t i2s_bytes_write=0;
	  i2s_write(I2S_NUM_0, buffer, nBytes, &i2s_bytes_write, 100 );

}