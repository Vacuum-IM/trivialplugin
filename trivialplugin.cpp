#include "trivialplugin.h"

#include <QDir>
#include <QMessageBox>
#include <QApplication>


TrivialPlugin::TrivialPlugin()
{
	FMainWindowPlugin = NULL;

#ifdef DEBUG_RESOURCES_DIR
	FileStorage::setResourcesDirs(FileStorage::resourcesDirs() << (QDir::isAbsolutePath(DEBUG_RESOURCES_DIR) ? DEBUG_RESOURCES_DIR : qApp->applicationDirPath()+"/"+DEBUG_RESOURCES_DIR));
#endif
}

TrivialPlugin::~TrivialPlugin()
{

}

void TrivialPlugin::pluginInfo(IPluginInfo *APluginInfo)
{
	APluginInfo->name = tr("Trivial Plugin");
	APluginInfo->description = tr("Example of Vacuum-IM extension plugin");
	APluginInfo->version = "1.2.0";
	APluginInfo->author = "Potapov S.A. aka Lion";
	APluginInfo->homePage = "http://code.google.com/p/vacuum-plugins";
	APluginInfo->dependences.append(MAINWINDOW_UUID);
}

bool TrivialPlugin::initConnections(IPluginManager *APluginManager, int &AInitOrder)
{
	Q_UNUSED(AInitOrder);

	IPlugin *plugin = APluginManager->pluginInterface("IMainWindowPlugin").value(0);
	if (plugin)
	{
		FMainWindowPlugin = qobject_cast<IMainWindowPlugin *>(plugin->instance());
	}

	return FMainWindowPlugin!=NULL;
}

bool TrivialPlugin::initObjects()
{
	if (FMainWindowPlugin)
	{
		Action *action = new Action(this);
		action->setIcon(RSR_STORAGE_MENUICONS,MNI_TRIVIALPLUGIN_MESSAGE);
		action->setText(tr("Trivial Message"));
		connect(action,SIGNAL(triggered(bool)),SLOT(onMessageActionTriggered(bool)));
		FMainWindowPlugin->mainWindow()->mainMenu()->addAction(action,AG_MMENU_TRIVIALMESSAGE);
	}
	return true;
}

void TrivialPlugin::onMessageActionTriggered(bool)
{
	QMessageBox::information(NULL,tr("Trivial Plugin"),tr("Use a Vacuum-IM every day, and your hair will be soft and silky!"));
}

Q_EXPORT_PLUGIN2(plg_trivialplugin, TrivialPlugin)
