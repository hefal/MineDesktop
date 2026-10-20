# Status handoff — smarthome-expert

**Updated:** 2026-10-20
**Live source:** Cursor MCP `home-assistant-dashboard` (HA 2026.10.2, ha-mcp 8.7.0)
**Backup:** snapshot `82df5958` “Pre-registry cleanup 2026-10-20”

## Done
- Källartrappan Hue: independent 30 s cycle per switch. Ljust → Tokyo → Koppla av → Månsken. Dim ±30 %. Off on short. Multi-room off on `long_press`.
- Helpers: `timer.kallartrappan_uppe_scencykel`, `timer.kallartrappan_nere_scencykel`, `input_select.kallartrappan_uppe_scen`, `input_select.kallartrappan_nere_scen`.
- LocalTuya Swedish names + areas. Cloud twins disabled. Tuya Cloud kept for camera, 1-433, offline cottage bulbs, leftover Moln lamps.
- Consumer remap: bathroom follow, failsafe, Tuya reconnect-off, källartrappan Tuya/garageentré, inactivity safety, Stugan IKEA/Hue-mirror/motion. Scenes `kallartrappan_*`, `kallaren_*_lokal`, `kallartoalett_tuya_*`, `garageentre_bright`, `stugan_led_*`. Dash view `tuya-ljus`.
- Dead `light.led_bastu` retargeted to `light.stugan_led_slinga`. `light.stugan_ledslinga_tapo` → `light.stugan_led_tapo`.
- Cloud leftovers renamed `light.kallaren_lampa_moln` / `_2` / `_23`. Cottage outdoor → `light.stugan_lampa_entre_ute_1` / `_2`.
- Hue display: Källartoalett Spot 1/2/3, Spegel Handfat, Garage Led Strip.

## Router / DHCP (not applied from this VM)
Reserve on Asus: `.239` Tapo L930, `.53` Nedis, LocalTuya `.3` `.34` `.76` `.88` `.106` `.148` `.202` `.211` `.223` `.248`.
**Conflict:** Källartoalett Spot Handfat and Garage Lampa Entré Mitt both stored as `192.168.1.106`.

## Open
- Cottage bulbs and `switch.1_433_switch_1` still unavailable — onboard LocalTuya when they get LAN IPs.
- TuyaCam stays Cloud (`support_local: false`, no RTSP).
- `Källaren Lampa 19–25` and Moln 1/2/23 need real positions.
- Remaining Hue entity IDs (`light.hue_lightstrip_plus_*`, `light.garage_1` = Stugan Blomma, floodlights) still English IDs; display names only partly cleaned.
- `light.led_bastu` may still appear in some `stugan_ledslingor_*` scene bodies (substring search noisy).
- No physical lamp tests. No DHCP write.

## Do not
- No credentials in this file.
- Do not start `*_animat` scripts unless a lamp test is requested.
- Do not restore snapshot `82df5958` without confirming it will wipe later work.
