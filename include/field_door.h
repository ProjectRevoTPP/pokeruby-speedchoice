#ifndef GUARD_FIELDDOOR_H
#define GUARD_FIELDDOOR_H

struct DoorGraphics
{
    u16 metatileNum;
    u8 unk2;
    void *tiles;
    void *palette;
};

struct DoorAnimFrame
{
    u8 time;
    u16 offset;
};

void FieldSetDoorOpened(u32, u32);
void FieldSetDoorClosed(u32, u32);
s8 FieldAnimateDoorClose(u32, u32);
s8 FieldAnimateDoorOpen(u32, u32);
bool8 FieldIsDoorAnimationRunning(void);
u32 sub_8058790(u32 x, u32 y);

#endif
