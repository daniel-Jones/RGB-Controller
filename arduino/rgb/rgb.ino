#include <SPI.h>
#include <Thread.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

const int redPin = 2;
const int greenPin = 4;
const int bluePin = 3;

int red = 0;
int rf = 0;
int rt = 255;
int green = 0;
int gf = 0;
int gt = 255;
int blue = 0;
int bf = 0;
int bt = 255;

void tests();

void red_thread();
bool r_rev = false;

void green_thread();
bool g_rev = false;

void blue_thread();
bool b_rev = false;

void draw_square(struct square *sq);

Thread r_fade = Thread();
Thread g_fade = Thread();
Thread b_fade = Thread();


struct square {
	int x1; // top left
	int x2; // top right
	int x3; // bottom left
	int x4; //bottom right
	int y1; //top left
	int y2; // top right
	int y3; // bottom left
	int y4; // bottom right
};


struct square sq1;

struct square sq2;



void parse(String com);

void OledWrite(int x, int y, int size, String text) { // this function will write to our oled
	display.setTextSize(size); // set the font size
	display.setTextColor(WHITE); // set the font color
	display.setCursor(x, y); // set the cursor position
	display.println(text); // add our text to the oled buffer
	display.display();
}

void setup()
{
	sq1.x1 = 0;
	sq1.x2 = 30;
	sq1.x3 = 0;
	sq1.x4 = 30;
	sq1.y1 = 0;
	sq1.y2 = 0; 
	sq1.y3 = 30;
	sq1.y4 = 30;


	sq2.x1 = 60;
	sq2.x2 = 90;
	sq2.x3 = 60;
	sq2.x4 = 90;
	sq2.y1 = 0;
	sq2.y2 = 0; 
	sq2.y3 = 30;
	sq2.y4 = 30;


	display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // lets begin our oled display/connection
	display.clearDisplay(); // clear oled display from anything left over from last session
	Serial.begin(9600);
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);

	r_fade.enabled = false;
	r_fade.onRun(red_thread);
	r_fade.setInterval(10);

	g_fade.enabled = false;
	g_fade.onRun(green_thread);
	g_fade.setInterval(10);

	b_fade.enabled = false;
	b_fade.onRun(blue_thread);
	b_fade.setInterval(10);

}

void red_thread()
{
	if (red < rf)
		red = rf;
	if (red > rt)
		red = rf;
	if (red == rt)
		r_rev = true;
	if (red == rf)
		r_rev = false;
	if (!r_rev)
		red++;analogWrite(redPin, red);
	if (r_rev)
		red--;analogWrite(redPin, red);
}

void green_thread()
{
	if (red < rf)
		green = gf;
	if (green > gt)
		green = gf;
	if (green == gt)
		g_rev = true;
	if (green == gf)
		g_rev = false;
	if (!g_rev)
		green++;analogWrite(greenPin, green);
	if (g_rev)
		green--;analogWrite(greenPin, green);
}


void blue_thread()
{
	if (blue < bf)
		red = bf;
	if (blue > bt)
		blue = bf;
	if (blue == bt)
		b_rev = true;
	if (blue == bf)
		b_rev = false;
	if (!b_rev)
		blue++;analogWrite(bluePin, blue);
	if (b_rev)
		blue--;analogWrite(bluePin, blue);
}

void parse(String com)
{
	String p1;
	String p2;
	p1 = com.substring(0, com.indexOf("="));
	p2 = com.substring(com.indexOf("=") + 1);

	if (p1.equalsIgnoreCase("red"))
	{
		red = p2.toInt();
		analogWrite(redPin, red);
	}
	if (p1.equalsIgnoreCase("green"))
	{
		green = p2.toInt();
		analogWrite(greenPin, green);
	}
	if (p1.equalsIgnoreCase("blue"))
	{
		blue = p2.toInt();
		analogWrite(bluePin, blue);
	}
	if (p1.equalsIgnoreCase("redfade"))
	{
		if (r_fade.enabled)
			r_fade.enabled = false;
		else if (!r_fade.enabled)
			r_fade.enabled = true;
	}
	if (p1.equalsIgnoreCase("greenfade"))
	{
		if (g_fade.enabled)
			g_fade.enabled = false;
		else if (!g_fade.enabled)
			g_fade.enabled = true;
	}
	if (p1.equalsIgnoreCase("bluefade"))
	{
		if (b_fade.enabled)
			b_fade.enabled = false;
		else if (!b_fade.enabled)
			b_fade.enabled = true;
	}
	if (p1.equalsIgnoreCase("rspeed"))
	{
		r_fade.setInterval(p2.toInt());
	}
	if (p1.equalsIgnoreCase("gspeed"))
	{
		g_fade.setInterval(p2.toInt());
	}

	if (p1.equalsIgnoreCase("bspeed"))
	{
		b_fade.setInterval(p2.toInt());
	}

	if (p1.equalsIgnoreCase("speed"))
	{
		r_fade.setInterval(p2.toInt());
		g_fade.setInterval(p2.toInt());
		b_fade.setInterval(p2.toInt());
	}
	if (p1.equalsIgnoreCase("rf"))
		rf = p2.toInt();
	if (p1.equalsIgnoreCase("rt"))
		rt = p2.toInt();
	if (p1.equalsIgnoreCase("gf"))
		gf = p2.toInt();
	if (p1.equalsIgnoreCase("gt"))
		gt = p2.toInt();
	if (p1.equalsIgnoreCase("bf"))
		bf = p2.toInt();
	if (p1.equalsIgnoreCase("bt"))
		bt = p2.toInt();
	if (p1.equalsIgnoreCase("ping"))
		Serial.write("ping=pong\n");
	if (p1.equalsIgnoreCase("write"))
	{
		display.clearDisplay();
		OledWrite(0, 0, 3, p2);
	}
	if (p1.equalsIgnoreCase("off"))
	{
		red = 0;
		green = 0;
		blue = 0;
		r_fade.enabled = false;
		g_fade.enabled = false;
		b_fade.enabled = false;
		analogWrite(redPin, red);
		analogWrite(greenPin, green);
		analogWrite(bluePin, blue);
	}
}

String line;

void loop()
{
	if (r_fade.shouldRun())
		r_fade.run();
	if (g_fade.shouldRun())
		g_fade.run();
	if (b_fade.shouldRun())
		b_fade.run();

	/* read serial data */
	while (Serial.available())
	{
		char c = Serial.read();
		if (c == '\n')
		{
			parse(line);
			line = "";
		}
		else 
		{
			line += c;
		}
	}
	tests();
}

void tests()
{
	display.clearDisplay();

	draw_square(&sq1);
	draw_square(&sq2);

	display.display();
}

void draw_square(struct square *sq)
{
	/* top left -> top right */
	display.drawLine(sq->x2, sq->y1, sq->x1, sq->y2, WHITE);
	/* top right -> bottom right */
	display.drawLine(sq->x2, sq->y2, sq->x4, sq->y4, WHITE);
	/* bottom right -> bottom left */
	display.drawLine(sq->x4, sq->y4, sq->x3, sq->y3, WHITE);
	/* bottom left -> top left */
	display.drawLine(sq->x3, sq->y3, sq->x1, sq->y1, WHITE);
}
