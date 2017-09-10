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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Dialog  : public Component,
                public ComboBoxListener,
                public ButtonListener
{
public:
    //==============================================================================
    Dialog ();
    ~Dialog();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void addLogLine(String line);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> playerTracksGroup;
    ScopedPointer<GroupComponent> playerActionGroup;
    ScopedPointer<GroupComponent> playerSelectionGroup;
    ScopedPointer<ComboBox> playerBox;
    ScopedPointer<TextButton> refreshButton;
    ScopedPointer<TextButton> playButton;
    ScopedPointer<TextButton> stopButton;
    ScopedPointer<TextButton> nextButton;
    ScopedPointer<TextButton> previousButton;
    ScopedPointer<TextButton> refreshTracksButton;
    ScopedPointer<GroupComponent> activityLogGroup;
    ScopedPointer<TextEditor> activityEditor;
    ScopedPointer<TextEditor> tracksEditor;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Dialog)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
