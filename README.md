# esp_wifiminus
A starting point to creating WiFi applications on the ESP32. It requires an SSID, password, and the number of retries, and **that's it.**

## Why?
You _could_ use one of the examples from the ESP_IDF folder, like I did for a while, but why use something that you can't (or, _shouldn't_) directly edit? But as for why I made this, well I was trying to connect to my Raspberry Pi, and the examples wouldn't even do that more than once, so, here we are.

## Limitations
Just like my CoAP client wrapper (which you can see [here](https://github.com/PearOrchards/esp_coap_client)), this is a very basic implementation, and provided zero configuration for anything more than SSID, password, and retries. However, there's nothing stopping you from implementing more yourself!

## Basic Usage
```c++
// Include statements not included

#ifdef __cplusplus
extern "C" {
#endif

void app_main() {

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    ESP_ERROR_CHECK(wifiminus::init());

    // And then do whateeeever you like!
}

#ifdef __cplusplus
}
#endif
```

## Installation
Clone this repository, and move it so that your project looks something like this (other structures are also likely fine but this is the one I tested with):
```commandline
project/
 |- components/
 | |- wifiminus/
 | | |- wifiminus.cpp
 | | |- README.md (the one you're reading!)
 | | |- ...
 | |- <any other components>
 |- main/
 | |- main.cpp
 | |- CMakeLists.txt
 | |- idf_component.yml
 |- CMakeLists.txt
 |- ...
```

### Updating CMakeLists.txt

The root `CMakeLists.txt` _should_ be okay left alone, though you may need to add something for CI. _An example was previously written here but, turns out, it doesn't work, so I've removed it._

The `main/CMakeLists.txt` should look like this (at the minimum):
```cmake
idf_component_register(SRCS main.cpp INCLUDE_DIRS "." REQUIRES wifiminus)
```

And this repo's `CMakeLists.txt` should be left as is.

## Configuration
The SSID, password, and max retries can all be done within the `menuconfig`, which can be accessed by running this in the root of your working directory:
```commandline
idf.py menuconfig
```
_(replace idf.py if you use IDF commands in a different way)_

Then, you should be able to find "WiFiMinus Configuration", and the fields can be edited in there.

## Contributing and Issues
If you have any problems using this, please open an issue on this repository, and I'll try get back to you as soon as possible.

If you'd like to contribute, please open a pull request. I'm happy to accept any contributions, but remember that this is supposed to be simple. If you're looking to add a lot of features, it may be better to fork this repository.