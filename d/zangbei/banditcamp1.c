inherit ROOM;

void create()
{
        set("short", "马贼营地");
        set("long", @LONG
废墟后转了几圈，面前是一块空地，空地上升了几堆篝火，烤肉的香味扑鼻而
来。几个满脸横肉的汉子懒懒散散地靠在篝火边，手里提着各式兵器。后面是三两
个帐篷，破旧不堪，旷野的风吹过，猎猎作响。
LONG
        );
        set("exits", ([ 
	  	"southeast" : __DIR__"deserted",
	  	"north" : __DIR__"camp",
	  	"northwest": __DIR__"banditcamp2",
			]));
	set("objects", ([
		__DIR__"npc/bandit3" : 1,
	]));
	set("outdoors", "zangbei");

        set("coor/x",-440);
	set("coor/y",610);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

