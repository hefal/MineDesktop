# Status handoff — smarthome-expert

## Current
- **When:** 2026-10-20
- **Backup:** HA snapshot `82df5958` “Pre-registry cleanup 2026-10-20” taken before registry work.
- **Källartrappan Hue:** independent 30 s scene cycle per switch (Uppe / Nere). Order Ljust → Tokyo → Koppla av → Månsken. Dim ±30 %. Off on short. Multi-room off on `long_press` (while holding).
- **Helpers:** `timer.kallartrappan_uppe_scencykel`, `timer.kallartrappan_nere_scencykel`, `input_select.kallartrappan_uppe_scen`, `input_select.kallartrappan_nere_scen`.
- **LocalTuya names (Swedish, Rum Typ Objekt):** see `packages/kallaren-stugan-local.yaml`.
- **Tuya Cloud twins + leftover Tuya scenes:** disabled. Cloud kept for camera, 1-433, and still-offline cottage/stugan bulbs.
- **Camera:** `camera.kamera_tuya_batteri` stays on Tuya Cloud (`support_local: false`, no RTSP in go2rtc). LocalTuya discovery sees it at `192.168.1.193` but cannot replace the stream.
- **Stugan strips:** `light.stugan_led_slinga` (Nedis/LocalTuya `.53`) and `light.stugan_led_tapo` (L930 `.239`). Animation scripts retargeted.

## Router / DHCP (not applied from this VM)
Cloud agent cannot reach `192.168.1.1`. Reserve on the Asus UI:

- `192.168.1.239` Tapo L930
- `192.168.1.53` Nedis LED
- LocalTuya lamps: `.3` `.34` `.76` `.88` `.106` `.148` `.202` `.211` `.223` `.248`
- **Conflict:** two LocalTuya devices share `.106` (Källartoalett Spot Handfat and Garage Lampa Entré Mitt). Fix after checking DHCP leases.

## Still open
- Cottage/Stugan outdoor bulbs and `1-433` still offline — onboard when they get LAN IPs.
- `Källaren Lampa 19–25` need real positions from you.
- Some källartrappan scenes / Hue-follow automations may still mention old IDs: `kallartrappan_relax`, `kallartrappan_allt_av`, `kallaren_klart_ljus`, `kallaren_koppla_av`, `automation.bathroom_spots_follow_hue_room_final`, failsafe, Tuya reconnect-off. Dashboards were not bulk-rewritten.
- Entity IDs are ASCII (`ö` → `o`). Display names keep Swedish.

## Do not
- No credentials in this file.
- Do not start `*_animat` scripts unless a lamp test is requested.
- Do not restore snapshot `82df5958` without confirming it will wipe later work.
