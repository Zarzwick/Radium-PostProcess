#include <PostProcessSystem.hpp>

namespace PostProcessPlugin {
  PostProcessSystem::PostProcessSystem() : Ra::Engine::System() {}
  
  PostProcessSystem::~PostProcessSystem() {}

  void PostProcessSystem::handleAssetLoading( Ra::Engine::Entity* entity,
                                            const Ra::Asset::FileData* fileData ) {}
  
  void PostProcessSystem::generateTasks( Ra::Core::TaskQueue* taskQueue,
                                       const Ra::Engine::FrameInfo& frameInfo ) {}
  
}

