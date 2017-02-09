# Ardupilot custom build

Based on Copter 3.5.

Alterations:
- Added waf-build.sh as docu-code for building on Raspberry Pi 2/Navio+
- Swapped definitions of motors 2 and 5 to bypass dead PWM channel

/etc/useful:
- Disable arming checks
- Disable Failsafes (including crash failsafe)
- Motor mapping: http://ardupilot.org/copter/docs/connect-escs-and-motors.html

Pi specific:
- Camera/uv4l:
  - install uv4l
    -`curl http://www.linux-projects.org/listing/uv4l_repo/lrkey.asc | sudo apt-key add -`
    - `sudo echo "deb http://www.linux-projects.org/listing/uv4l_repo/raspbian/ jessie main" >> /etc/apt/sources.list`
    - `sudo apt-get update && sudo apt-get install uv4l`
  - RT Kernel in Navio distribution needs some hacks for uv4l <-> GPU:
    - `wget files.emlid.com/uv4l-raspicam_1.9.40_armhf_hack.deb`
    - `sudo dpkg -i uv4l-raspicam_1.9.40_armhf_hack.deb && sudo apt-get install -f`
  - install uv4l server to stream over network
    - `sudo apt-get install uv4l-server`
  - Start:
    - `uv4l --driver raspicam --auto-video_nr --rotation 180 --encoding mjpeg --width 640 --height 480 --enable-server on`
