#ifndef POSTPROCESSPLUGIN_HPP
#define POSTPROCESSPLUGIN_HPP

#include <PluginBase/RadiumPluginInterface.hpp>
#include <PostProcessPluginMacros.hpp>

namespace Ra {
    namespace Engine {
        class RadiumEngine;
        class Entity;
    }
    namespace Gui {
        class PickingManager;
    }
    namespace GuiBase {
        class SelectionManager;
    }
}

namespace PostProcessPlugin {

    class PostProcessSystem;
    class PostProcessUI;

    class PostProcessPluginC : public QObject, Ra::Plugins::RadiumPluginInterface {
        Q_OBJECT
            Q_PLUGIN_METADATA( IID "RadiumEngine.PluginInterface" )
            Q_INTERFACES( Ra::Plugins::RadiumPluginInterface )

        public:
            /*!
             *  \brief Constructor
             *
             *  Constructor of the PostProcessPluginC class
             */
            PostProcessPluginC();

            /*!
             *  \brief Destructor
             *
             *  Destructor of the PostProcessPluginC class
             */
            virtual ~PostProcessPluginC();

            void registerPlugin( const Ra::PluginContext& context ) override;

            bool doAddWidget( QString& name ) override;
            QWidget* getWidget() override;

            bool doAddMenu() override;
            QMenu* getMenu() override;

            bool doAddAction( int& nb ) override;
            QAction* getAction( int id ) override;

        private:
            unsigned int nbLightEntity = 0;
            PostProcessSystem* m_system;
            PostProcessUI* m_widget;
            Ra::Engine::RadiumEngine* m_engine;
            Ra::Gui::PickingManager* m_PickingManager;
            Ra::GuiBase::SelectionManager* m_SelectionManager;
    };

}

#endif

