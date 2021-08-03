# JohnMee layout

Now it is something like

```buildoutcfg
# I do this to get into the qmk env.
$ cd qmk
$ source bin/activate   (because I installed a qmk pip package inside a venv, but then it clones the git repo)

# I do this to flash (or just compile)
$ qmk flash -kb niu_mini -km meej

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
