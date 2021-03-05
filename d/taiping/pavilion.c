inherit ROOM;
void create()
{
        set("short", "六角亭");
        set("long", @LONG
假山上是一座六角亭，白玉为柱，檐角如飞鸟展翅，亭外花径纵横，向东便是
鹦鹉阁。这里灯火如星，照着满园花树，花树间绿女红男轻歌曼舞，看来像是幅图
画。六角亭里有几个很年轻也很美的女孩子——就算是不太年轻，至少看起来不老，
就算不太美，至少都有某种吸引力。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"garden",
		"south": __DIR__"garden2",
	]));
        set("outdoors", "taiping");
        set("objects", ([
        	__DIR__"npc/sanye": 1,
        	__DIR__"npc/girl3": 1,
        	__DIR__"npc/girl4": 1,
        	__DIR__"npc/girl2": 1,
        	__DIR__"npc/girl1": 1,
        ]));
	set("item_desc", ([
	        
	]));
	set("coor/x",-100);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
