inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "驿站厢房");
        set("long", @LONG
厢房是一间又长，又窄，又低的屋子，一张狭长的黄杨木桌子从这头摆到那一
头，桌上铺着张旧得看不出原来颜色的台布。摆在桌上的是通常的餐具和饮食，无
非是些裂口很多的笨重瓷器。这里是给来往驿吏稍作歇息之处。
LONG
        );
        set("exits", ([ 
		"west":  __DIR__"yizhan",
	]));
        set("objects",([
 		__DIR__"npc/yayi": 1,
 		__DIR__"npc/yayi1":1,
        ])  );         
        set("item_desc", ([
		"桌子":	"一张狭长的黄杨木桌子从这头摆到那一头，桌上摆的是通常的餐具和饮食。
你可以在这儿歇息一阵（ｒｅｓｔ）。\n",
	 	"table":"一张狭长的黄杨木桌子从这头摆到那一头，桌上摆的是通常的餐具和饮食。
你可以在这儿歇息一阵（ｒｅｓｔ）。\n",
	 ]));
	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	set("map","taiping");
	setup();
}


void init(){
	add_action("do_rest","rest");
}


int do_rest(){
	object yayi,me;
	me=this_player();
	yayi=present("yayi",this_object());
	if (me->query("class")!="official" && objectp(yayi))
		return notify_fail("捕快说：＂这儿只供官差歇息，闲人速速离开。＂\n");
	me->start_busy(1);
	message_vision(WHT"$N坐在桌旁狼吞虎咽地吃喝起来。\n"NOR,me);
	call_out("done",2,me);
	return 1;
}


int done(object me) {
	me->set("food",230);
	me->set("water",230);
	message_vision(HIG"$N打了个饱嗝，心满意足地站了起来。\n"NOR,me);
	return 1;
}