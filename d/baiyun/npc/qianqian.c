#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("浅浅", ({ "qian qian","qian" }) );
        set("gender", "女性" );
        set("title", "茶姑");
        set("nickname",HIG"啜罢云间一盏茶，卧看白云补残霞"NOR);
        set("age", 22);
        set("long", "浅浅的微笑，浅浅的沏茶，浅浅的温柔。\n");
        set("combat_exp", 1400000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "浅浅抿嘴一笑道：虽说这碧螺春生于洞庭，毛峰长于黄山，龙井闻名自西湖，
岩茶来自武夷；但生长在白云岛后呀，却是别有妙处。。。\n",
	}) );
        set("attitude", "friendly");
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",120,120,0,"/obj/weapon/","fighter_w","taiji",1);
        setup();
        carry_object("/d/jinan/npc/obj/changbao")->wear();
}


int accept_fight(object me)
{
        command("say 小女子若有得罪，您千万别介意，小女子给您作揖陪个不是。\n");
        return 0;
}
