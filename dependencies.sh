#!/bin/bash

#
# Install Daedalus dependencies
# 

# install uv4l
curl http://www.linux-projects.org/listing/uv4l_repo/lrkey.asc | sudo apt-key add -
sudo echo "deb http://www.linux-projects.org/listing/uv4l_repo/raspbian/ jessie main" >> /etc/apt/sources.list
sudo apt-get update && sudo apt-get install uv4l

# RT Kernel in Navio distribution needs some hacks for uv4l <-> GPU
wget files.emlid.com/uv4l-raspicam_1.9.40_armhf_hack.deb
sudo dpkg -i uv4l-raspicam_1.9.40_armhf_hack.deb && sudo apt-get install -f
# install uv4l server which will stream over network, no Node involved
sudo apt-get install uv4l-server