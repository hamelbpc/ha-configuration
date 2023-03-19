#!/usr/bin/env bash

apk add htmlq --repository=http://dl-cdn.alpinelinux.org/alpine/edge/testing/
curl --silent https://weather.theage.com.au/local-forecast/vic/melbourne | htmlq ".right_plot svg" | tee /config/www/images/theageforecast.svg

