#!/bin/sh

export QMK_DOCKER_IMAGE="qmk-compiler"

export KEYBOARD="ergodox_ez"
#export KEYMAP="default"
export KEYMAP="tsankuanglee"
export TARGET="teensy"

docker run -it -e keymap=$KEYMAP -e keyboard=$KEYBOARD -e target=$TARGET --rm -v $('pwd'):/qmk:rw ${QMK_DOCKER_IMAGE}
