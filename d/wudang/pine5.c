#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "松林");
	set("long", @LONG
茂密的松林，不时能见到几只松鼠在树上跳来跳去。虽然只有几丝阳光能透林
而入，却不显得阴森可怖。习习凉风不时迎面吹来，使人浑身舒畅。使你想躺在这
里，睡上一觉。
LONG
	);
	set("exits", ([ 
  		"east" : __DIR__"pine1",
  		"west" : __DIR__"pine1",
  		"north" : __DIR__"pine2",
  		"south" : __DIR__"pine2",
	]));

	set("objects", ([
		__DIR__"npc/oldtaoist8" : 1,
		__DIR__"obj/pine" : 1,
		__DIR__"obj/hole" : 1,
   ]) );
	set("no_lu_letter",1);
	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",-40);
	setup();
}


void init()
{
	add_action("do_look", "look");
	add_action("do_get","get");
}

int do_look(string arg)
{
	if (!arg)	return 0;
	if (arg == "树洞" || arg == "hole")
	{
		write("一个黑漆漆的树洞，洞边刻着一把小小的黄金剑。"NOR"\n");
		return 1;
	}
	return 0;
}


int do_get(string arg)
{
    string what,where;
    object the_wall;
	object ye,ye1;
	object me = this_player();
	ye=present("taoist elder",this_object());
    if(!arg) return 0;
    if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
    the_wall = present(where,this_object()) ;
    if (the_wall)
    if(the_wall->query("name") == "树洞" || the_wall->query("name") == "hole" )       
    {
		if (ye)
		{
			message_vision("$N好奇地瞅着$n的动作，$n身上起了一阵鸡皮疙瘩，停下手瞪了一眼$N。\n",ye,this_player());
			return 1;
		}
    }
    return 0;
}


void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("树洞", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		if (!random(4))
		{
		stone = new(__DIR__"obj/mask");
		if(stone)
			stone->move(river);
		}
	}
	return;
}
