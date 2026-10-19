# Status handoff — smarthome-expert

## Current
- **When:** 2026-10-20
- **Nedis strip is LocalTuya:** `light.stugan_ledslinga_lokal` · `192.168.1.53` · area Stugan · on.
- **Tapo L930:** `light.stugan_ledslinga_tapo` · `192.168.1.239` · already local tplink.
- Animation scripts and `script.stugan_led_scenfarg` now drive the local Nedis entity.
- Cloud `light.led_bastu` left as backup.
- Källaren Tuya lamps `unavailable` = wall power off (parents). Not a LocalTuya fault.

## Router
- Could not open http://192.168.1.1 from this cloud VM.
- Used HA LocalTuya discovery + existing AsusWrt-Merlin integration instead.

## Do not
- No credentials in this file.
- Do not start the `*_animat` scripts unless a lamp test is requested.
