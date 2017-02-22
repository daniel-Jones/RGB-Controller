#include <SPI.h>
#include <Thread.h>

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

void red_thread();
bool r_rev = false;

void green_thread();
bool g_rev = false;

void blue_thread();
bool b_rev = false;

Thread r_fade = Thread();
Thread g_fade = Thread();
Thread b_fade = Thread();

void parse(String com);

void setup()
{
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
}
