.. -*- restructuredtext -*-

What is well-random?
====================

well-random is a c++11 fork from `random <https://bitbucket.org/sergiu/random>`_, a collection of various
pseudo-random number generators and distributions that were intended to
accompany the Boost Random Number Library.

This fork currently only adopted the WELL generator and its tests.

Getting started
===============

The no-boost branch no longer requires any boost library. Instead it requires c++11.
To compile the tests make sure first CMake 2.8 is installed, then enter ::

  $ cmake . -DCMAKE_BUILD_TYPE=Release

in your terminal or command prompt on Windows inside project's directory to
generate the appropriate configuration that can be used to compile the tests
using make/nmake or inside an IDE.
