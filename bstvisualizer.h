#ifndef BSTVISUALIZER_H
#define BSTVISUALIZER_H

#include <QDialog>
#include "mainwindow.h"

class BSTVisualizer : public QDialog {
    Q_OBJECT
public:
    explicit BSTVisualizer(const EmergencyBST& bst, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

private:
    const EmergencyBST& bst;
    void drawNode(QPainter &painter, EmergencyBSTNode *node, int x, int y, int level, int xOffset);
    int calculateTreeWidth(int levels) const;
};

#endif // BSTVISUALIZER_H