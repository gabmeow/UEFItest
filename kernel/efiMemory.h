#pragma once
#include<stdint.h>

struct EFI_MEMORY_DESCRIPTOR
{
    uint32_t type;
    void* phyAddr;
    void* virtAddr;
    uint64_t numPages;
    uint64_t attribute;
};

extern const char* EFI_MEMORY_TYPE_STRING[];