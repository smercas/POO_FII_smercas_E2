#include <iostream>
#include <queue>
#include "Canvas.h"
using namespace std;

int ax[4] = { 1, 0, -1, 0 };
int ay[4] = { 0, 1, 0, -1 };

Canvas::Canvas(int height, int width) {
    this->height = height;
    this->width = width;
	this->m = (char**)malloc(sizeof(char*) * this->height);
	for (int i = 0; i < this->height; i++) {
		*(this->m + i) = (char*)malloc(sizeof(char) * this->width);
        for (int j = 0; j < this->width; j++) {
            this->SetPoint(i, j, ' ');
        }
	}
}
Canvas::~Canvas() {
    for (int i = 0; i < this->height; i++) {
        free(*(this->m + i));
    }
	free(this->m);
}
bool Canvas::IsPixelOnCanvas(int x, int y) {
    return x >= 0 && x < this->height && y >= 0 && y < this->width;
}
void Canvas::Fill(int x, int y, char ch) {
    if (this->IsPixelOnCanvas(x, y) && *(*(this->m + x) + y) == ' ') {
        this->SetPoint(x, y, ch);
        this->Fill(x + 1, y, ch);
        this->Fill(x, y + 1, ch);
        this->Fill(x - 1, y, ch);
        this->Fill(x, y - 1, ch);
    }
}
void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    if (ray == 0) {
        if (this->IsPixelOnCanvas(x, y)) {
            this->SetPoint(x, y, ch);
        }
    }
    else {
        if (ray < 0) ray = -ray;
        int cx = ray, cy = 0;
        if (this->IsPixelOnCanvas(x + cx, y + cy)) {
            this->SetPoint(x + cx, y + cy, ch);
        }                                                       //pi * 0 : 4    0
        if (this->IsPixelOnCanvas(x - cx, y + cy)) {
            this->SetPoint(x - cx, y + cy, ch);
        }                                                       //pi * 4 : 4    4
        if (this->IsPixelOnCanvas(x + cy, y + cx)) {
            this->SetPoint(x + cy, y + cx, ch);
        }                                                       //pi * 2 : 4    2
        if (this->IsPixelOnCanvas(x + cy, y - cx)) {
            this->SetPoint(x + cy, y - cx, ch);
        }                                                       //pi * 6 : 4    6
        int P = 1 - ray;
        while (cx > cy) {
            cy++;
            if (P <= 0) {
                P = P + 2 * cy + 1;
            }
            else {
                cx--;
                P = P + 2 * cy - 2 * cx + 1;
            }
            if (cx < cy) {
                break;
            }
            if (this->IsPixelOnCanvas(x + cx, y + cy)) {
                this->SetPoint(x + cx, y + cy, ch);
            }                                                   //[pi * 0 : 4, pi * 1 : 4]  [0, 1]
            if (this->IsPixelOnCanvas(x - cx, y + cy)) {
                this->SetPoint(x - cx, y + cy, ch);
            }                                                   //[pi * 4 : 4, pi * 3 : 4]  [4, 3]
            if (this->IsPixelOnCanvas(x - cx, y - cy)) {
                this->SetPoint(x - cx, y - cy, ch);
            }                                                   //[pi * 4 : 4, pi * 5 : 4]  [4, 5]
            if (this->IsPixelOnCanvas(x + cx, y - cy)) {
                this->SetPoint(x + cx, y - cy, ch);
            }                                                   //[pi * 8 : 4, pi * 7 : 4]  [8, 7]
            if (cx != cy) {
                if (this->IsPixelOnCanvas(x + cy, y + cx)) {    
                    this->SetPoint(x + cy, y + cx, ch);
                }                                               //[pi * 2 : 4, pi * 1 : 4]  [2, 1]
                if (this->IsPixelOnCanvas(x - cy, y + cx)) {
                    this->SetPoint(x - cy, y + cx, ch);
                }                                               //[pi * 2 : 4, pi * 3 : 4]  [2, 3]
                if (this->IsPixelOnCanvas(x - cy, y - cx)) {
                    this->SetPoint(x - cy, y - cx, ch);
                }                                               //[pi * 6 : 4, pi * 5 : 4]  [6, 5]
                if (this->IsPixelOnCanvas(x + cy, y - cx)) {
                    this->SetPoint(x + cy, y - cx, ch);
                }                                               //[pi * 6 : 4, pi * 7 : 4]  [6, 7]
            }   //reverse points, if cx == cy, they're already covered (1, 3, 5, 7)
        }
    }
}
void Canvas::FillCircle(int x, int y, int ray, char ch, int rx, int ry) {
    this->DrawCircle(x, y, ray, ch);
    for (int i = x - ray; i < x + ray; i++) {
        for (int j = y - ray; j < y + ray; j++) {
            if (this->IsPixelOnCanvas(i, j) && *(*(this->m + i) + j) == ' ' && (x - i) * (x - i) + (y - j) * (y - j) <= ray * ray) {
                this->SetPoint(i, j, ch);
            }
        }
    }
}
void Canvas::DrawRect(int top, int left, int bottom, int right, char ch) {
    if (top > bottom) {
        top = top + bottom;
        bottom = top - bottom;
        top = top - bottom;
    }
    if (left > right) {
        left = left + right;
        right = left - right;
        left = left - right;
    }
    for (int i = left; i < right; i++) {
        if (this->IsPixelOnCanvas(top, i)) {
            this->SetPoint(top, i, ch);
        }
    }
    for (int i = top; i < bottom; i++) {
        if (this->IsPixelOnCanvas(i, right)) {
            this->SetPoint(i, right, ch);
        }
    }
    for (int i = right; i > left; i--) {
        if (this->IsPixelOnCanvas(bottom, i)) {
            this->SetPoint(bottom, i, ch);
        }
    }
    for (int i = bottom; i > top; i--) {
        if (this->IsPixelOnCanvas(i, left)) {
            this->SetPoint(i, left, ch);
        }
    }
}
void Canvas::FillRect(int top, int left, int bottom, int right, char ch) {
    this->DrawRect(top, left, bottom, right, ch);
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j < right; j++) {
            if (this->IsPixelOnCanvas(i, j)) {
                this->SetPoint(i, j, ch);
            }
        }
    }
}
void Canvas::SetPoint(int x, int y, char ch) {
    *(*(this->m + x) + y) = ch;
}
void Canvas::PlotPixel(int x1, int y1, int x2, int y2, int dx, int dy, char ch)
{
    int pk = 2 * dy - dx;
    for (int i = 0; i <= dx && this->IsPixelOnCanvas(x1, y1); i++) {
        this->SetPoint(x1, y1, ch);
        x1 < x2 ? x1++ : x1--;
        if (pk < 0) {
            pk = pk + 2 * dy;
        }
        else {
            y1 < y2 ? y1++ : y1--;
            pk = pk + 2 * dy - 2 * dx;
        }
    }
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = x2 - x1;
    if (dx < 0) {
        dx = -dx;
    }
    int dy = y2 - y1;
    if (dy < 0) {
        dy = -dy;
    }
    if (dx > dy) {
        this->PlotPixel(x1, y1, x2, y2, dx, dy, ch);
    }
    else {
        this->PlotPixel(y1, x1, y2, x2, dy, dx, ch);
    }
}
void Canvas::Print() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            printf("%c ", *(*(this->m + i) + j));
        }
        printf("\n");
    }
}
void Canvas::Clear() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            this->SetPoint(i, j, ' ');
        }
    }
}