include(qmake/debug.inc)
include(qmake/config.inc)

#Project configuration
TARGET              = trivialplugin
QT                  = core gui widgets
include(trivialplugin.pri)

#Default progect configuration
include(qmake/plugin.inc)

#Translation
TRANS_SOURCE_ROOT   = .
TRANS_BUILD_ROOT = $${OUT_PWD}
include(translations/languages.inc)
