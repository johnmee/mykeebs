# JohnMee layout

```
$ git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git
$ cd qmk_firmware
$ util/qmk_install.sh

$ ln -s ~/projects/keebs/myplanck ~/projects/keebs/qmk_firmware/keyboards/planck/keymaps/meej
$ make git-submodule
$ make planck/ez:meej:flash
$ (sudo) make niu_mini:meej:flash
```


Default: QWERTY  
Lower: Numpad on the right hand  
Raise: Symbols on top row, symbols on left home row, opening brackets on right home, cut/copy/paste/undo on lower left row, closing brackets on right  
Hold(D): Cursor navigation on the right hand, modifiers on left  
Hold(V): GUI shortcuts on right hand  
Function Keys layer from Raise+1 key  
Adjust Layer with reset, volume, keyboard lighting, and lock  
GUI key on lower 2 key  

