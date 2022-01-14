#include "gamewindow.h"
#include "ui_gamewindow.h"

// Constructor
GameWindow::GameWindow(char* argv[]) : QMainWindow(nullptr), ui(new Ui::GameWindow)
{
    args = *argv;
    setRootDirectory();
    this->setFixedSize(screenSize, screenSize);
    this->setWindowTitle("Chess In C++");
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            square = new CustomLabel;
            square->setParent(this);
            square->setGeometry(i * squareSize, j * squareSize, squareSize, squareSize);
            if((i + j) % 2 == 0){
                square->setStyleSheet("background-color: rgb(217, 200, 168);");
            } else {
                square->setStyleSheet("background-color: rgb(68, 40, 28);");
            }
            squares.emplace(std::pair<int, int>(i, j), square);
        }
    }
    std::vector<std::vector<std::string>> arr;
    std::string startPos = "RNBQKBNRPPPPPPPPOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOpppppppprnbkqbnr";
    arr = stringToArray(startPos);
    drawBoard(arr);
}

GameWindow::~GameWindow()
{

}

void GameWindow::drawPiece(int i, int j, std::string colour, std::string type, bool transparent = false)
{
    square = new CustomLabel;
    square->setParent(this);
    square->setGeometry(i * squareSize, j * squareSize, squareSize, squareSize);
    if((i + j) % 2 == 0){
        square->setStyleSheet("background-color: rgb(217, 200, 168);");
    } else {
        square->setStyleSheet("background-color: rgb(68, 40, 28);");
    }
    std::string fileName;
    if(transparent == false){
        fileName = rootDirectory + "\\images\\" + colour + " pieces\\" + type + ".png";
    } else {
        fileName = rootDirectory + "\\images\\transparent.png";
    }
    QPixmap pixmap(QString::fromStdString(fileName));
    if(!pixmap.isNull()){
        square->setPixmap(pixmap);
        square->setScaledContents(true);
        connect(square, SIGNAL(clicked()), this, SLOT(processClick(i, j)));
    }
}

void GameWindow::processClick(int i, int j)
{
    std::cout << "Click at " << i << ", " << j << std::endl;
    drawPiece(i, j, "", "", true);
}

void GameWindow::drawBoard(std::vector<std::vector<std::string>> arr)
{
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            std::string c = arr[j][i];
            if(c == "O"){
                drawPiece(i, j, "transparent", "piece", true);
            }
            std::pair<std::string, std::string> details = convert(c);
            drawPiece(i, j, details.first, details.second);
        }
    }
}

std::pair<std::string, std::string> GameWindow::convert(std::string c)
{
    if(c == "K") return std::make_pair("white", "king");
    else if(c == "Q") return std::make_pair("white", "queen");
    else if(c == "N") return std::make_pair("white", "knight");
    else if(c == "B") return std::make_pair("white", "bishop");
    else if(c == "R") return std::make_pair("white", "rook");
    else if(c == "P") return std::make_pair("white", "pawn");
    else if(c == "k") return std::make_pair("black", "king");
    else if(c == "q") return std::make_pair("black", "queen");
    else if(c == "n") return std::make_pair("black", "knight");
    else if(c == "b") return std::make_pair("black", "bishop");
    else if(c == "r") return std::make_pair("black", "rook");
    else if(c == "p") return std::make_pair("black", "pawn");
    else return std::make_pair("", "");
}

int GameWindow::convert(int i, int j)
{
    return i * 8 + j;
}

std::pair<int, int> GameWindow::convert(int i)
{
    int x = i / 8, y = i % 8;
    return std::pair<int, int>(x, y);
}

void GameWindow::setRootDirectory()
{
    std::string path = args;
    std::vector<std::string> splits = splitString(path, "\\");
    std::string name = splits[(int)splits.size() - 1];
    name = name.substr(0, name.size() - 4);
    splits = std::vector<std::string>(splits.begin(), splits.end() - 3);
    rootDirectory = joinStrings(splits, "\\") + name + "\\";
}


