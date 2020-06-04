#!/bin/sh

#export QMK_DOCKER_IMAGE="qmk-compiler"
#
#if [[ "$(docker images -q ${QMK_DOCKER_IMAGE} 2> /dev/null)" == "" ]]; then
#    docker build --rm -t ${QMK_DOCKER_IMAGE} .
#fi

export KEYBOARD="ergodox_ez"
export KEYMAP="tsankuanglee"
export HEXNAME=${KEYBOARD}_${KEYMAP}.hex

# compile
# old version
#docker run -it \
#    -e USERID=`id -u` -e GROUPID=`id -g` \
#    -e keymap=$KEYMAP -e keyboard=$KEYBOARD --rm -v $('pwd'):/qmk:rw ${QMK_DOCKER_IMAGE}
# new version
docker-compose run --rm\
    compiler \
    bash -c "qmk compile -kb ${KEYBOARD} -km ${KEYMAP}"
    #bash -c "qmk compile -kb ${KEYBOARD} -km ${KEYMAP}; qmk flash -kb ${KEYBOARD} -km  ${KEYMAP}"

# clean up; no need to keep it in the root
rm -f ./${HEXNAME}

# flashing
../teensy_loader_cli.git/teensy_loader_cli -mmcu=atmega32u4 -w -v .build/${HEXNAME}

# copy the files to archived
export TIMESTAMP=`date +%Y%m%d-%H%M%S`
export KEYMAP_FOLDER=./keyboards/${KEYBOARD}/keymaps/${KEYMAP}
rsync -at ${KEYMAP_FOLDER}/keymap.c ${KEYMAP_FOLDER}/archived/${TIMESTAMP}-keymap.c
rsync -at .build/${HEXNAME} ${KEYMAP_FOLDER}/archived/${TIMESTAMP}-${HEXNAME}
