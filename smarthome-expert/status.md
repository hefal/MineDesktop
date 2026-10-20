# Status handoff — smarthome-expert

**Updated:** 2026-10-20
**Live source:** Cursor MCP `home-assistant-dashboard` (HA 2026.10.2, ha-mcp 8.7.0)
**Backup:** snapshot `82df5958` “Pre-registry cleanup 2026-10-20”; Stugan quality `1e8d7407`

## Done
- Källartrappan Hue: independent 30 s cycle per switch. Ljust → Tokyo → Koppla av → Månsken. Dim ±30 %. Off on short. Multi-room off on `long_press`.
- LocalTuya Swedish names + areas. Cloud twins disabled. Tuya Cloud kept for camera, 1-433, offline cottage bulbs, leftover Moln lamps.
- **Stugan scene quality:** `script.stugan_stamning` is the only writer for the IKEA cycle, helper dropdown, Hue-app named scenes, motion cold-start, and rumsknapp.
  - **Tokyo** applies Hue integration scene `scene.stugan_stugan_tokyo` (dynamic, brightness 120) on Hue lamps. Tapo `sequence_effect` and Nedis hue fades use red / turquoise / blue / purple / pink at 120. Other moods stay static.
  - Shared floors on static moods: 2500 K, brightness 48, 4 s. Tapo `effect: Off` and Hue `effect: off` only on those moods, not on Tokyo.
  - Mirror live-follows only when helper is `Hue-färg`, and then with Tapo effect Off.
  - Motion fade uses brightness 48, not 5 %.
  - Dead IDs `light.led_bastu` / `light.stugan_ledslinga_tapo` removed from Stugan scripts, LED scenes, rumsknapp, släck-script, inactivity off, Tuya reconnect condition.
- Guessed Swedish display names on remaining Hue Stugan members (entity IDs unchanged).

## Router / DHCP (not applied from this VM)
Reserve on Asus: `.239` Tapo L930, `.53` Nedis, LocalTuya `.3` `.34` `.76` `.88` `.106` `.148` `.202` `.211` `.223` `.248`.
**Conflict:** Källartoalett Spot Handfat and Garage Lampa Entré Mitt both stored as `192.168.1.106`.

- **Stugan sleep / motion (live, 2026-10-20 night):** Hue, Tapo and Nedis forced off. Tokyo animat stopped. `input_boolean.ljus_stugan_manuellt` is **on** so bed movement does not restore ceiling lights. `automation.stugan_slackning_pausar_rorelseljus` sets that flag whenever Hue room goes off. `automation.stugan_ytterdorr_ateraktiverar_rorelseljus` clears it on `binary_sensor.ytterdorr_stugan` open. IKEA 0 still runs `script.stugan_slack_och_pausa` (now always turns lights off twice). Mirror skips while the flag is on.

## Open
- Cottage bulbs and `switch.1_433_switch_1` still unavailable — onboard LocalTuya when they get LAN IPs.
- TuyaCam stays Cloud (`support_local: false`, no RTSP).
- `Källaren Lampa 19–25` and Moln 1/2/23 need real positions.
- Guessed Stugan Hue names need a walk-around to confirm Höger/Vänster/Bänk/Skärm.
- `light.garage_1/2/3` still sit in the Hue room `light.stugan_stugan` (unavailable members). Moving them out of that Hue room is a Hue-app change.
- No physical lamp tests (night / family). Do not start `*_animat` unless requested.

## Do not
- No credentials in this file.
- Do not restore snapshot `1e8d7407` without confirming it will wipe later work.
