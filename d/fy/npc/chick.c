#include <ansi.h>
#include <command.h>
inherit NPC;

void create()
{
	set_name("土娼", ({ "chick girl","girl" }) );
	set("gender", "女性" );
	set("age", 22);
	set("per", 30);
	set("long", @LONG
土娼是．．．如果你感兴趣的话，请（ｅｎｊｏｙ）．
LONG
);
	set("combat_exp", 2000);
	set("attitude", "friendly");

	setup();
	
}

int accept_fight(object me)
{
	command("say 小女子哪里是您的对手？");
	return 0;
}


int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，您一定会．．．．！");
        return 1;
}


void init()
{
	::init();
	add_action("do_enjoy","enjoy");
}

int do_enjoy()
{
	object me;
	object *inv;
	int maxgin,maxkee, maxsen;
	int i;
	me = this_player();
	message_vision("$N用手挖了挖鼻孔，然后向$n走过来．．．\n",this_object(),me);
	
	inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++)
        {
        if (inv[i]->query("no_drop") || inv[i]->query("owner")) continue;
		if(!DROP_CMD->do_drop(me, inv[i])) {
			destruct(inv[i]);
		}
	}
	tell_object(me, "你觉得有些酸臭，不过人有三急，凑合吧。。。。\n");
	me->unconcious();
	me->apply_condition("hualiu_poison",10+random(20));
	return 1;
}
