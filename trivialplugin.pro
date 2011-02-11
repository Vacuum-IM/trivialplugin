#Plugin file name
TARGET              = trivialplugin
include(config.inc)

#Project Configuration
TEMPLATE            = lib
CONFIG             += plugin
QT                  = core gui
LIBS               += -l$${TARGET_UTILS}
LIBS               += -L$${VACUUM_LIB_PATH}
DEPENDPATH         += $${VACUUM_SRC_PATH}
INCLUDEPATH        += $${VACUUM_SRC_PATH}

#Install
include(install.inc)

#Translation
include(translations.inc)

include(trivialplugin.pri)
