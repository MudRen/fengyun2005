// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "苦竹林");
        set("long", @LONG
此处竹林茂盛，白天阳光透过密密的竹叶似乎都染上了淡淡的绿色，这里很少
看到游人，风吹竹动，脚下的竹叶发出沙沙的声响，空气中飘散着一股极淡的苦涩
味道，不仔细很难分辨的出来。     
LONG
        );
	set("exits", ([ 
		"southeast" : __DIR__"jiulong",
		"northdown" : __DIR__"kuzhu",
	]));
    set("outdoors", "huangshan");
	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",20);
	setup();
}

