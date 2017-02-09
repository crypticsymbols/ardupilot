#!/bin/bash

alias waf="$PWD/modules/waf/waf-light"
sudo ln -s /usr/bin/arm-unknown-linux-gnueabihf-pkg-config /usr/bin/arm-linux-gnueabihf-pkg-config
sudo chmod a+x /usr/bin/arm-linux-gnueabihf-pkg-config
waf configure --board=navio

waf --targets bin/ahrs
waf copter