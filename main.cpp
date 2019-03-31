#include<SFML/Graphics.hpp>
#include<bits/stdc++.h>
#include<SFML/Audio.hpp>

using namespace sf;
using namespace std;
RenderWindow window1(VideoMode(500, 500), "Shakes Man");
int level_number=4;
bool level[4];
int point=0;
class forhad
{
	Texture A,B;
	Sprite 	a,b;
	int i=0;
	Text text;
	Font font;
public:
	void load_image(string s,string ss)
	{
		A.loadFromFile(s);
		B.loadFromFile(ss);
		a.setTexture(A);
		b.setTexture(B);
		/*a.setOrigin(a.getLocalBounds().width/2, a.getLocalBounds().height/2);
		b.setOrigin(b.getLocalBounds().width/2, b.getLocalBounds().height/2);*/
		a.setPosition(40,-80);
		b.setPosition(40,-80);
		/*a.scale(0.2,0.2);
		b.scale(0.2,0.2);*/

	}
	void scale(float x,float y)
	{
		a.scale(x,y);
		b.scale(x,y);
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
	    text.setFillColor(Color::Red);
	}
};
class Menu
{
	public:
	Texture background;
	Sprite 	s_background;
	int i=0,point=0;
	Text gametxt,new_game,select_level,sound,help,about,exit,back;

	Text level1,level2,level3,level4;

	Font font1;
	int text_y=50;
	int x_axis=160;

	void level(){
		background.loadFromFile("file/background.jpg");

		 level1.setString("Play Forhad");
    level1.setFont(font1);
    level1.setCharacterSize(40);
    level1.setScale(1.f,1.f);
    //gametxt.setFillColor(Color::Red);
    level1.setPosition(200+150-x_axis,100+text_y*0);
    level1.setFillColor(Color::Yellow);

    	 level2.setString("Play Shouhardo");
    level2.setFont(font1);
    level2.setCharacterSize(40);
    level2.setScale(1.f,1.f);
    //gametxt.setFillColor(Color::Red);
    level2.setPosition(200+150-x_axis,100+text_y*1);
    level2.setFillColor(Color::Yellow);

    	 level3.setString("Play Maruf Bro");
    level3.setFont(font1);
    level3.setCharacterSize(40);
    level3.setScale(1.f,1.f);
    //gametxt.setFillColor(Color::Red);
    level3.setPosition(200+150-x_axis,100+text_y*2);
    level3.setFillColor(Color::Yellow);

                     back.setString("BACK");
                      back.setFont(font1);
                      back.setCharacterSize(40);
                      back.setScale(1.f,1.f);
                      //gametxt.setFillColor(Color::Red);
                      back.setPosition(200+150-x_axis,100+text_y*3);
                      back.setFillColor(Color::Yellow);



	}
	void level_show(){
		window1.draw(level1);
		window1.draw(level2);
		window1.draw(level3);
		window1.draw(back);
	}

	void load_all(){

		background.loadFromFile("file/background.jpg");
		s_background.setTexture(background);
		s_background.setScale(0.3f,0.4f);
	
		
		 font1.loadFromFile("file/kalpurush.ttf");

		gametxt.setString("Shakes Man");
    gametxt.setFont(font1);
    gametxt.setCharacterSize(80);
    gametxt.setScale(1.0f,1.0f);
    //gametxt.setFillColor(Color::Red);
    gametxt.setPosition(190-x_axis,-20);
    gametxt.setFillColor(Color::Blue);



    new_game.setString("Play Game");
    new_game.setFont(font1);
    new_game.setCharacterSize(40);
    new_game.setScale(1.f,1.f);
    //gametxt.setFillColor(Color::Red);
    new_game.setPosition(200+150-x_axis,100+text_y*0);
    new_game.setFillColor(Color::Yellow);

  

     select_level.setString("Select Man");
   select_level.setFont(font1);
    select_level.setCharacterSize(40);
    select_level.setScale(1.f,1.f);
    //gametxt.setFillColor(Color::Red);
    select_level.setPosition(200+150-x_axis,100+text_y*1);
    select_level.setFillColor(Color::Yellow);

     sound.setString("Music");
   sound.setFont(font1);
    sound.setCharacterSize(40);
    sound.setScale(1.f,1.f);
    //gametxt.setFillColor(Color::Red);
    sound.setPosition(200+150-x_axis,100+text_y*2);
    sound.setFillColor(Color::Yellow);

       help.setString("Help");
  help.setFont(font1);
    help.setCharacterSize(40);
    help.setScale(1.f,1.f);
    //gametxt.setFillColor(Color::Red);
   help.setPosition(200+150-x_axis,100+text_y*3);
    help.setFillColor(Color::Yellow);

     about.setString("About");
   about.setFont(font1);
    about.setCharacterSize(40);
    about.setScale(1.f,1.f);
    //gametxt.setFillColor(Color::Red);
   about.setPosition(200+150-x_axis,100+text_y*4);
    about.setFillColor(Color::Yellow);


      exit.setString("Exit");
  exit.setFont(font1);
    exit.setCharacterSize(40);
    exit.setScale(1.f,1.f);
    //gametxt.setFillColor(Color::Red);
   exit.setPosition(200+150-x_axis,100+text_y*5);
    exit.setFillColor(Color::Yellow);

                    


	}

	void menu_show()
	{
		window1.draw(s_background);
		window1.draw(gametxt);
		window1.draw(new_game);
		window1.draw(select_level);
		window1.draw(sound);
		window1.draw(help);
		window1.draw(about);
		window1.draw(exit);

	}

	
};



int main()
{
	bool menu=true,selectman=false,help=false,about=false,exit=false,sound=false,homee=true;
	Menu home;
	home.load_all();
	home.level();
	Clock clock;

	

	window1.setFramerateLimit(60);
	window1.setKeyRepeatEnabled(false);
	forhad bash;
	bash.load_image("file/a.JPG","file/b.JPG");
	bash.load_text("file/font.ttf");
	bash.scale(0.5,0.5);
		bash.scale(0.5,0.5);

	/*//bash.scale(0.2,0.2);
	                                bash.rotate();*/
	Music forhad_music;
	forhad_music.openFromFile("file/game2.wav");
    forhad_music.setVolume(100);
    
    unsigned  menuselect=1;
	 while(window1.isOpen()) {
	 	  Event event;
	 	
	 	if(menu)
	 	{
	 		while(window1.pollEvent(event)) {
            if(event.type == event.Closed) window1.close();
            }
	 		
	 		forhad_music.setLoop(true);

	 		float key=clock.getElapsedTime().asSeconds();

                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && key>0.3)
                             {
                                menuselect++;
                                 clock.restart();

                             }
                          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && key>0.3)
                            {
                                menuselect--;
                                 clock.restart();
                            }
                          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && key>0.2)
                            {
                             //if(!menu)window.close();
                            }
                            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
                            {
                             
                              if(selectman)
                              {
                                homee=true;
                                selectman=false;
                                menuselect=2;

                              }
                              else if(sound)
                              {
                                homee=true;
                                sound=false;
                                menuselect=3;
                              }
                              else if(help)
                              {
                                homee=true;
                                help=false;
                                menuselect=4;
                              }
                              else if(about)
                              {
                                homee=true;
                                about=false;
                                menuselect=5;
                              }
                              clock.restart();
                            }
                           else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)  && key>0.2 )
                            {
                              // if (Event::MouseButton.Button == sfButtonLeft && Event.Type == sfEvtMouseButtonPressed);
                                
                
                              
                              if( !selectman && !sound && !help && !about)
                              {
                                if(menuselect%6==1 )
                                  {
                                    
                                     menu=false;
                                     forhad_music.play();
                                  }
                                else if(menuselect%6==2)
                                {
                                  selectman=true;
                                  homee=false;
                                  menuselect=1;
                                }
                                else if(menuselect%6==3)
                                {
                                  sound=true;
                                  homee=false;
                                  menuselect=1;
                                }
                               else if(menuselect%6==4)
                                {
                                  help=true;
                                  homee=false;
                                  menuselect=1;
                                }
                              else  if(menuselect%6==5)
                                {
                                  about=true;
                                  homee=false;
                                  menuselect=1;
                                }
                              
                              else  if(menuselect%6==0)
                                window1.close();
                              }

                            else if(selectman)
                              {
                              	for (int i = 0; i < level_number; ++i)level[i]=false;

                              	if(menuselect%4==1)
                              	{	level[1]=1;
                              		bash.load_image("file/a.JPG","file/b.JPG");
                              		point=0;
                              		
                              	}
                              	else if(menuselect%4==2)
                              	{
                              		level[2]=1;
                              		bash.load_image("file/souharda1.JPG","file/souharda2.JPG");
                              		//bash.scale(0.26,0.5);
								    //bash.rotate();
								    point=0;
                              	}
                              	else if(menuselect%4==3)
                              	{
                              		level[3]=1;
                              		bash.load_image("file/maruf1.JPG","file/maruf2.JPG");
                              		//bash.scale(0.2,0.3);
								    //bash.rotate();
								    point=0;
                              	}
                              	else if(menuselect%4==0)
                              	{
                              		selectman=false;
                              		homee=true;
                              		menuselect=1;
                              	}
                              	
								
							                                

                              }
                            

                              clock.restart();
                           }

                if(homee)
                {
                	home.menu_show();

                        	if(menuselect%6==1)
                            {
                                home.new_game.setFillColor(Color::Green);
                            }
                            else  home.new_game.setFillColor(Color::Yellow);

                             if(menuselect%6==2 )
                            {
                                home.select_level.setFillColor(Color::Green);
                            }
                            else  home.select_level.setFillColor(Color::Yellow);
                             if(menuselect%6==3  )
                            {
                                home.sound.setFillColor(Color::Green);
                            }
                            else home.sound.setFillColor(Color::Yellow);
                             if(menuselect%6==4 )
                            {
                                home.help.setFillColor(Color::Green);
                            }
                            else home.help.setFillColor(Color::Yellow);
                             if(menuselect%6==5 )
                            {
                                home.about.setFillColor(Color::Green);
                            }
                            else home.about.setFillColor(Color::Yellow);
                             
                            if(menuselect%6==0)
                            {
                                home.exit.setFillColor(Color::Red);
                            }
                            else home.exit.setFillColor(Color::Yellow);
                }
                else if(selectman)
                {
                	window1.draw(home.s_background);
                	home.level_show();
                	if(menuselect%4==1)
                	{
                		home.level1.setFillColor(Color::Green);
                	}
                	else if(!level[1]) home.level1.setFillColor(Color::Yellow);

                	if(menuselect%4==2) home.level2.setFillColor(Color::Green);
                	else if(!level[2]) home.level2.setFillColor(Color::Yellow);

                	if(menuselect%4==3) home.level3.setFillColor(Color::Green);
                	else  if(!level[3])home.level3.setFillColor(Color::Yellow);

                	if(menuselect%4==0) home.back.setFillColor(Color::Red);
                	else home.back.setFillColor(Color::Yellow);

                	for (int i = 0; i < level_number; ++i)
                	{
                		if(level[i])
                			{
                				if(i==1)home.level1.setFillColor(Color::Magenta);
                				else if(i==2)home.level2.setFillColor(Color::Magenta);
                				else if(i==3)home.level3.setFillColor(Color::Magenta);
                				break;
                			}
                	}
                }           

                           
	 		
	 		


	 	}
	 	else
	 	{
	 		forhad_music.setLoop(true);
	 		int key=clock.getElapsedTime().asSeconds();

	 		 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && key>0.2)
               {
                             menu=true;
                             forhad_music.stop();
               }
        
        while(window1.pollEvent(event)) {
            if(event.type == event.Closed) window1.close();
            else if (event.type == event.MouseButtonReleased && event.mouseButton.button== sf::Mouse::Left )bash.move(1);
        }
        bash.move(0);
	 	}
	 	
        window1.display();
        window1.clear();
    }
}