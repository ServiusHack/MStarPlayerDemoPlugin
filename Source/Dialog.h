/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

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
                public juce::ComboBox::Listener,
                public juce::Button::Listener
{
public:
    //==============================================================================
    Dialog ();
    ~Dialog() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void addLogLine(String line);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> playerTracksGroup;
    std::unique_ptr<juce::GroupComponent> playerActionGroup;
    std::unique_ptr<juce::GroupComponent> playerSelectionGroup;
    std::unique_ptr<juce::ComboBox> playerBox;
    std::unique_ptr<juce::TextButton> refreshButton;
    std::unique_ptr<juce::TextButton> playButton;
    std::unique_ptr<juce::TextButton> stopButton;
    std::unique_ptr<juce::TextButton> nextButton;
    std::unique_ptr<juce::TextButton> previousButton;
    std::unique_ptr<juce::TextButton> refreshTracksButton;
    std::unique_ptr<juce::GroupComponent> activityLogGroup;
    std::unique_ptr<juce::TextEditor> activityEditor;
    std::unique_ptr<juce::TextEditor> tracksEditor;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Dialog)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

