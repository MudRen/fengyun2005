#include <ansi.h>

inherit NPC;
void create()
{
    set_name("小弥猴", ({ "monkey"}) );
    set("race", "野兽");
    set("age", 1);
    set("gender", "雌性");
    set("long", "一只龇牙咧嘴的小弥猴正好奇地地看着你。\n");
    set("attitude","peaceful");
    set("chat_msg", ({
        "小弥猴从悬崖上倒挂下来，在你的头顶上晃来晃去。\n",
    }) );
	set("agi", 60);
	
	set_skill("move",50);
    	set_skill("unarmed",100);
    	set_skill("dodge",50);
    	set("combat_exp", 80000);
	set("max_gin", 500);
    	set("max_kee", 500);
    	set("max_sen", 5000);
    	set("eff_gin", 500);
    	set("eff_kee", 500);
	set("eff_sen", 5000);
    	setup();
	
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int havenothingon(object ob)
{  
	object *inv;
	inv = all_inventory(ob);
	if (sizeof(inv)==0) 
		return 1;
	else
		return 0;
}

void greeting(object ob)
{
        object *tar;
        object obj;
        int i,size;

	if( ob->query("combat_exp")<10000 ) 
		return;
	if( !ob || !visible(ob) || environment(ob) != environment() ) 
		return;
	tar = all_inventory(ob);
	size=sizeof(tar);
	
	if(!havenothingon(ob))
	{
		if (random(100)<10)
		{
			i=random(size);
			obj=tar[i];
			if(!(int)obj->query("no_get") && !(int)obj->query("equipped") && !(int)obj->query("no_drop"))
			{
				obj->move(this_object());        	
				tell_object(ob, "小弥猴嗖地一下从你头上跳过．．．．．．。\n");
	      			tell_object(ob, "你感觉身上一轻，似乎丢了什么东西．．．．．．\n");
	      			message("vision", "你看到" + this_object()->name() + "鬼鬼祟祟地从" + ob->name() + "身上摸走了一" + obj->query("unit") 
	      			+ obj->name() + "！\n", environment(ob), ({ this_object(), ob }) );
	      			return;
	      		}
	      		else
	      		{
	      			tell_object(ob, "你觉得"+this_object()->name()+"鬼鬼祟祟的盯着你．．．．．．。\n");
	      			tell_object(ob, "你立刻提高警觉，小心翼翼的看护着自己的贵重物品．．．．．．。\n");
	      			return;
	      		}
      		}
      		else
      		{
                say( "小弥猴吱吱地叫了几声。\n");
			return;
		}
      	}
      	else
        {
        	say( "小弥猴满怀失望地看了你几眼.\n");
		return;
	}
}