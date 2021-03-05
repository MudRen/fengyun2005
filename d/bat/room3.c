#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "书房");
    set("long", @LONG
一进小屋，只见墙上挂满了无数名贵的字画。书架上也堆满了平时难得一见的
各种各样的书籍。一个中年文士正对着一幅字画出神。
LONG
    );
    set("exits", ([
		"north" : __DIR__"zoulang1",

    ]));
    set("objects", ([
		__DIR__"npc/wenshi": 1,
    
    ]));
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",-10);

	setup();

}

void reset() {
	string *item= ({"parry_50","literate_50b","move_60","skill/wuzheng-force_60"});
	object ob;
	
	:: reset();
	
	foreach (string x in item) 
	{
		ob = new(BOOKS+x);
		if (present(ob,this_object())) destruct(ob);
			else ob->move(this_object());
	}
}


