inherit NPC;

void create()
{
        set_name("老张", ({ "lao zhang","lao" }) );
        set("gender", "男性" );
        set("age", 68);

        set("attitude", "peaceful");

        set("long","这是一位久经风霜的老人。\n");

        set("combat_exp", 200000);
        set("score", 50);
        
        set_skill("unarmed", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100);
        set_skill("meihua-shou", 100);
        set_skill("qidaoforce", 150);
        set_skill("fall-steps", 100);

        map_skill("unarmed", "meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge", "fall-steps");

	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_gogo", "go");
}


int do_gogo(string arg)
{
	object me;
	me = this_player();
	if( arg == "north" )
	{
	if( me->query("class") ) 
		if( me->query("class") != "legend" && me->query("family") 
			&& !me->query_temp("resort_qin")) {
		command("sigh");
		command("say 江湖人身在江湖，江湖人莫入翠竹。");
		write("这个方向的路被老张挡住了 。\n");
		return 1;
		}
		else
			return 0;		
	}
	return 0;
}
