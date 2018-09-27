#ifndef POSTPROCESSPLUGIN_UI_HPP
#define POSTPROCESSPLUGIN_UI_HPP

#include "PostProcessPlugin.hpp"

#include <QWidget>
#include <QPixmap>

namespace Ui {
    class PostProcessUI;
}

namespace PostProcessPlugin {
    class PostProcessUI : public QWidget
    {
        Q_OBJECT
        public:
            explicit PostProcessUI( QWidget *parent = 0 );
            ~PostProcessUI();

        signals:
            void initSignal(const std::string);

        private:
            Ui::PostProcessUI *ui;
    };

}

#endif
