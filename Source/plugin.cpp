#include <string>

#include "../JuceLibraryCode/JuceHeader.h"

#include "globals.h"
#include "Dialog.h"

#define DLLEXPORT extern"C" __declspec(dllexport)

ScopedPointer<Dialog> dialogComponent;

DLLEXPORT int mstarPluginVersion()
{
    return 1;
}

DLLEXPORT void init(const PluginInterface::Init& pInit)
{
    g_init = pInit;
}

DLLEXPORT void configure()
{
    DialogWindow::LaunchOptions dialogLaunchOptions;
    dialogComponent = ScopedPointer<Dialog>(new Dialog());

    dialogLaunchOptions.dialogTitle = "Log Plugin";
    dialogLaunchOptions.content.setNonOwned(dialogComponent.get());
    dialogLaunchOptions.resizable = false;
    dialogLaunchOptions.escapeKeyTriggersCloseButton = true;
    dialogLaunchOptions.useNativeTitleBar = false;
    int result = dialogLaunchOptions.runModal();

    if (result == 1)
        return;
}

DLLEXPORT void playingStateChanged(const char* player_name, bool is_playing)
{
    if (!dialogComponent)
        return;

    String line = "[" + String(player_name) + "] " + (is_playing ? "playing" : "stopped");
    dialogComponent->addLogLine(line);
}

DLLEXPORT void nextEntrySelected(const char* player_name)
{
    if (!dialogComponent)
        return;

    String line = "[" + String(player_name) + "] next entry selected";
    dialogComponent->addLogLine(line);
}

DLLEXPORT void previousEntrySelected(const char* player_name)
{
    if (!dialogComponent)
        return;

    String line = "[" + String(player_name) + "] previous entry selected";
    dialogComponent->addLogLine(line);
}

DLLEXPORT void playlistEntrySelected(const char* player_name, int entry_index)
{
    if (!dialogComponent)
        return;

    String line = "[" + String(player_name) + "] playlist entry " + String(entry_index) + " selected";
    dialogComponent->addLogLine(line);
}

DLLEXPORT void trackVolumeChanged(const char* player_name, const char* track_name, float volume)
{
    if (!dialogComponent)
        return;

    String line = "[" + String(player_name) + "] volume of track " + String(track_name) + " changed to " + String(volume);
    dialogComponent->addLogLine(line);
}

DLLEXPORT void positionChanged(const char* player_name, double position)
{
    if (!dialogComponent)
        return;

    String line = "[" + String(player_name) + "] position changed to " + String(position);
    dialogComponent->addLogLine(line);
}

DLLEXPORT void shutdown()
{
    delete dialogComponent.release();
}

DLLEXPORT void loadConfiguration(const char* /*configurationText*/)
{
}

DLLEXPORT char* getConfiguration()
{
    return nullptr;
}

DLLEXPORT void freeConfigurationText(const char* /*configurationText*/)
{
}
