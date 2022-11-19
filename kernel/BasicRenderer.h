#pragma once
#include"math.h"
#include"Framebuffer.h"
#include"SimpleFont.h"

class BasicRenderer
{
    public:
    BasicRenderer(Framebuffer* targetFramebuffer, PSF1_FONT* psf1_font);
    Point CursorPosition;
    Framebuffer* TargetFrameBuffer;
    PSF1_FONT* PSF1_Font;
    unsigned int Colour;
    void Print(const char* str);
    void PutChar(char chr, unsigned int xOff, unsigned int yOff);
};
