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
        clear();
        for (auto artifact : pack) {
            QString line = (artifact.name + " (" + std::to_string(artifact.level) + ") | " + artifact.type + " - " + std::to_string(artifact.power)).c_str();
            addItem(line);
        }
    }
}
