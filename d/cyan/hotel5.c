// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "星月斋");
    set("long", @LONG
走进此处，你心头赫然一惊。好特殊的楼宇，宽敞如深邃的大海，不知是
书斋或寝房，简单的摆饰，唯一的壁柜橱上放的是各式各样各种年份的酒，边
上搁置着一盆雪色的百合花。墙上一幅水墨，画着一头盘踞于大草原上，张牙
舞爪，吟啸嘶吼雄壮而霸气，仿佛欲冲天翱翔的纯白大虎。
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/song":1,
	__DIR__"npc/zhou":1,

	__DIR__"obj/cabin":1,

	]));
	set("item_desc", ([
	"百合花":"一盆雪色的百合正娇艳绽放。\n",
	"百合":"一盆雪色的百合正娇艳绽放。\n",
	"花":"一盆雪色的百合正娇艳绽放。\n",
	"lily":"一盆雪色的百合正娇艳绽放。\n",
	"flower":"一盆雪色的百合正娇艳绽放。\n",

	
	]) );
	set("exits",([
  		"east" : __DIR__"bridge",
	]) );

	set("no_lu_letter",1);
	set("coor/x",-60);
	set("coor/y",20);
	set("coor/z",80);
	setup();
}


void reset()
{
	object river,stone,*inv;
	
	::reset();



	river = present("壁柜", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1 )
	{
		stone = new(__DIR__"obj/wine5");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/wine1");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/wine2");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/wine3");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/wine4");
		if(stone)
			stone->move(river);
	}


	return;
}

void init() {
	add_action("do_pick","pick");
	add_action("do_get","get");
}

int do_get(string arg)
{
    string what,where;
    object the_wall;
	object ye,ye1;
	object me = this_player();
	ye=present("zhou zimo",this_object());
	ye1=present("song qiuchen",this_object());
    if(!arg) return 0;
    if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
    the_wall = present(where,this_object()) ;
    if (the_wall)
    if(the_wall->query("name") == "壁柜橱")       
    {
		if (ye)
		{
			message_vision("$N皱眉道：这位" + RANK_D->query_respect(me)+"，请不要在光天化日下公然行窃。\n",ye);
			return 1;
		}
		if (ye1)
		{
			message_vision("$N皱眉道：这位" + RANK_D->query_respect(me)+"，请不要在光天化日下公然行窃。\n",ye1);
			return 1;
		}
    }
    return 0;
}


int do_pick(string arg)
{
	object me = this_player();
	string arg1,arg2;
	int num,gao;
	object ye,ye1;
	ye=present("zhou zimo",this_object());
	ye1=present("song qiuchen",this_object());
	if (!ye && !ye1)
		return notify_fail("你眼前一花，那朵花竟然不见了。\n");
	if (!arg)
		return notify_fail("你要摘什么？");
	if (arg != "百合花" && arg != "百合" && arg != "flower" && arg != "花" && arg != "lily")
		return notify_fail("你要摘什么？");
	if (ye)
	{
		message_vision("$N皱眉道：这位" + RANK_D->query_respect(me)+"，莫要辣手摧花。\n",ye);
		return 1;
	}
	if (ye1)
	{
		message_vision("$N皱眉道：这位" + RANK_D->query_respect(me)+"，莫要辣手摧花。\n",ye1);
		return 1;
	}
	return 0;
}
	
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


