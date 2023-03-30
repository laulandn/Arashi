Calling all Programmers - Arashi in black and white
======

"I’ve been playing with trying to get Arashi running on my SE/30. I can get it to build okay, and even not to die with an error when I run in in Black & White mode - but I can’t actually get it to display anything on screen either.

I wondered if anyone here might have more luck? B&W Arashi, on the SE/30 and Classic II would be an excellent addition to the Mac Garden - even if a version for the Mac Plus is probably impossible!

What do you think? Are you interested in this project? I’ll upload what changes I’ve made to GitHub and you could have a crack at the puzzle too…"
--VMSZealot @ https://macintoshgarden.org/

================

This repo is a fork of the 1.1.1 codebase that has been modified to no longer require 256 color mode.

There is new drawing code to run in B&W only, on either 1 bit or 8 bit screens, using the frame buffer directly, or strictly using QuickDraw, which should run on any display.

Files: Arashi 1.1.1 with modifications, compiles with Symantec C++ 7

arashi1.1.0nl.img: DiskCopy 6.3 image. (May need to change type/creator to dimg/ddsk)
arashi1.1.1nl.img: DiskCopy 6.3 image. (May need to change type/creator to dimg/ddsk)

mvm-arashi-1.1.1-nl.dsk.zip: Mini vMac system disk image with same contents.
mvm-arashi-1.1.0-nl.dsk.zip: Mini vMac system disk image with Arashi 1.1 and Think C 5

NOTE: The older Arashi 1.1.0 version is included as it compiles with Think C 5 (only) so can be built on older systems more easily.  Changes from 1.1.1 are backported, but will lag.

================

Many many bugs remain and this is a work in progress...

Prebuilt binaries included in image(s):

Arashi1.1.1: Original unpatched from macintoshgarden.org

Arashi1.1.1bw: Whatever my latest build is, may be unstable/crash.

Arashi1.1.1bw_1bit: "New" graphics routines only runs on 1 bit depth screens.

Arashi1.1.1bw_8bit: "New" graphics routines only runs on 8 bit depth screens.

Arashi1.1.1bw_qd: Pure QuickDraw, should run on any hardware, but much slower.

======

NOTE: You should use the disk image if at all possible, as you may otherwise have trouble with resource fork preservation/conversion and file type/creator codes.  The source text files will, at minimum, need to be changed to TEXT/KAHL to be recognized by Think/Symantec.

======

The following is from the original README.md:

Arashi is a Tempest game clone for Mac OS classic (68k and PPC).

Initially released in 1992 by Juri Munkki, it was then improved by several people.
Unfortunately, Mac OS classic computers are not easy to come by anymore.

The non-commercial/shareware licence you can find inside the source tree doesn't hold anymore, and
the code is now MIT Licenced.
