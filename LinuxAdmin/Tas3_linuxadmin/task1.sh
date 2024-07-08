#!/bin/bash

if [ -f "/home/somia/.bashrc" ]; then 
  echo "export HELLO = $(hostname)" >> /home/somia/.bashrc
  echo "LOCAL = $(whoami)" >> /home/somia/.bashrc
fi 

gnome-terminal


