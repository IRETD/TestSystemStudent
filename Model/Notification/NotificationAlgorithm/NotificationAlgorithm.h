#ifndef NOTIFICATIONALGORITHM_H
#define NOTIFICATIONALGORITHM_H

#include <Model/ModelItemDescriptor/ModelItemDescriptor.h>
#include <QHash>
#include <MyStorageType/SingleKeyContainer.h>
#include <Model/Notification/NotificationTypeQueue.h>
#include <Data/Icon/IconItemManager.h>

class IconItemManager;

class NotificationAlgorithm : public QObject {


    Q_OBJECT

protected:

    NotificationTypeQueue m_NotificationTypeQueue;

    QSharedPointer < IconItemManager > m_pIconItemManager;


public:
    NotificationAlgorithm( QSharedPointer < IconItemManager > pIconItemManager );
    virtual void doNextStepOfNotification() = 0;
    virtual void prepareAlgortihm() = 0;
    void addNotification( NotificationType notificationType,
                          QSharedPointer < ModelItemDescriptor > pModelItemDescriptor );
    bool isThereSomethingForUpdate();

private slots:
    void getModelItemDescriptorEvent( ModelItemDescriptorEvent event,
                                      ModelItemDescriptor *const pDescriptor );
};

#endif
