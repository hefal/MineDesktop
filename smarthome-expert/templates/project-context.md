# Project context — edit freely, delete what is wrong

The bot reads this before any live change. Keep it short and true. Never put secrets here.


## Live session (agent-filled)
- Connected via Cursor MCP `home-assistant-dashboard` (ha-mcp 8.7.0).
- Core version: **2026.10.2** · location: **Hemgårdsvägen** · tz: **Europe/Stockholm** · lang: en · state: RUNNING.
- Scale snapshot: 786 entities, 18 areas, 71 automations, 23 cameras, 74 lights, 4 persons.
- Areas seen: Stugan, Garage, Glashus, Vardagsrummet, Källartoalett, Källare, Hemgårdsvägen, Sovrum, …
- Do not store tokens or MCP URLs here.


## Platform
- Home Assistant OS running as a Hyper-V VM on a Windows laptop (HP EliteBook 640 G11, Core Ultra 5 125U, 32 GB RAM).
- HA URL: `http://<HA_LAN_IP>:8123` (LAN). Host PC LAN IP: `<WINDOWS_HOST_IP>`.
- Ollama runs on the Windows host (port 11434, LAN); BakLLaVA 7B pulled; more models as needed.
- Zigbee: ConBee coordinator; boot tasks on the Windows host start ConBee and Ollama.
- Backups: daily at 06:15 and on login, to an SMB share on HA and a OneDrive folder. Encryption key held separately.
- Constraint: HA runs in Hyper-V, so no restart without coordination.
- Remote access: `<none | Nabu Casa/Link | Tailscale | other>`.

## Dashboards
- Primary dashboard: "Dash" (`dashboard-dash`), Swedish UI, 25 views: `hem`, `belysning` (+`belysning-2`), `kameror`, `tv-kameror`, `ai`, `media`, `musik`, `klimat`, `system`, `system-rad`, `vardag`, per-room light views (`ljus-*`), per-person family views (`familj-*`), `familjekarta`, `handelser`, `stugan-live`, `tal`, `tuya-ljus`.
- Other dashboards: Map (generated), Karta (`karta-historik`), Router (ASUS router), Stugan Ljus (Hue).
- Stack: Bubble Card, custom components (Hue Rooms, Music Assistant, AI control), custom JavaScript served from `/local/neon-dashboard/` with `?v=N` cache-busting.
- Design brief: professional, futuristic, minimalist; a blend of cyberpunk and Philips Hue. Animated wallpapers selectable per tab (drawn from sliderrevolution.com's CSS animated-background list and adapted), a customizable fog layer, a per-person page template, a Musik carousel of album covers with a Spotify URL each, a vertical navbar replacing the default sidebar, and a top bar with a glowing active tab. Clock and weather always visible; the Hem page carries the family bars.
- Language: UI strings in Swedish; entity IDs, paths, code, and comments in English/ASCII. See `knowledge/glossary-sv-en.md`.
- Possible wall panel (status unknown): Fidelix VISIO-15-X, Android 11, 15.6-inch panel.

## Rules of this house
- Preserve entity IDs, service calls, and navigation paths.
- No cosmetic change may trigger a live action (lights, speech, music).
- Test on 1440×900, 768×1024, 390×844, 320×740, plus 1280×800.
- UI priorities: responsive layout, readability, consistent controls, clear busy/error/status, keyboard access.
- One writer per dashboard at a time. Status doc updated at every agent or account switch.

## Agents in play
Claude (two accounts), Codex, Cursor, a smaller Claude model for step-by-step integration, and this Grok bot. Handoff by `status.md` (from `templates/status-handoff.md`).

## Regressions to prevent
- An aborted brightness drag must not send a commit.
- Keyboard use and accessible names must work.
- Pending radio and media calls must not re-activate on Home Assistant updates.
- Error messages must survive re-renders.
- Event-list updates must keep focus (stable event IDs).
- A stale async result (speech, analysis) must never overwrite the state of a newer one.

## Open items
- 2026-10-20: DHCP reservations still user-side; LocalTuya .106 IP conflict; cottage/1-433 offline; TuyaCam Cloud-only; Hue lightstrip entity IDs still English.
