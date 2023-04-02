#!/usr/bin/env bash

apk add htmlq --repository=http://dl-cdn.alpinelinux.org/alpine/edge/testing/
curl --silent https://weather.theage.com.au/local-forecast/vic/melbourne | htmlq "#ga_48_hours svg" | tee /config/www/theageforecast.svg
sed -r 's/xlink:href/href/g' /config/www/theageforecast.svg


