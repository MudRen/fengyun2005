// Room: neishi.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "内室");

	set("long", @LONG
这是老于头俩口住的小屋，除了张板床外，简陋的似乎就只剩下还算干净的四
壁和屋正中的一张小木头桌了。桌子上点着盏油灯，若明若暗的摇曳着。
LONG);

	//{{ --- by MapMaker
	set("exits",([
		"south":__DIR__"yard",
	]) );
	
	set("item_desc", ([
		"桌子":		"一张普普通通的桌子。\n",
		"板床":		"一张普普通通的板床。\n",
		"bed":		"一张普普通通的板床。\n",
		"table":	"一张普普通通的桌子。\n",
	]));		
	
        set("indoors", "libie");
	set("coor/x",-5);
	set("coor/y",20);
	set("coor/z",0);

	setup();

}

int valid_enter(object me)
{	
	object ob, letter;
	
	if(me->query_temp("libie/离别钩_取信"))
	if(ob = present("old yu", this_object()))
	if(ob->query("信"))
		ob->start_call_out( (: call_other, ob, "give_letter" ,me:), 1);
	return 1;
}
