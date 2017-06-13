/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "CustomLookAndFeel.h"
#include "SampleGrid.h"
#include "DirectoryChooser.h"
#include "SampleManager.h"


//==============================================================================
/**
*/
class SampleBrowserAudioProcessorEditor  : public AudioProcessorEditor,
                                           public ButtonListener
{
public:
    SampleBrowserAudioProcessorEditor (SampleBrowserAudioProcessor&);
    ~SampleBrowserAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // Reference to processor
    SampleBrowserAudioProcessor& processor;
    
    // Button callback
    void buttonClicked(Button* button) override;
    
    SampleManager* sampleManager;
    
    DirectoryChooser directoryChooser;
    
    CustomLookAndFeel customLookAndFeel;
    ScopedPointer<SampleGrid> sampleGrid;
    
    TextButton filesButton;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SampleBrowserAudioProcessorEditor)
};
