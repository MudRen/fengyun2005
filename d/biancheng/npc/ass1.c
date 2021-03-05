//written by Cheng Bao
// gangster.c

#include <ansi.h>
inherit SMART_NPC;
void goaway();
void create()
{
        set_name("蒙面人", ({ "veiled man","man" }) );
        set("gender", "男性" );
        set("age", 27);
        set("per",10);
        set("long", "此人黑布蒙面，看不清他是男是女，更看不清他的面目。");
                
        set("bellicosity", 1500 );
        set("combat_exp", 10000);

        set("chat_chance", 50);
        set("chat_msg", ({
			(: goaway :),
        }) );

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
    		 (: auto_smart_fight(30) :),
        }) );
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void goaway()
{
		object ob;
		if (ob=present("fat lady",environment()) )
		{
			command("grin");
			kill_ob(ob);
			ob->kill_ob(this_object());
			return; 
		}
			
		message_vision("$N一声唿哨，消失得无影无踪！\n",this_object());
		destruct(this_object());
}


void unconcious()	{ die();}


void	die(){
	
	object killer;
	string deathmsg;
	string *msg = ({
		"\n蒙面人哎呀一声，捂着胸口倒了下去。\n",
		"\n蒙面人跌跌撞撞地斜飞出去，在地上打了几个滚儿，血花飞溅。\n",
		"\n蒙面人说：竟然有保镖，这下老大失策了，该多带点人手！\n",
		"\n蒙面人后悔地说：没想到，海不可斗量，人不可貌胖！\n",
		"\n蒙面人惊恐地说：怎么回事，不是说保镖是菜鸟么！\n",
	});
	
	deathmsg = msg[random(5)];
	
	message_vision(HIR""+ deathmsg + "\n蒙面人死了。\n"NOR, this_object());
	destruct(this_object());
}

