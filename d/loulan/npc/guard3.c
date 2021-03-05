#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("李义骑", ({ "li yiqi","li" }) );
        set("gender", "男性" );
        create_family("快活林", 1, "急风第三骑");
        set("long",
"快活王精心培养的急风三十六骑，征战多年，个个以一敌百。洒金斗篷，织锦劲装，\n胸前各有一面紫铜护心镜，唯有镜上刻的字不同，镜上刻着『三』字。 \n"  
                );
        set("attitude", "peaceful");
	set("class","bat");
		set("perform_busy_d", "bat/dodge/meng-steps/huanyinqianchong");
		set("perform_weapon_attack","bat/blade/bat-blade/shiwanshenmo");
		
		set("chat_chance_combat", 20);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
	set("age", 25);
        set("combat_exp", 680000);
        
        set("chat_chance", 2);
        set("chat_msg", ({
                "李义骑警惕地看了看四周，长吁口气道：可千万别出差错。\n",
                }) );

        set_skill("unarmed", 80);
        set_skill("blade", 100);
        set_skill("bat-blade", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move", 100);
        set_skill("meng-steps", 100);
        map_skill("dodge", "meng-steps");
        map_skill("blade", "bat-blade");
        map_skill("parry", "bat-blade");
                
        setup();
	carry_object(__DIR__"obj/jinzhuang")->wear();
	carry_object(__DIR__"obj/doupeng3")->wear();
	carry_object(__DIR__"obj/huxinjing3")->wear();
	carry_object("/obj/weapon/blade")->wield();
}

void init()
{	
	object me;
	::init();
	me = this_player();
	if( interactive(me) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 0, me);
	}
}

void greeting(object me)
{
	object *inv;
	int i;
	object ob;
	ob = this_object();
	
	if (environment(me) != environment(ob))		return;
	if( userp(me) )
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if(inv[i]->query("item_owner")=="李义骑" && (int)inv[i]->query("equipped"))
			{
				message_vision(HIY"$N大喝道：何人如此大胆，竟敢冒充本骑！\n"NOR,ob);
				ob->kill_ob(me);
				me->kill_ob(ob);
			}
		}
	}
}