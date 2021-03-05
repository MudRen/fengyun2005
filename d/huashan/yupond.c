
inherit ROOM;

void create()
{
        set("short", "玉泉池");
        set("long", @LONG
这里是一眼温泉，四周围以白布幛幔，旁边还摆放着几张桌椅。泉眼不大，四
周的岩石被水冲洗的光洁干净，泉水蓝中透着绿色，从泉上不断冒出的白色水雾把
这里笼罩在一片迷蒙之中。
LONG
        );
    set("exits", ([ 
  		"south" : __DIR__"path1",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",-10);
	set("objects", ([
                __DIR__"npc/nakedman" : 1,
				__DIR__"npc/nakedman2" : 1,
      ]) );
	setup();
	replace_program(ROOM);
}

