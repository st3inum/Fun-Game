#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>
#include<SFML/Audio.hpp>

using namespace sf;
using namespace std;
RenderWindow window1(VideoMode(500, 500), "shakes forhads");
class forhad
{
	Texture A,B;
	Sprite 	a,b;
	int i=0,point=0;
	Text text;
	Font font;
public:
	void load_image(string s,string ss)
	{
		A.loadFromFile(s);
		B.loadFromFile(ss);
		a.setTexture(A);
		b.setTexture(B);
		a.setOrigin(a.getLocalBounds().width/2, a.getLocalBounds().height/2);
		b.setOrigin(b.getLocalBounds().width/2, b.getLocalBounds().height/2);
		a.setPosition(250,250);
		b.setPosition(250,250);
	}
	void scale()
	{
		a.scale(0.2,0.2);
		b.scale(0.2,0.2);
	}
	void rotate()
	{
		a.rotate(-90);
		b.rotate(-90);
	}
	void move(bool f)
	{
		if(f)point++;
		if(point&1)window1.draw(a);
		else window1.draw(b);
		text.setString(to_string(point));
		window1.draw(text);
	}
	void load_text(string s)
	{
	    font.loadFromFile(s);
	    text.setFont(font);
	    text.setString("0");
	    text.setPosition(240,280);
	    text.setCharacterSize(45);
	    text.setColor(Color::Red);
	}
};


int main()
{
	window1.setFramerateLimit(60);
	window1.setKeyRepeatEnabled(false);
	forhad bash;
	bash.load_image("file/a.JPG","file/b.JPG");
	bash.load_text("file/font.ttf");
	bash.scale();
	bash.rotate();
	Music forhad_music;
	forhad_music.openFromFile("file/preview.wav");
    forhad_music.setVolume(100);
    forhad_music.play();
	 while(window1.isOpen()) {
	 	forhad_music.setLoop(true);
        Event event;
        while(window1.pollEvent(event)) {
            if(event.type == event.Closed) window1.close();
            else if (event.type == event.MouseButtonReleased && event.mouseButton.button== sf::Mouse::Left )bash.move(1);
        }
        bash.move(0);
        window1.display();
        window1.clear();
    }
}