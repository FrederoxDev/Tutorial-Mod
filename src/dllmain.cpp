#include "dllmain.hpp"
#include "items/ModItems.hpp"
#include "blocks/ModBlocks.hpp"

// Ran when the mod is loaded into the game by AmethystRuntime
ModFunction void Initialize(AmethystContext& ctx, const Amethyst::Mod& mod) 
{
    // Initialize Amethyst mod backend
    Amethyst::InitializeAmethystMod(ctx, mod);

    Amethyst::EventBus& bus = Amethyst::GetEventBus();
    bus.AddListener<RegisterItemsEvent>(&ModItems::RegisterItems);
    bus.AddListener<RegisterBlocksEvent>(&ModBlocks::RegisterModBlocks);
    bus.AddListener<RegisterItemsEvent>(&ModBlocks::RegisterBlockItems);
    bus.AddListener<InitBlockGraphicsEvent>(&ModBlocks::InitBlockGraphics);
}