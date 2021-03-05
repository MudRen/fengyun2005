// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("金凤凰", ({ "jin fenghuang", "jin"}) );
        set("gender", "女性" );
        set("age",32);
        set("long", "
她虽然已近中年，看起来还很年轻，一双凤眼棱棱有威，无论谁都可以看出
她一定是个很不好惹的女人。\n");
        
        create_family("黄山派", 5, "弟子");
	set("pursuer",1);
        set("combat_exp", random(200000)+100000);
        
        set_skill("sword", 100);
	set_skill("siqi-sword",80);
	set_skill("parry",100);
	set_skill("move",40);
	set_skill("force",20);
	set_skill("dodge",100);
	set_skill("liuquan-steps",40);
	set_skill("unarmed",100);
	set_skill("yunwu-strike",80);
	
	map_skill("unarmed","yunwu-strike");
	map_skill("sword", "siqi-sword");
	map_skill("parry", "siqi-sword");
	map_skill("dodge","liuquan-steps");
        
        set("chat_chance", 5);
        set("chat_msg", ({
		"金凤凰冷笑道：失敬失敬，抱歉抱歉，我本来还以为你是一条见人就咬的疯狗。\n",
        }) );
        
        set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
                (: perform_action, "dodge.liushuichanchan" :),
        }) );
        
	setup();
	carry_object(__DIR__"obj/cuiyi")->wear();
	carry_object(__DIR__"obj/bijian")->wield();
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

