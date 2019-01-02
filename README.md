# Teeworlds-Zod2
## Description
Zod is a Zombie-Mod for the retro-multiplayergame [Teeworlds](www.teeworlds.com).
It if written for teeworlds 0.7 and supports 60 zombies and 4 players.
The Mod supports a big variance of zombie-types.

After (re-)starting the game the mod beginns sending the first wave. After the player has defeated the first wave, a warmup starts and the next wave beginns.
The waves get more difficult the more you progress, because more zombie-types are added to the waves.

If you die, the **team** loses one if its lifes.

The game is over, after all teamlifes are gone.

## Install
* clone this repository

* compile the game the same way, you [compile default Teeworlds](https://www.teeworlds.com/?page=docs&wiki=compiling_everything). Remember, that this mod is written for **Teeworlds 0.7.x**. You only need the server, so use the command `<path>/bam conf=release server` for compiling

* start the server with
  - Linux: `./teeworlds_srv` (It may be found under /build)
  - Windows: doubleclick `teeworlds_srv.exe`
* you may have to call the restart command in the admin console (of teeworlds)
* Have Fun!

Binaries will be found in a later stage of this project.
You may want to take a look at the variables of this gamemode.
