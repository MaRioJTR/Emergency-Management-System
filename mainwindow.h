// #ifndef CONTROLCENTER_H
// #define CONTROLCENTER_H
//
// #include <QMainWindow>
// #include <QPushButton>
// #include <QTableWidget>
// #include <QString>
//
// class ControlCenter : public QMainWindow {
//     Q_OBJECT
//
// private:
//     QTableWidget *tableWidget;
//     QString selectedType;
//
// public:
//     ControlCenter(QWidget *parent = nullptr);
//
//     private slots:
//         void addEmergency();
//     void removeEmergency();
// };
//
// #endif // CONTROLCENTER_H

//------- Queue
// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H
//
// #include <QMainWindow>
// #include <QQueue>
// #include <QString>
// #include <QMessageBox>
// #include <QTableWidget>
// #include <QPushButton>
// #include <QVBoxLayout>
// #include <QHBoxLayout>
// #include <QWidget>
// #include <QDialog>
// #include <QComboBox>
// #include <QLineEdit>
// #include <QFormLayout>
// #include <QDialogButtonBox>
// #include <QSet>
//
// QT_BEGIN_NAMESPACE
// namespace Ui { class MainWindow; }
// QT_END_NAMESPACE
//
// class AddEmergencyDialog : public QDialog {
//     Q_OBJECT
// public:
//     explicit AddEmergencyDialog(QWidget *parent = nullptr);
//     QString getEmergencyType() const;
//     QString getAddress() const;
//
// private:
//     QComboBox *emergencyTypeComboBox;
//     QLineEdit *addressLineEdit;
// };
//
// class MainWindow : public QMainWindow {
//     Q_OBJECT
//
// public:
//     explicit MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();
//
//     private slots:
//         void addEmergency();
//     void removeEmergency();
//     void filterEmergencies(const QString &type);
//     void resetButtons();
//     void updateTable(const QString &filterType = "");
//
// private:
//     QQueue<QStringList> emergencies;
//     QString currentFilterType;
//     QTableWidget *emergencyTableWidget;
//     QPushButton *addEmergencyButton;
//     QPushButton *removeEmergencyButton;
// };
//
// #endif // MAINWINDOW_H

// Linked list + priority queue
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// #include <QMainWindow>
// #include <QDialog>
// #include <QTableWidget>
// #include <QComboBox>
// #include <QLineEdit>
// #include <QPushButton>
// #include <QFormLayout>
// #include <QMessageBox>
// #include <QDateTime>
// #include <QList>
//
// struct Emergency {
//     QString type;
//     QString address;
//     QString time;
//     int priority; // 1 (highest) to 4 (lowest)
//     qint64 timestamp; // For FIFO ordering
//
//     bool isHigherPriorityThan(const Emergency& other) const {
//         if (priority != other.priority)
//             return priority < other.priority;
//         return timestamp < other.timestamp;
//     }
// };
//
// class AddEmergencyDialog : public QDialog {
//     Q_OBJECT
// public:
//     explicit AddEmergencyDialog(QWidget *parent = nullptr);
//     QString getEmergencyType() const;
//     QString getAddress() const;
//     int getPriority() const;
//
// private:
//     QComboBox *emergencyTypeComboBox;
//     QLineEdit *addressLineEdit;
//     QComboBox *priorityComboBox;
// };
//
// class MainWindow : public QMainWindow {
//     Q_OBJECT
//
// public:
//     explicit MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();
//
//     private slots:
//         void addEmergency();
//     void removeEmergency();
//     void filterEmergencies(const QString &type);
//     void resetButtons();
//     void updateTable(const QString &filterType = "");
//
// private:
//     QList<Emergency> emergencies;
//     QString currentFilterType;
//
//     QTableWidget *emergencyTableWidget;
//     QPushButton *addEmergencyButton;
//     QPushButton *removeEmergencyButton;
//     QPushButton *controlCenterButton;
//     QPushButton *fireFighterButton;
//     QPushButton *dotButton;
//     QPushButton *enpButton;
//     QPushButton *ambulanceButton;
//
//     void setupUI();
//     void setupConnections();
//     Emergency removeHighestPriorityEmergency();
//     QColor getPriorityColor(int priority) const;
// };
//
// #endif // MAINWINDOW_H

//linked list + priority queue
// #include <QMainWindow>
// #include <QDialog>
// #include <QTableWidget>
// #include <QComboBox>
// #include <QLineEdit>
// #include <QPushButton>
// #include <QFormLayout>
// #include <QMessageBox>
// #include <QDateTime>
//
// struct Emergency {
//     QString type;
//     QString address;
//     QString time;
//     int priority; // 1 (highest) to 4 (lowest)
//     qint64 timestamp; // For FIFO ordering
//
//     bool isHigherPriorityThan(const Emergency& other) const {
//         if (priority != other.priority)
//             return priority < other.priority;
//         return timestamp < other.timestamp;
//     }
// };
//
// struct EmergencyNode {
//     Emergency data;
//     EmergencyNode* next;
//
//     EmergencyNode(const Emergency& emergency) : data(emergency), next(nullptr) {}
// };
//
// class EmergencyLinkedList {
// private:
//     EmergencyNode* head;
//     int count;
//
// public:
//     EmergencyLinkedList();
//     ~EmergencyLinkedList();
//
//     void insert(const Emergency& emergency);
//     Emergency removeHighestPriority();
//     void clear();
//     int size() const;
//     bool isEmpty() const;
//     EmergencyNode* getHead() const;
// };
//
// class AddEmergencyDialog : public QDialog {
//     Q_OBJECT
// public:
//     explicit AddEmergencyDialog(QWidget *parent = nullptr);
//     QString getEmergencyType() const;
//     QString getAddress() const;
//     int getPriority() const;
//
// private:
//     QComboBox *emergencyTypeComboBox;
//     QLineEdit *addressLineEdit;
//     QComboBox *priorityComboBox;
// };
//
// class MainWindow : public QMainWindow {
//     Q_OBJECT
//
// public:
//     explicit MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();
//
// private slots:
//     void addEmergency();
//     void removeEmergency();
//     void filterEmergencies(const QString &type);
//     void resetButtons();
//     void updateTable(const QString &filterType = "");
//
// private:
//     EmergencyLinkedList emergencies;
//     QString currentFilterType;
//
//     QTableWidget *emergencyTableWidget;
//     QPushButton *addEmergencyButton;
//     QPushButton *removeEmergencyButton;
//     QPushButton *controlCenterButton;
//     QPushButton *fireFighterButton;
//     QPushButton *dotButton;
//     QPushButton *enpButton;
//     QPushButton *ambulanceButton;
//
//     void setupUI();
//     void setupConnections();
//     Emergency removeHighestPriorityEmergency();
//     QColor getPriorityColor(int priority) const;
// };
//
// #endif // MAINWINDOW_H

// binary search tree

#include <QMainWindow>
#include <QDialog>
#include <QTableWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QMessageBox>
#include <QDateTime>

struct Emergency {
    QString type;
    QString address;
    QString time;
    int priority; // 1 (highest) to 4 (lowest)
    qint64 timestamp; // For FIFO ordering

    bool isHigherPriorityThan(const Emergency& other) const {
        if (priority != other.priority)
            return priority < other.priority;
        return timestamp < other.timestamp;
    }

    bool operator<(const Emergency& other) const {
        if (priority != other.priority)
            return priority < other.priority; // Lower number = higher priority
        return timestamp < other.timestamp;   // FIFO for equals
    }

    bool operator>(const Emergency& other) const {
        if (priority != other.priority)
            return priority > other.priority;
        return timestamp > other.timestamp;
    }

    bool operator==(const Emergency& other) const {
        return priority == other.priority && timestamp == other.timestamp;
    }
};

class EmergencyBSTNode {
public:
    Emergency data;
    EmergencyBSTNode* left;
    EmergencyBSTNode* right;

    EmergencyBSTNode(const Emergency& emergency)
        : data(emergency), left(nullptr), right(nullptr) {}
};

class EmergencyBST {
private:
    EmergencyBSTNode* root;
    int count;

    void clearHelper(EmergencyBSTNode* node);
    EmergencyBSTNode* insertHelper(EmergencyBSTNode* node, const Emergency& emergency);
    EmergencyBSTNode* removeMinHelper(EmergencyBSTNode* node, Emergency& result);
    void inOrderHelper(EmergencyBSTNode* node, QList<Emergency>& result) const;
    void filterByTypeHelper(EmergencyBSTNode* node, const QString& type, QList<Emergency>& result) const;

public:
    EmergencyBST();
    ~EmergencyBST();

    void insert(const Emergency& emergency);
    Emergency removeHighestPriority();
    void clear();
    int size() const;
    bool isEmpty() const;
    QList<Emergency> getAllEmergencies() const;
    QList<Emergency> getEmergenciesByType(const QString& type) const;
    EmergencyBSTNode* getRoot() const { return root; }
};

class AddEmergencyDialog : public QDialog {
    Q_OBJECT
public:
    explicit AddEmergencyDialog(QWidget *parent = nullptr);
    QString getEmergencyType() const;
    QString getAddress() const;
    int getPriority() const;

private:
    QComboBox *emergencyTypeComboBox;
    QLineEdit *addressLineEdit;
    QComboBox *priorityComboBox;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addEmergency();
    void removeEmergency();
    void filterEmergencies(const QString &type);
    void resetButtons();
    void updateTable(const QString &filterType = "");
    void showBSTVisualization();

private:
    EmergencyBST emergencies;
    QString currentFilterType;

    QTableWidget *emergencyTableWidget;
    QPushButton *addEmergencyButton;
    QPushButton *removeEmergencyButton;
    QPushButton *controlCenterButton;
    QPushButton *fireFighterButton;
    QPushButton *dotButton;
    QPushButton *enpButton;
    QPushButton *ambulanceButton;
    QPushButton *visualizeBSTButton;

    void setupUI();
    void setupConnections();
    Emergency removeHighestPriorityEmergency();
    QColor getPriorityColor(int priority) const;
};

#endif // MAINWINDOW_H