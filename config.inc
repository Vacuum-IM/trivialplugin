#Path to biulded Vacuum src direcroty
isEmpty(SDK_PATH) {
  SDK_PATH               = ../vacuum/src
}

#Debug Features
CONFIG(debug, debug|release) 
{
  #Path to copy plugin on build
  win32:DLLDESTDIR       = ../vacuum/plugins
  unix:DESTDIR           = ../vacuum/plugins

  #Path from vacumm to plugin resources
  DEFINES               += RESOURCES_DIR='\\\"../trivialplugin/resources\\\"'
}

#Should be included from SDK
TARGET_UTILS             = vacuumutils
unix:VERSION_UTILS       = 1.2.0
