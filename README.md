# D2Template89

D2Template, as well as D2Template89, is an open source community project that was developed in order to help modders getting started into advanced code editing on Diablo II. The library provides a basic and simple codebase, ready to be injected in-game, allowing you to quickly inject your own code, without the need to learn stuff like memory patching.

There are several differences between D2Template and D2Template89. The most notable change is the refactoring of the core codebase, and the rewrite to C89.

The documentation can be found [here](https://github.com/IAmTrial/D2Template/wiki)

## What does the template include?

To start off, a patcher. This is pretty much the basic of basics, as you need to inject your code into the game at some point, right? You do not need to get into complicated memory patching coding, the template does it for you. Then you have some various utility files, for pointers importing from the game's library, variables declaration, etc.

## What do I need to use this template?

The template was created and compiled with the help of CMake and Visual Studio 2019, but provides support for a wide range of compilers. See the wiki for more information under the "Tools" page. Pull requests to support additional compilers are welcome.

## What should I know before using this template?

First of all, get started with the basics of C or C++. Get used to the syntax, practice by creating basic programs, get at least a basic knowledge of the language. Next, get used with the IDE you're going to use to work with this template. And finally, basic ASM knowledge can also help you a lot. Some examples are already included with the base project, to help you get an understanding for how to add new features. For more details, check the wiki pages.
