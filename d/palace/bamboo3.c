
inherit ROOM;

void create()
{
        set("short", "翠竹林");
        set("long", @LONG
这里已靠近竹林的边缘，一条小溪哗啦啦欢跃著，冲向竹林，但一靠近竹林，
小溪就安静了下来。透过竹林的缝隙，你可以看见一些高大挺拔的松树，隐约可见
一些红瓦白墙，飞檐楼阁。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"huding",
  "north" : __DIR__"bamboo2",
]));

        set("objects", ([
                __DIR__"npc/huatong" : 1,
                        ]) );
                        
        set("outdoors", "palace");
        set("resource/water",1);
         set("liquid/name","翠竹溪水");
	set("coor/x",40);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

