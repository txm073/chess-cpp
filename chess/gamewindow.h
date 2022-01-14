#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtWidgets>
#include <QtGui>
#include "customlabel.h"
#include "utils.h"
#include "piece.h"
#include "windows.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(char* argv[]);
    ~GameWindow();
    void drawPiece(int i, int j, std::string colour, std::string type, bool transparent);
    void drawBoard(std::vector<std::vector<std::string>> arr);
    int convert(int i, int j);
    std::pair<std::string, std::string> convert(std::string c);
    std::pair<int, int> convert(int i);
    void processClick(int i, int j);
    static const int screenSize = 640;
    static const int squareSize = screenSize / 8;
    static const int imageSize = GameWindow::squareSize - 10;
    char* args = nullptr;
    std::string rootDirectory = "E:\\C++\\GUI\\Chess\\";

    QLabel *square = nullptr;
    QColor *white = new QColor(217, 200, 168);
    QColor *brown = new QColor(68, 40, 28);
    std::map<std::pair<int, int>, QLabel> squares;

private:
    Ui::GameWindow *ui;
    void setRootDirectory();
};



#endif // GAMEWINDOW_H
