#ifndef PIECE_H
#define PIECE_H
#include <string>
#include "gamewindow.h"

class Piece
{
public:
    Piece(std::string type, std::string colour);
    ~Piece();
    QPixmap image;

};

#endif // PIECE_H
