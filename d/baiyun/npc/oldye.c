#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("叶老夫子", ({ "old ye","ye" }) );
        set("gender", "男性" );
        set("title", "一叶堂 老学究");
        set("nickname",HIY"一叶蔽目，不见泰山，两豆塞耳，不闻雷霆"NOR);
        set("age", 72);
        set("long", "叶老夫子据说乃是叶氏一门的老长辈，闲来无事，来白云岛颐养天年。\n");
        set("combat_exp", 1000000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "叶老夫子一手持一卷竹简，另一手捋白须，摇头晃脑，不知所云。\n",
		}) );
        set("attitude", "friendly");
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",120,120,0,"/obj/weapon/","fighter_w","feixian-sword",1);
        setup();
        carry_object(__DIR__"obj/sengyi")->wear();
}
int accept_fight(object me)
{
        command("say 君子动口而不动手也。\n");
        return 0;
}
