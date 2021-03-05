#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("僧巨然", ({ "monk juran","juran" }) );
        set("gender", "男性" );
        set("title", "画僧");
        set("nickname",HIC"峰顶夕阳烟际水，分明六幅巨然山"NOR);
        set("age", 32);
        set("class","moon");
        set("long", 
"僧巨然师承董源，笔墨清润，多画烟岚气象，擅用长披麻皴，以破笔焦墨点苔，\n较之董源更为雄秀奇逸。为宋时南派画家的代表之一。\n");
        set("combat_exp", 10000000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "僧巨然淡淡一笑道：这白云岛真可谓人间仙境，再多的笔墨，也无法得其一分神韵，可惜可惜。\n",
		}) );
        set("attitude", "friendly");

		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_u","stormdance2",1);

        setup();
        carry_object(__DIR__"obj/sengyi")->wear();
}
int accept_fight(object me)
{
        command("say 善哉善哉，小僧一介画匠，施主何须动此干戈呢？\n");
        return 0;
}
/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
