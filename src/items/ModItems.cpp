#include "ModItems.hpp"
#include <amethyst/Log.hpp>
#include <mc/src/common/world/item/registry/ItemRegistry.hpp>
#include <mc/src/common/world/item/ItemStack.hpp>
#include <mc/src/common/world/actor/Actor.hpp>
#include <mc/src/common/world/level/BlockSource.hpp>

class ExampleItem2 : public Item {
public:
	ExampleItem2(const std::string& identifier, short id) 
		: Item(identifier, id) 
	{
		setIconInfo("tutorial_mod:example_item_2", 0);
		setIsGlint(true);
	}

	ItemStack& use(ItemStack& stack, Player& player) const override {
		Log::Info("ExampleItem2::use!");

		stack.mCount--;

		return Item::use(stack, player);
	}

	virtual InteractionResult _useOn(ItemStack& stack, Actor& actor, BlockPos pos, FacingID face, const Vec3& hit) const override {
		const BlockSource& region = actor.getDimensionBlockSourceConst();
		const Block& block = region.getBlock(pos);

		Log::Info("{} {}", pos, block.mLegacyBlock->mNameInfo.mFullName.getString());
	}
};

void ModItems::RegisterItems(RegisterItemsEvent& ev)
{
	Log::Info("Register Mod Items!");

	auto& exampleItem = ev.itemRegistry.registerItemShared<Item>("tutorial_mod:example_item", ev.itemRegistry.mMaxItemID++)
		->setIconInfo("diamond", 0)
		.setMaxStackSize(16);

	ev.itemRegistry.registerItemShared<ExampleItem2>("tutorial_mod:example_item_2", ev.itemRegistry.mMaxItemID++);
}
