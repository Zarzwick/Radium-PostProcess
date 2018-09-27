#include <PostProcessPlugin.hpp>
#include <PostProcessSystem.hpp>
#include <PostProcessUI.hpp>

#include <Engine/RadiumEngine.hpp>
#include <Engine/Entity/Entity.hpp>
#include <Engine/Managers/EntityManager/EntityManager.hpp>
#include <GuiBase/Utils/PickingManager.hpp>
#include <GuiBase/SelectionManager/SelectionManager.hpp>

using namespace Ra;
using namespace Engine;

namespace PostProcessPlugin {

    PostProcessPluginC::PostProcessPluginC(): m_system ( nullptr ),
    m_widget ( nullptr ),
    m_engine ( nullptr ),
    m_PickingManager ( nullptr ),
    m_SelectionManager ( nullptr ) {}

    PostProcessPluginC::~PostProcessPluginC() {}

    void PostProcessPluginC::registerPlugin( const Ra::PluginContext& context ) {
        delete( m_system );
        m_system = new PostProcessSystem;
        context.m_engine->registerSystem( "PostProcessSystem", m_system );
        m_engine = context.m_engine;
        m_SelectionManager = context.m_selectionManager;
        m_PickingManager = context.m_pickingManager;
    }

    bool PostProcessPluginC::doAddWidget( QString& name ) {
        delete ( m_widget );
        m_widget = new PostProcessUI();

        //connect(m_widget, &PostProcessUI::initSignal,
                //this, &PostProcessPluginC::initReading);

        name = "Post Process";
        return true;
    }

    QWidget* PostProcessPluginC::getWidget() {
        return m_widget;
    }

    bool PostProcessPluginC::doAddMenu() {
        return false;
    }

    QMenu* PostProcessPluginC::getMenu() {
        return nullptr;
    }

    bool PostProcessPluginC::doAddAction( int& nb ) {
        nb = 0;
        return false;
    }

    QAction* PostProcessPluginC::getAction( int id ) {
        return nullptr;
    }

}
