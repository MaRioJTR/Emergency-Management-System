#include "bstvisualizer.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <cmath>

BSTVisualizer::BSTVisualizer(const EmergencyBST& bst, QWidget *parent)
    : QDialog(parent), bst(bst)
{
    setWindowTitle("Emergency BST Visualization");
    setFixedSize(800, 600);
}

void BSTVisualizer::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    // Draw the BST
    QList<Emergency> emergencies = bst.getAllEmergencies();
    if (!emergencies.isEmpty()) {
        drawNode(painter, const_cast<EmergencyBSTNode*>(bst.getRoot()), width() / 2, 50, 0, width() / 4);
    } else {
        painter.drawText(rect(), Qt::AlignCenter, "BST is empty");
    }
}

void BSTVisualizer::drawNode(QPainter &painter, EmergencyBSTNode *node, int x, int y, int level, int xOffset) {
    if (!node) return;

    // Draw the node
    painter.setPen(Qt::black);
    QColor nodeColor;
    switch(node->data.priority) {
        case 1: nodeColor = Qt::red; break;
        case 2: nodeColor = QColor(255, 165, 0); break; // orange
        case 3: nodeColor = Qt::yellow; break;
        case 4: nodeColor = Qt::green; break;
        default: nodeColor = Qt::gray;
    }

    painter.setBrush(nodeColor);
    painter.drawEllipse(QPoint(x, y), 30, 30);

    // Draw node text
    QString priorityText;
    switch(node->data.priority) {
        case 1: priorityText = "H"; break;
        case 2: priorityText = "h"; break;
        case 3: priorityText = "M"; break;
        case 4: priorityText = "L"; break;
    }

    painter.setPen(Qt::black);
    painter.drawText(QRect(x-30, y-30, 60, 60), Qt::AlignCenter, priorityText);

    // Calculate positions for children
    int newY = y + 100;
    int newXOffset = xOffset / 2;

    // Draw left child
    if (node->left) {
        int leftX = x - xOffset;
        painter.drawLine(x, y+30, leftX, newY-30);
        drawNode(painter, node->left, leftX, newY, level+1, newXOffset);
    }

    // Draw right child
    if (node->right) {
        int rightX = x + xOffset;
        painter.drawLine(x, y+30, rightX, newY-30);
        drawNode(painter, node->right, rightX, newY, level+1, newXOffset);
    }
}

int BSTVisualizer::calculateTreeWidth(int levels) const {
    return std::pow(2, levels) * 60;
}