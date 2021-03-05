inherit SMART_NPC;

void create()
{
        set_name("持国天王", ({ "tianwang","天王","持国天王" }) );
        set("gender", "男性" );
        set("combat_exp", 560000);
        set("attitude", "friendly"); 
        set("no_shown",1);
        auto_npc_setup("wang",100,100,0,"/obj/weapon/","fighter_w","lianxin-blade",1);
        setup();
        carry_object(__DIR__"obj/godblade")->wield();
}

int is_ghost() { return 1; }

/*
void init()
{
	::init();
	add_action("do_kill","kill");
}

int getme(object me)
{
	this_object()->kill_ob(me);
	return 1;
}

int do_kill(string arg)
{
	object me;
	me = this_player();
	if(arg == "master can" || arg == "master" || arg == "can")
	{
	message_vision("参机大师说道：阿弥陀佛！如此涂碳生灵，让佛祖来惩罚$N吧！！\n",me);
	call_out("getme",1,me);
	return 1;
	}
	return 0;
}
*/