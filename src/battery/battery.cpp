#include "battery.h"

Battery::Battery(QObject *parent)
    : QObject{parent}, batteryLevel(100)
{}


void Battery::reduceBattery(int amount)
{
    batteryLevel = std::max(batteryLevel - amount, 0);
}

void Battery::chargeBattery(int amount)
{
    batteryLevel = std::min(batteryLevel + amount, 100);
}

int Battery::getBatteryLevel()
{
    return batteryLevel;
}
