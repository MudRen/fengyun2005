// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;
string look_stone();

void create()
{
	set("short", "水梦庵");
    set("long", @LONG
这座小庵隐在乱石之后，不为世人所知。这里供着的是一座观世音菩萨像
，四坪见方的小屋中打扫得一尘不染，案台上整整齐齐地摞着几本佛经，净瓶
中供着新折下的柳枝，个个蒲团摆放得井然有序，可见水梦庵的主人素喜整洁
清净。
LONG
        );
	set("objects", ([
		__DIR__"npc/nun":1,
		__DIR__"obj/statue" : 1,
		__DIR__"obj/desk" : 1,
		__DIR__"obj/vase" : 1,
//		__DIR__"obj/putun" : 1,
		__DIR__"obj/putun2" : 1,
		__DIR__"obj/vase" : 1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"southdown" : __DIR__"peak12",
	]) );

	set("coor/x",10);
	set("coor/y",60);
	set("coor/z",50);
	setup();
    create_door("southdown","rock","乱石","northup",DOOR_CLOSED);
}



void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("净瓶", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/willow");
		if(stone)
			stone->move(river);
	}

	river = present("案", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/nbook");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/nbook1");
		if(stone)
			stone->move(river);
	}

	river = present("蒲团", this_object());
	if (!river)
		return;
	set("long", @LONG
这座小庵隐在乱石之后，不为世人所知。这里供着的是一座观世音菩萨像
，四坪见方的小屋中打扫得一尘不染，案台上整整齐齐地摞着几本佛经，净瓶
中供着新折下的柳枝，个个蒲团摆放得井然有序，可见水梦庵的主人素喜整洁
清净。
LONG
        );
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/nbook2");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/nbook3");
		if(stone)
			stone->move(river);
	}


	return;
}


void init() {
	add_action("do_get","get");
}



int do_get(string arg) {
	
	string arg1,arg2;
	int num,gao;
	object ye;
	
	if (!ye=present("liaohen",this_object())) return 0;
	if (!arg)
		return 0;
	
	if (sscanf(arg,"%s from %s",arg1,arg2)==2)
	{
		if (arg2 == "vase" || arg2 == "净瓶" || arg2 == "瓶" || arg2 == "白玉净瓶")
			gao=2;
	
		if (arg1 == "willow" && gao == 2) gao=1;
		if (arg1 == "all" && gao == 2) gao=1;
		if (sscanf(arg1,"%s %d",arg2,num)==2)
			if (arg2=="willow" && gao == 2) gao=1;
		
		if (gao != 1)
		{
			if (arg2 == "案" || arg2 == "台" || arg2 == "案台" || arg2 == "desk" || arg2 == "table" || arg2 == "蒲团" || arg2 == "putuan")
			{
				if (arg1 == "buddhism book" || arg1 == "all" || arg1 == "book")
					gao=3;
				if (sscanf(arg1,"%s %d",arg2,num)==2)
					if (arg2=="buddhism book") gao=3;
			}
		}
	}
	
	if (gao == 1) {
		message_vision("$N摇摇头，微笑道：这位施主，莫对菩萨不敬。\n",ye);
		return 1;
	}
	
	if (gao == 3) {
		if (this_player()->query("bellicosity"))
		{
		message_vision("$N微笑道：施主既有心向善，便请将老尼手抄此书拿去。\n",ye);
		}
		else
		{
		message_vision("$N摇摇头，微笑道：这位施主，还是将它留给有缘之人吧。\n",ye);
		return 1;
		}
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


