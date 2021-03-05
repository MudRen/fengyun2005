#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("赵如钢", ({ "zhao rugang","zhao"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "这是西方神教四大金钢之一。\n");
        set("combat_exp", 6500000);
        set("attitude", "friendly");
        set("group", "demon");
        set("vendetta_mark","demon");
	set("title",YEL"西方神教 哏堂堂主"NOR);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );
        set("smartnpc_busy", 1);
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","tianmo",1);
	set_skill("iron-cloth",200);
	set_skill("jin-gang",200);
	map_skill("iron-cloth","jin-gang");
    	setup();
        carry_object("/obj/armor/cloth",([	
    						"name":  "哏字服",
    						"long": "西方神教哏堂堂主的服饰。\n",
    						 ]))->wear();
        carry_object(__DIR__"obj/yaopai");
}
