#include <room.h>
#include <ansi.h>
inherit ROOM;

int drop_him(object me)
{
	me->start_busy(1);
	call_out("dropnow", 1, me);
	return 1;
}

void init()
{	object ob;
	object jade;
	int water, food, bellicosity;
//	string outexit;
	if( interactive( ob = this_player()))
	{
		water = ob->query("water");
		food = ob->query("food");
		bellicosity = ob->query("bellicosity");
		
		water -= (random(2)+ 1) * water / 10;
		food -= (random(2)+ 1) * food / 10;
		
		if (water<0)	water=0;
		if (food<0)		food =0;
		
		bellicosity += random(10);
		ob->set("water", water);
		ob->set("food", food);
		ob->set("bellicosity", bellicosity);	
		if( !objectp(jade = present("jade", ob)))
		{
			if( random(1000)< 5)	drop_him(ob);
		}
		
	}
        add_action("do_pull", "pull");
}


int dropnow(object me)
{
	int num;
	if(environment(me) == this_object()){
	        message_vision(HIW"$N突然感到脚底软绵绵的，无处着力！", me);
        	message_vision("$N大叫一声“不好！”，可是来不及了…\n", me);
		message_vision("$N已陷身流沙之中！！\n"NOR, me); 
        	sscanf(file_name(this_object()),__DIR__"desert%d",num);
        	me->move(__DIR__"quicksand"+num);
    	}
        return 1;
}
	
int do_pull ( string arg)
{
	object me, who;
	object room;
	int num;
	me = this_player();
        if ( !arg  ) return notify_fail("你要拉谁上来？\n");
	sscanf(file_name(this_object()),__DIR__"desert%d",num);
	room = load_object(__DIR__"quicksand"+num);
        if(!objectp(who = present(arg, room)) ||  !living(who))
        return notify_fail("流沙里没有这个人。\n");
         message_vision(HIW"$N用尽全身力量，将$n从流沙中救了出来。\n"NOR, me,who);
        who->move(this_object());
	return 1;

}


		
		
	