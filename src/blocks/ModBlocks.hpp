#pragma once
#include <amethyst/runtime/events/RegisterEvents.hpp>
#include <mc/src/common/world/level/block/BlockLegacy.hpp>

class ModBlocks {
public:
    static WeakPtr<BlockLegacy> mTestBlock;

    static void RegisterModBlocks(RegisterBlocksEvent& ev);
    static void RegisterBlockItems(RegisterItemsEvent& ev);
    static void InitBlockGraphics(InitBlockGraphicsEvent& ev);
};