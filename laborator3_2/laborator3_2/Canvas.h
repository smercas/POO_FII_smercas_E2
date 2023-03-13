#pragma once
class Canvas
{
	char** m;
	int height, width;
	void PlotPixel(int x1, int y1, int x2, int y2, int dx, int dy, char ch);	//fml
	// add private data members
public:
	Canvas(int height, int width);
	~Canvas();
	bool IsPixelOnCanvas(int x, int y);
	void Fill(int x, int y, char ch);
	void DrawCircle(int x, int y, int ray, char ch);
	void FillCircle(int x, int y, int ray, char ch);
	void DrawRect(int top, int left, int bottom, int right, char ch);
	void FillRect(int top, int left, int bottom, int right, char ch);
	void SetPoint(int x, int y, char ch);
	void DrawLine(int x1, int y1, int x2, int y2, char ch);
	void Print(); // shows what was printed
	void Clear(); // clears the canvas
};