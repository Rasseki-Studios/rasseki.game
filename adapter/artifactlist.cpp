#include "artifactlist.h"

#include "libAdapter.h"
#include "config.h"
#include "style.h"

ArtifactList::ArtifactList(QWidget *parent) : QListWidget(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //отключим скроллбар по горизонтали


    timer = std::shared_ptr<QTimer>(new QTimer());   //инициализируем Таймер
    connect(timer.get(), SIGNAL(timeout()), this, SLOT(slotReload()));    //подключаем cлот для отрисовки к таймеру
    timer->start(timer_delay);   //стартуем таймер
}

void ArtifactList::slotReload()
{
    std::vector<InventoryData> pack;
    if (IData(pack)) {

        /*for (int i=0; i<CurObjectInfo.value(iterator).params.count(); i++){
            QStandardItem *item_col_01 = new QStandardItem(CurObjectInfo.value(iterator).params.value(i).paramname);
            QStandardItem *item_col_02 = new QStandardItem(CurObjectInfo.value(iterator).params.value(i).value.toString());
            model.appendRow(QList<QStandardItem*>() << item_col_01 << item_col_02);
        }
        ui->tableView->setModel(&model);
        for (auto element : pack) {
            this->ap
        }*/
    }
}
