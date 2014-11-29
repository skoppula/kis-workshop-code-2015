#!/bin/bash
echo Updating system information about software latest version
sudo apt-get update
echo Getting Arduino software...
sudo apt-get install arduino arduino-core
