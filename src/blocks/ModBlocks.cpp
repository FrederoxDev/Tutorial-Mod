#include "ModBlocks.hpp"
#include <mc/src/common/world/level/block/registry/BlockTypeRegistry.hpp>
#include <mc/src/common/world/level/block/BlockLegacy.hpp>
#include <mc/src/common/world/level/block/definition/BlockDefinitionGroup.hpp>
#include <mc/src/common/world/item/BlockItem.hpp>
#include <mc/src/common/world/item/registry/ItemRegistry.hpp>
#include <mc/src-client/common/client/renderer/block/BlockGraphics.hpp>

WeakPtr<BlockLegacy> ModBlocks::mTestBlock = nullptr;

class TestBlock : public BlockLegacy {
public:
	TestBlock(const std::string& nameId, short id, const Material& material)
		: BlockLegacy(nameId, id, material) {}

	virtual void onStandOn(EntityContext& unk0, const BlockPos& unk1) const override {
		Log::Info("onStandOn!");
	}
};

void ModBlocks::RegisterModBlocks(RegisterBlocksEvent& ev)
{
	Material& material = Material::getMaterial(MaterialType::Dirt);
	mTestBlock = BlockTypeRegistry::registerBlock<TestBlock>("tutorial_mod:test_block", ev.blockDefinitions.getNextBlockId(), material);
}

void ModBlocks::RegisterBlockItems(RegisterItemsEvent& ev) {
	ev.itemRegistry.registerItemShared<BlockItem>(mTestBlock->mNameInfo.mFullName.getString(), mTestBlock->getBlockItemId(), mTestBlock->mNameInfo.mFullName);

	auto& constructionTab = ev.mCreativeItemRegistry.GetVanillaCategory(CreativeItemCategory::Construction);
	constructionTab.AddCreativeItem(*mTestBlock);
}

void ModBlocks::InitBlockGraphics(InitBlockGraphicsEvent& ev)
{
	BlockGraphics* testBlockGraphics = BlockGraphics::createBlockGraphics(mTestBlock->mNameInfo.mFullName, BlockShape::BLOCK);
	testBlockGraphics->setTextureItem("tutorial_mod:test_block");
	testBlockGraphics->setDefaultCarriedTextures();
}
