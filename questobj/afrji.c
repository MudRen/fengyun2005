#include <ansi.h>
inherit ITEM;
void create()
{
    	set_name(YEL "阿发日记" NOR, ({ "afrji" }) );
    	set_weight(1);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
	        set("unit", "本");
	        set("material", "paper");
	        set("long", "一本阿发以前的日记，你可以读一读（ｒｅａｄ）。\n");
    	}

    	::init_item();
}


void init()
{
    	if(environment(this_object())==this_player()){
			add_action("do_read","read");
    		add_action("do_go","go");
		}
}


int markit(object me)
{
    	object gold;
    	if(!query("already"))   	{
        	gold = new("/obj/money/gold");
        	tell_object(me, YEL"\n\n你一弯腰，从『阿发日记』所指示的地方挖出些金子！\n"NOR);
        	if (me->query("combat_exp")>1000000)
        	if (!REWARD_D->check_m_success(me,"日记藏宝")) {
        		tell_object(me,HIY"你简直不敢相信自己的眼睛，这是一个大宝藏！！！\n");
        		tell_object(me,HIY"你的银行储蓄增加了50两金子！！！\n"NOR);
        		me->add("deposit",500000);
				REWARD_D->riddle_done(me,"日记藏宝",10,1);
        	}
        	gold->set_amount(1+random(5));
        	gold->move(me);
        	me->delete_temp("going");
        	set("already",1);
    	}
    	return 1;
}

int do_read(string arg)
{
    	object me;
    	mapping exits;
    	string *dirs;
		string thisdir;
		if(arg != "afrji" && arg != "阿发日记") return 0;
		
		me=this_player();
	
		if(me->query_temp("going") >= 20) {
			 markit(me);
			 return 1;
		}
		
		if( !mapp(exits = environment(me)->query("exits")) )    {
	        tell_object(me,"这儿地势不清，换个地方看看！\n");
	        return 1;
		}
	
		dirs = keys(exits);
		if (!dirs || sizeof(dirs) < 1)    {
	        tell_object(me,"这儿地势不清，换个地方看看！\n");
	        return 1;
		}
		
		thisdir = dirs[random(sizeof(dirs))];
		set("thisdir",thisdir);
		if (!query("already")) 
			tell_object(me,"有一批宝藏就在"+thisdir+"的方向！你可以用 go "+thisdir+" 来寻找它。\n");
		else 
			tell_object(me,"日记上记载着一批宝藏的位置，不过前几天这批宝藏就被人挖走了。\n");
		return 1;
}

int do_go(string arg)
{
	
       	if (query("already"))	return 0;
       		
       	if(arg == query("thisdir") && query("thisdir") != "none") {
			this_player()->add_temp("going",1);
    	}	else
    	{	
    		this_player()->delete_temp("going");		
//    		tell_object(this_player(),YEL"走错了！只能重头开始了。\n"NOR);
    	}
    	set("thisdir","none");	
//    	tell_object(this_player(),"going is"+ this_player()->query_temp("going")+"\n");
    	return 0;
}



