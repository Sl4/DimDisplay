//
//  main.c
//  DimDisplay
//
//  Created by Stanisław Uss on 24.02.2016.
//  Copyright © 2016 Stanisław Uss. All rights reserved.
//

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>

int main(void) {
    io_registry_entry_t r = IORegistryEntryFromPath(kIOMasterPortDefault, "IOService:/IOResources/IODisplayWrangler");
    if(!r) return 1;
    int err = IORegistryEntrySetCFProperty(r, CFSTR("IORequestIdle"), kCFBooleanTrue);
    IOObjectRelease(r);
    return err;
}
