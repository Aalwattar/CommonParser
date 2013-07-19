CommonParser
========

A file IO library.

    This makefile automatically builds the shared library, then places it in $HOME/lib
    It also places common_interfaces.h, architecture_library.h, dfg_library.h and
        hardware_library.h inside $HOME/include


BUILDING 
========
- Dependancies: libconfuse (installed either as the superuser or in $HOME)
- type: make


USAGE
=====

- to use the common data structures, include common_interfaces.c
- to institute file parsing, include the appropriately named .h file:
    architecture_library.h
    dfg_library.h
    hardware_library.h


CONTENTS:
=========

examples	= examples of the format that this parser follows
nbproject	= A configuration folder for Netbeans Projects (my IDE)
obj		= where the object files are stored to create the library
