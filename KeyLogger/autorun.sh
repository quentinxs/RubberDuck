#!/bin/sh
python keylogger.py test &
sleep 120
echo "\`"
systemctl suspend

