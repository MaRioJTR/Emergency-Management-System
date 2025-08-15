
// Queue

// #include "mainwindow.h"
// #include <QDateTime>
// #include <QMessageBox>
// #include <QVBoxLayout>
// #include <QHBoxLayout>
// #include <QFormLayout>
// #include <QComboBox>
// #include <QLineEdit>
// #include <QDialogButtonBox>
// #include <QPushButton>
// #include <QTableWidget>
// #include <QTableWidgetItem>
// #include <QHeaderView>
// #include <QIcon>
//
// AddEmergencyDialog::AddEmergencyDialog(QWidget *parent)
//     : QDialog(parent)
// {
//     setWindowTitle("Add Emergency");
//
//     QFormLayout *formLayout = new QFormLayout(this);
//
//     emergencyTypeComboBox = new QComboBox(this);
//     emergencyTypeComboBox->addItem("Fire Fighter");
//     emergencyTypeComboBox->addItem("DOT");
//     emergencyTypeComboBox->addItem("ENP");
//     emergencyTypeComboBox->addItem("Ambulance");
//
//     addressLineEdit = new QLineEdit(this);
//
//     formLayout->addRow("Emergency Type:", emergencyTypeComboBox);
//     formLayout->addRow("Address:", addressLineEdit);
//
//     QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
//     connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
//     connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
//
//     formLayout->addRow(buttonBox);
//     setLayout(formLayout);
// }
//
// QString AddEmergencyDialog::getEmergencyType() const {
//     return emergencyTypeComboBox->currentText();
// }
//
// QString AddEmergencyDialog::getAddress() const {
//     return addressLineEdit->text();
// }
//
// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
// {
//     // Set fixed window size
//     this->setFixedSize(800, 600);
//
//     // Create main layout
//     QHBoxLayout *mainLayout = new QHBoxLayout();
//
//     // Create left vertical layout for buttons
//     QVBoxLayout *leftLayout = new QVBoxLayout();
//
//     // Create buttons and set their styles
//     QPushButton *controlCenterButton = new QPushButton("Control Center");
//     controlCenterButton->setStyleSheet("background-color: lightgray; width: 100px; height: 60px; color: black; border-radius: 10px; font-size: 15px; font-weight: bold;");
//     controlCenterButton->setIcon(QIcon(":/icons/all.png"));
//     controlCenterButton->setIconSize(QSize(50, 50));
//     controlCenterButton->resize(150, 100);
//
//     QPushButton *fireFighterButton = new QPushButton("Fire Fighter");
//     fireFighterButton->setStyleSheet("background-color: #C62828; width: 100px; height: 60px; color: black; border-radius: 10px; font-size: 15px; font-weight: bold;");
//     fireFighterButton->setIcon(QIcon(":/icons/fire-truck.png"));
//     fireFighterButton->setIconSize(QSize(50, 50));
//     fireFighterButton->resize(150, 100);
//
//     QPushButton *dotButton = new QPushButton("DOT");
//     dotButton->setStyleSheet("background-color: #E5C100; width: 100px; height: 60px; color: white; border-radius: 10px; font-size: 15px; font-weight: bold;");
//     dotButton->setIcon(QIcon(":/icons/traffic-cone.png"));
//     dotButton->setIconSize(QSize(50, 50));
//     dotButton->resize(150, 100);
//
//     QPushButton *enpButton = new QPushButton("ENP");
//     enpButton->setStyleSheet("background-color: #0056b3; width: 100px; height: 60px; color: white; border-radius: 10px; font-size: 15px; font-weight: bold;");
//     enpButton->setIcon(QIcon(":/icons/police-car.png"));
//     enpButton->setIconSize(QSize(50, 50));
//     enpButton->resize(150, 100);
//
//     QPushButton *ambulanceButton = new QPushButton("Ambulance");
//     ambulanceButton->setStyleSheet("background-color: #F4D03F; width: 100px; height: 60px; color: black; border-radius: 10px; font-size: 15px; font-weight: bold;");
//     ambulanceButton->setIcon(QIcon(":/icons/ambulance.png"));
//     ambulanceButton->setIconSize(QSize(50, 50));
//     ambulanceButton->resize(150, 100);
//
//     // Connect filter buttons to slots
//     connect(controlCenterButton, &QPushButton::clicked, this, [this]() { resetButtons(); updateTable(); });
//     connect(fireFighterButton, &QPushButton::clicked, this, [this]() { filterEmergencies("Fire Fighter"); });
//     connect(dotButton, &QPushButton::clicked, this, [this]() { filterEmergencies("DOT"); });
//     connect(enpButton, &QPushButton::clicked, this, [this]() { filterEmergencies("ENP"); });
//     connect(ambulanceButton, &QPushButton::clicked, this, [this]() { filterEmergencies("Ambulance"); });
//
//     // Add buttons to the left layout
//     leftLayout->addWidget(controlCenterButton);
//     leftLayout->addWidget(fireFighterButton);
//     leftLayout->addWidget(dotButton);
//     leftLayout->addWidget(enpButton);
//     leftLayout->addWidget(ambulanceButton);
//     leftLayout->addStretch();
//
//     // Create right layout for the table and buttons
//     QVBoxLayout *rightLayout = new QVBoxLayout();
//
//     // Create table widget
//     emergencyTableWidget = new QTableWidget(this);
//     emergencyTableWidget->setColumnCount(3);
//     emergencyTableWidget->setHorizontalHeaderLabels({"Emergency Type", "Address", "Time"});
//     emergencyTableWidget->setColumnWidth(0, 200);
//     emergencyTableWidget->setColumnWidth(1, 200);
//     emergencyTableWidget->setColumnWidth(2, 139);
//     emergencyTableWidget->setAlternatingRowColors(true);
//     emergencyTableWidget->setStyleSheet(
//         "QHeaderView::section { background-color: black; color: white; } "
//         "QTableWidget { alternate-background-color: #F8F8F8; background-color: white; gridline-color: black; }"
//         "QTableWidget::item { color: black; }"
//         "QTableWidget::item:selected { background-color: lightgray; }"
//         "QTableWidget::item:selected:!active { color: black; }"
//         "QTableWidget::item:selected:active { background-color: lightgray; color: black; }"
//     );
//
//     // Create buttons for adding and removing emergencies
//     addEmergencyButton = new QPushButton("Add Emergency");
//     addEmergencyButton->setStyleSheet("background-color: #218838; color: white; height: 50px; border-radius: 10px;");
//
//     removeEmergencyButton = new QPushButton("Remove Emergency");
//     removeEmergencyButton->setStyleSheet("background-color: #C62828; color: white; height: 50px; border-radius: 10px;");
//
//     // Connect buttons to slots
//     connect(addEmergencyButton, &QPushButton::clicked, this, &MainWindow::addEmergency);
//     connect(removeEmergencyButton, &QPushButton::clicked, this, &MainWindow::removeEmergency);
//
//     // Add table and buttons to the right layout
//     rightLayout->addWidget(emergencyTableWidget);
//     rightLayout->addWidget(addEmergencyButton);
//     rightLayout->addWidget(removeEmergencyButton);
//
//     // Add left and right layouts to the main layout
//     mainLayout->addLayout(leftLayout, 30);
//     mainLayout->addLayout(rightLayout, 70);
//
//     // Set the main layout to the central widget
//     QWidget *centralWidget = new QWidget(this);
//     centralWidget->setLayout(mainLayout);
//     this->setCentralWidget(centralWidget);
// }
//
// MainWindow::~MainWindow()
// {
//     // Destructor implementation
// }
//
// void MainWindow::addEmergency()
// {
//     AddEmergencyDialog dialog(this);
//     if (dialog.exec() == QDialog::Accepted) {
//         QString type = dialog.getEmergencyType();
//         QString address = dialog.getAddress();
//         QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
//
//         if (address.isEmpty()) {
//             QMessageBox::warning(this, "Error", "Address cannot be empty!");
//             return;
//         }
//
//         // Add to queue (FIFO)
//         emergencies.enqueue({type, address, time});
//         updateTable();
//         QMessageBox::information(this, "Success", "Emergency added to queue!");
//     }
// }
//
// void MainWindow::removeEmergency()
// {
//     if (emergencies.isEmpty()) {
//         QMessageBox::warning(this, "Error", "Queue is empty - nothing to remove!");
//         return;
//     }
//
//     if (currentFilterType.isEmpty()) {
//         // If no filter is active, remove the oldest emergency from the queue
//         emergencies.dequeue();
//     } else {
//         // Find and remove the oldest emergency of the filtered type
//         bool found = false;
//         QQueue<QStringList> tempQueue;
//
//         while (!emergencies.isEmpty()) {
//             QStringList emergency = emergencies.dequeue();
//             if (emergency[0] == currentFilterType && !found) {
//                 // Remove the oldest emergency of the filtered type
//                 found = true;
//             } else {
//                 // Keep other emergencies in the queue
//                 tempQueue.enqueue(emergency);
//             }
//         }
//         emergencies = tempQueue;
//
//         if (!found) {
//             QMessageBox::warning(this, "Error", QString("No %1 emergencies to remove!").arg(currentFilterType));
//             return;
//         }
//     }
//
//     updateTable(currentFilterType);
//     QMessageBox::information(this, "Success", "Emergency removed from queue!");
// }
//
// void MainWindow::filterEmergencies(const QString &type)
// {
//     addEmergencyButton->setVisible(false);
//     removeEmergencyButton->setText("Accept");
//     currentFilterType = type;
//     updateTable(type);
// }
//
// void MainWindow::resetButtons()
// {
//     addEmergencyButton->setVisible(true);
//     removeEmergencyButton->setText("Remove Emergency");
//     currentFilterType = "";
// }
//
// void MainWindow::updateTable(const QString &filterType)
// {
//     emergencyTableWidget->setRowCount(0);
//
//     // Add rows based on the filter (FIFO order)
//     for (const QStringList &emergency : emergencies) {
//         if (filterType.isEmpty() || emergency[0] == filterType) {
//             int row = emergencyTableWidget->rowCount();
//             emergencyTableWidget->insertRow(row);
//             emergencyTableWidget->setItem(row, 0, new QTableWidgetItem(emergency[0]));
//             emergencyTableWidget->setItem(row, 1, new QTableWidgetItem(emergency[1]));
//             emergencyTableWidget->setItem(row, 2, new QTableWidgetItem(emergency[2]));
//         }
//     }
// }

// linked list + priority queue

// AddEmergencyDialog::AddEmergencyDialog(QWidget *parent)
//     : QDialog(parent)
// {
//     setWindowTitle("Add Emergency");
//
//     QFormLayout *formLayout = new QFormLayout(this);
//
//     emergencyTypeComboBox = new QComboBox(this);
//     emergencyTypeComboBox->addItems({"Fire Fighter", "DOT", "ENP", "Ambulance"});
//
//     addressLineEdit = new QLineEdit(this);
//
//     priorityComboBox = new QComboBox(this);
//     priorityComboBox->addItems({"1 - Highest (Life-threatening)",
//                                "2 - High (Critical)",
//                                "3 - Medium (Urgent)",
//                                "4 - Low (Routine)"});
//
//     formLayout->addRow("Emergency Type:", emergencyTypeComboBox);
//     formLayout->addRow("Address:", addressLineEdit);
//     formLayout->addRow("Priority:", priorityComboBox);
//
//     QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
//     connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
//     connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
//
//     formLayout->addRow(buttonBox);
//     setLayout(formLayout);
// }
//
// QString AddEmergencyDialog::getEmergencyType() const {
//     return emergencyTypeComboBox->currentText();
// }
//
// QString AddEmergencyDialog::getAddress() const {
//     return addressLineEdit->text();
// }
//
// int AddEmergencyDialog::getPriority() const {
//     return priorityComboBox->currentIndex() + 1;
// }
//
// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
// {
//     setFixedSize(1000, 700);
//     setupUI();
//     setupConnections();
// }
//
// MainWindow::~MainWindow() {}
//
// void MainWindow::setupUI() {
//     QWidget *centralWidget = new QWidget(this);
//     QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
//
//     // Left sidebar
//     QVBoxLayout *leftLayout = new QVBoxLayout();
//
//     controlCenterButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\all.png"),"Control Center");
//     fireFighterButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\fire-truck.png"),"Fire Fighter");
//     dotButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\traffic-cone.png"),"DOT");
//     enpButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\police-car.png"),"ENP");
//     ambulanceButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\ambulance.png"),"Ambulance");
//
//
//             // Style buttons
//     ;QString buttonStyle = "min-width: 120px; height: 60px; border-radius: 8px; font-size: 14px; font-weight: bold;";
//     controlCenterButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
//         "stop:0 #ff0000, stop:0.25 #ff8000, stop:0.5 #0000ff, stop:1 #ffffff ); color: white;");
//     controlCenterButton->setIconSize(QSize(40, 40));
//     fireFighterButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
//         "stop:0.5 #ff0000, stop:1 #ffffff); color: white;");
//     fireFighterButton->setIconSize(QSize(40, 40));
//     dotButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
//         "stop:0.5 #ff8000, stop:1 #ffffff); color: whiteص;");
//     dotButton->setIconSize(QSize(40, 40));
//     enpButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
//         "stop:0.5 #0056b3, stop:1 #ffffff); color: white;");
//     enpButton->setIconSize(QSize(40, 40));
//     ambulanceButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
//         "stop:0.5 #ffffff, stop:1 #ff0000);; color: black;");
//     ambulanceButton->setIconSize(QSize(40, 40));
//
//     leftLayout->addWidget(controlCenterButton);
//     leftLayout->addWidget(fireFighterButton);
//     leftLayout->addWidget(dotButton);
//     leftLayout->addWidget(enpButton);
//     leftLayout->addWidget(ambulanceButton);
//     leftLayout->addStretch();
//
//     // Right side
//     QVBoxLayout *rightLayout = new QVBoxLayout();
//
//     emergencyTableWidget = new QTableWidget(this);
//     emergencyTableWidget->setColumnCount(4);
//     emergencyTableWidget->setHorizontalHeaderLabels({"Type", "Address", "Time", "Priority"});
//     emergencyTableWidget->setColumnWidth(0, 150);
//     emergencyTableWidget->setColumnWidth(1, 250);
//     emergencyTableWidget->setColumnWidth(2, 180);
//     emergencyTableWidget->setColumnWidth(3, 145);
//     emergencyTableWidget->setAlternatingRowColors(true);
//
//     addEmergencyButton = new QPushButton("Add Emergency");
//     removeEmergencyButton = new QPushButton("Remove Highest Priority");
//
//     // Style action buttons
//     QString actionButtonStyle = "height: 40px; border-radius: 6px; font-size: 14px;";
//     addEmergencyButton->setStyleSheet(actionButtonStyle + "background-color: #28a745; color: white;");
//     removeEmergencyButton->setStyleSheet(actionButtonStyle + "background-color: #dc3545; color: white;");
//
//     rightLayout->addWidget(emergencyTableWidget);
//     rightLayout->addWidget(addEmergencyButton);
//     rightLayout->addWidget(removeEmergencyButton);
//
//     mainLayout->addLayout(leftLayout, 1);
//     mainLayout->addLayout(rightLayout, 3);
//     setCentralWidget(centralWidget);
// }
//
// void MainWindow::setupConnections() {
//     connect(controlCenterButton, &QPushButton::clicked, this, [this]() { resetButtons(); updateTable(); });
//     connect(fireFighterButton, &QPushButton::clicked, this, [this]() { filterEmergencies("Fire Fighter"); });
//     connect(dotButton, &QPushButton::clicked, this, [this]() { filterEmergencies("DOT"); });
//     connect(enpButton, &QPushButton::clicked, this, [this]() { filterEmergencies("ENP"); });
//     connect(ambulanceButton, &QPushButton::clicked, this, [this]() { filterEmergencies("Ambulance"); });
//
//     connect(addEmergencyButton, &QPushButton::clicked, this, &MainWindow::addEmergency);
//     connect(removeEmergencyButton, &QPushButton::clicked, this, &MainWindow::removeEmergency);
// }
//
// Emergency MainWindow::removeHighestPriorityEmergency() {
//     if (emergencies.isEmpty()) {
//         throw "No emergencies to remove";
//     }
//
//     // If filtered, only consider emergencies of the filtered type
//     if (!currentFilterType.isEmpty()) {
//         QList<Emergency> filteredEmergencies;
//         for (const Emergency& e : emergencies) {
//             if (e.type == currentFilterType) {
//                 filteredEmergencies.append(e);
//             }
//         }
//
//         if (filteredEmergencies.isEmpty()) {
//             throw QString("No %1 emergencies to remove").arg(currentFilterType).toStdString().c_str();
//         }
//
//         // Find highest priority in filtered emergencies
//         int highestPriorityIndex = 0;
//         for (int i = 1; i < filteredEmergencies.size(); ++i) {
//             if (filteredEmergencies[i].isHigherPriorityThan(filteredEmergencies[highestPriorityIndex])) {
//                 highestPriorityIndex = i;
//             }
//         }
//
//         // Remove from main list
//         Emergency toRemove = filteredEmergencies[highestPriorityIndex];
//         for (int i = 0; i < emergencies.size(); ++i) {
//             if (emergencies[i].type == toRemove.type &&
//                 emergencies[i].address == toRemove.address &&
//                 emergencies[i].time == toRemove.time) {
//                 return emergencies.takeAt(i);
//             }
//         }
//     }
//
//     // Normal case - no filter
//     int highestPriorityIndex = 0;
//     for (int i = 1; i < emergencies.size(); ++i) {
//         if (emergencies[i].isHigherPriorityThan(emergencies[highestPriorityIndex])) {
//             highestPriorityIndex = i;
//         }
//     }
//
//     return emergencies.takeAt(highestPriorityIndex);
// }
// // where is being editable
// void MainWindow::addEmergency() {
//     AddEmergencyDialog dialog(this);
//     if (dialog.exec() == QDialog::Accepted) {
//         Emergency e;
//         e.type = dialog.getEmergencyType();
//         e.address = dialog.getAddress();
//         e.time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
//         e.priority = dialog.getPriority();
//         e.timestamp = QDateTime::currentMSecsSinceEpoch();
//
//         if (e.address.isEmpty()) {
//             QMessageBox::warning(this, "Error", "Address cannot be empty!");
//             return;
//         }
//
//         emergencies.append(e);
//         updateTable(currentFilterType);
//
//         QString priorityText;
//         switch(e.priority) {
//             case 1: priorityText = "Highest Priority (Life-threatening)"; break;
//             case 2: priorityText = "High Priority (Critical)"; break;
//             case 3: priorityText = "Medium Priority (Urgent)"; break;
//             default: priorityText = "Low Priority (Routine)";
//         }
//
//         QMessageBox::information(this, "Success",
//             QString("Emergency added!\nType: %1\nPriority: %2").arg(e.type).arg(priorityText));
//     }
// }
//
// void MainWindow::removeEmergency() {
//     try {
//         Emergency e = removeHighestPriorityEmergency();
//         updateTable(currentFilterType);
//
//         QString priorityText;
//         switch(e.priority) {
//             case 1: priorityText = "Highest Priority (Life-threatening)"; break;
//             case 2: priorityText = "High Priority (Critical)"; break;
//             case 3: priorityText = "Medium Priority (Urgent)"; break;
//             default: priorityText = "Low Priority (Routine)";
//         }
//
//         QString message = QString("Dispatched %1 Emergency:\n"
//                                 "Priority: %2\n"
//                                 "Address: %3\n"
//                                 "Time Received: %4")
//                          .arg(e.type)
//                          .arg(priorityText)
//                          .arg(e.address)
//                          .arg(e.time);
//
//         QMessageBox::information(this, "Emergency Dispatched", message);
//     } catch (const char* msg) {
//         QMessageBox::warning(this, "Error", msg);
//     }
// }
//
// void MainWindow::filterEmergencies(const QString &type) {
//     addEmergencyButton->setVisible(false);
//     removeEmergencyButton->setText(QString("Accept %1").arg(type));
//     currentFilterType = type;
//     updateTable(type);
// }
//
// void MainWindow::resetButtons() {
//     addEmergencyButton->setVisible(true);
//     removeEmergencyButton->setText("Remove Highest Priority");
//     currentFilterType = "";
//     updateTable();
// }
//
// QColor MainWindow::getPriorityColor(int priority) const {
//     switch(priority) {
//         // I want to change colors :)
//         case 1: return QColor(255, 0, 0);
//         case 2: return QColor(255, 100, 0);
//         case 3: return QColor(255, 255, 0);
//         default: return QColor(0, 154, 0);
//     }
// }
//
// void MainWindow::updateTable(const QString &filterType) {
//     emergencyTableWidget->setRowCount(0);
//
//     for (const Emergency& e : emergencies) {
//         if (filterType.isEmpty() || e.type == filterType) {
//             int row = emergencyTableWidget->rowCount();
//             emergencyTableWidget->insertRow(row);
//
//             emergencyTableWidget->setItem(row, 0, new QTableWidgetItem(e.type));
//             emergencyTableWidget->setItem(row, 1, new QTableWidgetItem(e.address));
//             emergencyTableWidget->setItem(row, 2, new QTableWidgetItem(e.time));
//
//             QTableWidgetItem *priorityItem = new QTableWidgetItem();
//             switch(e.priority) {
//                 case 1:
//                     priorityItem->setText("Highest");
//                     break;
//                 case 2:
//                     priorityItem->setText("High");
//                     break;
//                 case 3:
//                     priorityItem->setText("Medium");
//                     priorityItem->setForeground(QColor(0, 0, 0));
//                     break;
//                 default:
//                     priorityItem->setText("Low");
//             }
//             priorityItem->setBackground(getPriorityColor(e.priority));
//             emergencyTableWidget->setItem(row, 3, priorityItem);
//         }
//     }
// }

// linked list
// #include "mainwindow.h"
// #include <QVBoxLayout>
// #include <QHBoxLayout>
// #include <QHeaderView>
// #include <QIcon>
//
// // EmergencyLinkedList implementation
// EmergencyLinkedList::EmergencyLinkedList() : head(nullptr), count(0) {}
//
// EmergencyLinkedList::~EmergencyLinkedList() { clear(); }
//
// void EmergencyLinkedList::insert(const Emergency& emergency) {
//     EmergencyNode* newNode = new EmergencyNode(emergency);
//
//     if (!head || emergency.isHigherPriorityThan(head->data)) {
//         newNode->next = head;
//         head = newNode;
//     } else {
//         EmergencyNode* current = head;
//         while (current->next && !emergency.isHigherPriorityThan(current->next->data)) {
//             current = current->next;
//         }
//         newNode->next = current->next;
//         current->next = newNode;
//     }
//     count++;
// }
//
// Emergency EmergencyLinkedList::removeHighestPriority() {
//     if (!head) {
//         throw "List is empty";
//     }
//
//     EmergencyNode* temp = head;
//     Emergency result = temp->data;
//     head = head->next;
//     delete temp;
//     count--;
//     return result;
// }
//
// void EmergencyLinkedList::clear() {
//     while (head) {
//         EmergencyNode* temp = head;
//         head = head->next;
//         delete temp;
//     }
//     count = 0;
// }
//
// int EmergencyLinkedList::size() const { return count; }
//
// bool EmergencyLinkedList::isEmpty() const { return count == 0; }
//
// EmergencyNode* EmergencyLinkedList::getHead() const { return head; }
//
// // AddEmergencyDialog implementation
// AddEmergencyDialog::AddEmergencyDialog(QWidget *parent)
//     : QDialog(parent)
// {
//     setWindowTitle("Add Emergency");
//
//     QFormLayout *formLayout = new QFormLayout(this);
//
//     emergencyTypeComboBox = new QComboBox(this);
//     emergencyTypeComboBox->addItems({"Fire Fighter", "DOT", "ENP", "Ambulance"});
//
//     addressLineEdit = new QLineEdit(this);
//
//     priorityComboBox = new QComboBox(this);
//     priorityComboBox->addItems({"1 - Highest (Life-threatening)",
//                                "2 - High (Critical)",
//                                "3 - Medium (Urgent)",
//                                "4 - Low (Routine)"});
//
//     formLayout->addRow("Emergency Type:", emergencyTypeComboBox);
//     formLayout->addRow("Address:", addressLineEdit);
//     formLayout->addRow("Priority:", priorityComboBox);
//
//     QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
//     connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
//     connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
//
//     formLayout->addRow(buttonBox);
//     setLayout(formLayout);
// }
//
// QString AddEmergencyDialog::getEmergencyType() const {
//     return emergencyTypeComboBox->currentText();
// }
//
// QString AddEmergencyDialog::getAddress() const {
//     return addressLineEdit->text();
// }
//
// int AddEmergencyDialog::getPriority() const {
//     return priorityComboBox->currentIndex() + 1;
// }
//
// // MainWindow implementation
// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
// {
//     setFixedSize(1000, 700);
//     setupUI();
//     setupConnections();
// }
//
// MainWindow::~MainWindow() {}
//
// void MainWindow::setupUI() {
//     QWidget *centralWidget = new QWidget(this);
//     QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
//
//     // Left sidebar
//     QVBoxLayout *leftLayout = new QVBoxLayout();
//
//     controlCenterButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\all.png"), "Control Center");
//     fireFighterButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\fire-truck.png"), "Fire Fighter");
//     dotButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\traffic-cone.png"), "DOT");
//     enpButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\police-car.png"), "ENP");
//     ambulanceButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\ambulance.png"), "Ambulance");
//
//     QString buttonStyle = "min-width: 120px; height: 60px; border-radius: 8px; font-size: 14px; font-weight: bold;";
//     controlCenterButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
//         "stop:0 #ff0000, stop:0.25 #ff8000, stop:0.5 #0000ff, stop:1 #ffffff ); color: white;");
//     controlCenterButton->setIconSize(QSize(40, 40));
//     fireFighterButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
//         "stop:0.5 #ff0000, stop:1 #ffffff); color: white;");
//     fireFighterButton->setIconSize(QSize(40, 40));
//     dotButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
//         "stop:0.5 #ff8000, stop:1 #ffffff); color: white;");
//     dotButton->setIconSize(QSize(40, 40));
//     enpButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
//         "stop:0.5 #0056b3, stop:1 #ffffff); color: white;");
//     enpButton->setIconSize(QSize(40, 40));
//     ambulanceButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
//         "stop:0.5 #ffffff, stop:1 #ff0000);; color: black;");
//     ambulanceButton->setIconSize(QSize(40, 40));
//
//     leftLayout->addWidget(controlCenterButton);
//     leftLayout->addWidget(fireFighterButton);
//     leftLayout->addWidget(dotButton);
//     leftLayout->addWidget(enpButton);
//     leftLayout->addWidget(ambulanceButton);
//     leftLayout->addStretch();
//
//     // Right side
//     QVBoxLayout *rightLayout = new QVBoxLayout();
//
//     emergencyTableWidget = new QTableWidget(this);
//     emergencyTableWidget->setColumnCount(4);
//     emergencyTableWidget->setHorizontalHeaderLabels({"Type", "Address", "Time", "Priority"});
//     emergencyTableWidget->setColumnWidth(0, 150);
//     emergencyTableWidget->setColumnWidth(1, 250);
//     emergencyTableWidget->setColumnWidth(2, 180);
//     emergencyTableWidget->setColumnWidth(3, 145);
//     emergencyTableWidget->setAlternatingRowColors(true);
//
//     addEmergencyButton = new QPushButton("Add Emergency");
//     removeEmergencyButton = new QPushButton("Remove Highest Priority");
//
//     QString actionButtonStyle = "height: 40px; border-radius: 6px; font-size: 14px;";
//     addEmergencyButton->setStyleSheet(actionButtonStyle + "background-color: #28a745; color: white;");
//     removeEmergencyButton->setStyleSheet(actionButtonStyle + "background-color: #dc3545; color: white;");
//
//     rightLayout->addWidget(emergencyTableWidget);
//     rightLayout->addWidget(addEmergencyButton);
//     rightLayout->addWidget(removeEmergencyButton);
//
//     mainLayout->addLayout(leftLayout, 1);
//     mainLayout->addLayout(rightLayout, 3);
//     setCentralWidget(centralWidget);
// }
//
// void MainWindow::setupConnections() {
//     connect(controlCenterButton, &QPushButton::clicked, this, &MainWindow::resetButtons);
//     connect(fireFighterButton, &QPushButton::clicked, this, [this]() { filterEmergencies("Fire Fighter"); });
//     connect(dotButton, &QPushButton::clicked, this, [this]() { filterEmergencies("DOT"); });
//     connect(enpButton, &QPushButton::clicked, this, [this]() { filterEmergencies("ENP"); });
//     connect(ambulanceButton, &QPushButton::clicked, this, [this]() { filterEmergencies("Ambulance"); });
//
//     connect(addEmergencyButton, &QPushButton::clicked, this, &MainWindow::addEmergency);
//     connect(removeEmergencyButton, &QPushButton::clicked, this, &MainWindow::removeEmergency);
// }
//
// Emergency MainWindow::removeHighestPriorityEmergency() {
//     if (emergencies.isEmpty()) {
//         throw "No emergencies to remove";
//     }
//
//     if (!currentFilterType.isEmpty()) {
//         EmergencyNode* current = emergencies.getHead();
//         EmergencyNode* prev = nullptr;
//         EmergencyNode* highestPriorityNode = nullptr;
//         EmergencyNode* prevHighest = nullptr;
//
//         while (current) {
//             if (current->data.type == currentFilterType) {
//                 if (!highestPriorityNode || current->data.isHigherPriorityThan(highestPriorityNode->data)) {
//                     highestPriorityNode = current;
//                     prevHighest = prev;
//                 }
//             }
//             prev = current;
//             current = current->next;
//         }
//
//         if (!highestPriorityNode) {
//             throw QString("No %1 emergencies to remove").arg(currentFilterType).toStdString().c_str();
//         }
//
//         Emergency result = highestPriorityNode->data;
//         if (prevHighest) {
//             prevHighest->next = highestPriorityNode->next;
//         } else {
//             return emergencies.removeHighestPriority();
//         }
//
//         delete highestPriorityNode;
//         return result;
//     }
//
//     return emergencies.removeHighestPriority();
// }
//
// void MainWindow::addEmergency() {
//     AddEmergencyDialog dialog(this);
//     if (dialog.exec() == QDialog::Accepted) {
//         Emergency e;
//         e.type = dialog.getEmergencyType();
//         e.address = dialog.getAddress();
//         e.time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
//         e.priority = dialog.getPriority();
//         e.timestamp = QDateTime::currentMSecsSinceEpoch();
//
//         if (e.address.isEmpty()) {
//             QMessageBox::warning(this, "Error", "Address cannot be empty!");
//             return;
//         }
//
//         emergencies.insert(e);
//         updateTable(currentFilterType);
//
//         QString priorityText;
//         switch(e.priority) {
//             case 1: priorityText = "Highest Priority (Life-threatening)"; break;
//             case 2: priorityText = "High Priority (Critical)"; break;
//             case 3: priorityText = "Medium Priority (Urgent)"; break;
//             default: priorityText = "Low Priority (Routine)";
//         }
//
//         QMessageBox::information(this, "Success",
//             QString("Emergency added!\nType: %1\nPriority: %2").arg(e.type).arg(priorityText));
//     }
// }
//
// void MainWindow::removeEmergency() {
//     try {
//         Emergency e = removeHighestPriorityEmergency();
//         updateTable(currentFilterType);
//
//         QString priorityText;
//         switch(e.priority) {
//             case 1: priorityText = "Highest Priority (Life-threatening)"; break;
//             case 2: priorityText = "High Priority (Critical)"; break;
//             case 3: priorityText = "Medium Priority (Urgent)"; break;
//             default: priorityText = "Low Priority (Routine)";
//         }
//
//         QString message = QString("Dispatched %1 Emergency:\n"
//                                 "Priority: %2\n"
//                                 "Address: %3\n"
//                                 "Time Received: %4")
//                          .arg(e.type)
//                          .arg(priorityText)
//                          .arg(e.address)
//                          .arg(e.time);
//
//         QMessageBox::information(this, "Emergency Dispatched", message);
//     } catch (const char* msg) {
//         QMessageBox::warning(this, "Error", msg);
//     }
// }
//
// void MainWindow::filterEmergencies(const QString &type) {
//     addEmergencyButton->setVisible(false);
//     removeEmergencyButton->setText(QString("Accept %1").arg(type));
//     currentFilterType = type;
//     updateTable(type);
// }
//
// void MainWindow::resetButtons() {
//     addEmergencyButton->setVisible(true);
//     removeEmergencyButton->setText("Remove Highest Priority");
//     currentFilterType = "";
//     updateTable();
// }
//
// QColor MainWindow::getPriorityColor(int priority) const {
//     switch(priority) {
//         case 1: return QColor(255, 0, 0);
//         case 2: return QColor(255, 100, 0);
//         case 3: return QColor(255, 255, 0);
//         default: return QColor(0, 154, 0);
//     }
// }
//
// void MainWindow::updateTable(const QString &filterType) {
//     emergencyTableWidget->setRowCount(0);
//
//     EmergencyNode* current = emergencies.getHead();
//     while (current) {
//         const Emergency& e = current->data;
//         if (filterType.isEmpty() || e.type == filterType) {
//             int row = emergencyTableWidget->rowCount();
//             emergencyTableWidget->insertRow(row);
//
//             emergencyTableWidget->setItem(row, 0, new QTableWidgetItem(e.type));
//             emergencyTableWidget->setItem(row, 1, new QTableWidgetItem(e.address));
//             emergencyTableWidget->setItem(row, 2, new QTableWidgetItem(e.time));
//
//             QTableWidgetItem *priorityItem = new QTableWidgetItem();
//             switch(e.priority) {
//                 case 1: priorityItem->setText("Highest"); break;
//                 case 2: priorityItem->setText("High"); break;
//                 case 3: priorityItem->setText("Medium"); break;
//                 default: priorityItem->setText("Low");
//             }
//             priorityItem->setBackground(getPriorityColor(e.priority));
//             emergencyTableWidget->setItem(row, 3, priorityItem);
//         }
//         current = current->next;
//     }
// }

// binary search tree

#include "mainwindow.h"
#include "bstvisualizer.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QIcon>

// EmergencyBST implementation
EmergencyBST::EmergencyBST() : root(nullptr), count(0) {}

EmergencyBST::~EmergencyBST() { clear(); }

void EmergencyBST::clearHelper(EmergencyBSTNode* node) {
    if (node) {
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }
}

void EmergencyBST::clear() {
    clearHelper(root);
    root = nullptr;
    count = 0;
}

EmergencyBSTNode* EmergencyBST::insertHelper(EmergencyBSTNode* node, const Emergency& emergency) {
    if (!node) {
        count++;
        return new EmergencyBSTNode(emergency);
    }

    if (emergency < node->data) {
        node->left = insertHelper(node->left, emergency);
    } else {
        node->right = insertHelper(node->right, emergency);
    }

    return node;
}

void EmergencyBST::insert(const Emergency& emergency) {
    root = insertHelper(root, emergency);
}

EmergencyBSTNode* EmergencyBST::removeMinHelper(EmergencyBSTNode* node, Emergency& result) {
    if (!node->left) {
        result = node->data;
        EmergencyBSTNode* rightChild = node->right;
        delete node;
        count--;
        return rightChild;
    }
    node->left = removeMinHelper(node->left, result);
    return node;
}

Emergency EmergencyBST::removeHighestPriority() {
    if (!root) {
        throw "BST is empty";
    }

    Emergency result;
    root = removeMinHelper(root, result);
    return result;
}

void EmergencyBST::inOrderHelper(EmergencyBSTNode* node, QList<Emergency>& result) const {
    if (node) {
        inOrderHelper(node->left, result);
        result.append(node->data);
        inOrderHelper(node->right, result);
    }
}

QList<Emergency> EmergencyBST::getAllEmergencies() const {
    QList<Emergency> result;
    inOrderHelper(root, result);
    return result;
}

void EmergencyBST::filterByTypeHelper(EmergencyBSTNode* node, const QString& type, QList<Emergency>& result) const {
    if (node) {
        filterByTypeHelper(node->left, type, result);
        if (node->data.type == type) {
            result.append(node->data);
        }
        filterByTypeHelper(node->right, type, result);
    }
}

QList<Emergency> EmergencyBST::getEmergenciesByType(const QString& type) const {
    QList<Emergency> result;
    filterByTypeHelper(root, type, result);
    return result;
}

int EmergencyBST::size() const { return count; }

bool EmergencyBST::isEmpty() const { return count == 0; }

// AddEmergencyDialog implementation
AddEmergencyDialog::AddEmergencyDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Add Emergency");

    QFormLayout *formLayout = new QFormLayout(this);

    emergencyTypeComboBox = new QComboBox(this);
    emergencyTypeComboBox->addItems({"Fire Fighter", "DOT", "ENP", "Ambulance"});

    addressLineEdit = new QLineEdit(this);

    priorityComboBox = new QComboBox(this);
    priorityComboBox->addItems({"1 - Highest (Life-threatening)",
                               "2 - High (Critical)",
                               "3 - Medium (Urgent)",
                               "4 - Low (Routine)"});

    formLayout->addRow("Emergency Type:", emergencyTypeComboBox);
    formLayout->addRow("Address:", addressLineEdit);
    formLayout->addRow("Priority:", priorityComboBox);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    formLayout->addRow(buttonBox);
    setLayout(formLayout);
}

QString AddEmergencyDialog::getEmergencyType() const {
    return emergencyTypeComboBox->currentText();
}

QString AddEmergencyDialog::getAddress() const {
    return addressLineEdit->text();
}

int AddEmergencyDialog::getPriority() const {
    return priorityComboBox->currentIndex() + 1;
}

// MainWindow implementation
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(1000, 700);
    setupUI();
    setupConnections();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    // Left sidebar
    QVBoxLayout *leftLayout = new QVBoxLayout();

    controlCenterButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\all.png"), "Control Center");
    fireFighterButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\fire-truck.png"), "Fire Fighter");
    dotButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\traffic-cone.png"), "DOT");
    enpButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\police-car.png"), "ENP");
    ambulanceButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\ambulance.png"), "Ambulance");
    visualizeBSTButton = new QPushButton(QIcon("C:\\Users\\maged\\CLionProjects\\Emergency Call Program\\binary.png"),"Visualize BST");

    QString buttonStyle = "min-width: 120px; height: 60px; border-radius: 8px; font-size: 14px; font-weight: bold;";
    controlCenterButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
        "stop:0 #ff0000, stop:0.25 #ff8000, stop:0.5 #0000ff, stop:1 #1e1e1e ); color: white;");
    controlCenterButton->setIconSize(QSize(40, 40));
    fireFighterButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
        "stop:0.5 #ff0000, stop:1 #1e1e1e); color: white;");
    fireFighterButton->setIconSize(QSize(40, 40));
    dotButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
        "stop:0.5 #ff8000, stop:1 #1e1e1e); color: white;");
    dotButton->setIconSize(QSize(40, 40));
    enpButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
        "stop:0.5 #0056b3, stop:1 #1e1e1e); color: white;");
    enpButton->setIconSize(QSize(40, 40));
    ambulanceButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
        "stop:0 #ffffff, stop:.5 #ff0000 stop:1 #1e1e1e);; color: white;");
    ambulanceButton->setIconSize(QSize(40, 40));
    visualizeBSTButton->setStyleSheet(buttonStyle + "background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
        "stop:0.5 #133b62,stop:1 #1e1e1e); color: white;");
    visualizeBSTButton->setIconSize(QSize(40, 40));

    leftLayout->addWidget(controlCenterButton);
    leftLayout->addWidget(fireFighterButton);
    leftLayout->addWidget(dotButton);
    leftLayout->addWidget(enpButton);
    leftLayout->addWidget(ambulanceButton);
    leftLayout->addWidget(visualizeBSTButton);
    leftLayout->addStretch();

    // Right side
    QVBoxLayout *rightLayout = new QVBoxLayout();

    emergencyTableWidget = new QTableWidget(this);
    emergencyTableWidget->setColumnCount(4);
    emergencyTableWidget->setHorizontalHeaderLabels({"Type", "Address", "Time", "Priority"});
    emergencyTableWidget->setColumnWidth(0, 150);
    emergencyTableWidget->setColumnWidth(1, 250);
    emergencyTableWidget->setColumnWidth(2, 180);
    emergencyTableWidget->setColumnWidth(3, 145);
    emergencyTableWidget->setAlternatingRowColors(true);

    addEmergencyButton = new QPushButton("Add Emergency");
    removeEmergencyButton = new QPushButton("Remove Highest Priority");

    QString actionButtonStyle = "height: 40px; border-radius: 6px; font-size: 14px;";
    addEmergencyButton->setStyleSheet(actionButtonStyle + "background-color: #28a745; color: white;");
    removeEmergencyButton->setStyleSheet(actionButtonStyle + "background-color: #dc3545; color: white;");

    rightLayout->addWidget(emergencyTableWidget);
    rightLayout->addWidget(addEmergencyButton);
    rightLayout->addWidget(removeEmergencyButton);

    mainLayout->addLayout(leftLayout, 1);
    mainLayout->addLayout(rightLayout, 3);
    setCentralWidget(centralWidget);
}

void MainWindow::setupConnections() {
    connect(controlCenterButton, &QPushButton::clicked, this, &MainWindow::resetButtons);
    connect(fireFighterButton, &QPushButton::clicked, this, [this]() { filterEmergencies("Fire Fighter"); });
    connect(dotButton, &QPushButton::clicked, this, [this]() { filterEmergencies("DOT"); });
    connect(enpButton, &QPushButton::clicked, this, [this]() { filterEmergencies("ENP"); });
    connect(ambulanceButton, &QPushButton::clicked, this, [this]() { filterEmergencies("Ambulance"); });
    connect(visualizeBSTButton, &QPushButton::clicked, this, &MainWindow::showBSTVisualization);

    connect(addEmergencyButton, &QPushButton::clicked, this, &MainWindow::addEmergency);
    connect(removeEmergencyButton, &QPushButton::clicked, this, &MainWindow::removeEmergency);
}

void MainWindow::showBSTVisualization() {
    BSTVisualizer visualizer(emergencies, this);
    visualizer.exec();
}

Emergency MainWindow::removeHighestPriorityEmergency() {
    if (emergencies.isEmpty()) {
        throw "No emergencies to remove";
    }

    if (!currentFilterType.isEmpty()) {
        QList<Emergency> filtered = emergencies.getEmergenciesByType(currentFilterType);
        if (filtered.isEmpty()) {
            throw QString("No %1 emergencies to remove").arg(currentFilterType).toStdString().c_str();
        }

        // Find the highest priority emergency in the filtered list
        Emergency highest = filtered.first();
        for (const Emergency& e : filtered) {
            if (e.isHigherPriorityThan(highest)) {
                highest = e;
            }
        }

        // Remove this emergency from the BST
        // Since BST doesn't support direct removal by value, we'll need to reconstruct the tree
        QList<Emergency> allEmergencies = emergencies.getAllEmergencies();
        emergencies.clear();

        for (const Emergency& e : allEmergencies) {
            if (!(e == highest)) {
                emergencies.insert(e);
            }
        }

        return highest;
    }

    return emergencies.removeHighestPriority();
}

void MainWindow::addEmergency() {
    AddEmergencyDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Emergency e;
        e.type = dialog.getEmergencyType();
        e.address = dialog.getAddress();
        e.time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        e.priority = dialog.getPriority();
        e.timestamp = QDateTime::currentMSecsSinceEpoch();

        if (e.address.isEmpty()) {
            QMessageBox::warning(this, "Error", "Address cannot be empty!");
            return;
        }

        emergencies.insert(e);
        updateTable(currentFilterType);

        QString priorityText;
        switch(e.priority) {
            case 1: priorityText = "Highest Priority (Life-threatening)"; break;
            case 2: priorityText = "High Priority (Critical)"; break;
            case 3: priorityText = "Medium Priority (Urgent)"; break;
            default: priorityText = "Low Priority (Routine)";
        }

        QMessageBox::information(this, "Success",
            QString("Emergency added!\nType: %1\nPriority: %2").arg(e.type).arg(priorityText));
    }
}

void MainWindow::removeEmergency() {
    try {
        Emergency e = removeHighestPriorityEmergency();
        updateTable(currentFilterType);

        QString priorityText;
        switch(e.priority) {
            case 1: priorityText = "Highest Priority (Life-threatening)"; break;
            case 2: priorityText = "High Priority (Critical)"; break;
            case 3: priorityText = "Medium Priority (Urgent)"; break;
            default: priorityText = "Low Priority (Routine)";
        }

        QString message = QString("Dispatched %1 Emergency:\n"
                                "Priority: %2\n"
                                "Address: %3\n"
                                "Time Received: %4")
                         .arg(e.type)
                         .arg(priorityText)
                         .arg(e.address)
                         .arg(e.time);

        QMessageBox::information(this, "Emergency Dispatched", message);
    } catch (const char* msg) {
        QMessageBox::warning(this, "Error", msg);
    } catch (const QString& msg) {
        QMessageBox::warning(this, "Error", msg);
    }
}

void MainWindow::filterEmergencies(const QString &type) {
    addEmergencyButton->setVisible(false);
    removeEmergencyButton->setText(QString("Accept %1").arg(type));
    currentFilterType = type;
    updateTable(type);
}

void MainWindow::resetButtons() {
    addEmergencyButton->setVisible(true);
    removeEmergencyButton->setText("Remove Highest Priority");
    currentFilterType = "";
    updateTable();
}

QColor MainWindow::getPriorityColor(int priority) const {
    switch(priority) {
        case 1: return QColor(255, 0, 0);
        case 2: return QColor(255, 100, 0);
        case 3: return QColor(255, 255, 0);
        default: return QColor(0, 154, 0);
    }
}

void MainWindow::updateTable(const QString &filterType) {
    emergencyTableWidget->setRowCount(0);

    QList<Emergency> emergenciesList;
    if (filterType.isEmpty()) {
        emergenciesList = emergencies.getAllEmergencies();
    } else {
        emergenciesList = emergencies.getEmergenciesByType(filterType);
    }

    for (const Emergency& e : emergenciesList) {
        int row = emergencyTableWidget->rowCount();
        emergencyTableWidget->insertRow(row);

        emergencyTableWidget->setItem(row, 0, new QTableWidgetItem(e.type));
        emergencyTableWidget->setItem(row, 1, new QTableWidgetItem(e.address));
        emergencyTableWidget->setItem(row, 2, new QTableWidgetItem(e.time));

        QTableWidgetItem *priorityItem = new QTableWidgetItem();
        switch(e.priority) {
            case 1: priorityItem->setText("Highest"); break;
            case 2: priorityItem->setText("High"); break;
            case 3: priorityItem->setText("Medium"); break;
            default: priorityItem->setText("Low");
        }
        priorityItem->setBackground(getPriorityColor(e.priority));
        emergencyTableWidget->setItem(row, 3, priorityItem);
    }
}