#ifndef TRIVIALPLUGIN_H
#define TRIVIALPLUGIN_H

#include "definitions.h"

#include <definitions/resources.h>
#include <interfaces/ipluginmanager.h>
#include <interfaces/imainwindow.h>
#include <utils/action.h>
#include <utils/filestorage.h>

#define TRIVIALPLUGIN_UUID "{9B9F39B1-F3C9-4258-B273-7970243B649A}"

class TrivialPlugin : 
	public QObject,
	public IPlugin
{
	Q_OBJECT;
	Q_INTERFACES(IPlugin);
	Q_PLUGIN_METADATA(IID "org.vacuum-im.plugins.TrivialPlugin");
public:
	TrivialPlugin();
	~TrivialPlugin();
	//IPlugin
	virtual QObject *instance() { return this; }
	virtual QUuid pluginUuid() const { return TRIVIALPLUGIN_UUID; }
	virtual void pluginInfo(IPluginInfo *APluginInfo);
	virtual bool initConnections(IPluginManager *APluginManager, int &AInitOrder);
	virtual bool initObjects();
	virtual bool initSettings() { return true; }
	virtual bool startPlugin() { return true; }
protected slots:
	void onMessageActionTriggered(bool);
private:
	IMainWindowPlugin *FMainWindowPlugin;
};

#endif // TRIVIALPLUGIN_H
