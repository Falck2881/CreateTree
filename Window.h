#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QDebug>

class Window: public QWidget
{
    Q_OBJECT

    public:
        Window(Window* window);
    public slots:
        void open();
        void close();
    private:
        Window* window;

};
#endif // WINDOW_H
