#ifndef _MATRIXGRAPHS_H
#define _MATRIXGRAPHS_H
#include <inttypes.h>

void drawHorizontalLine(uint8_t x0, uint8_t y0, uint8_t color, uint8_t x1);
void drawVerticalLine(uint8_t x0, uint8_t y0, uint8_t color, uint8_t x1);
void Display(void);
void drawLetter(uint8_t x0, uint8_t y0, uint16_t letter, uint8_t length, uint8_t color);
void drawSquare(uint8_t x0, uint8_t y0, uint8_t color, uint8_t side_lenght);
void Line(uint8_t x0,uint8_t y0, uint8_t x1, uint8_t y1, uint8_t color);
void paintPixel(uint8_t x, uint8_t y, uint8_t color);

void drawDiagonal(uint8_t x0, uint8_t y0, uint8_t color, uint8_t lenght);
void drawDiagonal2(uint8_t x0, uint8_t y0, uint8_t color, uint8_t lenght);
void drawDiagonal3(uint8_t x0, uint8_t y0, uint8_t color, uint8_t lenght);

void drawCounterDiagonal(uint8_t x0, uint8_t y0, uint8_t color, uint8_t x1);
void drawCounterDiagonal2(uint8_t x0, uint8_t y0, uint8_t color, uint8_t lenght);
void drawCounterDiagonal3(uint8_t x0, uint8_t y0, uint8_t color, uint8_t lenght);

void drawHand(uint8_t x0, uint8_t y0, uint8_t y1, uint8_t color);
void drawCircle(int16_t x0, int16_t y0, int16_t color, uint16_t r);

void HourHand(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1,uint8_t color);
void CleanMatrix(void);
#endif  /* _TIMER1_H */
