/*
 * Copyright Daniel Jones 2016-2018
 *
 * This file is part of RGBController.
 *
 * RGBController is free software: you can redistribute it and/or modifiy
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RGBController is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RGBController.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <SPI.h>
#include <Thread.h>

const int redPin = 4;
const int greenPin = 3;
const int bluePin = 2;

int red = 0;
int rf = 0;
int rt = 255;
int green = 0;
int gf = 0;
int gt = 255;
int blue = 0;
int bf = 0;
int bt = 255;

struct stat
{
	int r;
	int g;
	int b;
	bool r_fade;
	bool g_fade;
	bool b_fade;
} status; 

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
	if (red < rf) red = rf;
	if (red > rt) red = rf;
	if (red == rt) r_rev = true;
	if (red == rf) r_rev = false;
	((!r_rev) ? (red++, analogWrite(redPin, red)) : (red--, analogWrite(redPin, red))); 
}

void green_thread()
{
	if (red < rf) green = gf;
	if (green > gt) green = gf;
	if (green == gt) g_rev = true;
	if (green == gf) g_rev = false;
	((!g_rev) ? (green++, analogWrite(greenPin, green)) : (green--, analogWrite(greenPin, green)));
}


void blue_thread()
{
	if (blue < bf) red = bf;
	if (blue > bt) blue = bf;
	if (blue == bt) b_rev = true;
	if (blue == bf) b_rev = false;
	((!b_rev) ? (blue++, analogWrite(bluePin, blue)) : (blue--, analogWrite(bluePin, blue)));
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
	if (p1.equalsIgnoreCase("redfade")) (r_fade.enabled) ? r_fade.enabled = false : r_fade.enabled = true;
	if (p1.equalsIgnoreCase("greenfade")) (g_fade.enabled) ? g_fade.enabled = false : g_fade.enabled = true;
	if (p1.equalsIgnoreCase("bluefade")) (b_fade.enabled) ? b_fade.enabled = false : b_fade.enabled = true;
	if (p1.equalsIgnoreCase("rspeed")) r_fade.setInterval(p2.toInt());
	if (p1.equalsIgnoreCase("gspeed")) g_fade.setInterval(p2.toInt());
	if (p1.equalsIgnoreCase("bspeed")) b_fade.setInterval(p2.toInt());

	if (p1.equalsIgnoreCase("speed"))
	{
		r_fade.setInterval(p2.toInt());
		g_fade.setInterval(p2.toInt());
		b_fade.setInterval(p2.toInt());
	}
	if (p1.equalsIgnoreCase("rf")) rf = p2.toInt();
	if (p1.equalsIgnoreCase("rt")) rt = p2.toInt();
	if (p1.equalsIgnoreCase("gf")) gf = p2.toInt();
	if (p1.equalsIgnoreCase("gt")) gt = p2.toInt();
	if (p1.equalsIgnoreCase("bf")) bf = p2.toInt();
	if (p1.equalsIgnoreCase("bt")) bt = p2.toInt();
	if (p1.equalsIgnoreCase("ping")) Serial.write("ping=pong\n");

	/* color increment/decrement */
	if (p1.equalsIgnoreCase("ru") && red <= 255)
	{
		red++;analogWrite(redPin, red);
	}
	if (p1.equalsIgnoreCase("gu") && green <= 255)
	{
		green++;analogWrite(greenPin, green);
	}
	if (p1.equalsIgnoreCase("bu") && blue <= 255)
	{
		blue++;analogWrite(bluePin, blue);
	}

	if (p1.equalsIgnoreCase("rd") && red > 0)
	{
		red--;analogWrite(redPin, red);
	}
	if (p1.equalsIgnoreCase("gd") && green > 0)
	{
		green--;analogWrite(greenPin, green);
	}
	if (p1.equalsIgnoreCase("bd") && blue > 0)
	{
		blue--;analogWrite(bluePin, blue);
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
	if (p1.equalsIgnoreCase("dark"))
	{
		status.r = red;
		status.g = green;
		status.b = blue;
		status.r_fade = r_fade.enabled;
		status.g_fade = g_fade.enabled;
		status.b_fade = b_fade.enabled;
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
	if (p1.equalsIgnoreCase("resume"))
	{
		red = status.r;
		green = status.g;
		blue = status.b;
		r_fade.enabled = status.r_fade;
		g_fade.enabled = status.g_fade;
		b_fade.enabled = status.b_fade;
		analogWrite(redPin, red);
		analogWrite(greenPin, green);
		analogWrite(bluePin, blue);

	}
}

String line;

void loop()
{
	if (r_fade.shouldRun()) r_fade.run();
	if (g_fade.shouldRun()) g_fade.run();
	if (b_fade.shouldRun()) b_fade.run();

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
