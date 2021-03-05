#include <ansi.h>
inherit MAZE_NPC;

void create()
{
        set_name("金衣卫首领", ({ "sentry"}) );
        set("gender", "男性" );
        set("title","金钱帮 护法弟子");
        set("age", 32);
        set("maze","jq1");
        set("target_name","金衣卫");
	set("class","assassin");
        set("long", "
金衣卫俱是由荆无命亲手训练的护卫弟子，虽然个个籍籍无名，但较之江湖中的
所谓名门侠士，毫无逊色，而每个俱是不畏生死的死士，以一敌十，亦多可同归
于尽。\n");
        
        set("combat_exp", 700000);
        set("attitude", "aggressive");
        set("pursuer",1);
            
		set("chat_chance", 1);
        set("chat_msg", ({
                "金衣卫首领冷冷道：私闯武堂者，死！\n",
        }) );
		
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
        }) );
	
		auto_npc_setup("liaoyin",100,120,1,"/obj/weapon/","fighter_w","sharen-sword",1);
		delete_skill("iron-cloth");
		setup();
        carry_object("/d/fy/npc/obj/tangfu")->wear();
}

int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}