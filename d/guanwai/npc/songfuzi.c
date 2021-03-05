inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
    	set_name("宋老夫子", ({ "song fuzi","song" }) );
    	set("gender", "男性" );
    	set("age", 99 );
    	set("title", HIG "悬壶济世"NOR);
	set("long",
        	"一个白发苍苍，闭目养神，似乎随时都可能倒下的老者。但偶尔双目\n睁开，立刻就象换了一个年轻人般。\n");
	set("attitude", "friendly");
    	set("combat_exp", 500000);
        set("chat_chance", 1);
        set("chat_msg", ({
  		"宋老夫子懒懒地抬起头，打量了你一眼。\n",
                }) );
	set("per",30);
    	set("vendor_goods", ([
               __DIR__"obj/xuezhi":50,
               __DIR__"obj/sanyecao":50,
               __DIR__"obj/qisehua":50,
	]) );
    
    	set_skill("fall-steps",100);
    	set_skill("unarmed",100);
    	set_skill("dodge",100);
    	set_skill("parry",100);
    	set_skill("meihua-shou",50);
    	map_skill("unarmed","meihua-shou");
    	map_skill("dodge","fall-steps");
	setup();
    	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	::init();
        add_action("do_vendor_list", "list");
}

