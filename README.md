# Teeworlds-Zod2
[![CircleCI](https://circleci.com/gh/AssassinTee/Teeworlds-Zod2.svg?style=shield)](https://circleci.com/gh/AssassinTee/Teeworlds-Zod2)
[![Build status](https://ci.appveyor.com/api/projects/status/rfhb7d6755ce28xi/branch/master?svg=true)](https://ci.appveyor.com/project/AssassinTee/teeworlds-zod2/branch/master)
[![release version](https://img.shields.io/github/release/AssassinTee/Teeworlds-Zod2.svg?style=flat)](https://github.com/AssassinTee/Teeworlds-Zod2/releases)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/c132571702c4443286ab6df0e5904014)](https://www.codacy.com/app/AssassinTee/Teeworlds-Zod2?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=AssassinTee/Teeworlds-Zod2&amp;utm_campaign=Badge_Grade)
![Teeworlds version](https://img.shields.io/badge/Teeworlds-0.7.2-brightgreen.svg)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/AssassinTee/Teeworlds-Zod2/issues)
[![HitCount](http://hits.dwyl.io/AssassinTee/Teeworlds-Zod2.svg)](http://hits.dwyl.io/AssassinTee/Teeworlds-Zod2)
> _"HITS - How Idiots Track Success"_

## Attention

Archived as of 2025!

## Description
Zod is a Zombie-Mod for the retro-multiplayergame [Teeworlds](www.teeworlds.com).
It is written for Teeworlds 0.7 and supports 60 zombies and 4 players at once.
The mod supports a big variance of zombie-types.

After (re-)starting the game the mod beginns sending the first wave. After the player has defeated the first wave, a warmup starts and the next wave begins.
The waves get more difficult the more you progress, because more zombie-types are added to the waves.

If you die, the **team** loses one of its lifes.

The game is over, after all teamlifes are gone.

## Getting Started

* clone this repository

* compile the game the same way, you [compile default Teeworlds](https://www.teeworlds.com/?page=docs&wiki=compiling_everything). Remember, that this mod is written for **Teeworlds 0.7.x**. You only need the server, so use the command `<path>/bam conf=release server` for compiling

* start the server with

    * Linux: `./teeworlds_srv` (It may be found under /build)

    * Windows: doubleclick `teeworlds_srv.exe`

* you may have to call the restart command in the admin console (of teeworlds)

* Have Fun!

Binaries will be found in a later stage of this project.
You may want to take a look at the variables of this gamemode.

## Configure

Waves are configurable with .json files. Teeworlds already uses a json reader for the skin files, but I added another json-reader.

* `example_wave.json` is default wavefile

* with `sv_wave_file <your wave file>` you can change the wave configuration file

* Top5 and rank statistics will always be found under `top5/` in `<mapname>.json`

* You can't change the filename or location of the top5 files

Example wave-configurations:
```JSON
{
  "Version": "1.0.0",
  "Waves": {
    "1": {
      "Zaby": 10
    },
    "2": {
      "Zaby": 10,
      "Zooker": 2
    }
  }
}
```

* `Version`: The Version of the wave file. This allows backwards compatibility.

* `Waves`: Stores the waves in key value form. The key is the wave number and the value is a json-object

* Wave-object: **Key**: _Zombiename_, **Value**: _Zombienumber_

Full wave-object example:

```JSON
    "13": {
      "Zaster": 2,
      "Zaby": 10,
      "Zooker": 2,
      "Zamer": 10,
      "Zunner": 10,
      "Zotter": 10,
      "Zenade": 10,
      "Flombie": 10,
      "Zinja": 10,
      "Zele": 10,
      "Zinvis": 10,
      "Zoomer": 5,
      "Zeater": 10
    }
```
## Contributing

Feel free to contribute! In the current project state every feedback is usefull

## Built With

* [nlohmann/json](https://github.com/nlohmann/json) - JSON for Modern C++, version 3.5.0

## Authors

* **AssassinTee** - Everything

## License
This project is licensed under the GPLv3, as every Teeworlds code should be - see [license.txt](https://github.com/AssassinTee/Teeworlds-Zod2/blob/master/license.txt) file for details

## Great Thanks to

* nlohmann for his great [json library](https://github.com/nlohmann/json)

* CircleCI integration is awesome, thank you Teeworlds devs!
