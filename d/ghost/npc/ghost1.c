#include <ansi.h>
inherit NPC;

void create()
{
		object		biao, bag;
        set_name("勾魂使者", ({ "ghost" }) );
        set("gender", "男性");
        set("per", 1);
        set("class", "ghost");
        create_family("幽灵山庄", 2, "弟子");
        set("combat_exp", 150000);
        set("long",	"他的脸赫然已被人一刀削平了，据说，他最怕的便是别人告诉他“没有面目”
（tell ghost no face）\n");
        set("no_arrest",1);
        set_skill("move", 150);
        set_skill("dodge", 100);
        set_skill("five-steps", 100);
        set_skill("sword", 140);
        set_skill("three-sword", 50);
        set_skill("parry",100);
        map_skill("parry","three-sword");
		map_skill("dodge", "five-steps");
		map_skill("move", "five-steps");
		map_skill("sword", "three-sword");
        setup();
		carry_object(__DIR__"obj/clip2")->wield();
		carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
	object		me;

        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
		add_action("do_accept", "accept");
		add_action("do_tell", "tell");
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

int do_tell(string arg)
{
	string 	obname, things;
	object me = this_player();
        if(!arg || sscanf(arg, "%s %s", obname, things)!=2 )
                return notify_fail("tell <人> <事>\n");
	if(!this_player()->query_temp("marks/test")) return 0;
	this_player()->set_temp("marks/test", 0);
	if(obname == "ghost") {
		if(things == "no face" || things == "没有面目" || things == "知道来历") {
			remove_call_out("do_test");
			message_vision(YEL "\n$N脸色变得极为难看，对$n说道：你可以过去了。\n"NOR, this_object(), this_player());
			this_player()->set_temp("marks/合约", 1);
           	REWARD_D->riddle_done(me,"幽灵山庄",10,1);
		
        	return 1;
		}
	}
	return 0;
}

int greeting(object me)
{
	message_vision(YEL "\n$N对$n说道：想过我这一关？就接我一招（accept test）。\n"NOR, this_object(), me);
	return 1;
}

int do_accept(string arg)
{
	if( arg != "test" ) {
                return notify_fail("你要接受什么？\n");
	}
	remove_call_out("do_test");
	message_vision( YEL "$N说道：好！给你五分钟时间准备！\n"NOR, this_object());
	this_player()->set_temp("marks/test", 1);
	call_out("do_test", 15, this_player());
	return 1;
}

int do_test(object me)
{
	int	kee;

	if(objectp(me)) {
		me->set_temp("marks/test", 0);
		if(environment(me) == environment()) {
			message_vision(YEL "\n$N说道：准备了！接我这一招！\n"NOR, this_object());
			kee = (int)me->query("kee");
			COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
			if( (int)me->query("kee") < kee  || !present(me, environment())) { 
				message_vision(YEL "\n$N说道：：连一招都接不下，真是自不量力！\n"NOR, this_object());
				return 1;
			}
			else {
				message_vision(YEL "\n$N对$n说道：好功夫！你可以过去了。\n"NOR, this_object(), me);
				me->set_temp("marks/合约", 1);
				return 1;
			}
		}
	}
	return 0;
}
