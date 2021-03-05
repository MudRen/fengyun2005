// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("艾绒", ({ "airong"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一卷从越秀山采来的艾绒。有特殊的功效，可以治灸（cure）各种瘀肿。\n");
		set("unit", "卷");
		set("value", 1000);
		set("wear_msg", "$N把一卷$n戴在头上。\n");
		set("unwield_msg", "$N把$n从头上除了下来。\n");
		set("female_only", 1);

	}
	::init_head();
}

void init()
{
  	if(this_player()==environment() )
  	add_action("do_cure","cure");
}

int do_cure(string arg)
{
 	object me;
 	object ob;
 	if(!arg) return notify_fail("cure <某人>\n");
 	me =this_player();
 	if (me->is_busy())
 		return notify_fail("你现在正忙。\n");
 	if(objectp(ob=present(arg,environment(me)))) {
	   	if (ob==me) {
	   		tell_object(me,"你从怀里掏出一卷越秀山艾绒在自己身上治灸了一会儿。\n");
	   		message("vision",me->name()+"从怀里掏出一卷越秀山艾绒在自己身上治灸了一会儿。\n",environment(me),me);	
	   	} else 	
	   	   	message_vision("$N从怀里掏出一卷越秀山艾绒在$n身上治灸了一会儿。\n",me,ob);
	   	ob->cure_arong(me);
   		me->perform_busy(1);
   		return 1;
 	} else return notify_fail("找不到"+arg+"。\n");
 
}
