#include "piece.h"

Piece::Piece(std::string pieceType, std::string pieceColour)
{
    std::string type = pieceType, colour = pieceColour;
    QPixmap image("images/background.jpg");
    image = image.scaled(GameWindow::squareSize, GameWindow::squareSize);
}

Piece::~Piece()
{

}
