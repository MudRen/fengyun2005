inherit ROOM;

void create()
{
        set("short", "小客栈");
        set("long", @LONG
简陋的客厅当中供着一个手捧金元宝的财神爷，后面的一扇门上，挂着已洗的
发白的蓝布棉门帘，上面还贴着张斗大的红“喜”字，无论谁走进这里，都可以看
得出这地方的主人，一定是整天在做着发财梦的穷小子。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"street2",
  "east" : __DIR__"pofang",
]));
        set("objects", ([
        __DIR__"npc/waiter" : 1,
                        ]) );
	set("coor/x",20);
	set("coor/y",20);
	set("coor/z",0);
	setup();
//    replace_program(NEWBIE_HELP_ROOM);

}

