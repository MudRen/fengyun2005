
inherit ROOM;

void create()
{
        set("short", "珠宝店");
        set("long", @LONG
这是一家破旧的小店。专门经营玉器，虽是穷乡僻壤，这家小店的生意却特别
好。也许是出塞的人都知到塞外险恶，想必凶多吉少，都想买块玉来消消灾，就算
是不信神佛的人也不例外。
LONG
        );
        set("exits", ([ 
		 "north" : __DIR__"fair2",
	]));
        
        set("objects", ([
                __DIR__"npc/jadeowner" : 1,
        ]) );

	set("coor/x",-1030);
	set("coor/y",-15);
	set("coor/z",0);
	setup();

}

