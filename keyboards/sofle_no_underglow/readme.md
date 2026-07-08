# sofle_no_underglow

A [Sofle](https://github.com/josefadamcik/SofleKeyboard) split keyboard build with
the per-key RGB matrix kept but the underglow removed, running Vial-enabled QMK on
RP2040 controllers.

* Keyboard Maintainer: [MagneticNeedle](https://github.com/MagneticNeedle)
* Hardware Supported:
  * PCB: Sofle (RGB, choc/MX) — https://github.com/josefadamcik/SofleKeyboard
  * Controller: **EmpWorks Arcadia** — an RP2040-based, USB-C, Pro Micro drop-in
    replacement (https://github.com/EmpWorks/Arcadia)
  * 2× SSD1306 128x32 OLED
  * 2× rotary encoder (EC11)

## Hardware notes

* **Controller / convert target.** The Arcadia is pin-compatible with the SparkFun
  Pro Micro RP2040 mapping, so the firmware is built with
  `CONVERT_TO = sparkfun_pm2040` (in `keymaps/default/rules.mk`). Do **not** use
  `rp2040_ce` or the deprecated `promicro_rp2040` — a mismatched converter mis-maps
  the matrix (nothing types) and USB detection.
* **Handedness: `EE_HANDS`.** Each half stores whether it is left or right in its own
  EEPROM, so the USB cable can be plugged into **either** half. This requires a
  one-time per-half handedness flash (see below).
* **Master detection: hardware VBUS pin.** `USB_VBUS_PIN` is set to GP19 (the
  Arcadia's onboard VBUS-sense divider) and `split.usb_detect` is disabled, so the
  plugged-in half is chosen as master by reading VBUS rather than by USB
  enumeration. See "Known behavior" for the trade-off.
* **Split transport.** Serial (single wire) on `D2` (GP1), with matrix-state sync and
  the split watchdog enabled.

## Build

    qmk compile -kb sofle_no_underglow -km default
    # or
    make sofle_no_underglow:default

Produces `sofle_no_underglow_default.uf2`.

## Flashing

The controller is RP2040 (UF2 bootloader). Enter the bootloader on the half you are
flashing (see "Bootloader" below), then flash it. Each half has its own USB port —
flash each half through its own port.

### First-time / handedness flash (do this once per half)

Because the board uses `EE_HANDS`, each half must be told which side it is. On RP2040
this is done with the split-handedness flash targets, which write the handedness into
EEPROM on first boot:

    # LEFT half in bootloader:
    qmk flash -kb sofle_no_underglow -km default -bl uf2-split-left

    # RIGHT half in bootloader:
    qmk flash -kb sofle_no_underglow -km default -bl uf2-split-right

Make sure the `-left` command goes to the physical left half and `-right` to the
right half. After this the handedness is stored permanently.

### Normal reflash (handedness already set)

Once handedness is in EEPROM, either half can be reflashed with the plain firmware:

    qmk flash -kb sofle_no_underglow -km default

(Handedness survives a normal reflash; only an EEPROM reset requires redoing the
handedness flash above.)

### Flashing on Linux

`qmk flash` waits at `Waiting for drive to deploy...` until the `RPI-RP2` bootloader
drive appears **and is mounted**. If you don't run an automounter, press `Ctrl+C` and
copy the already-built UF2 manually:

    cp .build/sofle_no_underglow_default.uf2 /run/media/$USER/RPI-RP2/

## Bootloader

Enter the RP2040 UF2 bootloader in any of these ways:

* **Double-tap reset** — quickly press the reset button twice (within 500 ms). Enabled
  by the controller config.
* **Bootmagic** — hold the top-left key (Esc, matrix `(0,0)`) while plugging in the
  keyboard.
* **BOOT button/jumper** — hold BOOT while plugging in USB (or hold BOOT and tap
  reset). Always works, even if current firmware is broken.

The `RPI-RP2` drive appears; drop a `.uf2` on it or let `qmk flash` copy it.

## Vial

This board is Vial-enabled (`vial.json` in the keymap). Configure layers, keymap and
RGB in [Vial](https://get.vial.today/) — the `default` keymap is just the starting
point. `VIAL_INSECURE = yes` is set in `rules.mk`.

## OLED

* **Master half** (the one with USB) shows the current layer / status image
  (`OLED_ROTATION_270`).
* **Slave half** shows the QMK logo.

Behavior lives in `keymaps/default/oled.c` (layer bitmaps in `oled_layers.h`), pulled
in via `keymap.c`.

## Known behavior

Because master detection uses the VBUS pin (a single read early in boot) rather than
USB enumeration:

* **Occasionally on cold PC boot, both OLEDs show the QMK logo.** This means neither
  half was detected as master — the VBUS rail was still ramping when the master half
  sampled GP19, so it mis-read itself as a slave. The decision is cached until reboot;
  **replug the keyboard** to fix it.
* Plugging into the **right** half is the reliable side. Plugging into the **left**
  half may not come up, because the Arcadia's VBUS divider sits right at the RP2040
  logic-high threshold and the left board tends to read it low.

To make master detection robust (either-side plugging, no boot-time logo), switch to
enumeration-based detection instead: set `split.usb_detect.enabled = true` (and
optionally `split.usb_detect.timeout` ~5000 for slow PC boots) in `keyboard.json`, and
remove `#define USB_VBUS_PIN 19U` from `keymaps/default/config.h`.

---

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools)
and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more
information. Brand new to QMK? Start with the
[Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
