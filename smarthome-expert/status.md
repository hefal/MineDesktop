# Status handoff — smarthome-expert

**Updated:** 2026-10-20 (overnight pass)
**Live source:** Cursor MCP `home-assistant-dashboard` (HA 2026.10.2, ha-mcp 8.7.0)
**Backup:** snapshot `82df5958` “Pre-registry cleanup 2026-10-20”; Stugan quality `1e8d7407`

## Overnight priority (2026-10-20)
Kept Stugan dark while sleeping. Did **not** turn lights or `*_animat` on to test.

Verified at end of pass: `light.stugan_stugan` / `light.stugan_led_tapo` / `light.stugan_led_slinga` **off**, house-wide lights **on** count 0, `input_boolean.ljus_stugan_manuellt` **on**, `script.stugan_tokyo_animat` **off**, ytterdörr **off** (closed), `input_boolean.ropa_ut_aktivitet` **off**, `input_boolean.stugvakt` **off**.

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
- **Stugan sleep / motion (live):**
  - Flag `input_boolean.ljus_stugan_manuellt` **on** until `binary_sensor.ytterdorr_stugan` opens (`door.opened` on `automation.stugan_ytterdorr_ateraktiverar_rorelseljus`).
  - Hue room off → flag on (`automation.stugan_slackning_pausar_rorelseljus`).
  - Motion, Hue-scene mirror, IKEA 1, helper dropdown, rumsknapp “on” branch, and personlarm TTS/notify skip while the flag is on.
  - `script.stugan_slack_och_pausa` always sets the flag, stops animat, turns Hue/Tapo/Nedis off twice.
  - `script.stugan_stamning` and all four `*_animat` scripts stop at the first step if the flag is on.
  - **Watchdog** `automation.stugan_sovpaus_haller_slackt`: if Hue room, Tapo, Nedis or `light.stugan_spot_1` turn on (or recover unavailable→on) while the flag is on, stop animat and turn those four off, retry after 3 s. Does not touch outdoor/floodlight/camera IR.
  - TV follow and Telldus-follow-Hue automations remain `off` (`initial_state: false`).

## Router / DHCP (not applied from this VM)
Reserve on Asus: `.239` Tapo L930, `.53` Nedis, LocalTuya `.3` `.34` `.76` `.88` `.106` `.148` `.202` `.211` `.223` `.248`.
**Conflict:** Källartoalett Spot Handfat and Garage Lampa Entré Mitt both stored as `192.168.1.106`.
WAN GUI is reachable as `https://hefal91.asuscomm.com:8443` but this VM could not keep a login session (self-signed cert, lockout). Do not store the password in git.

## Open
- Cottage bulbs and `switch.1_433_switch_1` still unavailable — onboard LocalTuya when they get LAN IPs.
- TuyaCam stays Cloud (`support_local: false`, no RTSP).
- `Källaren Lampa 19–25` and Moln 1/2/23 need real positions.
- Guessed Stugan Hue names need a walk-around to confirm Höger/Vänster/Bänk/Skärm.
- `light.garage_1/2/3` still sit in the Hue room `light.stugan_stugan` (unavailable members). Moving them out of that Hue room is a Hue-app change.
- Native Hue motion in the Hue app can still flash bulbs before the watchdog turns them off.
- Unavailable leftover YAML watchers: `automation.auto_reload_automations_scripts_on_file_change`, `automation.smart_yaml_reload_safe_restart` — do not delete without review.
- No physical lamp tests (night / family). Do not start `*_animat` unless requested.

## Do not
- No credentials in this file.
- Do not restore snapshot `1e8d7407` without confirming it will wipe later work.
- Do not turn Stugan lights or animations back on while `ljus_stugan_manuellt` is on.
