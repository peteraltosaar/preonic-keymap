#!/bin/bash

cp keymap.c ../qmk_firmware/keyboards/preonic/keymaps/peteraltosaar/
cd ../qmk_firmware
make preonic/rev2:peteraltosaar
cd -
