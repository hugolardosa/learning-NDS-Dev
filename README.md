# NDS-Development Intro
My research and projects for developing on the NDS will be placed in this read me.
This repo will also include the default SDK folder and various projects I build.
All development will be done on OSX and unfortunately I don't know how this effect those trying the code out on windows.
Windows users this might help you out: http://www.coranac.com/tonc/text/setup.htm

# Repo details

Exmaple code list:

/improved-simple/ 
Includes an on going practice script to learn the kit. It's based off the *simple* example shipped with DKP.


# Downloading and Installing
So since the NDS is getting a little old devkitPro is now starting you off with Wii and GC. Which we don't want we want GBA/NDS devkitPro. So the correct download link is here:
http://devkitpro.org/wiki/Getting_Started/devkitARM

After installing (at least with the OSX perl install) it requires you to set up environment variables.
This is what my *~/.bash_profile* looks like:
```
  export DEVKITPRO=/Users/jdriselvato/devkitPro
  export DEVKITARM=${DEVKITPRO}/devkitARM
```

Then literally after that go to *~/devkitPro/examples* and type *make* in any of the example folders and it will run. It couldn't be easier.

#Emulator
I'm using DESMUME as the emulator to test out the code on OSX. I do have an R4 that I'll be using to test on device

#Resources to read
1. http://devkitpro.org/wiki/Getting_Started/devkitARM - Getting Started
2. https://patater.com/files/projects/manual/manual.html - Best guide to get you really familair with developing NDS
2. https://web.archive.org/web/20150814060137/http://www.tobw.net/dswiki/index.php?title=Graphic_modes - Graphic Modes
3. http://libnds.devkitpro.org/index.html - The libNDS documentation (the bible practically)
