Calling all Programmers - Arashi in black and white
======

"I’ve been playing with trying to get Arashi running on my SE/30. I can get it to build okay, and even not to die with an error when I run in in Black & White mode - but I can’t actually get it to display anything on screen either.

I wondered if anyone here might have more luck? B&W Arashi, on the SE/30 and Classic II would be an excellent addition to the Mac Garden - even if a version for the Mac Plus is probably impossible!

What do you think? Are you interested in this project? I’ll upload what changes I’ve made to GitHub and you could have a crack at the puzzle too…"
--VMSZealot @ https://macintoshgarden.org/

======

This repo is a fork of the 1.1.1 codebase that has been modified to no longer require 256 color mode.


Files: Arashi 1.1.1 with modifications, compiles with Symantec C++ 7

arashi-1.1.1-nl.img: DiskCopy 6 image of Arashi 1.1.1 and Symantec C++ 7.
mvm-arashi-1.1.1-nl.dsk.zip: Mini vMac system disk image with same contents.

======

NOTE: There is a separate older Arashi 1.1 tree that may (or may not) run better on older systems.  You can replace the VA Kit folder using the same one as 1.1.1 here and build it with Think C 5.  I'll include disk images of it here soon.

======

It currently uses only basic QuickDraw to draw in black and white.  Not all Color QuickDraw code has been removed yet, so it still requires machines with Color QuickDraw in their ROMs.

Many many bugs remain and this is a work in progress...


======

The following is from the original README.md:

Arashi is a Tempest game clone for Mac OS classic (68k and PPC).

Initially released in 1992 by Juri Munkki, it was then improved by several people.
Unfortunately, Mac OS classic computers are not easy to come by anymore.

The non-commercial/shareware licence you can find inside the source tree doesn't hold anymore, and
the code is now MIT Licenced.
