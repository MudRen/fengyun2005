// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
int leave();

void create()
{
	object weapon;
        set_name("战死尸鬼", ({ "warrior ghost","ghost" }) );

		set("age",331);
		set("class","yinshi");

		set("resistance/kee",40);

     	set_skill("cursism", 100);
    	set_skill("celecurse", 100);


        set("long","一条徘徊不肯离去的怨魂。\n");

        set("combat_exp", 1000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("curse bloodcurse") :),
             }) );


        set_skill("dodge", 100);
        set_skill("13-sword", 80);

        map_skill("dodge", "13-sword");
		map_skill("cursism", "celecurse");
		setup();

}

int	is_ghost() { return 1;}

void die()
{
    object killer, owner;
    if(objectp(killer = query_temp("last_damage_from")))
    {
    	if ( objectp(owner = killer->query("possessed")))
    		killer = owner;
    	REWARD_D->riddle_set(killer,"超度亡魂/战死尸",1);
    }    	
    ::die();
}
