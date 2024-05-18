#include "DhtModule.h"

void DhtRead()
{
    int chk;
    chk = DHT.read(DHT11_PIN); // read data
    switch (chk)
    {
    case DHTLIB_OK:
        break;
    case DHTLIB_ERROR_CHECKSUM: // check and return error
        break;
    case DHTLIB_ERROR_TIMEOUT: // Timeout and return error
        break;
    default:
        break;
    }
    temperature = DHT.temperature;
    humidity = DHT.humidity;
}