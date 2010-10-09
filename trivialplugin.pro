include(config.inc)

#Project Configuration
TARGET              = trivialplugin
TEMPLATE            = lib
CONFIG             += plugin
QT                  = core gui
LIBS               += -L$${SDK_PATH}/libs
LIBS               += -l$${TARGET_UTILS}
DEPENDPATH         += $${SDK_PATH}
INCLUDEPATH        += $${SDK_PATH}

#SVN Info
SVN_REVISION=$$system(svnversion -n -c .)
win32 {
  exists(svninfo.h):system(del svninfo.h)
  !isEmpty(SVN_REVISION):system(echo $${LITERAL_HASH}define SVN_REVISION \"$$SVN_REVISION\" >> svninfo.h) {
    DEFINES       += SVNINFO
  }
} else {
  exists(svninfo.h):system(rm -f svninfo.h)
  !isEmpty(SVN_REVISION):system(echo \\$${LITERAL_HASH}define SVN_REVISION \\\"$${SVN_REVISION}\\\" >> svninfo.h) {
    DEFINES       += SVNINFO
  }
}

#Translation
TRANSLATIONS        = ./translations/src/ru_RU/$${TARGET}.ts

include(trivialplugin.pri)
