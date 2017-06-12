/*
  ==============================================================================

    CustomLookAndFeel.cpp
    Created: 2 Jun 2017 5:28:39pm
    Author:  Jordie Shier 

  ==============================================================================
*/

#include "CustomLookAndFeel.h"


CustomLookAndFeel::CustomLookAndFeel()
{
    buttonRadius = 7.0f;
}

void CustomLookAndFeel::drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour,
                                            bool isMouseOverButton, bool isButtonDown)
{
    Rectangle<float> buttonArea = button.getLocalBounds().toFloat();
    g.setColour(Colours::buttonEdge);
    g.drawRoundedRectangle(buttonArea, buttonRadius, 1.5f);
    
    if (isMouseOverButton)
    {
        g.setGradientFill(Colours::backgroundOver);
        g.fillRoundedRectangle(buttonArea, buttonRadius);
    }
    
    
}


// Colours
const Colour CustomLookAndFeel::Colours::buttonEdge = Colour::fromRGB(174, 191, 215);

// Gradients
const ColourGradient CustomLookAndFeel::Colours::background = ColourGradient(
                                                                             Colour::fromRGB(140, 140, 140) ,
                                                                             0.0f,
                                                                             0.0f,
                                                                             Colour::fromRGB(160, 160, 160),
                                                                             0.0f,
                                                                             650.0f,
                                                                             false);
const ColourGradient CustomLookAndFeel::Colours::backgroundOver = ColourGradient(
                                                                             Colour::fromRGB(150, 150, 150) ,
                                                                             0.0f,
                                                                             0.0f,
                                                                             Colour::fromRGB(170, 170, 170),
                                                                             0.0f,
                                                                             650.0f,
                                                                             false);
