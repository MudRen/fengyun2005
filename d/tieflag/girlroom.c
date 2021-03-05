// Room: girl


inherit ROOM;
#include <room.h>

void create()
{
        set("short", "雅室");
        set("long", @LONG
屋内堆满了各类珍奇的玩物，时鲜的水果，华丽的衣杉，绝美的珠宝．．．室
内玉塌锦墩上，似乎斜坐着一个白衣女子。
LONG
        );
        set("objects", ([
                __DIR__"npc/shui": 1,
        ]) );
       

	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
//	replace_program(ROOM);      
}

void init(){
	add_action("do_open", "push");
}



int do_open(string arg)
{
	object room;
        object me;  
	me=this_player();
	if(!objectp(room = find_object(__DIR__"goldroom")))
	room = load_object(__DIR__"goldroom");
	switch (arg)
         {
         case "jade":
         case "玉壁":
             if(query("exits/west")) return notify_fail("门已经是开的了。");
             message_vision("$N伸手在玉壁上一按，玉壁上出现一扇小门。\n",this_player());
             set("exits/west",__DIR__"goldroom");
		room->set("exits/east",__DIR__"girlroom");
	     call_out("closepath",5,room);
             return 1;
         }
}

void closepath(object room)
{
tell_object(this_object(),"小门＂吱＂的一声又关上了。\n");
delete("exits/west");
room->delete("exits/east");
}