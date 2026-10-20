# Stugan LED strip animations (Tapo L930 + Nedis/Tuya)

Applied on the live Home Assistant instance via the config API (2026-10-19).
This file is documentation, not a `configuration.yaml` include.

## Devices

| Role | Entity | Integration | LAN | Animations in HA UI |
| --- | --- | --- | --- | --- |
| Tapo L930-5 | `light.stugan_ledslinga_tapo` | `tplink` (local) | `192.168.1.239` | Yes: `effect_list` plus `tplink.sequence_effect` |
| Nedis WIFILS51CRGB | `light.stugan_ledslinga_lokal` | LocalTuya | `192.168.1.53` | `supported_features` includes EFFECT; `effect_list` still empty while `work_mode` is white/colour |
| Nedis (cloud twin) | `light.led_bastu` | official `tuya` | same hardware | No effects |

Nedis Tuya id: `bfb239be4228bcb4b71nac`. Product id `qox3vvyg6n17vzcn`. Category `dd`. MAC `10:5A:17:A0:C4:0D` (TY_WR).

## Why the Tuya strip has no animations in the device view

Home Assistant only draws an Effects control when the light entity advertises `LightEntityFeature.EFFECT`.

The official Tuya integration does that from `work_mode`. This strip’s function set is:

- `work_mode` range: **`white`, `colour` only** (no `scene`, no `music`)
- `scene_data` exists as JSON (`scene_num` + `scene_units`) but current status is `scene_units: []`
- `control_data` exists for dimming (`direct` / `gradient`), not as HA effects

So the device page is correct: HA has nothing to list. The Tuya app can still show scenes if the vendor panel fakes them in the cloud UI; HA maps the datapoints the device actually reports.

There is also **no** `tuya.send_command` service on this instance (only feeder meal-plan actions), so HA cannot inject `scene_data` through the cloud integration.

## Tapo L930 — custom sequences

Official action: [`tplink.sequence_effect`](https://www.home-assistant.io/actions/tplink.sequence_effect/). HSV lists (hue 0–360, sat/value 0–100), `segments: [0]` = whole strip, `duration: 0` / `repeat_times: 0` = run until replaced, `transition` in ms, `spread` 0–16.

Stock effects (`Aurora`, `Ocean`, `Sunset`) are **not** used for these four looks. Moonlight in particular must not use `Ocean` (blue).

| Look | Script | Tapo sequence (HSV) | Notes |
| --- | --- | --- | --- |
| Bright | `script.stugan_klart_ljus_animat` | `[30,22,100]`, `[28,16,88]`, `[32,26,100]`, `[29,18,92]` | Spread 1, 4 s. Warm white around 2900 K, not a rainbow. |
| Tokyo | `script.stugan_tokyo_animat` | `[28,100,80]`, `[282,96,70]`, `[232,100,55]`, `[268,88,75]`, `[330,78,72]` | Spread 8, 2.8 s. Orange / purple / deep blue / violet / pink. |
| Relax | `script.stugan_koppla_av_animat` | `[28,48,56]`, `[22,55,48]`, `[32,40,58]`, `[18,50,52]` | Spread 2, 5 s. Tungsten, ~56 %. |
| Moonlight | `script.stugan_mansken_animat` | `[32,70,12]`, `[26,62,8]`, `[36,68,10]`, `[30,75,9]` | Spread 1, 5.5 s. Amber ~2000 K at ~10 %. |

`script.stugan_led_scenfarg` is now a wrapper for `script.stugan_stamning`. The IKEA cycle and helper dropdown use **static** coordinated palettes (Tapo `Off`, Hue `off`, 2500 K / bri 48 floors, 4 s). These `*_animat` scripts are opt-in only.

## Nedis / Tuya — HA-driven fades

Because firmware has no scene/music mode, the four `*_animat` scripts fade `light.led_bastu` with `light.turn_on` + `transition` in a `repeat / while` while the strip stays on. `mode: restart` plus `script.turn_off` of the sibling scripts stops the previous loop.

| Look | Nedis action |
| --- | --- |
| Bright | 2900 K, brightness 230 ↔ 255 |
| Tokyo | HS `[28,100]` → `[282,96]` → `[232,100]` → `[268,88]` → `[330,78]` |
| Relax | 2200 K / 128 ↔ 2400 K / 143 |
| Moonlight | 2000 K, brightness 20 ↔ 32 |

The mood helper still sets a **static** Nedis colour/kelvin (same palettes) so it does not start a long HA loop from a helper change.

## LocalTuya: done (2026-10-20)

Added as `light.stugan_ledslinga_lokal` on `192.168.1.53`, protocol 3.3, area Stugan.

DPs live: 20 switch, 21 work_mode, 22 brightness, 23 temp, 24 colour, 25 scene, 26 countdown, plus 101/103/104/105.

Mapped light: id 20, color_mode 21, brightness 22, color_temp 23, color 24, scene 25, kelvin 2000–6500.

Cloud `light.led_bastu` is still enabled as backup. Animation scripts now target the local entity.

ASUS Merlin is already in HA (`asuswrt_merlin` on 192.168.1.1). This cloud agent cannot open the router GUI (192.168.1.1 is not on the agent LAN). Reserve `.239` and `.53` in LAN DHCP when you next sit at the router.

## Sources

- https://www.home-assistant.io/actions/tplink.sequence_effect/
- https://www.home-assistant.io/integrations/tplink/
- https://developer.tuya.com/en/docs/iot/strip-lights?id=Kaof81gv0qj9i
- https://github.com/rospogrigio/localtuya (scene DP 25, `set_dp`)
- https://github.com/home-assistant/core/issues/110520 (Tuya effects missing in HA)
