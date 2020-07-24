#include <string>

#include "../JuceLibraryCode/JuceHeader.h"

#include "globals.h"
#include "Dialog.h"

#define DLLEXPORT extern"C" __declspec(dllexport)

std::unique_ptr<Dialog> dialogComponent;

DLLEXPORT int mstarPluginVersion()
{
    return 2;
}

DLLEXPORT void mstarInit(const PluginInterface::V2::Init& pInit)
{
    g_init = pInit;
}

DLLEXPORT void mstarConfigure()
{
    DialogWindow::LaunchOptions dialogLaunchOptions;
    dialogComponent = std::make_unique<Dialog>();

    dialogLaunchOptions.dialogTitle = "Log Plugin";
    dialogLaunchOptions.content.setNonOwned(dialogComponent.get());
    dialogLaunchOptions.resizable = false;
    dialogLaunchOptions.escapeKeyTriggersCloseButton = true;
    dialogLaunchOptions.useNativeTitleBar = false;
    dialogLaunchOptions.launchAsync();
}

DLLEXPORT void mstarPlayingStateChanged(const char* player_name, bool is_playing)
{
    if (!dialogComponent)
        return;

    String line = "[" + String(player_name) + "] " + (is_playing ? "playing" : "stopped");
    dialogComponent->addLogLine(line);
}

DLLEXPORT void mstarNextEntrySelected(const char* player_name)
{
    if (!dialogComponent)
        return;

    String line = "[" + String(player_name) + "] next entry selected";
    dialogComponent->addLogLine(line);
}

DLLEXPORT void mstarPreviousEntrySelected(const char* player_name)
{
    if (!dialogComponent)
        return;

    String line = "[" + String(player_name) + "] previous entry selected";
    dialogComponent->addLogLine(line);
}

DLLEXPORT void mstarPlaylistEntrySelected(const char* player_name, int entry_index, const char* playlistEntryName, double duration)
{
    if (!dialogComponent)
        return;

    String line = "[" + String(player_name) + "] playlist entry " + String(entry_index) + " with name '" + playlistEntryName + "' and duration " + String(duration) + " selected";
    dialogComponent->addLogLine(line);
}

DLLEXPORT void mstarPlaylistEntryNameChanged(const char* player_name, int entry_index, const char* playlistEntryName)
{
    if (!dialogComponent)
        return;

    String line = "[" + String(player_name) + "] playlist entry " + String(entry_index) + " changed name to '" + playlistEntryName + "'";
    dialogComponent->addLogLine(line);
}

DLLEXPORT void mstarPlaylistEntryDurationChanged(const char* player_name, int playlist_index, double duration)
{
    if (!dialogComponent)
        return;

    String line = "[" + String(player_name) + "] playlist entry " + String(playlist_index) + " changed duration to " +  String(duration);
    dialogComponent->addLogLine(line);
}

DLLEXPORT void mstarTrackVolumeChanged(const char* player_name, const char* track_name, float volume)
{
    if (!dialogComponent)
        return;

    String line = "[" + String(player_name) + "] volume of track " + String(track_name) + " changed to " + String(volume);
    dialogComponent->addLogLine(line);
}

DLLEXPORT void mstarPositionChanged(const char* player_name, double position)
{
    if (!dialogComponent)
        return;

    String line = "[" + String(player_name) + "] position changed to " + String(position);
    dialogComponent->addLogLine(line);
}

DLLEXPORT void mstarShutdown()
{
    dialogComponent.reset();
}

DLLEXPORT void mstarLoadConfiguration(const char* /*configurationText*/)
{
}

DLLEXPORT char* mstarGetConfiguration()
{
    return nullptr;
}

DLLEXPORT void mstarFreeConfigurationText(const char* /*configurationText*/)
{
}
