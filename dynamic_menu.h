#define ALLEGRO_STATICLINK
#include <string>
#include "sound.h"
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro.h>

using std::string;
#ifdef _MSC_VER
#pragma comment(lib, "allegro_font-5.0.6-static-md.lib")
#pragma comment(lib, "allegro_ttf-5.0.6-static-md.lib")
#pragma comment(lib, "allegro-5.0.6-static-md.lib")
#pragma comment(lib, "freetype-2.4.8-static-md.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "psapi.lib")
#endif
#pragma once
class dynamic_menu
{
public:
	dynamic_menu(int numberofitems);
	~dynamic_menu(void);
	int add_item_sound(string filename, int pos);
	int add_item_text(string text, int pos);
	int get_item_count();
	int get_position();
	void reset(bool completely, int numberofitems);
	int run(string filename, string text);
	int run_extended(string filename, string text, int pos, bool speak = false);
	void set_callback(int (*functocall)(dynamic_menu*, string), string data);
	bool set_font(string f, int size);
	void set_display(ALLEGRO_DISPLAY* d);
	bool wrap;
	bool allow_escape;
private:
	int number_of_items;
	string* textarray;
	string* soundarray;
	int position;
	int (*function)(dynamic_menu*, string);
	sound* s;
	ALLEGRO_FONT* font;
	ALLEGRO_DISPLAY* display;
	int font_size;
};

