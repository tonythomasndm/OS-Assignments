#!/bin/bash

cd linux-6.0.9
make menuconfig
make -j2
make modules_install
cd ..