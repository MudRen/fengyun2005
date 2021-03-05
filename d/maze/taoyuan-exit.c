// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
原来这草地仍然在桃花林中，仿若花海中的一叶绿舟，四周种满了桃花，粉红
色的花瓣飘洒在空中，地上也铺着一层厚厚有如地毯般的桃花瓣，空气中充满着浓
重的花香，但隐隐之中，一缕更沁人心魄的淡淡的幽香弥漫在花丛中，空气中，你
的心中。。。草地尽头是间木屋，极小，只容得下两三人。
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"north" : __DIR__"taoyuan-maze/exit",
		"south":  __DIR__"taoyuan-end",
	]));
        set("item_desc", ([
        	"house":	"桃花林中，一座小小的木屋。\n",
        	"cabin":	"桃花林中，一座小小的木屋。\n",
        	"木屋":		"桃花林中，一座小小的木屋。\n",
        	"south":	"桃花林中，一座小小的木屋。\n",
        	
	]) );
	set("NONPC", 1);
	set("coor/x",-80);
	set("coor/y",-110);
	set("coor/z",-10);
	setup();
//	create_door("south", "door","木门", "north", DOOR_CLOSED);

}


int	valid_leave(object who , string dir) {
	object room, meihuadao;
	mapping doors;
	
	if (dir == "south") 
	{
/*		doors = this_object()->query_doors();
                if (doors["south"]["status"]==1)
                        return notify_fail("小屋的门关得紧紧的。\n");*/
		room = find_object(__DIR__"taoyuan-end");
                if (room && room->usr_in())
			return notify_fail("木屋太小，容不下这么多人。\n");
		if (!REWARD_D->riddle_check(who,"桃花林探幽"))
			return notify_fail("你探头到木屋中看了看，没什么古怪的地方。\n");
		if (room) {
			if (meihuadao = present("meihuadao",room))
			if (!userp(meihuadao))	
				destruct(meihuadao);
			room->reset();
		}
	}
	return ::valid_leave(who,dir);
}

void init()
{
        if(interactive(this_player()))
        {
                remove_call_out("dropleaf");
                call_out("dropleaf",random(10)+10,this_player());
        }
}

int dropleaf(object me)
{
        object leaf;
        if(me)
        if(environment(me) == this_object())
        {
                message_vision(WHT"风过，枝动，几片桃花瓣纷纷扬扬地飘落下来，飘在你的发梢，落在你的肩头，\n"NOR,me);
		message_vision(WHT"春去秋来，江湖飘零，你是否也如这桃花瓣一般，还是孑然一身，无所依靠？\n\n"NOR,me);
        }
	return 1;
}
	