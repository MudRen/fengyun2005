
inherit ROOM;

void create()
{
        set("short", "古董滩");
        set("long", @LONG
一阵凉爽的微风拂面而来，这儿是一条南北走向的深沟，长约二三十米，沟中
泉水涓涓，甚为甘冽，几尾小鱼在水里游弋。沟边绿树成荫绿草芬芳，土坡上有汉
代的古墓数座，故附近的人称此地为古董滩。阳关西出千余里，这里是唯一可以补
充饮水的地方，在你出发前快把水袋装满吧！
LONG
        );
        set("exits", ([ 
	  	"south" : __DIR__"yangguan",
			]));
	set("objects", ([
		__DIR__"npc/camel" : 1,
		__DIR__"npc/camel2" : 1,
		__DIR__"npc/waterwoman" : 1,
		
	]));
	set("item_desc",([
		"tomb":"这些古墓已经有年头了，里面就算是有珍宝也早就不知去向。\n",
		"古墓":	"这些古墓已经有年头了，里面就算是有珍宝也早就不知去向。\n",
		"深沟": "泉水涓涓，快打些水吧。\n",
	]));
	set("resource/water",1);
        set("liquid", ([
        "container": "沟",
        "name":	"古董滩水",
       	]));
        set("outdoors", "zangbei");
        set("map","zbeast");

        set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}

void dig_notify()
{
     object me;
     me = this_player();
     tell_object(me,"君子有所为有所不为，纵然饿死也不能做此缺德之事！\n");
}
