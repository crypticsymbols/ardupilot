#!/bin/bash

# 
# symlink build tools (only needed on initial build)
# 
#sudo ln -s /usr/bin/arm-unknown-linux-gnueabihf-pkg-config /usr/bin/arm-linux-gnueabihf-    pkg-config
#sudo chmod a+x /usr/bin/arm-linux-gnueabihf-pkg-config

# 
# Configure for navio+
# 
./modules/waf/waf-light configure --board=navio
  
# 
# Build AHRS target (on hold)
# 
# waf --targets bin/ahrs

# 
# Build ArduCopter
# 
./modules/waf/waf-light copter
mv build/navio/bin/arducopter ~/builds/arducopter-2-8-2017