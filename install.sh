#! /bin/bash

#kompiliere main.c
gcc main.c -o millionaer

#verschiebe nach /usr/bin
sudo mv millionaer /usr/bin
echo "Fertig!"
