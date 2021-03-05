#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("奇异古画", ({ "picture","mysterious picture" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "一张奇异的古画，画像边上细细密密的用蝇头小楷写了些文字（study）。\n");
                set("value", 2);
                set("material", "paper");
       			set("cat","华山派 掌门弟子的宠物「整天哈欠的」华真真的猫(Mimicat)");
       }
    	::init_item();
}

void init()
{
	if(this_player()==environment())
		add_action("do_study","study");
}

int do_study(string arg)
{
    object me,ob;
	int sena;
	string book, cat;
        
    me = this_player();
    if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
        return notify_fail("指令格式：study <书> <神数量>\n");
    if(this_object() != present(book, me)) 
          return 0;
	message("vision",me->name()+"正在专心地研读"+name()+"。\n"NOR,environment(me),me);
	
	cat = query("cat");
	tell_object(this_player(),name()+"上画着一只胖胖的大懒猫，边上注道：风云懒功第一的\n————"+ cat+"\n");
	
	if (query("p_id")== me->query("id")) {
		tell_object(me,HIC"你的「偷懒之术」已经登峰造极，无人可比了！\n"NOR);
		return 1;
	}
	
	if (me->query_temp("annie/yawnbook_2")>50){
		tell_object(me,CYN"胖胖的大懒猫对着你打了个打哈欠说：让位，让位。\n"NOR);
		set("cat",me->query("name")+"（"+me->query("id")+"）");
		set("p_id",me->query("id"));
		return 1;
	}
	
	me->add_temp("annie/yawnbook",1+sena/10);
	if (me->query_temp("annie/yawnbook") > 
			me->query_temp("annie/yawnbook_2") * me->query_temp("annie/yawnbook_2"))
	{
		me->add_temp("annie/yawnbook_2",1);
		me->set_temp("annie/yawnbook",0);
		tell_object(me,HIC"你的「偷懒之术」进步了！\n"NOR);
	}
	tell_object(this_player(),"你研读有关偷懒之术的技巧，似乎有点心得。\n");
	return 1;
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
