/**
 * @file tachometer.hpp
 * @author Mickael GAILLARD (mick.gaillard@gmail.com)
 * @brief OpenWinch Project
 * 
 * @copyright Copyright © 2020-2021
 */

#ifndef TACHOMETER_HPP_
#define TACHOMETER_HPP_

#include <string>

class Logger;
class InputDevice;
class OutputDevice;
class PWMOutputDevice;


typedef enum rotation {
  Clock = 1,
  CounterClock = -1
} rotation_t;


typedef struct tacho_hallSensor {
    uint32_t pulseTime;
    uint32_t pulseCount;

    uint32_t startTime;
    uint32_t prevTime;

    uint32_t rpm;
} tacho_hallSensor_t;


class Tachometer {
 public:
  static Tachometer& get();
  static uint32_t get_rpm(uint32_t pulseTime);
  static uint32_t reduce_rpm(uint32_t rpm_motor);

  Tachometer(InputDevice *sensor_u, InputDevice *sensor_w, InputDevice *sensor_v);
  Tachometer(const Tachometer&)= delete;
  Tachometer& operator=(const Tachometer&)= delete;
  virtual ~Tachometer() = default;

  void initialize();
  void hall_debug(tacho_hallSensor_t sensor, std::string name);
  rotation_t get_rotation();

  uint32_t get_rpm();
  uint32_t get_rpmU();
  uint32_t get_rpmW();
  uint32_t get_rpmV();

  tacho_hallSensor_t get_hall_sensorU();
  tacho_hallSensor_t get_hall_sensorW();
  tacho_hallSensor_t get_hall_sensorV();

 protected:
  void int_hall_W(int, int, uint32_t);
  void int_hall_V(int, int, uint32_t);
  void int_hall_U(int, int, uint32_t);

 private:
  Logger* logger = nullptr;
  InputDevice* input_hal_u;
  InputDevice* input_hal_w;
  InputDevice* input_hal_v;

  rotation_t tacho_direct = rotation::Clock;

  tacho_hallSensor_t tacho_hsu;
  tacho_hallSensor_t tacho_hsw;
  tacho_hallSensor_t tacho_hsv;

  // Tachometer();
  //~Tachometer()= default;

  void hall_init(tacho_hallSensor_t *sensor);
};

#endif  // TACHOMETER_HPP_
