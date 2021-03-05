#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "秘道");
	set("long", @LONG
秘道两旁，每隔十步，便有一盏石灯，走了数十步，便是道月牙石门，低垂着
淡青长帘。
LONG
	);
	set("exits",([
		"up" :__DIR__"stone1",
		"west" : __DIR__"stone3",
	
	]) );
	set("coor/x",-90);
	set("coor/y",-20);
	set("coor/z",-30);
	setup();
	create_door("west","door","月牙石门","east",DOOR_CLOSED);
}

void init()
{
	add_action("do_bomb","bomb");
}


int do_bomb(string arg)
{
        object  me, *inv, exp, nroom;
        int     i;

        me = this_player();
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
                if( (int) inv[i]->query("explosive") ) exp = inv[i];
        if( !exp)  return 0;
        	
        message_vision(HIR"$N点燃了手中的"+exp->name()+"．．．
只听得一声滔天巨响＂轰＂，洞壁被炸开个大洞．\n"NOR, me, exp);
        destruct(exp);
        nroom = find_object(__DIR__"rock0");
        if(!objectp(nroom))
        	nroom = load_object(__DIR__"rock0");
        inv = all_inventory(this_object());
        
        for(i=0; i<sizeof(inv); i++) {
        	if(userp(inv[i]) ) {
            	tell_object(inv[i],BLU"你觉得两耳轰鸣，天晕地转，差点没晕过去。\n"NOR);
            	inv[i]->set("gin",0);
            	inv[i]->set("sen",0);
            }
        }
        
        me->move(nroom);
        return 1;
}
