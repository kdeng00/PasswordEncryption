#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include<QDialog>
#include<QPushButton>
#include<QTextEdit>
#include<QLabel>
#include<QMenuBar>
#include<QMainWindow>
#include<QMenu>
#include<QAction>
#include<QVBoxLayout>
#include<QDockWidget>
#include<QWidget>
#include<memory>
#include"KeyManagementWindow.h"
#include"CommonWindow.h"


class MainWindow : public QMainWindow, public CommonWindow
{
	Q_OBJECT
public:
	MainWindow();
	~MainWindow() = default;
signals:

private slots:
	void changeCryptionType();
	void determineCryption();
	void keyManagementWindow();
	void exitApplication();
private:	
	void setupMainWindow();
	void createMenus();

	unique_ptr<QVBoxLayout> buttonLayout;

	unique_ptr<QWidget> buttonWidget;

	unique_ptr<QDockWidget> buttonDockWidget;
	unique_ptr<QDockWidget> cryptionArea;

	unique_ptr<QLabel> lblOfEncryptedBox;

	unique_ptr<QTextEdit> textForCryption;

	unique_ptr<QPushButton> cryptionButon;
	unique_ptr<QPushButton> cryptionSwitch;

	unique_ptr<QMenu> fileMenu;
	unique_ptr<QMenu> editMenu;
	unique_ptr<QAction> closeApplication;
	unique_ptr<QAction> keyEdit;	

	unique_ptr<KeyManagementWindow> kh;

	std::string grabCryptionText();

	bool cryptionChoice;
};
#endif
