#include <QFileDialog>
#include "PostProcessUI.hpp"
#include "ui_PostProcessUI.h"

#include <Core/Log/Log.hpp>

namespace PostProcessPlugin {

    PostProcessUI::PostProcessUI( QWidget *parent ) :
        QWidget( parent ),
        ui( new Ui::PostProcessUI ) {
            ui->setupUi( this );
        }

    PostProcessUI::~PostProcessUI() { delete ui; }

}
