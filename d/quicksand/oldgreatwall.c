
inherit ROOM;

void create()
{
        set("short", "破旧长城");
        set("long", @LONG
昔日雄伟的长城已面目全非，岁月和战争已几乎把它夷为平地。唯一仅存的一
点废墟，都被历代英雄的鲜血染成暗红色。这里虽然是一片萧杀，却有几株小树从
碎石的缝隙中挤出，给人以一线生机的感觉。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"saikou",
  "west" : __DIR__"saiwai",
]));
        set("outdoors", "quicksand");

	set("coor/x",-1040);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

