#ifndef POSTPROCESSPLUGIN_SYSTEM_HPP
#define POSTPROCESSPLUGIN_SYSTEM_HPP

#include <PostProcessPluginMacros.hpp>
#include <PostProcessPlugin.hpp>

#include <Engine/System/System.hpp>


namespace PostProcessPlugin {
  class PP_PLUGIN_API PostProcessSystem : public Ra::Engine::System {
  public:
    PostProcessSystem();
    virtual ~PostProcessSystem();
    
    void handleAssetLoading( Ra::Engine::Entity* entity,
                             const Ra::Asset::FileData* fileData ) override;
    
    void generateTasks( Ra::Core::TaskQueue* taskQueue,
                        const Ra::Engine::FrameInfo& frameInfo ) override;
    
  };
}

#endif

