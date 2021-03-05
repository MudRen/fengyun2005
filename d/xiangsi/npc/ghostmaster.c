inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()
{
		object weapon;
        set_name("鬼道士", ({ "ghost taoist","ghost","taoist"}) );
        set("title",CYN"怨念深厚"NOR);
        set("gender", "男性" );
    
	set("real_boss",1);
	set("no_arrest",1);


		set("chat_chance", 1);
		set("chat_msg", ({
				"鬼道士喃喃道：我恨……我恨啊……\n",
				"鬼道士喃喃道：妖女……妖女……\n",
				"鬼道士喃喃道：山上……雪洞……\n",
		}) );

        set("age", 54);

        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
//                (: smart_fight() :),
             }) );

        set("combat_exp", 6000000);
		set_temp("apply/haste",200);
		set_temp("apply/damage",200);
		set_temp("apply/attack",600);
    
        set_skill("spells", 75);
        set_skill("perception", 75);
        
		set("skill_public",1);
        
		setup();

	weapon = new("/obj/armor/cloth");
	weapon->set_name(HIR BLK"残烂布衣"NOR, ({ "cloth" }));
	weapon->move(this_object());
	weapon->wear();
}


int recognize_apprentice(object ob)
{
        if (!ob->query("free_learn/advanced_spells_perception"))
        {
                message_vision("鬼道士翻着惨白的眼珠子，喃喃道：杀……杀了她……报……报仇……\n\n",ob);
                return 0;
        }
    return 1;
}



int is_ghost() { return 1; }

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

