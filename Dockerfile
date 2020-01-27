FROM qmkfm/base_container

VOLUME /qmk_firmware
WORKDIR /qmk_firmware
COPY . .

ENV keyboard=ergodox
ENV subproject=ez
ENV keymap=default

VOLUME /qmk
WORKDIR /qmk
CMD groupadd -g ${GROUPID} user; useradd -g ${GROUPID} -u ${USERID} --no-create-home --home-dir /qmk user ; \
    make clean ; make keyboard=${keyboard} subproject=${subproject} keymap=${keymap} ; \
    chown -R user:user .build *.hex ;
CMD make all:default
