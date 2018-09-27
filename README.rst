===================
Post-process plugin
===================

Purpose
=======

This plugin aims to reimplement work that was done some years ago, but not
integrated into the Radium Engine back then. The evolution of Radium makes
impossible to reuse the code as is, so here is a real plugin doing the same
thing.

Compilation/Configuration
=========================

Building this plugin requires that

1. The Radium Engine is present and built somewhere
2. This somewhere should preferably be the same folder
3. The build mode is the same for both the Radium and the plugin

The ideal project configuration : ::

    Dev/
    ├── Radium-Engine/
    ├── Etc..
    └── Radium-PostProcess/

Dependencies from the Radium are - for now - enough.

