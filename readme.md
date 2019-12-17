# JohnMee layout
Default: QWERTY
Lower: Numpad on the right hand
Raise: Symbols on top row, symbols on left home row, opening brackets on right home, cut/copy/paste/undo on lower left row, closing brackets on right
Hold(D): Cursor navigation on the right hand, modifiers on left
Hold(V): GUI shortcuts on right hand
Function Keys layer from Raise+1 key
Adjust Layer with reset, volume, keyboard lighting, and lock.
GUI key on lower 2 key

Bit of a mess generally as I have to use macOS at work (planckez), but use ubuntu linux at home (niumini) and would like them to use the same keys for
the same things, but that isn't entirely possible.

```
$ ln -s ~/projects/keebs/myplanck ~/projects/keebs/qmk_firmware/keyboards/planck/keymaps/meej
$ make planck/ez:meej:flash
```
