#ifndef RESIZEBUTTON_H
#define RESIZEBUTTON_H

#include <QPushButton>

class ResizeButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ResizeButton(const QString& text, int maxWidth, QWidget* parent = nullptr)
        : QPushButton(text, parent), m_maxWidth(maxWidth) {
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        setMaximumWidth(m_maxWidth);
    }

protected:
    void resizeEvent(QResizeEvent* event) override {
        if (width() > m_maxWidth) {
            setFixedWidth(m_maxWidth); // Обмежуємо ширину
        }
        QPushButton::resizeEvent(event);
    }

private:
    int m_maxWidth;

signals:
    void clicked(); // Определяем сигнал clicked
};

#endif // RESIZEBUTTON_H
