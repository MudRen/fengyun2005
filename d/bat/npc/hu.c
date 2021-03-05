#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("胡铁花", ({ "hu tiehua","hu" }) );
	set("title",HIB "无拘无束" NOR);
	set("gender", "男性" );
	set("age", 35);
	set("no_heal",1);
    set("long","阳光，照着他满脸青惨惨的胡茬子，也照着他脸上那懒洋洋的笑容，
一双又黑又亮的大眼睛, 他就是楚留香最好的朋友胡铁花，又名花疯子。\n");
    set("combat_exp", 4600000);
	set("attitude", "friendly");
		
	set("chat_chance", 1);
    set("chat_msg", ({
               	"胡铁花说道：唉！虎落平阳被犬欺呀 ！\n",
				"胡铁花默然半晌，说道：不知老臭虫现在在哪里 ？\n",
    }) );
    
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
     }) ); 		

	auto_npc_setup("wang",220,200,0,"/obj/weapon/","fighter_u","luori",1);
	set_skill("fengyu-piaoxiang", 250);
	
	setup();	
	carry_object("/obj/armor/cloth",([	
    						"name":  "染血的长衫",
    						"long": "一件长衫，上面血花点点，触目惊心。\n",
    						 ]))->wear();

}


/*
void die()
{
	int i;
	object killer,owner;
	if(objectp(killer = query_temp("last_damage_from")))
        if(owner=killer->query("possessed")) {
		killer=owner;
	} 
        killer->set_temp("marks/murderhu", 1);
	::die();

}

void init()
{	
	::init();
	add_action("do_killing", "kill");
    
}

int do_killing(string arg)
{
    	object player, victim;
    	string id;
    	player = this_player();
    	if(!arg || arg == "") return 0;
    	victim = present(arg, environment(player));
    	if(!objectp(victim))
		return notify_fail("这里没有这个人。\n");
    	if(living(victim))
    	{
        	id=victim->query("id");
       		if(victim == this_object())
        	{
            	message_vision(HIW
"$N笑道：你中了原随云的借刀杀人之计了！他不敢来见我，所以派你来探虚实。\n"NOR, this_object());
            	return 0;
        	} 
    	}
    	return 0;
}*/