#ifndef DHTMODULE_H
#define DHTMODULE_H

#include <Arduino.h>
#include "KS0530Common.h"
#include <dht11.h>

extern int DHT11_PIN;
extern dht11 DHT;

void DhtRead();

#endif // DHTMODULE_H
