#pragma once
#include "esp_event.h"

#ifndef WIFIMINUS_H
#define WIFIMINUS_H

/**
* Creates a WiFi connection for the ESP32, using the details provided by `menuconfig` to connect to a station.
* @author Pawel Kedzia
* @note You probably want to use wifiminus::init();
*/
class wifiminus {
    static void event_handler(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id, void *event_data);
public:
    /**
    * Initializes the WiFi connection.
    * @author Pawel Kedzia
    * @returns ESP_OK if the connection was successful, ESP_FAIL otherwise.
    * @note Intended to be used within an ESP_ERROR_CHECK.
    */
    static esp_err_t init();
};

#endif //WIFIMINUS_H
