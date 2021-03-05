#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("僧义海", ({ "monk yihai","yihai" }) );
        set("gender", "男性" );
        set("class", "shaolin");
        set("nickname",WHT"琴僧"NOR);
        set("age", 32);
        set("long", "僧义海为其时著名的一代琴僧，乃夷中的入门弟子。在越州法华山学琴，积十年不下山，\n
昼夜手不释弦，遂穷其妙。叶孤城亲自登门方请得其来白云岛主持绿竹斋。\n");
        set("combat_exp", 900000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "僧义海叹了口气，喃喃道：小僧不远万里来此白云岛，盖是因由传闻琴心姑娘会抚“广陵散”\n
这绝曲。。但寒暑三载，却未得谋其一面。。。哎。。\n",
        "僧义海痴痴道：若是谁能让贫僧听得一曲广陵散，小僧我愿将平生所得琴术赠与他。\n",
	}) );
        set("attitude", "friendly");
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",100,120,0,"/obj/weapon/","fighter_w","feixian-sword",1);
		setup();
        carry_object(__DIR__"obj/sengyi")->wear();
		carry_object(__DIR__"obj/sinny1");
}
int accept_fight(object me)
{
        command("say 善哉善哉，小僧不通武道，施主勿开玩笑。\n");
        return 0;
}
