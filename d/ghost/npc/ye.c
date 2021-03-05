#include <ansi.h>
inherit NPC;

void create()
{
        set_name("叶孤鸿", ({ "ye gu hong", "ye" }) );
        set("nickname", "小白龙");
        set("title", "武当弟子");
        set("gender", "男性");
        set("age", 26);
        set("no_arrest",1);
        set("long",	"苍白的脸，苍白的手，苍白的剑，一身白衣如雪。\n");
        set("combat_exp", 400000);                     
        set_skill("move", 80);
        set_skill("dodge", 80);
        set_skill("sword", 80);
        set_skill("parry", 80);
        set_skill("three-sword", 80);
        map_skill("sword", "three-sword");
        map_skill("parry", "three-sword");
        setup();
		carry_object(__DIR__"obj/sword2")->wield();
		carry_object("/obj/armor/cloth")->wear();
}

void init()
{
		object		me;

        ::init();
        me = this_player();
        if((interactive(me) && !me->is_ghost()) && !is_fighting()) {
	        add_action("do_leave", "leave");
                call_out("greeting", 2, me);
        }
}

int do_leave(string arg)
{
	object		me, env, gudu, fen;

	env = environment();
	gudu = present("gu du mei", env);
	if(arg != "gu du mei" || !objectp(gudu)) {
		write("你要留下谁？\n");
		return 1;
	}
	me = this_player();
	fen = present("fen yan zi", env);
	if(!objectp(fen)) {
		remove_call_out("noleave");
		say( YEL "\n叶孤鸿冷冷的脸上露出一丝笑容道：多谢这位朋友。\n"NOR);
		say( YEL "\n孤独美惊慌地喊道：你答应帮我的！没我你走不出这片森林！\n"NOR);
		say( HIR "\n叶孤鸿喝道：老匹夫！还我爱妻命来！\n"NOR);
		this_object()->kill_ob(gudu);
	}
	else {
		message_vision(YEL"\n$N对叶孤鸿道:叶大少爷，你可已出手了！\n",fen);
		message_vision(YEL"$N道:好！\n",this_object());
		message_vision(HIR"$N一剑刺入了$n的胸膛！\n",this_object(), fen);
		fen->die();
		message_vision(YEL"\n叶孤鸿对$N说道:你们可以走了！\n"NOR,me);
		me->set_temp("marks/okleave", 1);
	}
	return 1;
}

int greeting(object who)
{
	object	env, tree, fen, gudu; //add by justdoit to judge whether there is fen in tree or in room
	env=environment(this_object());
	if (!who || environment(who)!= env || who->is_ghost())
		return 1;
	
	tree = present("big tree", env);
	if(!objectp(present("fen yan zi", tree)) && !objectp(present("fen yan zi", env))) {
		fen=find_object(__DIR__"fen");
		if (!objectp(fen)) {
			fen=load_object(__DIR__"fen");
		}
		fen->move(tree);
	}
	if(gudu=present("gu du mei", environment()) && !who->query_temp("marks/okleave")) {
		message_vision( YEL "\n叶孤鸿冷冷的盯着$N道：请这位朋友把孤独美留下。(leave)\n"NOR, who);
		call_out("noleave", 10, who);
	}
	return 1;
}

int noleave(object who)
{
	object		fen, tree, env;
	env = environment(this_object());
	
	if (!who || environment(who)!= env || who->is_ghost())
		return 1;
		
	if(!is_fighting()) {
		message_vision( HIR "\n叶孤鸿冷冷的盯着$N道：这位朋友再不把孤独美留下，莫怪我要动武了。(leave)\n"NOR, who);
		tree = present("big tree", env);
		if(objectp(fen = present("fen yan zi", tree))) {
			message("vision", "\n茂密的叶间，＂哗啦啦＂一声响，一个人燕子般飞下来\n", environment(this_object()));
			fen->move(environment(this_object()));
		}
	}
	return 1;
}
