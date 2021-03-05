// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit __DIR__"bush_base.c";

void create()
{
        set("short", "沼泽边缘");
        set("long", @LONG
这里乌云密布，天色极暗。再往前走就是武林中有名的死域－－[33m火沼泽[32m。那里
不但荆棘密布，猛兽出没，还有能瞬间随时喷射至人于死地的毒火泉，还未走近，
已是热浪滚滚，若没有深厚的内功，多待一刻也是艰难。故老相传这火沼泽内有
一条巨龙，每当夜深人静时还能听到它的吼声。
LONG
        );
        set("exits", ([ 
  		"north" : AREA_CHENXIANG"cxs8",
	]));

        set("item_desc", ([
                "bush": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n",
                "荆棘": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n"

        ]) );

        set("outdoors", "zhaoze");
        
        set("route","south");
        set("route_room",__DIR__"zhaoze1");
        
	set("coor/x",20);
	set("coor/y",40);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_cut", "chop");
        add_action("do_listen","listen");
}

void reset()
{
	::reset();
	delete("exits/"+query("route"));
}


int do_listen(){
	object dragon, room;
	room = find_object(__DIR__"center");
	if (!room)
		room = load_object(__DIR__"center");
		
	if (dragon = present("red dragon",room))
	{
		tell_object(this_player(),HIR"\n沼泽深处隐约传来低低的轰鸣，似乎是巨兽的呜咽之声。\n"NOR);
	}else
		tell_object(this_player(),HIR"\n沼泽里一片，静寂偶尔有几声咕咕的水泡声。\n"NOR);
	return 1;
}


