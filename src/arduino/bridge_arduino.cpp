/**
 * @file bridge_pigpio.cpp
 * @author Mickael GAILLARD (mick.gaillard@gmail.com)
 * @brief OpenWinch Project
 * 
 * @copyright Copyright © 2020
 */

#include "openwinch.hpp"
#include "bridge_io.hpp"

#ifdef OW_BD_ESP32
#ifdef OW_BG_ARDUINO

#include <arduino.h>

#endif  // OW_BG_ARDUINO
#endif  // OW_BD_ESP32