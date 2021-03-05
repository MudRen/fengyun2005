#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("白鸽弟子", ({ "baige dizi", "dizi"}) );
        set("title",WHT"西方神教 "NOR);
        set("gender", "男性" );
        set("age", 22);
        set("long", "
西方神教复现江湖，天地人三长老，四金刚，金银铜铁锡五护卫。
又分白鸽、灰狼、黄犬，三个分舵。“黄犬”负责追踪：“灰狼”
负责搏杀：“白鸽”的任务，就是负责刺探传递各路的消息。\n");
        set("combat_exp", 250000);
        set("attitude", "friendly");
                        
        set("chat_chance", 1);
        set("chat_msg", ({
                
        }) );
	
	setup();
	auto_npc_setup("wang",100,65,1,"/obj/weapon/","fighter_w","demon-blade",2);
	carry_object("/obj/armor/cloth",([	
    						"name":  "白色教服",
    						"long": "西方神教教众的服饰。\n",
    						 ]))->wear();
}
