# ttraverser
## a tiny project that detects gigantic files in your computer! :skull_and_crossbones:


- Troubling with your disk which is almost full all the time?
- Cannot decide which files to wipe off?
- Where all these GBs come from?

This project comes handy in locating the extreme sized files in your computer that you are unaware of!

Just specify the location where you want to do searching and specify a threshold to compare file sizes. If a file have a size greater than that threshold, then its path and name will be printed by program.

## Usage
- Right click and edit the bat file.
- Arrange the parameters according to your needence.

### Parameters in batch file
```bash
ttraverser.exe C:/Users 268435456 4
pause
```

`ttraverser.exe` -> exe name, don't change it  
`C:/Users` -> directory to start traversing. it searches inside this folder  
`268435456` -> threshold (in bits) to compare files with. greater sized files will be printed  
`4` -> max iteration count for algorithm. picking it too small results in unuseful results, and too big choice ends up with a nonterminal program. if you have no idea what DFS is, let it be 4

- Then just click on the batch file and enjoy!
