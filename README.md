# NULCEO-F091RC-PIDMotoroCTRL-ROS2
https://os.mbed.com/users/6f953f6d-adb0-4afd-b254-05004248a722/code/NUCLEO-F091RC-PIDMotor-ROS2/ <br /> 
Dependencies:<br /> 
  &emsp;ROS2 humble:<br />
    &emsp;&emsp;-pyserial<br />
    &emsp;&emsp;-python3<br />
  &emsp;mbed:<br />
    &emsp;&emsp;-MotorControl<br />

Installation:<br />
  &emsp;ROS2 humble:
    
    pip3 install pyserial

Usage:<br />

    sudo chmod +777 /dev/ttyACM0
    ros2 run mbedROS2 mbed_motor_ctrl
