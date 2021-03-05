
inherit ROOM;

void create()
{
        set("short", "五里关");
        set("long", @LONG
五里关为华山天险第一关，此处西依绝壁，东临深渊，地势险要，当地人为
逃兵灾匪祸，便依此天险，磊石为称，据险以守，乃一夫当关，万夫莫开。过此
关，再向前行便是华山峪石门。
LONG
        );
    set("exits", ([ 
  		"eastdown" : __DIR__"yuquan",
  		"southeast" : __DIR__"shaluo",
	]));
  	set("objects", ([
		__DIR__"npc/explorer" : 1,
	]));    
    set("outdoors", "huashan");

	set("coor/x",-15);
	set("coor/y",10);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}

