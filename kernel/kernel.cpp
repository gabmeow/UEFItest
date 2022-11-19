#include<stddef.h>
#include"BasicRenderer.h"
#include"CStr.h"
#include"efiMemory.h"
#include"memory.h"
#include"Bitmap.h"

struct BootInfo
{
	Framebuffer* framebuffer;
	PSF1_FONT* psf1_Font;
	EFI_MEMORY_DESCRIPTOR* mMap;
	uint64_t mMapSize;
	uint64_t mMapDescriptorSize;
};

uint8_t testbuffer[20];
extern "C" void _start(BootInfo* bootInfo)
{
	BasicRenderer newRenderer = BasicRenderer(bootInfo->framebuffer, bootInfo->psf1_Font);

	newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y + 16};

	uint64_t mMapEntries = bootInfo->mMapSize / bootInfo->mMapDescriptorSize;

	Bitmap testBitmap;
	testBitmap.Buffer = &testbuffer[0];
	testBitmap.Set(0, false);
	testBitmap.Set(1, true);
	testBitmap.Set(2, false);
	testBitmap.Set(3, false);
	testBitmap.Set(4, true);

	for (int i = 0; i < 20; i++)
	{
		newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y + 16};
		newRenderer.Print(testBitmap[i] ? "true" : "false");
	}
	
	/*for (int i = 0; i < mMapEntries; i++)
	{
		EFI_MEMORY_DESCRIPTOR* desc = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)bootInfo->mMap + i *bootInfo->mMapDescriptorSize);
		newRenderer.CursorPosition = {50, newRenderer.CursorPosition.Y + 16};
		newRenderer.Print(EFI_MEMORY_TYPE_STRING[desc->type]);
		newRenderer.Colour = 0xffff00ff;
		newRenderer.Print(" ");
		newRenderer.Print(to_string(desc->numPages * 4096 / 1024));
		newRenderer.Print(" KB");
		newRenderer.Colour = 0xffffffff;
	}*/
	

    return;
}