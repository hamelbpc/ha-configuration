#!/usr/bin/env bash
set -x
apk add htmlq --repository=http://dl-cdn.alpinelinux.org/alpine/edge/testing/
curl -sSL https://weather.theage.com.au/local-forecast/vic/melbourne | htmlq "#data" | htmlq -t ".timestamp, .datelabel, .label, .temp_c .prob_precip, .wind_speed_direction, .wind_speed_kph, .image_filename, .temp_image img, .delta_t_c" "


