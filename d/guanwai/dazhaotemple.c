inherit ROOM;

void create()
{
        set("short", "大昭寺");
        set("long", @LONG
宫殿高四十丈，宽一百二十丈。连绵蜿蜒的雉堞，高耸在山崖上的城堡，古老
的寺院、禅房、碑碣、楼阁、算不清的窗牖帷帘，看起来瑰丽而条和，就好象是梦
境，就象是神话。
LONG
        );

        set("exits", ([ 
	"east" : __DIR__"octostreet",
	"west" : __DIR__"templeyard",
	]));
        set("objects", ([
                __DIR__"npc/hanren" : 1,
		__DIR__"npc/bhutanese" : 1,
                __DIR__"npc/mongol" : 1,   
        ]) );
        set("outdoors", "guanwai");
	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}