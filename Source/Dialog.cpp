/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.1.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "globals.h"
//[/Headers]

#include "Dialog.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Dialog::Dialog ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (playerTracksGroup = new GroupComponent ("new group",
                                                               TRANS("Player Tracks")));

    addAndMakeVisible (playerActionGroup = new GroupComponent ("new group",
                                                               TRANS("Player Action")));

    addAndMakeVisible (playerSelectionGroup = new GroupComponent ("new group",
                                                                  TRANS("Player Selection")));

    addAndMakeVisible (playerBox = new ComboBox ("new combo box"));
    playerBox->setEditableText (false);
    playerBox->setJustificationType (Justification::centredLeft);
    playerBox->setTextWhenNothingSelected (String());
    playerBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    playerBox->addListener (this);

    addAndMakeVisible (refreshButton = new TextButton ("new button"));
    refreshButton->setButtonText (TRANS("refresh"));
    refreshButton->addListener (this);

    addAndMakeVisible (playButton = new TextButton ("new button"));
    playButton->setButtonText (TRANS("play"));
    playButton->addListener (this);

    addAndMakeVisible (stopButton = new TextButton ("new button"));
    stopButton->setButtonText (TRANS("stop"));
    stopButton->addListener (this);

    addAndMakeVisible (nextButton = new TextButton ("new button"));
    nextButton->setButtonText (TRANS("next"));
    nextButton->addListener (this);

    addAndMakeVisible (previousButton = new TextButton ("new button"));
    previousButton->setButtonText (TRANS("previous"));
    previousButton->addListener (this);

    addAndMakeVisible (refreshTracksButton = new TextButton ("new button"));
    refreshTracksButton->setButtonText (TRANS("refresh"));
    refreshTracksButton->addListener (this);

    addAndMakeVisible (activityLogGroup = new GroupComponent ("new group",
                                                              TRANS("Activity Log")));

    addAndMakeVisible (activityEditor = new TextEditor ("new text editor"));
    activityEditor->setMultiLine (true);
    activityEditor->setReturnKeyStartsNewLine (true);
    activityEditor->setReadOnly (true);
    activityEditor->setScrollbarsShown (true);
    activityEditor->setCaretVisible (false);
    activityEditor->setPopupMenuEnabled (true);
    activityEditor->setText (String());

    addAndMakeVisible (tracksEditor = new TextEditor ("new text editor"));
    tracksEditor->setMultiLine (true);
    tracksEditor->setReturnKeyStartsNewLine (false);
    tracksEditor->setReadOnly (true);
    tracksEditor->setScrollbarsShown (true);
    tracksEditor->setCaretVisible (false);
    tracksEditor->setPopupMenuEnabled (true);
    tracksEditor->setText (String());


    //[UserPreSize]
    //[/UserPreSize]

    setSize (500, 600);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

Dialog::~Dialog()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    playerTracksGroup = nullptr;
    playerActionGroup = nullptr;
    playerSelectionGroup = nullptr;
    playerBox = nullptr;
    refreshButton = nullptr;
    playButton = nullptr;
    stopButton = nullptr;
    nextButton = nullptr;
    previousButton = nullptr;
    refreshTracksButton = nullptr;
    activityLogGroup = nullptr;
    activityEditor = nullptr;
    tracksEditor = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Dialog::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Dialog::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    playerTracksGroup->setBounds (8, 200, getWidth() - 16, 192);
    playerActionGroup->setBounds (8, 80, getWidth() - 16, 112);
    playerSelectionGroup->setBounds (8, 8, getWidth() - 16, 64);
    playerBox->setBounds (24, 32, getWidth() - 139, 24);
    refreshButton->setBounds (getWidth() - 99, 32, 78, 24);
    playButton->setBounds (24, 112, proportionOfWidth (0.4398f), 24);
    stopButton->setBounds (24, 152, proportionOfWidth (0.4398f), 24);
    nextButton->setBounds (getWidth() - 27 - proportionOfWidth (0.4398f), 112, proportionOfWidth (0.4398f), 24);
    previousButton->setBounds (getWidth() - 27 - proportionOfWidth (0.4398f), 152, proportionOfWidth (0.4398f), 24);
    refreshTracksButton->setBounds (getWidth() - 99, 224, 78, 24);
    activityLogGroup->setBounds (8, 400, getWidth() - 16, getHeight() - 400);
    activityEditor->setBounds (32, 424, getWidth() - 59, getHeight() - 445);
    tracksEditor->setBounds (24, 224, getWidth() - 131, 152);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Dialog::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == playerBox)
    {
        //[UserComboBoxCode_playerBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_playerBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void Dialog::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == refreshButton)
    {
        //[UserButtonCode_refreshButton] -- add your button handler code here..
        playerBox->clear();

        auto addPlayer = [this](const char* player_name){
            playerBox->addItem(player_name, playerBox->getNumItems() + 1);
        };

        auto callback = [](const char* player_name, void* user_data){
            auto fn = static_cast<decltype(&addPlayer)>(user_data);
            (*fn)(player_name);
};

        g_init.listPlayers(callback, &addPlayer);
        //[/UserButtonCode_refreshButton]
    }
    else if (buttonThatWasClicked == playButton)
    {
        //[UserButtonCode_playButton] -- add your button handler code here..
        g_init.play(playerBox->getText().toRawUTF8());
        //[/UserButtonCode_playButton]
    }
    else if (buttonThatWasClicked == stopButton)
    {
        //[UserButtonCode_stopButton] -- add your button handler code here..
        g_init.stop(playerBox->getText().toRawUTF8());
        //[/UserButtonCode_stopButton]
    }
    else if (buttonThatWasClicked == nextButton)
    {
        //[UserButtonCode_nextButton] -- add your button handler code here..
        g_init.next(playerBox->getText().toRawUTF8());
        //[/UserButtonCode_nextButton]
    }
    else if (buttonThatWasClicked == previousButton)
    {
        //[UserButtonCode_previousButton] -- add your button handler code here..
        g_init.previous(playerBox->getText().toRawUTF8());
        //[/UserButtonCode_previousButton]
    }
    else if (buttonThatWasClicked == refreshTracksButton)
    {
        //[UserButtonCode_refreshTracksButton] -- add your button handler code here..
        tracksEditor->clear();

        String text;
        size_t count = 0;

        auto addTrack = [&text, &count](const char* track_name){
            if (count > 0)
                text += "\n";
            text += String(++count) + ": " + String(track_name);
        };

        auto callback = [](const char* track_name, void* user_data){
            auto fn = static_cast<decltype(&addTrack)>(user_data);
            (*fn)(track_name);
        };

        g_init.listTracks(playerBox->getText().toRawUTF8(), callback, &addTrack);

        tracksEditor->setText(text);
        //[/UserButtonCode_refreshTracksButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void Dialog::addLogLine(String line)
{
    String text = activityEditor->getText();
    auto time = Time::getCurrentTime();
    text = time.formatted("%H:%M:%S:") + String(time.getMilliseconds()) + " " + line + "\n" + text;
    activityEditor->setText(text);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Dialog" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="500" initialHeight="600">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GROUPCOMPONENT name="new group" id="3dfa81aa35af9c54" memberName="playerTracksGroup"
                  virtualName="" explicitFocusOrder="0" pos="8 200 16M 192" title="Player Tracks"/>
  <GROUPCOMPONENT name="new group" id="ef3e10e24d0aa831" memberName="playerActionGroup"
                  virtualName="" explicitFocusOrder="0" pos="8 80 16M 112" title="Player Action"/>
  <GROUPCOMPONENT name="new group" id="dc1d17fca3c57dba" memberName="playerSelectionGroup"
                  virtualName="" explicitFocusOrder="0" pos="8 8 16M 64" title="Player Selection"/>
  <COMBOBOX name="new combo box" id="cc90b3f364a0177" memberName="playerBox"
            virtualName="" explicitFocusOrder="0" pos="24 32 139M 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="new button" id="be749335664dc93d" memberName="refreshButton"
              virtualName="" explicitFocusOrder="0" pos="99R 32 78 24" buttonText="refresh"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="782524494342ddb2" memberName="playButton"
              virtualName="" explicitFocusOrder="0" pos="24 112 43.994% 24"
              buttonText="play" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="a697f73c0108e251" memberName="stopButton"
              virtualName="" explicitFocusOrder="0" pos="24 152 43.994% 24"
              buttonText="stop" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="b87e4e67dd2f57e2" memberName="nextButton"
              virtualName="" explicitFocusOrder="0" pos="27Rr 112 43.994% 24"
              buttonText="next" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="f3a85ddec6b3d359" memberName="previousButton"
              virtualName="" explicitFocusOrder="0" pos="27Rr 152 43.994% 24"
              buttonText="previous" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="88829d275c38cdf4" memberName="refreshTracksButton"
              virtualName="" explicitFocusOrder="0" pos="99R 224 78 24" buttonText="refresh"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <GROUPCOMPONENT name="new group" id="455c2fc8192f910b" memberName="activityLogGroup"
                  virtualName="" explicitFocusOrder="0" pos="8 400 16M 400M" title="Activity Log"/>
  <TEXTEDITOR name="new text editor" id="5429b7c7d4cdb8a4" memberName="activityEditor"
              virtualName="" explicitFocusOrder="0" pos="32 424 59M 445M" initialText=""
              multiline="1" retKeyStartsLine="1" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="fa7d294e141330ca" memberName="tracksEditor"
              virtualName="" explicitFocusOrder="0" pos="24 224 131M 152" initialText=""
              multiline="1" retKeyStartsLine="0" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
