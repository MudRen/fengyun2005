// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(WHT"信"NOR, ({"letter","mail" }));
    set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "封");
			set("long", "一封从不丢信的风云驿站丢失的信。\n");
            set("value", 0);
			set("no_reset",1);
			set("no_stack",1);
			set("desc_ext","任务物件");
        }
	::init_item();
}

void invoke(string name)
{
	set("name",WHT"送给"+name+"的信"NOR);
	set("marks",name);
	call_out("dest",900);
}


void dest()
{
	object me;
	me = environment();
	if (me)
		tell_object(me,"一阵风过，"+query("name")+"飘飘摇摇，飞上青天。\n");
	destruct(this_object());
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/




