# JohnMee layout

```
qmk flash -kb crkbd -km meej -bl :dfu-split-right
```

I installed it with linuxbrew this time.
And set `~/.config/qmk/qmk.ini` defaults to `crkbd` and `meej`.

```buildoutcfg
# So now I do this to flash (and press the little reset button)
$ qmk flash -bl dfu

# I did this to establish my keebs...
$ ln -s ~/projects/keebs/meej/niumini ~/projects/keebs/qmk/qmk_firmware/keyboards/niu_mini/keymaps/meej
$ ln -s ~/projects/keebs/meej/planckez ~/projects/keebs/qmk/qmk_firmware/keyboards/planck/keymaps/meej
```

This is what it used to be:
```
$ git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git
$ (git pull --recurse-submodules)   
$ cd qmk_firmware
$ util/qmk_install.sh

$ ln -s ~/projects/keebs/myplanck ~/projects/keebs/qmk_firmware/keyboards/planck/keymaps/meej
$ make git-submodule
$ make planck/ez:meej:flash
$ make niu_mini:meej:flash  (plug the keeb directly into the computer--no usb hub!!)
```
