include(qmake/debug.inc)
include(qmake/config.inc)

#Project configuration
TARGET              = trivialplugin
QT                  = core gui
include(trivialplugin.pri)

#Default progect configuration
include(qmake/plugin.inc)

#Translation
TRANS_SOURCE_ROOT   = .
include(translations/languages.inc)
