/*
  ==============================================================================

    CustomLookAndFeel.h
    Created: 2 Jun 2017 5:28:39pm
    Author:  Jordie Shier 

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class CustomLookAndFeel : public LookAndFeel_V4
{
public:
    
    // Default Constructor
    CustomLookAndFeel();
    
    // Custom button drawing
    void drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour,
                               bool isMouseOverButton, bool isButtonDown) override;
    
    // Colours
    struct Colours {
        static const ColourGradient background;
        static const ColourGradient backgroundOver;
        static const Colour buttonEdge;
    };
    
private:
    
    float buttonRadius;
    
};
