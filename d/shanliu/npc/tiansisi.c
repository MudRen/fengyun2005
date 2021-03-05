// yangfan.c

inherit NPC;

#include <ansi.h>
void create()
{
		set_name("田丝丝", ({ "tian sisi","tian" }) );
		set("gender", "女性" );
		set("age", 18);
		set("title",GRN"大小姐"NOR);
		set("long",
"她便是世袭镇远侯，中原孟尝田白石田二爷的独生女儿，也因为她实在是
个甜丝丝的人儿。不但人长得甜，说话也甜，笑起来更甜，甜得令任何人大都
不愿，也不忍拒绝她任何的要求。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "田丝丝嘴噘得简直可以挂个油瓶，跺着脚道：死胖子，臭酒鬼，
猪八戒……,又不知道死到哪去了？\n",
    }) );
		set("combat_exp", 80000);
		set("attitude", "friendly");
		set("per",30);
		set_skill("dodge",100);
        set_skill("unarmed",50);
        set_skill("parry", 50);
		setup();
}

