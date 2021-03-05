#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "照壁");
        set("long", @LONG
屏风遮住的是一面照壁，照壁的两旁各挂着一盏长明灯。灯光并不怎样明亮，
但已足够照亮那面照壁，也已足够照亮照壁上面画着的那个女人。水蛇般的腰，飞
云般的发。那种美丽并不像人间所有。她的人也在飞舞。上没有天空，下没有土地，
只有风和雾，寒冰和火焰。她就飞舞在凤雾冰火之中。她，是不是就是天魔女？
LONG
        );
        set("exits", ([ 
		"west":  __DIR__"village2",
//		"east": __DIR__"andao1",
	]));
        set("item_desc", ([
        	"woman": MAG"她浑身赤裸，只有一条轻纱。迷朦的轻纱环飞在她的腿臂左右，并没有掩遮
她应遮掩的地方。\n"NOR,
		"天魔女": MAG"她浑身赤裸，只有一条轻纱。迷朦的轻纱环飞在她的腿臂左右，并没有掩遮
她应遮掩的地方。\n"NOR,
        	"女人": MAG"她浑身赤裸，只有一条轻纱。迷朦的轻纱环飞在她的腿臂左右，并没有掩遮
她应遮掩的地方。\n"NOR,
		"照壁":		"照壁上画着一个女人。\n",
	 ]));
	set("coor/x",80);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
}


void init()
{
       	add_action("do_push", "push");
}


void close_passage()
{
        object room;
        message("vision", "照壁无声无息地又转了回来，遮住了暗道。\n", this_object() );
        delete("exits/east");
}

int do_push(string arg)
{
        object obj, room;
        if(!arg || (arg != "天魔女" && arg != "woman" && arg !="女人")) {
                return 0;
        }
	if (query("exits/east"))
		return notify_fail("照壁已经打开了。\n");
		message_vision(WHT"$N轻轻在天魔女身上某处一按。\n"NOR,this_player());
		message_vision("天魔女诱人的笑容仿佛抹上了一层奇异的痛苦。她的两条脚倏地向后弯曲。这一弯，
她的小腹便似在向前迎去，画着那两条腿的一方照壁也向后弯，弯出了一道暗门。\n",this_player());
		set("exits/east",__DIR__"andao1");
        call_out("close_passage", 10);
        return 1;
}


void reset()
{
        ::reset();
        delete("exits/east");
}