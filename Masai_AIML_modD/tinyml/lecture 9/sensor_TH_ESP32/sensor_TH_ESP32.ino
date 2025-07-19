#include <EloquentTinyML.h>
#include <eloquent_tinyml/tensorflow.h>
#include "sensor_model_ESP32_sm.h"

#define NUMBER_OF_INPUTS 2
#define NUMBER_OF_OUTPUTS 1
#define TENSOR_ARENA_SIZE 2 * 1024  // Increased to 2KB for stability

Eloquent::TinyML::TensorFlow::TensorFlow<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

void setup() {
  Serial.begin(115200);
  ml.begin(sensor_model_ESP32_sm);
}

void loop() {
  // Simulate sensor readings

//  float temperature = 24.0; // read from sensor
//  float humidity = 40.0;    // read from sensor
  
  float temperature = 62.0; // read from sensor
  float humidity = 10.0;    // read from sensor

  // Apply same normalization as in training
  float input[2] = {temperature, humidity};

  float output = ml.predict(input);
  Serial.print("Anomaly score: ");
  Serial.println(output);

  if (output > 0.5) {
    Serial.println("Anomaly detected! Security alert.");
  } else {
    Serial.println("Normal reading.");
  }

  delay(5000);
}
