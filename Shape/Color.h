#pragma once
class ColorShape
{
public:
	enum Color {Black, White, Red, Violet, Green, Blue, Yellow};
	Color color;

	ColorShape();
	~ColorShape();
	ColorShape(Color color);
};

