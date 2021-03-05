
inherit ROOM;

void create()
{
        set("short", "密林中");
        set("long", @LONG
树木越来越多，林木虽没有遮天蔽日却也渐渐得让你转晕了头，分不清东南西
北了，向四周看只觉得眼前景色都是一样，已不见了来时的路。原本悦耳的鸟鸣声
现在也让你感到烦躁不安。
LONG
        );
    set("exits", ([ 
  		"south" : __DIR__"milin1",
	    "north" : __DIR__"duanshan",
	    "west" : __DIR__"milin",
	    "east" : __DIR__"milin1",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-5);
	set("coor/y",-50);
	set("coor/z",-107);
	setup();
    replace_program(ROOM);
}

