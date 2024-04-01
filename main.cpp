#include "mbed.h"
#include "SerialROS2.hpp"
#include "MotorControl.hpp"

MotorCtrl motor1(D4, D5, D12, D11);

SerialROS2 pc(USBTX, USBRX, 115200);

float setpoint1 = 0.0;

void setMotorSpeed(float* data){
    if (data != nullptr){ 
        setpoint1 = data[0];
    }
}

int main() {
    pc.init();
    pc.recvCallback = &setMotorSpeed;

    motor1.motor.set_pid_gain(20.0, 0.001, 0.005, 0.0);

    motor1.set_encoder_resolution(0.0007633);
    motor1.init();
    motor1.start();

    while(1) {
        pc.recvVals();
        
        motor1.update();
        motor1.setSpeed(setpoint1);


        printf("get %f, 0.0, %f, 0.0\n",setpoint1, motor1.getMotorSpeed());

        wait_us(1000);
    }
}