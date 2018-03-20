#ifndef NOTIFICATIONTIMER_H
#define NOTIFICATIONTIMER_H

/*
 *
 * Данный класс испускает задающий периодичность смены состояния иконки.
 * Это некий синхронизатор, по которому иконки, которые должны сменить свое изображение,
 * в один момент времени изменяю его. Благодарю этому классу,
 * мы избавляем от рассинхронизации в изменении изображения разных иконок.
 * Пока что предполагается, что иконка может одновременно может сменять 2 состояния (состояние по умолчанию и любое другое).
 * Поэтому сигнал notificationSignal, попросту задает разрешение на смену другого состояния, отличного от по умолчанию.
 *
*/

#include <QTimer>

class NotificationTimer : public QObject {

    Q_OBJECT

    QTimer m_Timer;
    bool m_LightOn;
    int m_Interval;

private slots:
    void setLightOnStatus();

signals:
    void notificationSignal( bool lightOn );

public:
    NotificationTimer();
    //Задает время периодичного испускания сигнала
    void setInterval( const int &interval );
    void startNotifications();
    void stopNotifications();


};

#endif // NOTIFICATIONTIMER_H
