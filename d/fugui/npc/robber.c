#include <ansi.h>
inherit NPC;
void checking();

void create()
{
        set_name("强盗", ({ "robber" }) );
        set("gender", "男性" );
        set("age", 30);
        set("str", 30);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
这强盗满脸伤疤，虎背熊腰，一脸凶狠而霸道的样子。
LONG
);
        set("attitude", "heroism");
        set("bellicosity", 1500 );
        set("combat_exp", 800000);
        set("chat_chance", 3);
        set("chat_msg", ({
		"强盗高喊：他奶奶个熊，老子要钱又要命，叫你人财两空。\n",
		(: checking :),
        }) );

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
              "强盗显是以劫为生，刀刀冲要害而来。\n",
              "强盗高喊：叫你人财两空。\n",
        }) );

        set("force",1000);
        set("force_factor",20);
        set_skill("unarmed", 120);
        set_skill("blade", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("demon-blade",120);
        map_skill("blade","demon-blade");
        map_skill("parry","demon-blade");
        setup();
        add_money("silver", 10); 
        carry_object(__DIR__"obj/blade")->wield();
        carry_object("/obj/armor/cloth")->wear();
}

void checking()
{
        object cart;
        object robber,player;
        robber = this_object();
        player = this_player();
        cart = present("silver cart",environment());
        
        if((int)robber->query("kee")* 100 / (int)robber->query("max_kee") <= 30)
        {
                if (!living(robber)) 
                	return;
                else 
                {
               		message_vision("\n$N叫道：点子扎手，扯呼！\n\n$N个起纵遁入暗里不见了。\n",robber);
                  	destruct(this_object());
                  	return;
                }
        }

        if (robber->is_fighting()) 
        {
                return;
        }
        else
        {
        	if ( !present(player->query("id"), environment(this_object())) && present("silver cart",environment(this_object())) )
           	{  
                	command("laugh");
                        message_vision("$N推着镖车呼啸而去。\n", robber);
                        if( present("silver cart",environment(this_object())) )
                        	destruct(cart);
                	call_out("destroying",1,robber);
                	return;
        	}
	        else
          	{
        		message_vision("$N悻悻的说：“算你跑的快！”\n",robber);
			command("sigh");
			call_out("destroying",1,robber);
			message_vision("$N身形几起几落消失在暗处．\n",robber);
			return;
		}
	}
             
}

void destroying(object me)
{
        destruct(me);
        return;
}