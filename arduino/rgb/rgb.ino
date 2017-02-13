#include <SPI.h>
#include <Thread.h>

const int redPin = 2;
const int greenPin = 4;
const int bluePin = 3;

int red;
int green;
int blue;

void red_thread();
bool r_rev = false;

void green_thread();
bool g_rev = false;

void blue_thread();
bool b_rev = false;

Thread r_fade = Thread();
Thread g_fade = Thread();
Thread b_fade = Thread();

void setup()
{
	Serial.begin(9600);
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);

	/* set all values to 0 */
	red = 0;
	green = 0;
	blue = 0;
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
        if (red == 255)
                r_rev = true;
        if (red == 0)
                r_rev = false;
        if (!r_rev)
                red++;analogWrite(redPin, red);
        if (r_rev)
                red--;analogWrite(redPin, red);
}

void green_thread()
{
        if (green == 255)
                g_rev = true;
        if (green == 0)
                g_rev = false;
        if (!g_rev)
                green++;analogWrite(greenPin, green);
        if (g_rev)
                green--;analogWrite(greenPin, green);
}


void blue_thread()
{
        if (blue == 255)
                b_rev = true;
        if (blue == 0)
                b_rev = false;
        if (!b_rev)
                blue++;analogWrite(bluePin, blue);
        if (b_rev)
                blue--;analogWrite(bluePin, blue);
}


void loop()
{
	if (r_fade.shouldRun())
		r_fade.run();
	if (g_fade.shouldRun())
                g_fade.run();
	if (b_fade.shouldRun())
                b_fade.run();

	/* read serial data */
	while (Serial.available() > 1)
	{

		red = Serial.parseInt();
		green = Serial.parseInt();
		blue = Serial.parseInt();
		analogWrite(redPin, red);
		analogWrite(greenPin, green);
		analogWrite(bluePin, blue);
	}
}
