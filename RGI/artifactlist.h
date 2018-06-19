#ifndef ARTIFACTLIST_H
#define ARTIFACTLIST_H

#include <QListWidget>
#include <QTimer>

#include <memory>

class ArtifactList : public QListWidget
{
    Q_OBJECT
public:
    explicit ArtifactList(QWidget *parent = 0);

public slots:
    void slotReload();

private:
    std::shared_ptr<QTimer> timer;
};

#endif // ARTIFACTLIST_H
