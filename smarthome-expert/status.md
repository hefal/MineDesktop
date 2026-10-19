# Status handoff — smarthome-expert

## Current
- **When:** 2026-10-19
- **Instance:** Hemgårdsvägen · Core 2026.10.2 · Europe/Stockholm · RUNNING
- **Strip animations (this pass):**
  - Custom Tapo L930 `tplink.sequence_effect` palettes for Bright, Tokyo, Relax, Moonlight (not stock Aurora/Ocean/Sunset).
  - Matching Nedis HA-driven fades in `script.stugan_klart_ljus_animat`, `script.stugan_tokyo_animat`, `script.stugan_koppla_av_animat`, `script.stugan_mansken_animat`.
  - `script.stugan_led_scenfarg` uses the same Tapo sequences; Nedis static colours/kelvin aligned (Moonlight no longer blue).
- **Not done:** `light.led_bastu` is still Tuya Cloud. LocalTuya has 11 devices; none is Nedis `bfb239be`. Onboard Tuya effects cannot appear in HA while `work_mode` is only `white`/`colour`.
- **Docs:** `packages/stugan-led-strip-animations.md`
- **Rollback:** restore previous script configs from HA history; previous mood helper used Tapo `Aurora`/`Ocean`/`Sunset` and Moonlight rgb `[25,35,95]`.

## Do not
- No credentials or local keys in this file.
- Do not run the strip scripts unless a lamp test is requested (they turn the Stugan strips on).
