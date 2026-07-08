// EE_HANDS: each half stores its own handedness in EEPROM, so USB can be
// plugged into either half. Master (the plugged-in half) is detected via
// USB_VBUS_PIN below. Flash handedness once per half with uf2-split-left/right.
#define EE_HANDS
#undef NO_DEBUG

// Arcadia RP2040 controller has a hardware VBUS-detect divider on GP19
// (VBUS -R10(5.1k)- GP19 -R11(10k)- GND). Use it for master detection
// instead of USB-enumeration state. Requires split.usb_detect = false in
// keyboard.json so SPLIT_USB_DETECT does not override this.
// Use the raw RP2040 pad number (GP19 == 19U); the GPxx aliases are not
// visible in tmk_core/protocol/usb_util.c where USB_VBUS_PIN is consumed.
#define USB_VBUS_PIN 19U
