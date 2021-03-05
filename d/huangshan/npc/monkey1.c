#include <ansi.h>

inherit NPC;
void create()
{
    set_name("大马猴", ({ "monkey"}) );
    set("race", "野兽");
    set("age", 1);
    set("gender", "雌性");
    set("long", "一只龇牙咧嘴的大马猴正不怀好意地看着你。\n");
    set("attitude","peaceful");
    set("limbs", ({ "头部", "身体","尾巴" }) );
    set("chat_msg", ({
        "大马猴抓了抓头。\n",
    }) );
	set_skill("move",500);
    	set_skill("unarmed",600);
    	set_skill("dodge",600);
    	set("combat_exp", 2000000);
    	set("verbs", ({ "bite","claw" }) );
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
		
	if( !ob || !visible(ob) || environment(ob) != environment() ) 
		return;
	if( ob->query("combat_exp")<30000 ) 
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
				tell_object(ob, "大马猴嗖地一下从你头上跳过．．．．．．。\n");
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
                say( "大马猴吱吱地叫了几声。\n");
			return;
		}
      	}
      	else
        {
        	say( "大马猴满怀失望地看了你几眼.\n");
		return;
	}
}