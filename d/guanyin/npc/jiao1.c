inherit NPC;
#include <ansi.h>

void create()
{
        object armor;
        set_name("焦化", ({ "jiao hua" }) );
        set("gender", "男性");
        set("age", 45);
        set("nickname","天残");
        set("title",WHT"海天双煞"NOR);
        set("long","
此人脸上像是平整整的一块，无鼻无耳，连眉毛都没有，只有眼睛像是
两块寒玉，发出一种彻骨的光芒。\n");
	  
        set("attitude", "friendly");
        set("reward_npc", 1);
		set("difficulty",3);
	
		set("class","lama");
        set("no_busy",4);
        set("combat_exp", 3200000);        
                               
        set_skill("perception", 150);
        set_skill("force", 180);
        set_skill("unarmed", 180);
        set_skill("parry",200);
		set_skill("move", 180);
		set_skill("lingxi-zhi",150);
        set_skill("kwan-yin-spells",130);
		set_skill("spells",200);
		set_skill("perception", 180);
	
		map_skill("spells","kwan-yin-spells");  
		map_skill("move","five-steps");
		map_skill("unarmed","lingxi-zhi");
	      
        setup();

	armor=new("/obj/armor/cloth");
	armor->set_name(WHT"天残衫"NOR,({"cloth"}) );
	armor->move(this_object());
	armor->wear();
}

 
void init()
{
//      object ob;
        ::init();
	add_action("do_killing","kill");
}

int do_killing(string arg)
{
    	object player, victim;
    	string id;
//  	int sen;

    	player = this_player();
    	if(!arg || arg == "") return 0;
    	victim = present(arg, environment(player));
    	if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    	if(living(victim))
    	{
        	id= victim->query("id");
        	if( id == "jiao lao" && player->query("combat_exp")>3400000)
        	{
	            	message_vision("$N笑道：对手厉害，咱兄弟俩一块儿上。\n", this_object());
	            	this_object()->kill_ob(player);
	            	player->kill_ob(this_object());
	            	return 0;
        	}
    	}
    	return 0;
} 