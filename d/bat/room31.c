#include <ansi.h>

inherit ROOM;
string* books = ({
	__DIR__"obj/book-bamboo",
	__DIR__"obj/book-paper",
	__DIR__"obj/book-silk",
	__DIR__"obj/book-iron",
});


void create()
{
    set("short", "书房");
    set("long", @LONG
一进小屋，只见墙上挂满了无数名贵的字画。书架上也堆满了平时难得
一见的各种各样的书籍。一个中年文士正对着一幅字画出神。
LONG
    );
    set("exits", ([
		"north" : __DIR__"zoulang1",

    ]));
    set("objects", ([
		__DIR__"npc/wenshi": 1,
/*		books[0] : 1,
		books[1] : 1,
    		books[2] : 1,
		books[3] : 1,
    			*/
    ]));
   set("coor/x",3290);
	set("coor/y",20);
	set("coor/z",-30);
//	set("refresh_all_items", 1);
	setup();

}


void reset() {
	string *item= ({"book-bamboo","book-paper","book-silk","book-iron"});
	object ob;
	
	:: reset();
	
	foreach (string x in item) 
	{
		ob = new(__DIR__"obj/"+x);
		if (present(ob,this_object())) destruct(ob);
			else ob->move(this_object());
	}
}


